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

#include "yarp_read_ros.h"

//++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++++
//  Constructor: Inicializa y se suscribe al puerto
//++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++

yarp_read_ros::yarp_read_ros()
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

    yarp::os::Subscriber<String> subscriber;

    if (!subscriber.topic("/camera/rgb/image_raw")) {
        cerr<< "Lo siento, no se ha podido realizar la conexión con el topic de ROS";
        return -1;
    }else{

        cout<<"La conexión con el topic de ROS se ha establecido correctamente"<<endl;
    }

}

//++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++++
//  Función: Recibe datos de ROS
//++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++

string yarp_read_ros::recibir()
{

    //***************************************
    // Leemos datos del topic
    //***************************************

        subscriber.read(data);
        cout << "Datos recibidos:" << data.data << " " << endl;
}

yarp_read_ros::~yarp_read_ros()
{

}
