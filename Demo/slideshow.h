#ifndef SLIDESHOW_H
#define SLIDESHOW_H
#include "funcoes.h"

class SlideShow
{
    Imagens imagens;
    int posicao,n_imagens;
public:
    SlideShow();
    void mostra_imagem();
    void avanca();
    void recua();
    void roda();

};


void SlideShow::mostra_imagem(){
    destroyAllWindows();
    namedWindow(imagens[posicao-1].name.c_str(),WINDOW_AUTOSIZE);
    moveWindow(imagens[posicao-1].name.c_str(),100,100);
    imshow(imagens[posicao-1].name.c_str(),imagens[posicao-1].im);
}

SlideShow::SlideShow(){
    Imagem imagem1=Imagem("Imagem 1","imagem1.jpg");
    Imagem imagem2=Imagem("Imagem 2","imagem2.jpg");
    Imagem imagem3=Imagem("Imagem 3","imagem3.jpg");
    Imagem imagem4=Imagem("Imagem 4","imagem4.jpg");

    imagens.push_back(imagem1);
    imagens.push_back(imagem2);
    imagens.push_back(imagem3);
    imagens.push_back(imagem4);

    posicao=1;
    n_imagens=4;
}

void SlideShow::avanca(){
    if (posicao==n_imagens)posicao=1;
    else posicao++;
}

void SlideShow::recua(){
    if (posicao==1)posicao=n_imagens;
    else posicao--;
}

void SlideShow::roda(){
    imagens[posicao-1].rotate();
}

#endif // SLIDESHOW_H
