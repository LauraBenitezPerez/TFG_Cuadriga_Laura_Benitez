using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Terrain_Detection : MonoBehaviour
{
    [Header("Material físico a modificar")]
    public PhysicMaterial physicMaterial;

    [Header("Capas a ignorar")]
    public LayerMask layerToIgnore;

    [Header("Sistema de clima")]
    public WeatherEffects weatherEffects;

    private RaycastHit hit;

    void FixedUpdate()
    {
        if (Physics.Raycast(transform.position, transform.TransformDirection(Vector3.down), out hit, Mathf.Infinity, ~layerToIgnore))
        {
            Debug.DrawRay(transform.position, transform.TransformDirection(Vector3.down) * hit.distance, Color.yellow);

            bool raining = false;

            if (weatherEffects != null)
            {
                raining = weatherEffects.isRaining;
            }

            if (hit.transform.CompareTag("Road"))
            {
                if (raining)
                {
                    SetPhysicMaterial(0.15f, 0.15f, 0.0f);
                    Debug.Log("Road mojado. df = " + physicMaterial.dynamicFriction + " sf = " + physicMaterial.staticFriction);
                }
                else
                {
                    SetPhysicMaterial(0.3f, 0.3f, 0.0f);
                    Debug.Log("Road seco. df = " + physicMaterial.dynamicFriction + " sf = " + physicMaterial.staticFriction);
                }
            }
            else if (hit.transform.CompareTag("Pavement"))
            {
                if (raining)
                {
                    SetPhysicMaterial(0.1f, 0.1f, 0.0f);
                    Debug.Log("Pavement mojado. df = " + physicMaterial.dynamicFriction + " sf = " + physicMaterial.staticFriction);
                }
                else
                {
                    SetPhysicMaterial(0.2f, 0.2f, 0.0f);
                    Debug.Log("Pavement seco. df = " + physicMaterial.dynamicFriction + " sf = " + physicMaterial.staticFriction);
                }
            }
            else if (hit.transform.CompareTag("RiverBed"))
            {
                if (raining)
                {
                    SetPhysicMaterial(0.8f, 0.8f, 0.0f);
                    Debug.Log("RiverBed con lluvia. df = " + physicMaterial.dynamicFriction + " sf = " + physicMaterial.staticFriction);
                }
                else
                {
                    SetPhysicMaterial(0.6f, 0.6f, 0.0f);
                    Debug.Log("RiverBed seco. df = " + physicMaterial.dynamicFriction + " sf = " + physicMaterial.staticFriction);
                }
            }
            else
            {
                if (raining)
                {
                    SetPhysicMaterial(0.7f, 0.7f, 0.0f);
                    Debug.Log("OffRoad mojado. df = " + physicMaterial.dynamicFriction + " sf = " + physicMaterial.staticFriction);
                }
                else
                {
                    SetPhysicMaterial(0.5f, 0.5f, 0.0f);
                    Debug.Log("OffRoad seco. df = " + physicMaterial.dynamicFriction + " sf = " + physicMaterial.staticFriction);
                }
            }
        }
    }

    void SetPhysicMaterial(float dynamicFriction, float staticFriction, float bounciness)
    {
        physicMaterial.dynamicFriction = dynamicFriction;
        physicMaterial.staticFriction = staticFriction;
        physicMaterial.bounciness = bounciness;
    }
}