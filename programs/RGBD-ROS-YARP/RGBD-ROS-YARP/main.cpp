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

    cout<<"Inicializando YARP..."<<endl;

    //***************************************
    //***************************************
    // Inicialización YARP
    //***************************************
    //***************************************

    Network yarp;

    char seleccion='0';// Variable de control menú de selección

    while(seleccion!='5'){

    cout<<endl;
    cout<<"Por favor, selecione una de las opciones"<<endl;
    cout<<"1. Leer de puerto ROS"<<endl;
    cout<<"2. Escribir a puerto ROS"<<endl;
    cout<<"3. Recibir imagen ROS"<<endl;
    cout<<"4. Extra ports"<<endl;
    cout<<"5. Salir"<<endl;
    cout<<endl;
    cout<<" Ha introducido:"<<endl;
    cin>>seleccion;
    cout<<endl;

    switch (seleccion){


    case '1':

        cout<<"Ha seleccionado leer de puerto ROS"<<endl;
        break;

    case '2':

        cout<<"Ha seleccionado escribir en puerto ROS"<<endl;
        break;

    case '3':

        cout<<"Ha seleccionado recibir imagen por ROS"<<endl;
        break;

    case '4':

        cout<<"Ha seleccionado extra ports"<<endl;
        break;

    case '5':

        cout<<"Ha seleccionado salir"<<endl;
        cout<<"Hasta luego, apagando..."<<endl;
        break;

    default:
        cout<<"La opción introducida no es correcta, porfavor vuelva a intentarlo"<<endl;



    }



}
    return 0;
}



//++++++++++++++++++++++++++++++++++++++++
// Funciones
//++++++++++++++++++++++++++++++++++++++++










