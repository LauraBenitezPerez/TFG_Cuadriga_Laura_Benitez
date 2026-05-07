#include "cuadriga/cuadriga.hpp"

using std::placeholders::_1;


Cuadriga::Cuadriga() : Node("cuadriga")
{
    float Latitud=0;
    float Longitud=0;
    float Altitud=0;
    float Latitud0=0;
    float Longitud0=0;
    float Altitud0=0;
    bool flag_origen=false;
    std::vector<u_int8_t> data = {0};
    bool flag = 0;
    bool flag_rafaga_activa =false;
    int contador_rafaga = 0;
    int temporizador = 0;
    std::array <char,2> Caracter = {0,0};
    float Voltaje_bateria = 0;
    float Voltaje_controladora = 0;
    this -> v_lineal = 0.4;
    float w = 0;
    this -> vmin = 0.4;
    this -> vmax = 1;
    std::vector<u_int8_t> palabra_actual = {0};
    std::vector<std::vector<uint8_t>> palabras = {{0},{0}};
    std::array<char,2> cmd_vel_hex = {0,0};
    this -> trayectoria = {};
    //auto qos = rclcpp::QoS(rclcpp::KeepLast(32)).best_effort();
    rclcpp::QoS qos_profile(rclcpp::KeepLast(150));
    //qos_profile.reliable();
    qos_profile.reliability(RMW_QOS_POLICY_RELIABILITY_BEST_EFFORT);
    //qos_profile.history(RMW_QOS_POLICY_HISTORY_KEEP_LAST);
    //qos_profile.durability(RMW_QOS_POLICY_DURABILITY_VOLATILE);

    pub_cmd_ = this-> create_publisher<geometry_msgs::msg::Twist>("/cmd_vel", 10);
    pub2_ = this -> create_publisher<std_msgs::msg::Float32MultiArray>("Cuadriga/posicion_grafica",10);
    pub3_ = this -> create_publisher<std_msgs::msg::Float32MultiArray>("Cuadriga/objetivo_grafica",10);

    sub2_ = this -> create_subscription<sensor_msgs::msg::NavSatFix>("cuadriga/fixposition/navsatfix",1, std::bind(&Cuadriga::process_GPS_data,this,_1));
    sub3_ = this -> create_subscription<geometry_msgs::msg::Vector3>("cuadriga/fixposition/ypr",1, std::bind(&Cuadriga::process_orientation_data,this,_1));
    sub4_ = this -> create_subscription<cuadriga_interfaces::msg::GPXPath>("/trayectoria_gpx",10,std::bind(&Cuadriga::process_trayectoria_archivo,this,_1));

    this -> declare_parameter<bool>("flag_origen",true);
    this -> declare_parameter<bool>("enable_navegacion",true);
    this -> declare_parameter<float>("v_lineal",0.3);
}

Cuadriga::~Cuadriga()
{
    RCLCPP_INFO(this->get_logger(), "Se acabo");
}

std::array<float,2> Cuadriga::LLR2XYR(float Latitud, float Longitud, float Altitud)
{
    //Punto de referencia donde se encuantra mi robot (para mi el (0.0))
    double Latitud0 = 36.7171415;
    double Longitud0 = -4.4895005;

    // Convertir grados a radianes
    float lat_rad = M_PI * Latitud / 180.0;
    float lon_rad = M_PI * Longitud / 180.0;
    float lat0_rad = M_PI * Latitud0 / 180.0;
    float lon0_rad = M_PI * Longitud0 / 180.0;

    // Radio de la Tierra (WGS-84)
    float R = 6378137.0;

    // Diferencias angulares
    float dLat = lat_rad - lat0_rad;
    float dLon = lon_rad - lon0_rad;

    // Coordenadas ENU
    float X = dLat * R;
    float Y  = - dLon * R * cos(lat0_rad);

    return {X, Y};
}

void Cuadriga::process_trayectoria_archivo(const cuadriga_interfaces::msg::GPXPath::SharedPtr msg)
{
    flag_origen = this->get_parameter("flag_origen").as_bool();
    if(flag_origen == true)
    {
        trayectoria.clear(); //limpia trayectoria anterior por si acaso
        for (const auto& punto : msg->waypoints)
        {
            // LLH → XY
            std::array<float, 2> punto_xy;
            punto_xy = LLR2XYR(punto.latitude, punto.longitude, punto.altitude);
            //punto_xy[0] = punto_xy[0] - origen[0];
            //punto_xy[1] = punto_xy[1] - origen[1];

            trayectoria.push_back(punto_xy);
            RCLCPP_INFO(this->get_logger(), "Punto LLH (%.6f, %.6f) → XY (%.2f, %.2f)",
                        punto.latitude, punto.longitude,
                        punto_xy[0], punto_xy[1]);
        }
    }
    
    RCLCPP_INFO(this->get_logger(), " Trayectoria cargada con %zu puntos.", trayectoria.size());
    flag_origen = false;
    this->set_parameter(rclcpp::Parameter("flag_origen", false));
    RCLCPP_INFO(this->get_logger(), "Flag origen reiniciado a false (esperando primer GPS).");
}

void Cuadriga::FollowTheCarrot()
{
    float look_ahead_distance = 1.0;
    float distancia;
    if (trayectoria.empty()) return;
 
    // Posición actual
    float x = posicion[0];  //X del robot en Unity  
    float y = posicion[1];  //Z del robot en Unity
   
    // Buscar el punto de seguimiento (look-ahead)
    std::array punto_objetivo_global = trayectoria.back(); // por defecto el último
   
    while(!trayectoria.empty())
    {
        float dx = trayectoria[0][0] - x;
        float dy = trayectoria[0][1] - y;
        distancia = std::sqrt(dx * dx + dy * dy);
       
        if(distancia < look_ahead_distance)
        {
            trayectoria.erase(trayectoria.begin());
        }
        else
        {
            punto_objetivo_global = trayectoria[0];
            break;
        }
    }
    if (trayectoria.empty())
    {
        v_lineal = 0;
        //flag_origen = false; //Se reinicia para cuando se inicie otra trayectoria sin haber parado el nodo Cuadriga
        return;
    }else{

        //Calculo objetivo en coordenadas locales al robot
        std::array<float,2> punto_objetivo_local;
        punto_objetivo_local[0] = std::cos(orientacion_actual)*(punto_objetivo_global[0]-x) + std::sin(orientacion_actual)*(punto_objetivo_global[1] - y);
        punto_objetivo_local[1] = - std::sin(orientacion_actual)*(punto_objetivo_global[0] - x) + std::cos(orientacion_actual)*(punto_objetivo_global[1]-y);
    
        RCLCPP_INFO(this->get_logger(), "Mi punto objetivo local es: (%f, %f)",punto_objetivo_local[0],punto_objetivo_local[1]);
        RCLCPP_INFO(this->get_logger(), "Mi punto objetivo global es: (%f, %f)",punto_objetivo_global[0],punto_objetivo_global[1]);

        // Cálculo del ángulo objetivo (relativo a la posición actual)
        angulo_objetivo = std::atan2(punto_objetivo_local[1], punto_objetivo_local[0]); // Radianes
        //angulo_objetivo = fmod(angulo_objetivo + 2*M_PI,2*M_PI); //Normalizar angulo entre [0, 2pi]
    
        //Cálculo de la velocidad lineal en función de la distancia al waypoint
    
        float k = 1; //Ganancia que le da peso a la distancia en el calculo
        //v_lineal = vmin +(vmax - vmin)*std::tanh(k*distancia);
        
        //float alpha_error = angulo_objetivo - orientacion_actual;
        float alpha_error = angulo_objetivo;
        
        if(alpha_error > M_PI) alpha_error -= 2*M_PI;
        if(alpha_error<  -M_PI) alpha_error += 2*M_PI;

        //Cálculo de la velocidad angular en funcion de la lineal
        //float L = 0.5;
        w = - 1.8*alpha_error;
        v_lineal = 0.4*;
        w = -(v_lineal / L) * sin(alpha_error);
        RCLCPP_INFO(this->get_logger(), "Orientacion objetivo : (%f)",alpha_error);
        RCLCPP_INFO(this->get_logger(), "Velocidad lineal y angular : (%f, %f)",v_lineal,w);
    }
}

void Cuadriga::process_orientation_data(const geometry_msgs::msg::Vector3::SharedPtr msg)
{
    orientacion_actual = msg->x - M_PI/2;
    orientacion_actual = - orientacion_actual;
    if(orientacion_actual > M_PI) orientacion_actual -= 2*M_PI;
    if(orientacion_actual <  -M_PI) orientacion_actual += 2*M_PI;
    RCLCPP_INFO(this->get_logger(),"YAW recibido de Unity: %.4f rad (%.2f grados)",orientacion_actual, orientacion_actual * 180.0 / M_PI );
    //orientacion_actual = fmod(orientacion_actual+2*M_PI,2*M_PI);
}

void Cuadriga::process_GPS_data(const sensor_msgs::msg::NavSatFix::SharedPtr msg)
{   
    RCLCPP_INFO(this->get_logger(), "He entrado en process_GPS_DATA");
    flag_origen = this -> get_parameter("flag_origen").as_bool();
    bool enable_navegacion = this -> get_parameter("enable_navegacion").as_bool();
    std::array<std::vector<u_char>,2> comando;
    std::string out="";
    Latitud = msg -> latitude;
    Longitud = msg -> longitude;
    Altitud = msg -> altitude;
    
    if(flag_origen==false)
    {
        Latitud0 = Latitud;
        Longitud0 = Longitud;
        Altitud0 = Altitud;
        //origen = LLR2XYR(Latitud, Longitud, Altitud);
        flag_origen=true;
        this ->set_parameter(rclcpp::Parameter("flag_origen",true));
        RCLCPP_INFO(this->get_logger(), "Mi coordenada geografica de origen es: (%f, %f)",Latitud0,Longitud0);
    }
    if(!trayectoria.empty() && enable_navegacion)
    {
        posicion = LLR2XYR(Latitud, Longitud, Altitud);
        //posicion[0] = posicion[0] - origen[0];
        //posicion[1] = posicion[1] - origen[1];
        RCLCPP_INFO(this->get_logger(), "Mi posicion es: (%f, %f)\n",posicion[0],posicion[1]);
        posicion_grafica.data = std::vector<float>(posicion.begin(),posicion.end());
        pub2_-> publish(posicion_grafica);

        //PurePursuit();
        FollowTheCarrot();
        float L = 0.5f;
        
        geometry_msgs::msg::Twist cmd;
        cmd.linear.x = v_lineal;
        cmd.angular.z = w;
        pub_cmd_->publish(cmd);
        
        RCLCPP_INFO(this->get_logger(), "Publicando cmd_vel -> v: %.2f m/s | w: %.2f rad/s", v_lineal, w);
    }
}

int main(int argc, char **argv){

    rclcpp::init(argc,argv);

    auto node = std::make_shared<Cuadriga>();

    rclcpp::Rate rate(10);

    while(rclcpp::ok())
    {
        rclcpp::spin_some(node);
        //node -> prueba();
        RCLCPP_INFO(node ->get_logger(), "................");
        rate.sleep();
    }

    rclcpp::shutdown();
    return 0;
}
