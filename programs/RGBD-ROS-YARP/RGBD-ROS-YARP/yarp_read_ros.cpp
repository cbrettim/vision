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

        subscriber.read(datos_recibidos);
        cout << "Datos recibidos:" << datos_recibidos.data << " " << endl;

        BufferedPort<ImageOf<PixelRgb> > puerto_imagen;
        puerto_imagen.open("/imagen_ROS");
        yarp.connect("/yarp/listener","/image_ROS");
        ImageOf<PixelRgb> *img = puerto_imagen.read();
        img.resize(800,600);
        IplImage *cvImage = cvCreateImage(cvSize(img.width(),
                                                 img.height()),
                                          IPL_DEPTH_8U, 3 );
        cvCvtColor((IplImage*)img.getIplImage(), cvImage, CV_RGB2BGR);

        Mat image_opencv = cvarrToMat(cvImage);

        // Introducir los HAAR aquí

        cvNamedWindow("Imagen: ROS",1);
        cvShowImage("Imagen: ROS",image_opencv);

}


yarp_read_ros::~yarp_read_ros()
{

}
