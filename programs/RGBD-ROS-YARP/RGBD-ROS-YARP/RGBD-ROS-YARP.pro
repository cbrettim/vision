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
    ip_camera_tiago.cpp

HEADERS += \
    image.h \
    yarp_read_ros.h \
    yarp_write_ros.h \
    get_image_ros.h \
    extra_ports_fix.h \
    ip_camera_tiago.h

