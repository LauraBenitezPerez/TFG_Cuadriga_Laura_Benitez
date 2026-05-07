using UnityEngine;
using Unity.Robotics.ROSTCPConnector;
using RosMessageTypes.Geometry;
using Unity.Robotics.UrdfImporter.Control;

namespace RosSharp.Control
{
    public class Controlador_Cuadriga : MonoBehaviour
    {
        public string topicName = "/cmd_vel";

        public GameObject RDD_Link;
        public GameObject RTD_Link;
        public GameObject RDI_Link;
        public GameObject RTI_Link;


        private ArticulationBody RDD_Joint;
        private ArticulationBody RTD_Joint;
        private ArticulationBody RDI_Joint;
        private ArticulationBody RTI_Joint;
   


        public float maxLinearSpeed = 10; //  m/s
        public float maxRotationalSpeed = 5;
        public float wheelRadius = 0.175f; //meters
        public float trackWidth = 0.5f; // meters Distance between line of tyres
        public float forceLimit = 50;
        public float damping = 100;

        public float ROSTimeout = 0.5f;
        private float lastCmdReceived = 0f;

        ROSConnection ros;
        private RotationDirection direction;
        private float rosLinear = 0f;
        private float rosAngular = 0f;

        void Start()
        {
            RDD_Joint = RDD_Link.GetComponent<ArticulationBody>();
            RTD_Joint = RTD_Link.GetComponent<ArticulationBody>();
            RDI_Joint = RDI_Link.GetComponent<ArticulationBody>();
            RTI_Joint = RTI_Link.GetComponent<ArticulationBody>();


            SetParameters(RDD_Joint);
            SetParameters(RTD_Joint);
            SetParameters(RDI_Joint);
            SetParameters(RTI_Joint);


            ros = ROSConnection.GetOrCreateInstance();
            ros.Subscribe<TwistMsg>("cmd_vel", ReceiveROSCmd);
        }

        void ReceiveROSCmd(TwistMsg cmdVel)
        {
            rosLinear = (float)cmdVel.linear.x;
            rosAngular = (float)cmdVel.angular.z;
            lastCmdReceived = Time.time;
        }

        void FixedUpdate()
        {
           if (Time.time - lastCmdReceived > ROSTimeout)
            {
                rosLinear = 0f;
                rosAngular = 0f;
            }
            RobotInput(rosLinear, rosAngular);
        }

        private void SetParameters(ArticulationBody joint)
        {
            ArticulationDrive drive = joint.xDrive;
            drive.forceLimit = forceLimit;
            drive.damping = damping;
            joint.xDrive = drive;
        }

        private void SetSpeed(ArticulationBody joint, float wheelSpeed = float.NaN)
        {
            ArticulationDrive drive = joint.xDrive;
            if (float.IsNaN(wheelSpeed))
            {
                drive.targetVelocity = ((2 * maxLinearSpeed) / wheelRadius) * Mathf.Rad2Deg * (int)direction;
            }
            else
            {
                drive.targetVelocity = wheelSpeed;
            }
            joint.xDrive = drive;
        }

        private void RobotInput(float speed, float rotSpeed) // m/s and rad/s
        {
            if (speed > maxLinearSpeed)
            {
                speed = maxLinearSpeed;
            }
            if (rotSpeed > maxRotationalSpeed)
            {
                rotSpeed = maxRotationalSpeed;
            }

            float wR_Rotation = (speed / wheelRadius);
            float wL_Rotation = wR_Rotation;
            float wheelSpeedDiff = ((rotSpeed * trackWidth) / wheelRadius);
            if (rotSpeed != 0)
            {
                forceLimit = 500;
                damping = 500;
                wR_Rotation = (wR_Rotation - (wheelSpeedDiff / 1)) * Mathf.Rad2Deg;
                wL_Rotation = (wL_Rotation + (wheelSpeedDiff / 1)) * Mathf.Rad2Deg;

            }
            else
            {
                forceLimit = 50;
                damping = 50;
                wR_Rotation *= Mathf.Rad2Deg;
                wL_Rotation *= Mathf.Rad2Deg;
            }

            SetSpeed(RDD_Joint, wR_Rotation);
            SetSpeed(RTD_Joint, wR_Rotation);
            SetSpeed(RDI_Joint, wL_Rotation);
            SetSpeed(RTI_Joint, wL_Rotation);

            // Debug.Log(speed);
            // Debug.Log(rotSpeed);
            // Debug.Log(wL_Rotation); //-174 130
            // Debug.Log(wR_Rotation); //174 130
            // Debug.Log("--------------\n");
        }
    }
}

