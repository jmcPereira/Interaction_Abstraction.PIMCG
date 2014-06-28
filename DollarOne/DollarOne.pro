#-------------------------------------------------
#
# Project created by QtCreator 2014-03-19T17:16:07
#
#-------------------------------------------------

QT       +=  network core gui  widgets


TARGET = DollarOne
TEMPLATE = app




SOURCES +=  main.cpp \
            mainwindow.cpp \
    lib/GeometricRecognizer.cpp \
    rato.cpp \
    cam.cpp \
    teclado.cpp \
    act.cpp

HEADERS +=  mainwindow.h \
    lib/utils.h \
    lib/SampleMultiStrokeGestures.h \
    lib/SampleGestures.h \
    lib/PathWriter.h \
    lib/MultipleStrokeGestureTemplate.h \
    lib/GestureTemplate.h \
    lib/GeometricRecognizerTypes.h \
    lib/GeometricRecognizer.h \
    frame.h \
    rato.h \
    cam.h \
    teclado.h \
    act.h


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
