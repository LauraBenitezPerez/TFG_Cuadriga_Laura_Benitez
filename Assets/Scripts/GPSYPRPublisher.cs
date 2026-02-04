using UnityEngine;
using RosMessageTypes.Sensor;
using RosMessageTypes.Geometry;
using Unity.Robotics.ROSTCPConnector;
using System;

public class GPSYPRPublisher : MonoBehaviour
{
    ROSConnection ros;
    public GameObject Sensor_Link;

    // Coordenadas de referencia
    public double referenceLatitude = 36.717083;
    public double referenceLongitude = -4.489515;
    public double referenceAltitude = 50.0;
    private const double EarthRadius = 6378137.0;

    // Frecuencias de publicación
    public float gpsPublishFrequency = 5.0f; // 1 Hz típico GPS 
    public float yprPublishFrequency = 10.0f; // 30 Hz o lo que quieras 
    private float gpsTimer = 0f; 
    private float yprTimer = 0f;


    void Start()
    {
        ros = ROSConnection.GetOrCreateInstance();

        // Topics que espera tu nodo "cuadriga"
        ros.RegisterPublisher<NavSatFixMsg>("/cuadriga/fixposition/navsatfix");
        ros.RegisterPublisher<Vector3Msg>("/cuadriga/fixposition/ypr");
    }

    void Update() 
    {
        float dt = Time.deltaTime; 
        gpsTimer += dt; 
        yprTimer += dt; 
        // GPS cada segundo 
        if (gpsTimer >= 1f / gpsPublishFrequency) 
        { 
            PublishGPSData(); 
            gpsTimer = 0f; 
        } 
        // Orientación (YPR) más frecuente 
        if (yprTimer >= 1f / yprPublishFrequency) 
        { 
            PublishYPRData(); 
            yprTimer = 0f; 
        } 
    }

    // -------- GPS ---------
    void PublishGPSData()
    {
        Vector3 relativePosition = Sensor_Link.transform.position;
        Debug.Log($"Sensor_Link global: {relativePosition}");
        //Calcular las coordenadas GPS
        double deltaLatitude = (relativePosition.x / EarthRadius) * (180.0 / Math.PI);
        double deltaLongitude = (- relativePosition.z / (EarthRadius * Math.Cos(referenceLatitude * Math.PI / 180.0))) * (180.0 / Math.PI);
        double deltaAltitude = relativePosition.y;

        double latitude  = referenceLatitude  + deltaLatitude;
        double longitude = referenceLongitude + deltaLongitude;
        double altitude = referenceAltitude + deltaAltitude;
  

        NavSatFixMsg gpsMessage = new NavSatFixMsg
        {
            header = new RosMessageTypes.Std.HeaderMsg
            {
                stamp = new RosMessageTypes.BuiltinInterfaces.TimeMsg
                {
                    sec = (int)DateTimeOffset.UtcNow.ToUnixTimeSeconds(),
                    nanosec = (uint)(DateTimeOffset.UtcNow.ToUnixTimeMilliseconds() % 1000 * 1000000)
                },
                frame_id = "GPS"
            },
            latitude = latitude,
            longitude = longitude,
            altitude = altitude,
            status = new NavSatStatusMsg
            {
                status = NavSatStatusMsg.STATUS_FIX,
                service = NavSatStatusMsg.SERVICE_GPS
            },
            position_covariance = new double[9],
            position_covariance_type = NavSatFixMsg.COVARIANCE_TYPE_UNKNOWN
        };

        ros.Publish("/cuadriga/fixposition/navsatfix", gpsMessage);
        Debug.Log($"Publicado GPS: lat={latitude}, lon={longitude}, alt={altitude}");
    }
    void PublishYPRData()
    {
        Quaternion rot = Sensor_Link.transform.rotation;
        
        Vector3 dir = rot * Vector3.up;

        float yaw = Mathf.Atan2(dir.x, dir.z);

        // Normalización a [-pi, +pi]
        if (yaw > Mathf.PI)  yaw -= 2f * Mathf.PI;
        if (yaw < -Mathf.PI) yaw += 2f * Mathf.PI;

        float pitch = 0f;
        float roll  = 0f;

        ros.Publish("/cuadriga/fixposition/ypr", new Vector3Msg(yaw, pitch, roll));

        Debug.Log($"Publicado YAW REAL: {yaw}");
    }

}
