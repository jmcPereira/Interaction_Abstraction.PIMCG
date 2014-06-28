
#include "lib/GeometricRecognizer.h"
#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <QThread>
#include <QTcpSocket>


class Cam : public QThread{

public:
    Cam(int a);

public slots:
    void run();
    void socketConnected();

private:
    QTcpSocket socket;

};
