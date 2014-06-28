#include "act.h"

using namespace std;

Act::Act(QString nome_txt){

    QFile fich(nome_txt);
    if(!fich.open(QFile::ReadOnly)){

        cout << "Erro ao abrir txt!"<< endl;
        return;
    }

    QTextStream rd(&fich);
    QString line;

    Action nova;
    int pronto=0;

    do {
        line=rd.readLine();
        if(line.contains("ACT ", Qt::CaseSensitive)){
            //cout << "ACCAO ENCONTRADA!" << endl;
            if(pronto){
                actions.push_back(nova);
                //nova.inputs.clear();
            }
            Action aux;
            nova=aux;
            line=line.remove(0,4);
            nova.nome=line;
            pronto=1;
        }
        else if(!line.isEmpty()){
            nova.inputs.push_back(line);
        }
        //qDebug() << line;
    }while (!line.isNull());

    if(pronto)actions.push_back(nova);

}


QString Act::match(QString inp){
    QString res("NULL");
    for(int i=0;i<actions.size();i++){
        for(int k=0;k<actions[i].inputs.size();k++)
            if(actions[i].inputs[k]==inp)return (actions[i].nome);
    }


    return res;
}

void Act::print_actions(){
    for(int i=0;i<actions.size();i++){
        qDebug() << "Action: " << actions[i].nome << endl;
        for(int k=0;k<actions[i].inputs.size();k++)
            qDebug() << "   -" << actions[i].inputs[k] << endl;

    }

}
