using UnityEngine;
using Unity.Robotics.ROSTCPConnector;
using RosMessageTypes.CuadrigaInterfaces;
using RosMessageTypes.Sensor;
using RosMessageTypes.Std;   // <-- necesario para HeaderMsg

public class SendPath : MonoBehaviour
{
    ROSConnection ros;
    public string topicName = "/trayectoria_gpx";

    void Start()
    {
        ros = ROSConnection.GetOrCreateInstance();
        ros.RegisterPublisher<GPXPathMsg>(topicName);

        HeaderMsg header = new HeaderMsg();
        NavSatStatusMsg status = new NavSatStatusMsg();
        double[] covariance = new double[9];
        byte covarianceType = 0;

        //NavSatFixMsg wp1 = new NavSatFixMsg(header, status, 36.717083, -4.489332, 50.0, covariance, covarianceType);
        //NavSatFixMsg wp2 = new NavSatFixMsg(header, status, 36.717011, -4.489332, 50.0, covariance, covarianceType);
        //NavSatFixMsg wp3 = new NavSatFixMsg(header, status, 36.717038, -4.489455, 50.0, covariance, covarianceType);
        NavSatFixMsg wp1 = new NavSatFixMsg(header, status,36.716866 ,-4.489648, 50.0, covariance, covarianceType);
        NavSatFixMsg wp2 = new NavSatFixMsg(header, status, 36.716869, -4.489253, 50.0, covariance, covarianceType);
        GPXPathMsg msg = new GPXPathMsg(new[] { wp1, wp2 });

        ros.Publish(topicName, msg);
        Debug.Log("Ruta GPXPath publicada con " + msg.waypoints.Length + " puntos");
    }
}
