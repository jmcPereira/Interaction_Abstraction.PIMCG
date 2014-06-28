#include <iostream>
#include <stdio.h>
#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <vector>
using namespace cv;
using namespace std;

class Imagem
{
public:
    string name;
    Mat im; //Imagem actual.
    Mat imo; //Imagem original.
    int zoomi; //flag, se foi aplicado zoom ou não.
    int zoomo;
    int rotated;  //angulo em que foi rodada a imagem.


    Imagem(string name, string filename)
        {
                this->name   = name;
        this->im = imread(filename);
        this->imo = imread(filename);
        this->rotated=0;
        this->zoomi=0;
        this->zoomo=0;
        if(!im.data)cout << "Erro ao ler!" <<endl;

        }
    void rotate();
};

typedef vector<Imagem>  Imagens;



void Imagem::rotate(){
    Point2f pt(im.cols/2., im.rows/2.);
    Mat r = getRotationMatrix2D(pt, 90, 1.0);
    Mat nova;
    warpAffine(im,nova, r, im.size());
    im=nova;
    rotated++;
}

Mat zoom_in(Mat im,int zoomin){
    Mat copia=im.clone(),nova;
    int n_z=4;
    printf("%d %d",n_z,zoomin);
    pyrUp(copia,nova, Size( copia.cols*n_z, copia.rows*n_z ) );
    return nova;

}

void zoom_out(Imagem im){

}
