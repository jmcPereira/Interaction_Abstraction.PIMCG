#ifndef TECLADO_H
#define TECLADO_H

#include <QThread>
#include <QTcpSocket>
#include <QHostAddress>
#include <QTimer>
#include <QDebug>


class Teclado : public QThread{

public:
    Teclado(int a);

public slots:
    void run();
    void socketConnected();

private:
    QTcpSocket socket;

};

#endif // TECLADO_H
