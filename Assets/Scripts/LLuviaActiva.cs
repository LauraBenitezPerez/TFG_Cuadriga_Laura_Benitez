using UnityEngine;

public class WeatherEffects : MonoBehaviour
{
    public ParticleSystem rainEffect;

    // Variable pública para activar o desactivar la lluvia desde el Inspector
    public bool isRaining = false;

    void Start()
    {
        rainEffect.Stop();  // Para que la lluvia no se inicie automáticamente
    }

    void Update()
    {
        // Activar o desactivar la lluvia dependiendo de la variable isRaining
        if (isRaining && !rainEffect.isPlaying)
        {
            StartRain(); // Iniciar la lluvia si no está ya corriendo
        }
        else if (!isRaining && rainEffect.isPlaying)
        {
            StopRain(); // Detener la lluvia si está corriendo
        }
    }

    public void StartRain()
    {
        rainEffect.Play();  // Iniciar la lluvia
        Debug.Log("La lluvia ha comenzado");
    }

    public void StopRain()
    {
        rainEffect.Stop();  // Detener la lluvia
        Debug.Log("La lluvia se ha detenido");
    }
}