
#include "lib/GeometricRecognizer.h"
#include <QThread>
#include <QTcpSocket>


class Rato : public QThread{

public:
    Rato(int a);

public slots:
    void run();
    void socketConnected();

private:
    QTcpSocket socket;

};
