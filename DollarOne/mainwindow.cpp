

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "rato.h"
#include "cam.h"
#include "teclado.h"





using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    Rato *rt=new Rato(1);
    Cam *cm=new Cam(1);
    Teclado *tc=new Teclado(1);
    //Act ac("acoes.txt");
    actions=new Act("acoes.txt");
    //actions->print_actions();

    socket1.connectToHost(QHostAddress::LocalHost, 33334);
    bool connected = socket1.waitForConnected();
    //qDebug() << "connected = " << connected;

    if(connected)
    {
        cout << "Ligado ao Demo!" << endl;
        QTimer *timer = new QTimer(this);
        connect(timer, SIGNAL(timeout()), this, SLOT(sendData()));
        timer->start(1000);
    }


    if(!server.listen(QHostAddress::LocalHost, 33333))
    {
        qDebug() << "Error listening";
    }
    else
    {
        connect(&server, SIGNAL(newConnection()), this, SLOT(acceptConnection()));
        rt->start();
        cm->start();
        tc->start();
    }
}

void MainWindow::acceptConnection(){


    if(!server.hasPendingConnections())
    {
        qDebug() << "No pending connections";
        return;
    }
    //qDebug() << "Got client";

    QTcpSocket * socket = server.nextPendingConnection();
    connect(socket, SIGNAL(readyRead()), this, SLOT(readData()));
}

void MainWindow::readData()
{
    QTcpSocket * socket = qobject_cast<QTcpSocket*>(sender());
    if(!socket)
        return;
    QString comando(socket->readAll());
    qDebug() << "Received: " << comando;
    QString acao(actions->match(comando));
    qDebug() << "AÇÃO : " << acao << endl;


    if(acao.contains("NULL",Qt::CaseInsensitive)==0){
        qDebug() << "ENVIEI: " << acao <<endl;
        socket1.write(acao.toUtf8());
        socket1.flush();
    }




}


MainWindow::~MainWindow()
{
    delete ui;
}











