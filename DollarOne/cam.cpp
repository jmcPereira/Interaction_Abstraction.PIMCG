#include "cam.h"
#include <QHostAddress>
#include <QTimer>
#include <QDebug>
#include <iostream>
#include <Windows.h>
#include "frame.h"

using namespace DollarRecognizer;
using namespace cv;

Cam::Cam(int a)
{
}

void Cam::run(){
    socket.connectToHost(QHostAddress::LocalHost, 33333);
    bool connected = socket.waitForConnected();
    qDebug() << "Thread: connected = " << connected;

    QString bla("Estas ai?,camera");

    //socket.write(bla.toUtf8());
    //socket.flush();

    GeometricRecognizer g;
    g.loadTemplates();
    vector<string> gesturesList;
    gesturesList.push_back("Circle");
    gesturesList.push_back("Delete");
    gesturesList.push_back("Arrow");
    gesturesList.push_back("Pigtail");
    gesturesList.push_back("Rectangle");
    gesturesList.push_back("V");
    gesturesList.push_back("0");
    g.activateTemplates(gesturesList);

    VideoCapture cap(0);
    Mat frame;
    if (!cap.isOpened()){
        cout << "Erro ao iniciar a camera!" << endl;
        return;
       }
    bool bSuccess = cap.read(frame);
    if (!bSuccess){
         cout << "Erro ao capturar um frame" << endl;
         return;
    }
    Frame frames(frame);
    frames.resetimgtrack();
    //frames.Trackbars();    // TRACKBARS PARA AJUSTAR A CAMERA
    QString metodo("CAMERA ");
    while (true){
           bool bSuccess = cap.read(frame);
           if (!bSuccess){
                cout << "Erro ao capturar um frame" << endl;
                //return;
           }
           flip(frame,frame,1);
           //for(int i=3;i<5;i+=2)medianBlur(frame,frame,i);
           frames.operador(frame);
           Mat Thresh=frames.GetThresholdedImage();
           frames.resetimgtrack();
           frames.trackObject(Thresh);
           int res=frames.testa();

           if(res==1){qDebug() << "GRRR";
               Path2D gesto_novo=frames.getgesto();
               RecognitionResult resultado=g.recognize(gesto_novo);
               cout << "Gesto Reconhecido pela camera: " << resultado.name << endl;
               //qDebug() << "Send data";
               QString bla(resultado.name.c_str());
               bla=metodo+bla;

               socket.write(bla.toUtf8());
               socket.flush();
               frames.cleargesto();
           }
           Mat track=frames.getTrack();
           imshow("Bola", Thresh);   // DEBUG DA CAMERA


           waitKey(5);
       }

}
