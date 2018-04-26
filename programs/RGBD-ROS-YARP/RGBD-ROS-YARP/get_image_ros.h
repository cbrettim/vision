/**************************************************************
 **************************************************************
 *
 *      RGBD Sensor: TIAGo
 *
 *      YARP Subscribe -> ROS Topic
 *      Class: Get image
 *      Type: Headers
 *
 *      Robotics Lab
 *      Departamento de Ingeniería de Sistemas y Automática
 *      Universidad Carlos III de Madrid
 *
 **************************************************************
 **************************************************************
 */

#ifndef GET_IMAGE_ROS_H
#define GET_IMAGE_ROS_H

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


class get_image_ros
{
public:
    get_image_ros();// Constructor inicializa
    void solicitar_imagen();// Solicita imagen a ROS
    Mat decodeImage(Image_t *message);// Usa OpenCV para mostrar la imagen
    ~get_image_ros();

//+++++++++++++
// Variables
//+++++++++++++

double fil;
double col;

};

#endif // GET_IMAGE_ROS_H
