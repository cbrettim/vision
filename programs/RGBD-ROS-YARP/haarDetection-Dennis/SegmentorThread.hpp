// -*- mode:C++; tab-width:4; c-basic-offset:4; indent-tabs-mode:nil -*-

#ifndef __SEGMENTOR_THREAD_HPP__
#define __SEGMENTOR_THREAD_HPP__

#include <yarp/os/RFModule.h>
#include <yarp/os/Network.h>
#include <yarp/os/Port.h>
#include <yarp/os/BufferedPort.h>
#include <yarp/os/RateThread.h>
#include <yarp/os/Subscriber.h>

#include <yarp/dev/all.h>
#include <yarp/sig/all.h>

#include "RosImageTransport.hpp"
#include "sensor_msgs_CompressedImage.h"

#include <cv.h>
//#include <highgui.h> // to show windows

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/objdetect/objdetect.hpp>

// thanks! https://web.stanford.edu/~qianyizh/projects/scenedata.html
#define DEFAULT_FX_D          525.0  // 640x480
#define DEFAULT_FY_D          525.0  //
#define DEFAULT_CX_D          319.5  //
#define DEFAULT_CY_D          239.5  //

#define DEFAULT_RATE_MS 20
#define DEFAULT_SEE_BOUNDING 3
#define DEFAULT_THRESHOLD 55
#define DEFAULT_XMLCASCADE  "haarcascade_frontalface_alt.xml"


namespace roboticslab
{

typedef sensor_msgs_CompressedImage Image_t;
typedef sensor_msgs_CompressedImage	DepthImage_t;

/**
 * @ingroup haarDetection
 *
 * @brief Implements haarDetection callback on Bottle.
 */
class DataProcessor : public yarp::os::PortReader {
    virtual bool read(yarp::os::ConnectionReader& connection) {
        yarp::os::Bottle b;
        b.read(connection);
        // process data in b
        printf("Got %s\n", b.toString().c_str());
        if(waitForFirst) {
            xKeep = b.get(0).asInt();
            yKeep = b.get(1).asInt();
            waitForFirst = false;
        } else {
            if((b.get(0).asInt()<xKeep)||(b.get(1).asInt()<yKeep)){
                x = 0;
                y = 0;
                w = 0;
                h = 0;
            } else {
                x = xKeep;
                y = yKeep;
                w = b.get(0).asInt() - x;
                h = b.get(1).asInt() - y;
            }
            waitForFirst = true;
        }
        return true;

    }
public:
    bool reset() {
        waitForFirst = true;
        x = 0;
        y = 0;
        w = 0;
        h = 0;
        xKeep = 0;
        yKeep = 0;
    }
    int xKeep, yKeep;
    int x, y, w, h;
    bool waitForFirst;
};

/**
 * @ingroup haarDetection
 *
 * @brief Implements haarDetection RateThread.
 */
class SegmentorThread : public yarp::os::RateThread {
private:

    // Ports to get source data (from ROS topics)
    yarp::os::Subscriber<Image_t> *inImagePort;
    yarp::os::Subscriber<DepthImage_t> *inDepthPort;
    
    // Output YARP ports
    yarp::os::BufferedPort<yarp::sig::ImageOf<yarp::sig::PixelRgb> > *pOutImg;  // for testing
    yarp::os::Port *pOutPort;

    // Crop selector YARP ports
    yarp::os::BufferedPort<yarp::sig::ImageOf<yarp::sig::PixelRgb> >* outCropSelectorImg;
    yarp::os::Port* inCropSelectorPort;

    int cropSelector;
    
    //
    double fx_d,fy_d,cx_d,cy_d;
    //

    DataProcessor processor;

    cv::CascadeClassifier face_cascade;


public:
    SegmentorThread() : RateThread(DEFAULT_RATE_MS) {}

    void init(yarp::os::ResourceFinder &rf);
    void run();  // The periodical function


    void setInDepthSubscriber(yarp::os::Subscriber<DepthImage_t> *_inDepthPort);
    void setInImageSubscriber(yarp::os::Subscriber<Image_t> *_inImagePort);
    void setOutImg(yarp::os::BufferedPort<yarp::sig::ImageOf<yarp::sig::PixelRgb> > * _pOutImg);
    void setOutPort(yarp::os::Port *_pOutPort);
    void setCropSelector(int _cropSelector);
    void setOutCropSelectorImg(yarp::os::BufferedPort<yarp::sig::ImageOf<yarp::sig::PixelRgb> >* _outCropSelectorImg);
    void setInCropSelectorPort(yarp::os::Port* _inCropSelectorPort);

};

}  // namespace roboticslab

#endif  // __SEGMENTOR_THREAD_HPP__
