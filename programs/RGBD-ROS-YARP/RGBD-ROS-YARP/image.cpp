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

void image::leer_imagen(string ruta)
{
    Mat imagen;
    imagen.imread(ruta, CV_LOAD_IMAGE_COLOR);
    if(!imagen.data )
        {
            cout<<"Lo siento, no se ha podido abri la imagen"<<endl;
            return -1;
        }
    namedWindow("Imagen: TIAGo", WINDOW_AUTOSIZE );
    imshow("Imagen: TIAGo", imagen );

    waitKey(0);


    fil= imagen.get(CV_CAP_PROP_FRAME_WIDTH);
    col= imagen.get(CV_CAP_PROP_FRAME_HEIGHT);
}


image::~image()
{

}
