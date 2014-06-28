#include "teclado.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <QString>

using namespace std;


Teclado::Teclado(int a)
{
}


void Teclado::run(){
    socket.connectToHost(QHostAddress::LocalHost, 33333);
    bool connected = socket.waitForConnected();
    /*qDebug() << "Thread: connected = " << connected;

    QString bla("Estas ai?,teclado");

    socket.write(bla.toUtf8());
    socket.flush();*/


    QString metodo("TECLADO ");

    while(true){
        if( GetAsyncKeyState(VK_DELETE) < 0 ){

            QString sai("DELETE");
            sai=metodo+sai;
            socket.write(sai.toUtf8());
            socket.flush();
            Sleep(100);
        }

        if( GetAsyncKeyState(VK_LEFT) < 0 ){
            QString sai("ESQUERDA");
            sai=metodo+sai;
            socket.write(sai.toUtf8());
            socket.flush();
            Sleep(100);
        }
        if( GetAsyncKeyState(VK_RIGHT) < 0 ){
            QString sai("DIREITA");
            sai=metodo+sai;
            socket.write(sai.toUtf8());
            socket.flush();
            Sleep(100);
        }
        if( GetAsyncKeyState(VK_SPACE) < 0 ){
            QString sai("SPACE");
            sai=metodo+sai;
            socket.write(sai.toUtf8());
            socket.flush();
            Sleep(100);
        }
        Sleep(100);

    }


}
