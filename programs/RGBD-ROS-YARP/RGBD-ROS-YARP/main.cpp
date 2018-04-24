/**************************************************************
 **************************************************************
 *
 *      RGBD Sensor: TIAGo
 *
 *      YARP Subscribe -> ROS Topic
 *      Type: Main
 *
 *      Robotics Lab
 *      Departamento de Ingeniería de Sistemas y Automática
 *      Universidad Carlos III de Madrid
 *
 **************************************************************
 **************************************************************
 */

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



typedef sensor_msgs_CompressedImage Image_t;
yarp::os::Subscriber<Image_t> inImagePort;

//***************************************
//***************************************
// Espacios de nombres
//***************************************
//***************************************

using namespace cv;
using namespace std;
using namespace yarp::os;


//---------------------------------------
//---------------------------------------
// Función main
//---------------------------------------
//---------------------------------------

int main()
{
    cout<<endl;
    cout << "\t RGBD Sensor: TIAGo" << endl;
    cout << "\t YARP Subscribe -> ROS Topic" << endl;
    cout<<endl;
    cout << "\t Robotics Lab" << endl;
    cout << "\t Departamento de Ingeniería de Sistemas y Automática" << endl;
    cout << "\t Universidad Carlos III de Madrid" << endl;
    cout<<endl;

    cout<<"Inicializando YARP"<<endl;

    //***************************************
    //***************************************
    // Inicialización YARP
    //***************************************
    //***************************************

    Network yarp;


    return 0;
}



//++++++++++++++++++++++++++++++++++++++++
// Funciones
//++++++++++++++++++++++++++++++++++++++++










