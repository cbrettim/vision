TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    image.cpp \
    yarp_read_ros.cpp \
    yarp_write_ros.cpp \
    get_image_ros.cpp \
    extra_ports_fix.cpp \
    ip_camera_tiago.cpp \
    yarp_read_ros_image.cpp

HEADERS += \
    image.h \
    yarp_read_ros.h \
    yarp_write_ros.h \
    get_image_ros.h \
    extra_ports_fix.h \
    ip_camera_tiago.h \
    yarp_read_ros_image.h
INCLUDEPATH += /usr/local/include/opencv
LIBS += -L/usr/local/lib  -lopencv_videostab -lopencv_objdetect -lopencv_ml -lopencv_photo -lopencv_superres -lopencv_dnn -lopencv_shape -lopencv_video -lopencv_stitching -lopencv_calib3d -lopencv_features2d -lopencv_highgui -lopencv_videoio -lopencv_imgcodecs -lopencv_imgproc -lopencv_flann -lopencv_core
