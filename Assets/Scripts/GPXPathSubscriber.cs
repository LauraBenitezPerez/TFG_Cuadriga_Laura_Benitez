using UnityEngine;
using Unity.Robotics.ROSTCPConnector;
using RosMessageTypes.CuadrigaInterfaces;  // IMPORTANTE
using RosMessageTypes.Sensor;

public class GPXPathSubscriber : MonoBehaviour
{
    ROSConnection ros;

    [Header("Prefab del cubo para visualizar puntos")]
    public GameObject waypointPrefab;

    [Header("Referencia GPS del (0,0) de Unity")]
    public double referenceLatitude = 36.7171415;
    public double referenceLongitude = -4.4895005;
    private const double R = 6378137.0;

    void Start()
    {
        ros = ROSConnection.GetOrCreateInstance();

        ros.Subscribe<GPXPathMsg>("/trayectoria_gpx", OnPathReceived);

        Debug.Log("Suscrito a /trayectoria_gpx");
    }


    // Cuando llega la trayectoria del archivo GPX

    void OnPathReceived(GPXPathMsg msg)
    {
        Debug.Log("Recibido trayectoria GPX con " + msg.waypoints.Length + " puntos");

        foreach (NavSatFixMsg wp in msg.waypoints)
        {
            Vector3 posUnity = GPSToUnity(wp.latitude, wp.longitude);
            Instantiate(waypointPrefab, posUnity, Quaternion.identity);
        }
    }


    // Conversion GPS Unity (misma formula que en LLR2XYR)
   
    Vector3 GPSToUnity(double lat, double lon)
    {
        double lat0 = referenceLatitude;
        double lon0 = referenceLongitude;

        double dLat = (lat - lat0) * Mathf.Deg2Rad;
        double dLon = (lon - lon0) * Mathf.Deg2Rad;

        double North = dLat * R;
        double East  = dLon * R * Mathf.Cos((float)(lat0 * Mathf.Deg2Rad));

        // Tu orientacion Unity: X = North, Z = −East
        float X = (float)North;
        float Z = (float)(-East);

        return new Vector3(X, 2.5f, Z);
    }
}

