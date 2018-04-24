/**************************************************************
 **************************************************************
 *
 *      RGBD Sensor: TIAGo
 *
 *      YARP Subscribe -> ROS Topic
 *      Class: YARP Write
 *      Type: Headers
 *
 *      Robotics Lab
 *      Departamento de Ingeniería de Sistemas y Automática
 *      Universidad Carlos III de Madrid
 *
 **************************************************************
 **************************************************************
 */

#ifndef YARP_READ_H
#define YARP_READ_H

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

// Include ROS mesage headers. Generated with yarpidl_rosmsgs

#include "../msg/sensor_msgs_CameraInfo.h"
#include "../msg/sensor_msgs_Image.h"
#include "../msg/sensor_msgs_CompressedImage.h"
#include "../msg/sensor_msgs_PointCloud2.h"

#define TOPIC_IMAGE "/xtion/rgb/image_raw/compressed"

//***************************************
//***************************************
// Espacios de nombres
//***************************************
//***************************************

using namespace cv;
using namespace std;
using namespace yarp::os;


class yarp_write
{
public:
    yarp_write();// Inicializa y suscribe del puerto de ROS
    void escribir();// Escribe
    ~yarp_write();
};

#endif // YARP_WRITE_H