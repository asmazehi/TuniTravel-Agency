#ifndef TODOLIST_E_H
#define TODOLIST_E_H

#include <QDialog>
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>


class todolist_e
{

    int id_task;
    QString task;
    QString employee_task;
    QString etat_task ;


public:
    todolist_e();
    todolist_e(int,QString,QString,QString);
    todolist_e(QString);
    bool ajouter_task();
    bool supprimer_task(int);
     bool modifier_task(int);
    int getId_task() {return id_task ;}
    void setId_task(int val) {id_task=val;}


   float  nbre_totale();
    float nbre_totalep();
    float nbre_totaled();

    QSqlQueryModel* afficher_p();
    QSqlQueryModel* afficher_d();

};


#endif // TODOLIST_E_H
