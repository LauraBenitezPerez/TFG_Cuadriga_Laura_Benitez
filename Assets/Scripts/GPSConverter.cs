using UnityEngine;
using System;

public class UnityToGPSConverter : MonoBehaviour
{
    // Coordenadas GPS del punto (0,0,0) de la escena
    public double referenceLatitude = 36.717083;
    public double referenceLongitude = -4.489455;
    public double referenceAltitude = 50.0;

    // Objeto a convertir
    public Transform target;

    void Update()
    {
        Vector3 pos = target.position;
        (double lat, double lon, double alt) = UnityToGPS(pos);
        Debug.Log($"{target.name} → Lat: {lat:F6}, Lon: {lon:F6}, Alt: {alt:F2}");
    }

    private (double, double, double) UnityToGPS(Vector3 pos)
    {
        double metersPerDegLat = 111320.0;
        double metersPerDegLon = 111320.0 * Math.Cos(referenceLatitude * Math.PI / 180.0);

        double lat = referenceLatitude + (pos.z / metersPerDegLat);
        double lon = referenceLongitude + (pos.x / metersPerDegLon);
        double alt = referenceAltitude + pos.y;

        return (lat, lon, alt);
    }
}


