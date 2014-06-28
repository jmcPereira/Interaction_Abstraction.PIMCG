#ifndef ACT_H
#define ACT_H

#include <QString>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <iostream>
#include <vector>


using namespace std;

typedef struct action{
    QString nome;
    vector <QString> inputs;
}Action;

class Act{
    vector<Action> actions;


public:
    Act(QString nome_txt);
    QString match(QString inp);
    void print_actions();
};

#endif // ACT_H
