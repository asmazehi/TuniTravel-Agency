#include "todolist_e.h"

#include <QSqlQuery>
#include <QtDebug>
#include <QObject>


//**********************************
todolist_e::todolist_e()
{

}

//**********************************
todolist_e::todolist_e(int id_task,QString task,QString employee_task,QString etat_task)
{

    this->id_task=id_task;
    this->task=task;
    this->employee_task=employee_task;
    this->etat_task=etat_task;
}
//*******************************
todolist_e::todolist_e(QString etat_task)
{
    this->etat_task=etat_task;
}
//**********************************

bool todolist_e::ajouter_task()
{

    QSqlQuery query;
    QString res11 =QString::number(id_task);

    //prepare prend la request en paramétre pour la préparer a l'exucution


    query.prepare("insert into DB_EMPLOYEE_TODOLIST (ID_TASK_E,TASK_E,EMPLOYEE_TASK_E,ETAT_TASK_E)" "values(:ID_TASK_E,:TASK_E,:EMPLOYEE_TASK_E,:ETAT_TASK_E)");

    query.bindValue(":ID_TASK_E",res11);
    query.bindValue(":TASK_E",task);
    query.bindValue(":EMPLOYEE_TASK_E",employee_task);
    query.bindValue(":ETAT_TASK_E",etat_task);


    return query.exec();

}


//************************************


bool todolist_e::supprimer_task(int ID_TASK_E)
{


    QSqlQuery query;
    QString id_string=QString::number(ID_TASK_E);
    query.prepare("Delete from DB_EMPLOYEE_TODOLIST where ID_TASK_E=:ID_TASK_E");
    query.bindValue(0, ID_TASK_E);

return query.exec();

}
//*************************************



 bool todolist_e::modifier_task(int id)
{
     QSqlQuery query;
     QString res1 =QString::number(id);




    query.prepare("UPDATE DB_EMPLOYEE_TODOLIST SET etat_task_e='"+this->etat_task+"' WHERE ID_TASK_E='"+res1+"'");
                 // "NOM_E=:NOM_E,PRENOM_E=:PRENOM_E,CIN_E=:CIN_E,TEL_E=:TEL_E,SALAIRE_E=:SALAIRE_E,HEURDETRAVAIL_E=:HEURDETRAVAIL_E WHERE ID_E:=ID_E");

   query.bindValue(":ID_E",res1);
   query.bindValue(":ID_TASK_E",id_task);
  /*  query.bindValue(":nom_e",nom);

     query.bindValue(":prenom_e",prenom);
      query.bindValue(":salaire_e",res5);
    query.bindValue(":cin_e",res2);
    query.bindValue(":tel_e",res3);
    query.bindValue(":heuredetravail_e",res4);*/

    return query.exec();

}

 //*********************
float todolist_e::nbre_totale()
 {
     QSqlQuery query;

   /*  QString res1=QString::number(username);
     query.bindValue(":ID_E",res1);*/

     query.prepare("select * from DB_EMPLOYEE_TODOLIST");

     float i=0;

     if (query.exec())
     {
         while(query.next()){i++;}
        }
        return i ;
 }

 //**********************************
float todolist_e::nbre_totalep()
 {
     QSqlQuery query;
     QString etat_task="in progress";
     query.bindValue(":ETAT_TASK_E",etat_task);

     query.prepare("select * from DB_EMPLOYEE_TODOLIST where ETAT_TASK_E='"+etat_task+"' ");

     float i=0;

     if (query.exec())
     {
         while(query.next()){i++;}
      }
     return i ;
 }
 //***********************************

float todolist_e::nbre_totaled()
 {
     QSqlQuery query;
     QString etat_task="done";
     query.bindValue(":ETAT_TASK_E",etat_task);

     query.prepare("select * from DB_EMPLOYEE_TODOLIST where ETAT_TASK_E='"+etat_task+"' ");

     float  i=0;

     if (query.exec())
     {
         while(query.next()){i++;}
      }
     return i ;
 }
//**********************
