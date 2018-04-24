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

#include "yarp_read.h"

yarp_read::yarp_read()
{
    //***************************************
    //          YARP: Recibe de ROS
    //***************************************


    //***************************************
    // Instanciar nodo de escucha YARP
    //***************************************

    Node node("/yarp/listener");

    //***************************************
    // Suscribirse al topic de ROS
    //***************************************

    yarp::os::Subscriber<String> subscriber;

    if (!subscriber.topic("/camera/rgb/image_raw")) {
        cerr<< "Lo siento, no se ha podido realizar la conexión con el topic de ROS";
        return -1;
    }else{

        cout<<"La conexión con el topic de ROS se ha establecido correctamente"<<endl;
    }

}

string yarp_read::recibir()
{

    //***************************************
    // Leemos datos del topic
    //***************************************

        subscriber.read(data);
        cout << "Datos recibidos:" << data.data << " " << endl;
}

yarp_read::~yarp_read()
{

}
