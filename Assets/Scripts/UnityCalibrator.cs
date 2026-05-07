using UnityEngine;

public class UnityCalibrator : MonoBehaviour
{
    [Header("GPS de los dos puntos conocidos")]
    public double lat1;
    public double lon1;
    public double lat2;
    public double lon2;

    [Header("Posiciones Unity de esos puntos (X,Z)")]
    public double X1;
    public double Z1;
    public double X2;
    public double Z2;

    [Header("Resultado: referencia GPS del (0,0)")]
    public double referenceLatitude;
    public double referenceLongitude;

    const double R = 6378137.0;   // Radio WGS84

    [ContextMenu("Calcular Referencia GPS")]
    public void ComputeReference()
    {
        // Constantes
        double Klat = (180.0 / Mathf.PI) / R;

        // Estimación inicial para cos(lat0)
        // Usamos una media para empezar
        double latGuess = (lat1 + lat2) * 0.5;
        double cosLat = Mathf.Cos((float)(latGuess * Mathf.Deg2Rad));

        double Klon = (180.0 / Mathf.PI) / (R * cosLat);

        // ---- CALCULAR LATITUD DE REFERENCIA ----
        double lat0_1 = lat1 - X1 * Klat;
        double lat0_2 = lat2 - X2 * Klat;

        double lat0 = (lat0_1 + lat0_2) * 0.5;

        // ---- CALCULAR LONGITUD DE REFERENCIA ----
        // Recuerda: Unity usa -Z como East
        double lon0_1 = lon1 - (-Z1) * Klon;
        double lon0_2 = lon2 - (-Z2) * Klon;

        double lon0 = (lon0_1 + lon0_2) * 0.5;

        referenceLatitude = lat0;
        referenceLongitude = lon0;

        Debug.Log($"Referencia calculada:");
        Debug.Log($"Lat0 = {referenceLatitude}");
        Debug.Log($"Lon0 = {referenceLongitude}");
    }
}

