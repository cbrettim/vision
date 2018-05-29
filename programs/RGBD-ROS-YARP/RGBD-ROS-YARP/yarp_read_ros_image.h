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

#ifndef YARP_READ_ROS_IMAGE_H
#define YARP_READ_ROS_IMAGE_H

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

class yarp_read_ros_image
{
public:
    yarp_read_ros_image();
    void leer();

    //----------------------
    //----------------------
    //  Variables
    //----------------------
    //----------------------

};

#endif // YARP_READ_ROS_IMAGE_H
