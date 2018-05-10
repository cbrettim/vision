/**************************************************************
 **************************************************************
 *
 *      RGBD Sensor: TIAGo
 *
 *      YARP Subscribe -> ROS Topic
 *      Class: YARP Read ROS
 *      Type: Headers
 *
 *      Robotics Lab
 *      Departamento de Ingeniería de Sistemas y Automática
 *      Universidad Carlos III de Madrid
 *
 **************************************************************
 **************************************************************
 */

#ifndef YARP_READ_ROS_H
#define YARP_READ_ROS_H

//***************************************
//***************************************
// Librerias
//***************************************
//***************************************

#include <iostream>
#include <yarp/os/all.h>
#include <stdio.h>
#include <image.h>
#include <yarp/os/all.h>
#include <yarp/sig/all.h>
#include <string>
#include <vector>
#include <sys/time.h>
#include <unistd.h>
#include <opencv2/opencv.hpp>

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
using namespace yarp::sig;
using namespace yarp::sig::draw;

class yarp_read_ros
{
public:
    yarp_read_ros();// Inicializa y se suscribe al puerto ROS
    string recibir();// Recibe datos de ROS
    ~yarp_read_ros();

//----------------------
//----------------------
//  Variables
//----------------------
//----------------------

protected:

string datos_recibidos;
};

#endif // YARP_READ_ROS_H
