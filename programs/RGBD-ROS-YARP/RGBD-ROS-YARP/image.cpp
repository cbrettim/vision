/**************************************************************
 **************************************************************
 *
 *      RGBD Sensor: TIAGo
 *
 *      YARP Subscribe -> ROS Topic
 *      Class: Image
 *      Type: Sources
 *
 *      Robotics Lab
 *      Departamento de Ingeniería de Sistemas y Automática
 *      Universidad Carlos III de Madrid
 *
 **************************************************************
 **************************************************************
 */
#include "image.h"

image::image()
{
}

void image::leer_imagen()
{
    Mat imagen;
    imagen.imread(ruta, CV_LOAD_IMAGE_COLOR);
}


image::~image()
{

}
