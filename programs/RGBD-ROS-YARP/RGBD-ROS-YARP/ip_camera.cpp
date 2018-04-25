/**************************************************************
 **************************************************************
 *
 *      RGBD Sensor: TIAGo
 *
 *      YARP Subscribe -> ROS Topic
 *      Class: IP camera
 *      Type: Sources
 *
 *      Robotics Lab
 *      Departamento de Ingeniería de Sistemas y Automática
 *      Universidad Carlos III de Madrid
 *
 **************************************************************
 **************************************************************
 */

#include "ip_camera.h"

ip_camera::ip_camera()
{
}

int ip_camera::ver_ip_camera()
{
    VideoCapture stream1("https://tiago-38c:8080video?x.mjpeg");//NOTA: Comprobar

    if (!stream1.isOpened()) {
    cout<<"Lo siento, no he podido acceder a la webcam"<<endl;
    }

    while (true) {
    Mat cameraFrame;
    stream1.read(cameraFrame);
    imshow("Webcam: TIAGo", cameraFrame);
    if (waitKey(30) >= 0)
    break;
    }
    return 0;
}

ip_camera::~ip_camera()
{

}
