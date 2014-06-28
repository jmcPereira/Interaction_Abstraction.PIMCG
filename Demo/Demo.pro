#-------------------------------------------------
#
# Project created by QtCreator 2014-03-19T17:15:50
#
#-------------------------------------------------

QT       +=  core gui network widgets


TARGET = Demo
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h \
    funcoes.h \
    slideshow.h

FORMS    += mainwindow.ui







INCLUDEPATH += $$PWD/../../Qt/5.3/msvc2012_opengl/include
DEPENDPATH += $$PWD/../../Qt/5.3/msvc2012_opengl/include

win32: LIBS += -L$$PWD/../../Qt/5.3/msvc2012_opengl/lib/ -lopencv_calib3d249
win32: LIBS += -L$$PWD/../../Qt/5.3/msvc2012_opengl/lib/ -lopencv_contrib249
win32: LIBS += -L$$PWD/../../Qt/5.3/msvc2012_opengl/lib/ -lopencv_core249
win32: LIBS += -L$$PWD/../../Qt/5.3/msvc2012_opengl/lib/ -lopencv_features2d249
win32: LIBS += -L$$PWD/../../Qt/5.3/msvc2012_opengl/lib/ -lopencv_flann249
win32: LIBS += -L$$PWD/../../Qt/5.3/msvc2012_opengl/lib/ -lopencv_gpu249
win32: LIBS += -L$$PWD/../../Qt/5.3/msvc2012_opengl/lib/ -lopencv_highgui249
win32: LIBS += -L$$PWD/../../Qt/5.3/msvc2012_opengl/lib/ -lopencv_imgproc249
win32: LIBS += -L$$PWD/../../Qt/5.3/msvc2012_opengl/lib/ -lopencv_legacy249
win32: LIBS += -L$$PWD/../../Qt/5.3/msvc2012_opengl/lib/ -lopencv_ml249
win32: LIBS += -L$$PWD/../../Qt/5.3/msvc2012_opengl/lib/ -lopencv_nonfree249
win32: LIBS += -L$$PWD/../../Qt/5.3/msvc2012_opengl/lib/ -lopencv_objdetect249
win32: LIBS += -L$$PWD/../../Qt/5.3/msvc2012_opengl/lib/ -lopencv_ocl249
win32: LIBS += -L$$PWD/../../Qt/5.3/msvc2012_opengl/lib/ -lopencv_photo249
win32: LIBS += -L$$PWD/../../Qt/5.3/msvc2012_opengl/lib/ -lopencv_stitching249
win32: LIBS += -L$$PWD/../../Qt/5.3/msvc2012_opengl/lib/ -lopencv_superres249
win32: LIBS += -L$$PWD/../../Qt/5.3/msvc2012_opengl/lib/ -lopencv_ts249
win32: LIBS += -L$$PWD/../../Qt/5.3/msvc2012_opengl/lib/ -lopencv_video249
win32: LIBS += -L$$PWD/../../Qt/5.3/msvc2012_opengl/lib/ -lopencv_videostab249
