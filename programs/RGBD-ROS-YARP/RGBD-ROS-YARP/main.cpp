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


#include <string>
#include <vector>
#include <sys/time.h>
#include <unistd.h>
#include <opencv2/opencv.hpp>

// Include ROS mesage headers. Generated with yarpidl_rosmsgs

#include "msg/sensor_msgs_CameraInfo.h"
#include "msg/sensor_msgs_Image.h"
#include "msg/sensor_msgs_CompressedImage.h"
#include "msg/sensor_msgs_PointCloud2.h"

#define TOPIC_IMAGE     "/xtion/rgb/image_raw/compressed"



typedef sensor_msgs_CompressedImage Image_t;
yarp::os::Subscriber<Image_t> inImagePort;

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



    //***************************************
    // Obtener una imagen de TIAGo
    //***************************************

    yarp::os::Node rosNode("/obj_image_test");


        cout<<"Analizando red YARP..."<<endl;
        fflush(stdout);
        if (!yarp.checkNetwork()) {
            cout<<"Lo siento, no se ha encontrado red de YARP"<<endl;
            return 1;
        }else{
            cout<<"Listo, se ha encontrado red de YARP"<<endl;
        }
        printf("[OK]\n");


        if (!inImagePort.topic(TOPIC_IMAGE)) {
            cout<<"Error al conectarse al topic de ROS"<<endl;
            return 1;
        }else{
            cout<<"Conexión con el topic de ROS establecida correctamente"<<endl;
        }

        namedWindow("image");

        Image_t *frame;

        struct timeval start, end;
        long secs_used,micros_used;


        char pressedKey;

        solicitar_image();

    return 0;
}



//++++++++++++++++++++++++++++++++++++++++
// Funciones
//++++++++++++++++++++++++++++++++++++++++

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


//***************************************
// OPENCV: Pasamos al objeto image
//***************************************

Mat decodeImage(Image_t *message) {
    Mat image;

    image = imdecode(Mat(message->data), IMWRITE_JPEG_QUALITY);

    return image;
}

//***************************************
// Solicitar imagen
//***************************************

void solicitar_image(){

    gettimeofday(&start, NULL);


    frame = inImagePort.read();

    Mat rgbImage = decodeImage(frame);


    imshow("image", rgbImage);

    pressedKey = waitKey(0);

    cout << "Key pressed: " << pressedKey << endl;

    if (pressedKey == ' '){
        cout << "Saving image..." << endl;
        imwrite ("/home/tiagoentrenamiento/repos/vision/programs/RGBD-ROS-YARP/images/image.jpg", rgbImage);
    }



    gettimeofday(&end, NULL);

    secs_used=(end.tv_sec - start.tv_sec);
    micros_used= ((secs_used*1000000) + end.tv_usec) - (start.tv_usec);
}
