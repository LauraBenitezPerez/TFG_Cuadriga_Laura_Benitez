using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CameraManagerPro : MonoBehaviour
{
    // -------- CAMARAS DEL ARGO J8 --------
    [Header("Cámaras ARGO J8")]
    public GameObject argoFrontCam;
    public GameObject argoBackCam;

    // -------- CAMARAS DE CUADRIGA --------
    [Header("Cámaras CUÁDRIGA-II")]
    public GameObject cuadFrontCam;
    public GameObject cuadBackCam;

    // -------- CAMARAS DEL UAV --------
    [Header("Cámaras UAV")]
    public GameObject uavFrontCam;
    public GameObject uavBackCam;

    // -------- CAMARA GLOBAL --------
    [Header("Cámara Global")]
    public GameObject globalCam;

    // -------- CONTROL INTERNO --------
    private string activeRobot = "argo"; 
    // argo, cuadriga o uav

    private bool frontCameraActive = true;
    // true = frontal, false = trasera

    private bool globalMode = true;
    // true = cámara global activa


    void Start()
    {
        ShowGlobalCamera();
    }


    void Update()
    {
        // Seleccionar ARGO J8 con tecla J
        if (Input.GetKeyDown(KeyCode.J))
        {
            activeRobot = "argo";
            globalMode = false;
            frontCameraActive = true;
            UpdateCameras();
        }

        // Seleccionar CUÁDRIGA-II con tecla C
        if (Input.GetKeyDown(KeyCode.C))
        {
            activeRobot = "cuadriga";
            globalMode = false;
            frontCameraActive = true;
            UpdateCameras();
        }

        // Seleccionar UAV con tecla U
        if (Input.GetKeyDown(KeyCode.U))
        {
            activeRobot = "uav";
            globalMode = false;
            frontCameraActive = true;
            UpdateCameras();
        }

        // Activar cámara global con tecla G
        if (Input.GetKeyDown(KeyCode.G))
        {
            ShowGlobalCamera();
        }

        // Cambiar entre cámara frontal y trasera con tecla R
        if (Input.GetKeyDown(KeyCode.R))
        {
            if (!globalMode)
            {
                frontCameraActive = !frontCameraActive;
                UpdateCameras();
            }
        }
    }


    // -------- FUNCIONES DE CAMARA --------

    private void ShowGlobalCamera()
    {
        globalMode = true;
        UpdateCameras();
    }


    private void UpdateCameras()
    {
        // Primero apagamos todas las cámaras
        globalCam.SetActive(false);

        argoFrontCam.SetActive(false);
        argoBackCam.SetActive(false);

        cuadFrontCam.SetActive(false);
        cuadBackCam.SetActive(false);

        uavFrontCam.SetActive(false);
        uavBackCam.SetActive(false);

        // Si está activa la cámara global
        if (globalMode)
        {
            globalCam.SetActive(true);
            Debug.Log("Cámara activa: GLOBAL");
            return;
        }

        // Si está activo ARGO J8
        if (activeRobot == "argo")
        {
            if (frontCameraActive)
            {
                argoFrontCam.SetActive(true);
                Debug.Log("Robot activo: ARGO J8 | Cámara frontal");
            }
            else
            {
                argoBackCam.SetActive(true);
                Debug.Log("Robot activo: ARGO J8 | Cámara trasera");
            }
        }

        // Si está activa CUÁDRIGA-II
        else if (activeRobot == "cuadriga")
        {
            if (frontCameraActive)
            {
                cuadFrontCam.SetActive(true);
                Debug.Log("Robot activo: CUÁDRIGA-II | Cámara frontal");
            }
            else
            {
                cuadBackCam.SetActive(true);
                Debug.Log("Robot activo: CUÁDRIGA-II | Cámara trasera");
            }
        }

        // Si está activo UAV
        else if (activeRobot == "uav")
        {
            if (frontCameraActive)
            {
                uavFrontCam.SetActive(true);
                Debug.Log("Robot activo: UAV | Cámara frontal");
            }
            else
            {
                uavBackCam.SetActive(true);
                Debug.Log("Robot activo: UAV | Cámara trasera");
            }
        }
    }
}