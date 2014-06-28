#include "rato.h"
#include <QHostAddress>
#include <QTimer>
#include <QDebug>
#include <iostream>
#include <Windows.h>



using namespace std;
using namespace DollarRecognizer;



Rato::Rato(int a){

}


void Rato::run(){
    socket.connectToHost(QHostAddress::LocalHost, 33333);
    bool connected = socket.waitForConnected();
    //qDebug() << "Thread: connected = " << connected;

    //QString bla("Estas ai?,rato");

    //socket.write(bla.toUtf8()); //DEBUG DA SOCKET
    //socket.flush();

    LPPOINT ponto;
    GeometricRecognizer gr;
    gr.loadTemplates();
    vector<string> gesturesList;
    gesturesList.push_back("Circle");
    gesturesList.push_back("Delete");
    gesturesList.push_back("Arrow");
    gesturesList.push_back("Pigtail");
    gesturesList.push_back("Rectangle");
    gesturesList.push_back("V");
    gesturesList.push_back("0");
    gr.activateTemplates(gesturesList);
    Path2D gesto;
    int inc=0;
    QString metodo("RATO ");
    while(true){

        gesto.clear();

        while( GetAsyncKeyState(VK_LBUTTON) < 0 ){
            inc++;
            //cout << "Botao esquerdo primido!" << endl;
            GetCursorPos(ponto);
            qDebug() << "X: " << ponto->x << "Y: " << ponto->y << endl;
            gesto.push_back(Point2D(ponto->x,ponto->y));
            Sleep(100);
        }

        Sleep(100);
        if(inc>5){
            RecognitionResult res = gr.recognize(gesto);
            //cout << "Gesto Reconhecido: " << res.name << endl;
            QString gesto(res.name.c_str());
            gesto=metodo+gesto;
            socket.write(gesto.toUtf8());
            socket.flush();

            //return;
        }
    gesto.clear();
    inc=0;

    }
    return;



}
