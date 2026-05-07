using UnityEngine;
using System.Collections.Generic;

public class SimpleFollowLine : MonoBehaviour
{
    public Transform objetoParaSeguir;     // El robot (Cuadriga)
    public LineRenderer lineRenderer;      // La línea
    public float minDistance = 0.1f;       // Cuánto debe moverse para añadir un nuevo punto

    private List<Vector3> puntos = new List<Vector3>();

    void Start()
    {
        // Añadimos el primer punto al empezar
        puntos.Add(objetoParaSeguir.position);
        lineRenderer.positionCount = 1;
        lineRenderer.SetPosition(0, objetoParaSeguir.position);
    }

    void Update()
    {
        // Distancia entre ultimo punto guardado y la posición actual
        float dist = Vector3.Distance(objetoParaSeguir.position, puntos[puntos.Count - 1]);

        if (dist >= minDistance)
        {
            // Añadir la posición actual a la lista
            puntos.Add(objetoParaSeguir.position);

            // Actualizar el tamaño del LineRenderer
            lineRenderer.positionCount = puntos.Count;

            // ACTUALIZAR TODOS LOS PUNTOS CON UN BUCLE FOR
            for (int i = 0; i < puntos.Count; i++)
            {
                lineRenderer.SetPosition(i, puntos[i]);
            }
        }
    }
}
