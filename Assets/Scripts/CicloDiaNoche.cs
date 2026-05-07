using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CicloDiaNoche : MonoBehaviour
{
	[Range(0.0f, 24f)] public float Hora = 12;
	public Transform Sun;

	private float SunX;

	private void Update()
	{
		RotacionSun();
	}



	void RotacionSun()
	{
		SunX = (Hora - 6f) * 15f;

		Sun.localEulerAngles = new Vector3(SunX, 0, 0);

		if(Hora < 6 || Hora > 18)
		{
			Sun.GetComponent<Light>().intensity = 0;
		}
		else 
		{
			Sun.GetComponent<Light>().intensity = 1;
		}

	}
}
