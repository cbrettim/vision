/**************************************************************
 **************************************************************
 *
 *      RGBD Sensor: TIAGo
 *
 *      YARP Subscribe -> ROS Topic
 *      Class: IP camera
 *      Type: Headers
 *
 *      Robotics Lab
 *      Departamento de Ingeniería de Sistemas y Automática
 *      Universidad Carlos III de Madrid
 *
 **************************************************************
 **************************************************************
 */

#ifndef IP_CAMERA_TIAGO_H
#define IP_CAMERA_TIAGO_H

//***************************************
//***************************************
// Librerias
//***************************************
//***************************************

#include <iostream>
#include <yarp/os/all.h>
#include <stdio.h>
#include <image.h>


#include <string>
#include <vector>
#include <sys/time.h>
#include <unistd.h>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

// Include ROS mesage headers. Generated with yarpidl_rosmsgs
/*
#include "../msg/sensor_msgs_CameraInfo.h"
#include "../msg/sensor_msgs_Image.h"
#include "../msg/sensor_msgs_CompressedImage.h"
#include "../msg/sensor_msgs_PointCloud2.h"
*/
#define TOPIC_IMAGE "/xtion/rgb/image_raw/compressed"

//***************************************
//***************************************
// Espacios de nombres
//***************************************
//***************************************

using namespace cv;
using namespace std;
using namespace yarp::os;


class ip_camera_tiago
{
public:
    ip_camera_tiago();
    int ver_ip_camera();
    ~ip_camera_tiago();


//++++++++++++
// Variables
//++++++++++++

double fil;
double col;

};

#endif // IP_CAMERA_TIAGO_H
