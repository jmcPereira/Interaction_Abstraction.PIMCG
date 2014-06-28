#ifndef FRAME_H
#define FRAME_H


#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "lib/GeometricRecognizer.h"
#include "lib/PathWriter.h"
#include <cmath>
#include <Windows.h>

using namespace cv;
using namespace DollarRecognizer;

class Frame{
    Mat frame;
    int hmin,smin,vmin,hmax,smax,vmax,lastX,lastY,desenha_rato;
    Path2D gesto;
    Mat imgTrack;
    int grava;
    int flag_gesto;

public:
    Frame(Mat f);
    void operador(Mat novo_frame);
    Mat GetThresholdedImage();
    void trackObject(Mat imgThresh);
    void Trackbars();
    void resetimgtrack();
    int testa();
    Path2D getgesto(){return gesto;}
    void cleargesto(){gesto.clear();}
    Mat getTrack(){return imgTrack;}

};

Frame::Frame(Mat f){
    frame=f.clone();
    hmin=36;
    smin=124;
    vmin=71;hmax=65;
    smax=255;
    vmax=255;lastX=0;
    lastY=0;
    desenha_rato=0;
    grava=0;
    flag_gesto=0;
}


//TESTA: se devolve 1 gesto pronto a ser reconhecido.
// se devolve 2 gesto pronto a ser gravado
// se devolve 0 gesto ainda nao esta pronto
int Frame::testa(){
    if (flag_gesto==2){
        if(!grava){
            flag_gesto=0;
            return 1;
        }

        else{

            return 2;
            flag_gesto=0;
            grava=0;
            }
        }
    else return 0;
}




void Frame::Trackbars(){
    namedWindow("Trackbars",WINDOW_NORMAL);
    createTrackbar("H minimo","Trackbars",&hmin,255);
    createTrackbar("S minimo","Trackbars",&smin,255);
    createTrackbar("V minimo","Trackbars",&vmin,255);

    createTrackbar("H maximo","Trackbars",&hmax,255);
    createTrackbar("S maximo","Trackbars",&smax,255);
    createTrackbar("V maximo","Trackbars",&vmax,255);
}

void Frame::resetimgtrack(){
    Mat image(frame.rows,frame.cols, CV_8UC3, Scalar(0,0,0));
    if(flag_gesto==0)imgTrack=image.clone();
}


void Frame::operador(Mat novo_frame){
    frame=novo_frame.clone();

}

Mat Frame::GetThresholdedImage(){
    Mat frameHSV,frameThresh;
    cvtColor(frame,frameHSV,CV_RGB2HSV);
    inRange(frameHSV, Scalar(hmin,smin,vmin), Scalar(hmax,smax,vmax), frameThresh);
    return frameThresh;
}

void Frame::trackObject(Mat imgThresh){
    // Calculate the moments of 'imgThresh'
    if(!desenha_rato){
        Moments mo;
        mo=moments(imgThresh, 1);
        double moment10 = mo.m10;
        double moment01 = mo.m01;
        double area = mo.m00;

     // if the area<1000, I consider that the there are no object in the image and it's because of the noise, the area is not zero
        if(area>1000 && flag_gesto!=2){
        // calculate the position of the ball
            int posX = moment10/area;
            int posY = moment01/area;
            if(flag_gesto==0){
                flag_gesto=1;
                lastX=posX;
                lastY=posY;
             }
            else{
                line(imgTrack, Point(posX, posY), Point(lastX, lastY), Scalar(0,0,255), 4);

                lastX=posX;
                lastY=posY;
            }

            gesto.push_back(Point2D(posX,posY));
        }
        else{
            if (flag_gesto==1)flag_gesto=2;

        }
        }
}


#endif // FRAME_H
