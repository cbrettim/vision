/**************************************************************
 **************************************************************
 *
 *      RGBD Sensor: TIAGo
 *
 *      YARP Subscribe -> ROS Topic
 *      Class: Get image
 *      Type: Sources
 *
 *      Robotics Lab
 *      Departamento de Ingeniería de Sistemas y Automática
 *      Universidad Carlos III de Madrid
 *
 **************************************************************
 **************************************************************
 */
#include "get_image.h"

//++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++++
//  Constructor: Inicializa nodo
//++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++
get_image::get_image()
{
    cout<<" Conectando a topic ROS /obj_image_test"<<endl;
    yarp::os::Node rosNode("/obj_image_test");
}

//++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++++
//  Función: Solicita imagen a ROS
//++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++

void get_image::solicitar_imagen()
{
    //***************************************
    // Obtener una imagen de TIAGo
    //***************************************

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

//++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++++
//  Función: Uso de OpenCV para la imagen
//++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++

Mat decodeImage(Image_t *message) {
    Mat image;

    image = imdecode(Mat(message->data), IMWRITE_JPEG_QUALITY);

    return image;
}

get_image::~get_image()
{

}
