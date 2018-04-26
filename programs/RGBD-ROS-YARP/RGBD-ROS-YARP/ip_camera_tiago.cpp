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

#include "ip_camera_tiago.h"

ip_camera_tiago::ip_camera_tiago()
{
}

int ip_camera_tiago::ver_ip_camera()
{
    VideoCapture stream1("https://tiago-38c:8080/video?x.mjpeg");//NOTA: Comprobar

    if (!stream1.isOpened()) {
    cout<<"Lo siento, no he podido acceder a la webcam"<<endl;
    }

    while (true) {
    Mat cameraFrame;
    stream1.read(cameraFrame);
    imshow("Webcam: TIAGo", cameraFrame);


    fil= cameraFrame.get(CV_CAP_PROP_FRAME_WIDTH);
    col= cameraFrame.get(CV_CAP_PROP_FRAME_HEIGHT);

    if (waitKey(30) >= 0)
    break;
    }
    return 0;
}

ip_camera_tiago::~ip_camera_tiago()
{

}