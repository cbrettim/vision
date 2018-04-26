/**************************************************************
 **************************************************************
 *
 *      RGBD Sensor: TIAGo
 *
 *      YARP Subscribe -> ROS Topic
 *      Class: Extra ports
 *      Type: Sources
 *
 *      Robotics Lab
 *      Departamento de Ingeniería de Sistemas y Automática
 *      Universidad Carlos III de Madrid
 *
 **************************************************************
 **************************************************************
 */

#include "extra_ports_fix.h"

//++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++++
//  Constructor: Inicializa puertos a futuro uso
//++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++


extra_ports_fix::extra_ports_fix()
{

    cout<<"Generando puertos YARP de entrada y de salida"<<endl;
    cout<<"Nombres de los puertos:"<<endl;
    cout<<"Puerto de entrada: /puerto_in"<<endl;
    cout<<"Puerto de salida: /puerto_out"<<endl;

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
}

extra_ports_fix::~extra_ports_fix()
{

}