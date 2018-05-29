/**************************************************************
 **************************************************************
 *
 *      RGBD Sensor: TIAGo
 *
 *      YARP Subscribe -> ROS Topic
 *      Class: YARP Read
 *      Type: Sources
 *
 *      Robotics Lab
 *      Departamento de Ingeniería de Sistemas y Automática
 *      Universidad Carlos III de Madrid
 *
 **************************************************************
 **************************************************************
 */

#include "yarp_read_ros_image.h"

yarp_read_ros_image::yarp_read_ros_image()
{
    //***************************************
    //          YARP: Recibe de ROS
    //***************************************

    cout<<"Suscribiendo a topic de ROS para leer de el..."<<endl;
    //***************************************
    // Instanciar nodo de escucha YARP
    //***************************************

    Node node("/yarp/listener");

    //***************************************
    // Suscribirse al topic de ROS
    //***************************************

    yarp::os::Subscriber<Image_t> subscriber;

    if (!subscriber.topic("/camera/rgb/image_raw")) {
        cerr<< "Lo siento, no se ha podido realizar la conexión con el topic de ROS";
        return -1;
    }else{

        cout<<"La conexión con el topic de ROS se ha establecido correctamente"<<endl;
    }

}

void yarp_read_ros_image::leer()
{

    Image_t *imageFrame;
    imageFrame = inImagePort->read(FALSE);
       if (imageFrame == YARP_NULLPTR) {

           return;
       }

    Mat inCvMat = decodeImage(imageFrame);

    // Introducir HAAR
}

yarp_read_ros_image::~yarp_read_ros_image()
{


}
