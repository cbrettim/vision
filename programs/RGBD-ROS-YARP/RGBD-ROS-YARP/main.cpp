/**************************************************************
 **************************************************************
 *
 *      RGBD Sensor: TIAGo
 *
 *      YARP Subscribe -> ROS Topic
 *
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
#include "String.h"
#include <image.h>

//***************************************
//***************************************
// Espacios de nombres
//***************************************
//***************************************

using namespace std;
using namespace yarp::os;


//***************************************
//***************************************
// Función main
//***************************************
//***************************************

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

    //***************************************
    // Instanciar Bottles
    //***************************************

    BufferedPort<Bottle> Botella_inPort, Botella_outPort;

    //*****************************************************
    // Abrir puertos: Ahora no se emplean, para un futuro
    //*****************************************************

    bool ok_in = Botella_inPort.open("/puerto_in");
    bool ok_out = Botella_outPort.open("/puerto_out");


    //*********************************************
    // Comprobación puertos abiertos correctamente
    //*********************************************

    if(ok_in==false){

        cout<<"No se ha podido abrir el puerto YARP de entrada, por favor revise el sistema"<<endl;
    }

    if(ok_out==false){

        cout<<"No se ha podido abrir el puerto YARP de salida, por favor revise el sistema"<<endl;
    }


    //****************************************
    //****************************************
    // Comunicación YARP - ROS: Bidireccional
    //****************************************
    //****************************************


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

    if (!subscriber.topic("/camera/rgb/image_color")) {
        cerr<< "Lo siento, no se ha podido realizar la conexión con el topic de ROS";
        return -1;
    }else{

        cout<<"La conexión con el topic de ROS se ha establecido correctamente"<<endl;
    }

    //***************************************
    // Instanciamos objeto para guardarlo
    //***************************************

    image Objeto_de_imagenes();


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

    String data;

    //***************************************
    // YARP: Lee de ROS
    //***************************************

    data=yarp_read_ros();

    return 0;
}

//***************************************
// Funciones
//***************************************

//***************************************
// YARP: Lee de ROS
//***************************************

String yarp_read_ros(){

    //***************************************
    // Leemos datos del topic
    //***************************************

        subscriber.read(data);
        cout << "Datos recibidos:" << data.data << " " << endl;


}

//***************************************
// YARP: Escribe a ROS
//***************************************

void yarp_write_ros(String data){

    //***************************************
    //          YARP: Envía a ROS
    //***************************************

        data.data="Esto es lo que envío";

        //***************************************
        // Publicamos a ROS
        //***************************************

        publisher.write(data);



    }

