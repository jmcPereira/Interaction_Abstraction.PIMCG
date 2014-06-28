#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTcpSocket>
#include "slideshow.h"
#include <QHostAddress>
#include <QTimer>
#include <QDebug>


#include <iostream>

using namespace cv;

SlideShow ab;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    //ui->setupUi(this);
    qDebug() << "olaa";
    ab.mostra_imagem();
    if(!server.listen(QHostAddress::LocalHost, 33334))
    {
        qDebug() << "Error listening";
    }
    else
    {
        connect(&server, SIGNAL(newConnection()), this, SLOT(acceptConnection()));
    }

}



MainWindow::~MainWindow()
{
    delete ui;
}





void MainWindow::acceptConnection(){



    if(!server.hasPendingConnections())
    {
        qDebug() << "No pending connections";
        return;
    }
    qDebug() << "Got client";

    QTcpSocket * socket = server.nextPendingConnection();
    connect(socket, SIGNAL(readyRead()), this, SLOT(readData()));
}

void MainWindow::readData()
{
    QTcpSocket * socket = qobject_cast<QTcpSocket*>(sender());
    if(!socket)
        return;
    //qDebug() << "Received: " << socket->readAll();
    QString a(socket->readAll());
    socket->flush();
    qDebug()<<"Recebi: " <<a << endl;
    //ss.frente();

    if(a.contains("AVANCA",Qt::CaseInsensitive)){

        ab.avanca();
        ab.mostra_imagem();
        a.clear();
        return;

    }
    if(a.contains("RECUA",Qt::CaseInsensitive)){

        ab.recua();
        ab.mostra_imagem();
        a.clear();
        return;

    }
    if(a.contains("RODA",Qt::CaseInsensitive)){

        ab.roda();
        ab.mostra_imagem();
        a.clear();
        return;
    }
    if(a.contains("SAI",Qt::CaseInsensitive)){
        qDebug() << "SAI!" << a <<endl;
        exit(0);
    }
    a.clear();

}



