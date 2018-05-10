/**************************************************************
 **************************************************************
 *
 *      RGBD Sensor: TIAGo
 *
 *      YARP Subscribe -> ROS Topic
 *      Class: YARP Write
 *      Type: Sources
 *
 *      Robotics Lab
 *      Departamento de Ingeniería de Sistemas y Automática
 *      Universidad Carlos III de Madrid
 *
 **************************************************************
 **************************************************************
 */

#include "yarp_write_ros.h"

//++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++++
//  Constructor: Inicializa y suscribe
//++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++

yarp_write_ros::yarp_write_ros()
{
    //***************************************
    //          YARP: Envía a ROS
    //***************************************

    cout<<"Suscribiendo al topic de ROS para escribir..."<<endl;

    //***************************************
    // Instanciamos nodo de YARP->ROS
    //***************************************

    Node node("/yarp/talker");

    //********************************************
    // Suscripción al topic de ROS que se prepare
    //********************************************


    yarp::os::Publisher<String> publisher;
    if (!publisher.topic("/chatter")) {
        cerr<< "Lo siento, YARP no se ha podido conectar con ROS en modo envio YARP->ROS";
        return -1;
    }
}

//++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++++
//  Función: Eascribe a ROS
//++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++

void yarp_write_ros::escribir()
{

    cout<<"Enviando de YARP a ROS"<<endl;
    cout<<"Se va ha enviar:"<<endl;
    //***************************************
    //          YARP: Envía a ROS
    //***************************************

        datos_a_enviar.data="Esto es lo que envío";
        cout<<datos_a_enviar.data<<endl;
        //***************************************
        // Publicamos a ROS
        //***************************************

        publisher.write(datos_a_enviar);

}

yarp_write_ros::~yarp_write_ros()
{

}
