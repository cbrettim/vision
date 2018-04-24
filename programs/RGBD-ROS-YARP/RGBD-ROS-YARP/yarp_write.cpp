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

#include "yarp_write.h"

//++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++++
//  Constructor: Inicializa y suscribe
//++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++

yarp_write::yarp_write()
{
    //***************************************
    //          YARP: Envía a ROS
    //***************************************



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

void yarp_write::escribir()
{


    //***************************************
    //          YARP: Envía a ROS
    //***************************************

        data.data="Esto es lo que envío";

        //***************************************
        // Publicamos a ROS
        //***************************************

        publisher.write(data);

}

yarp_write::~yarp_write()
{

}
