TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    image.cpp \
    yarp_read.cpp \
    yarp_read.cpp \
    yarp_write.cpp \
    get_image.cpp \
    extra_ports.cpp \
    ip_camera.cpp

HEADERS += \
    image.h \
    yarp_read.h \
    yarp_read.h \
    yarp_write.h \
    get_image.h \
    extra_ports.h \
    ip_camera.h

