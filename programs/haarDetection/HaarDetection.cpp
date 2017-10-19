// -*- mode:C++; tab-width:4; c-basic-offset:4; indent-tabs-mode:nil -*-

#include "HaarDetection.hpp"

namespace roboticslab
{

/************************************************************************/
bool HaarDetection::configure(yarp::os::ResourceFinder &rf) {

    cropSelector = DEFAULT_CROP_SELECTOR;
    yarp::os::ConstString strImageTopic = DEFAULT_IMAGE_TOPIC;
    yarp::os::ConstString strDepthTopic = DEFAULT_DEPTH_TOPIC;
    yarp::os::ConstString strImageOutPort = DEFAULT_IMAGEOUT_PORT;
    yarp::os::ConstString strStateOutPort = DEFAULT_STATEOUT_PORT;
    yarp::os::ConstString strCropImagePort = DEFAULT_CROP_IMAGEOUT_PORT;
    yarp::os::ConstString strCropStatePort = DEFAULT_CROP_STATEIN_PORT;
    watchdog = DEFAULT_WATCHDOG;  // double

    fprintf(stdout,"--------------------------------------------------------------\n");
    if (rf.check("help")) {
        printf("\t--help (this help)\t--from [file.ini]\t--context [path]\n");
        printf("\t--cropSelector (default: \"%d\")\n",cropSelector);
        printf("\t--imageTopic (default: \"%s\")\n",strImageTopic.c_str());
        printf("\t--depthTopic (default: \"%s\")\n",strDepthTopic.c_str());
        printf("\t--watchdog ([s] default: \"%f\")\n",watchdog);
        // Do not exit: let last layer exit so we get help from the complete chain.
    }
    if(rf.check("cropSelector")) cropSelector = rf.find("cropSelector").asInt();
    printf("HaarDetector using cropSelector: %d.\n",cropSelector);
    if(rf.check("imageTopic")) strImageTopic = rf.find("imageTopic").asString();
    if(rf.check("depthTopic")) strDepthTopic = rf.find("depthTopic").asString();
    if(rf.check("watchdog")) watchdog = rf.find("watchdog").asDouble();
    
    printf("HaarDetector using imageTopic: %s, depthTopic: %s.\n", strImageTopic.c_str(), strDepthTopic.c_str());
    printf("HaarDetector using watchdog: %f.\n",watchdog);

    if (!rf.check("help")) {
    
        // Confgure ROS 
        printf("Conecting to ROS topics ... ");
        if (!inDepthPort.topic(strDepthTopic)) {
            fprintf(stderr, "[fail]\nError conecting to ROS topic %s\n", strDepthTopic.c_str());
            return 1;
        }
        if (!inImagePort.topic(strImageTopic)) {
            fprintf(stderr, "[fail]\nError conecting to ROS topic %s\n", strImageTopic.c_str());
            return 1;
        }
        printf("[OK]\n");
        
        
        // Configure YARP
        printf("Conecting to YARP ports ... ");
        if (!outImg.open(strImageOutPort)) {
            fprintf(stderr, "[fail]\nError conecting to YARP port %s\n", strImageOutPort.c_str());
            return 1;
        }
        if (!outPort.open(strStateOutPort)) {
            fprintf(stderr, "[fail]\nError conecting to YARP port %s\n", strStateOutPort.c_str());
            return 1;
        }
        printf("[OK]\n");
        
        // Configure crop selector if enabled
        if(cropSelector != 0) {
            printf("Conecting to crop selection YARP ports ... ");
            if (!outCropSelectorImg.open(strCropImagePort)) {
                fprintf(stderr, "[fail]\nError conecting to YARP port %s\n", strCropImagePort.c_str());
                return 1;
            }
            if (!inCropSelectorPort.open(strCropStatePort)) {
                fprintf(stderr, "[fail]\nError conecting to YARP port %s\n", strCropStatePort.c_str());
                return 1;
            }
            printf("[OK]\n");
        }
        
        printf("Configuring segmentor thread:\n");
        segmentorThread.setInImageSubscriber(&inImagePort);
        segmentorThread.setInDepthSubscriber(&inDepthPort);
        segmentorThread.setOutImg(&outImg);
        segmentorThread.setOutPort(&outPort);
        segmentorThread.setCropSelector(cropSelector);
        if(cropSelector != 0) {
            printf("\t- Crop selector ENABLED\n");
            segmentorThread.setOutCropSelectorImg(&outCropSelectorImg);
            segmentorThread.setInCropSelectorPort(&inCropSelectorPort);
        }
    }
    
    
    printf("Launch segmentor thread");
    segmentorThread.init(rf);
    return true;
}

/*****************************************************************/
double HaarDetection::getPeriod() {
    return watchdog;  // [s]
}

/************************************************************************/

bool HaarDetection::updateModule() {
    printf("HaarDetection alive...\n");
    return true;
}

/************************************************************************/

bool HaarDetection::interruptModule() {
    printf("HaarDetection closing...\n");
    segmentorThread.stop();
    outImg.interrupt();
    outPort.interrupt();
    if(cropSelector != 0) {
        outCropSelectorImg.interrupt();
        inCropSelectorPort.interrupt();
    }
    outImg.close();
    outPort.close();
    if(cropSelector != 0) {
        outCropSelectorImg.close();
        inCropSelectorPort.close();
    }
    return true;
}

/************************************************************************/

}  // namespace roboticslab
