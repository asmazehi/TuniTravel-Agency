#include "employee.h"


#include <QSqlQuery>
#include <QtDebug>
#include <QObject>


#include <QIntValidator>
#include <QTextStream>
#include <QTextDocument>
#include <QPrintDialog>
#include <QPrinter>

employee::employee()
{

}


//****************

employee::employee(QString nom,QString prenom,int cin,int id,QString motpass,int tel,int salaire,int heure)
{
    this->nom=nom;
    this->prenom=prenom;
    this->cin=cin;
    this->id=id;
    this->motpass=motpass;
    this->tel=tel;
    this->salaire=salaire;
    this->heure=heure ;
}
//****************
employee::employee(QString nom,QString prenom,int cin,int tel,int salaire,int heure)
{
    this->nom=nom;
    this->prenom=prenom;
    this->cin=cin;
    this->tel=tel;
    this->salaire=salaire;
    this->heure=heure ;
}
//****************
employee::employee(QString motpass)
{
   this->motpass=motpass;
}
//****************
bool employee::ajouter()
{

    QSqlQuery query;
    QSqlQuery queryh;

    QString res1 =QString::number(id);
    QString res2 =QString::number(cin);
    QString res3 =QString::number(tel);
    QString res4 =QString::number(heure);
  //prepare prend la request en paramétre pour la préparer a l'exucution


    query.prepare("insert into DB_EMPLOYEE (ID_E,NOM_E,PRENOM_E,CIN_E,TEL_E,SALAIRE_E,HEURDETRAVAIL_E)" "values(:ID_E,:NOM_E,:PRENOM_E,:CIN_E,:TEL_E,:SALAIRE_E,:HEURDETRAVAIL_E)");
    queryh.prepare("insert into DB_EMPLOYEE_LOGIN (ID_E,MOTPASS_E)" "values(:ID_E,:MOTPASS_E)");


  queryh.bindValue(":ID_E",res1);
  queryh.bindValue(":MOTPASS_E",motpass);

    query.bindValue(":NOM_E",nom);
    query.bindValue(":PRENOM_E",prenom);
    query.bindValue(":CIN_E",res2);
    query.bindValue(":ID_E",res1);
   // query.bindValue(":MOTPASS_E",motpass);
    query.bindValue(":TEL_E",res3);
    query.bindValue(":SALAIRE_E",salaire);
    query.bindValue(":HEURDETRAVAIL_E",res4);

    return (query.exec() && queryh.exec());

}

//****************

bool employee::supprimer(int ID_E)
{

    QSqlQuery query;
    QString id_string=QString::number(ID_E);
    query.prepare("Delete from DB_EMPLOYEE where ID_E=:ID_E");
    query.bindValue(0, ID_E);


return query.exec();

}

//****************

QSqlQueryModel* employee::afficher()
{
   QSqlQueryModel* model=new QSqlQueryModel();

   model->setQuery("select ID_E,NOM_E,PRENOM_E,CIN_E,TEL_E,SALAIRE_E,HEURDETRAVAIL_E from DB_EMPLOYEE");

   return model;
}
//****************
QSqlQueryModel* employee::tri_nom()
{
    QSqlQueryModel* model=new QSqlQueryModel();

    model->setQuery("select ID_E,NOM_E,PRENOM_E,CIN_E,TEL_E,SALAIRE_E,HEURDETRAVAIL_E from DB_EMPLOYEE ORDER BY NOM_E ASC");

    return model;
}
 QSqlQueryModel* employee::tri_salaire()
 {
     QSqlQueryModel* model=new QSqlQueryModel();

     model->setQuery("select ID_E,NOM_E,PRENOM_E,CIN_E,TEL_E,SALAIRE_E,HEURDETRAVAIL_E from DB_EMPLOYEE ORDER BY SALAIRE_E ASC");


     return model;

 }

  QSqlQueryModel* employee::tri_heure()
  {
      QSqlQueryModel* model=new QSqlQueryModel();

      model->setQuery("select ID_E,NOM_E,PRENOM_E,CIN_E,TEL_E,SALAIRE_E,HEURDETRAVAIL_E from DB_EMPLOYEE ORDER BY HEURDETRAVAIL_E ASC");

   /*   model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_E"));
      model->setHeaderData(2, Qt::Horizontal, QObject::tr("NOM_E"));
      model->setHeaderData(3, Qt::Horizontal, QObject::tr("PRENOM_E"));
      model->setHeaderData(4, Qt::Horizontal, QObject::tr("CIN_E"));
      model->setHeaderData(5, Qt::Horizontal, QObject::tr("TEL_E"));
      model->setHeaderData(6, Qt::Horizontal, QObject::tr("SALAIRE_E"));
      model->setHeaderData(7, Qt::Horizontal, QObject::tr("HEURDETRAVAIL_E"));*/
      return model;
  }

  //****************

 bool employee::modifier(int id)
{
     QSqlQuery query;
     QString res1 =QString::number(id);
     QString res2 =QString::number(cin);
     QString res3 =QString::number(tel);
     QString res4 =QString::number(heure);
     QString res5 =QString::number(salaire);



    /**/
    query.prepare("UPDATE DB_EMPLOYEE SET nom_e='"+this->nom+"',prenom_e='"+this->prenom+"',cin_e='"+res2+"',tel_e='"+res3+"',salaire_e='"+res5+"',heurdetravail_e='"+res4+"' WHERE ID_E='"+res1+"'");
                 // "NOM_E=:NOM_E,PRENOM_E=:PRENOM_E,CIN_E=:CIN_E,TEL_E=:TEL_E,SALAIRE_E=:SALAIRE_E,HEURDETRAVAIL_E=:HEURDETRAVAIL_E WHERE ID_E:=ID_E");

   query.bindValue(":ID_E",res1);
    query.bindValue(":nom_e",nom);
     query.bindValue(":prenom_e",prenom);
      query.bindValue(":salaire_e",res5);
    query.bindValue(":cin_e",res2);
    query.bindValue(":tel_e",res3);
    query.bindValue(":heuredetravail_e",res4);

    return query.exec();

}

//****************

 bool employee::modifier_mot_passe(int id,QString motpassa,QString motpassn)
{
     QSqlQuery query;
     QString res1 =QString::number(id);
   //  QString res2 =QString::number(cin);
    // QString res3 =QString::number(tel);
     //QString res4 =QString::number(heure);



    /**/
    query.prepare("UPDATE DB_EMPLOYEE_LOGIN SET motpass_e='"+motpassn+"' WHERE (ID_E='"+res1+"' AND motpass_e='"+motpassa+"')");

    query.bindValue(":ID_E",res1);
    /*query.bindValue(":CIN_E",res2);
    query.bindValue(":TEL_E",res3);
    query.bindValue(":HEURDETRAVAIL_E",res4);
    */
    return query.exec();
}

//*************
/*
 QString employee::motpass_kdim(int id)
 {
        QSqlQueryModel* model=new QSqlQueryModel();
     QSqlQuery query;
     QString kdim;
      QString res1 =QString::number(id);
      model->setQuery("SELECT MOTPASS_E FROM DB_EMPLOYEE where ID_E='"+res1+"'");

         query.bindValue(":ID_E",res1);

      return kdim;

 }
*/
//****************


QSqlQueryModel * employee::recherche(QString id)
{
     QSqlQuery query;



    QSqlQueryModel *model=new QSqlQueryModel();

    model->setQuery("SELECT ID_E,NOM_E,PRENOM_E,CIN_E,TEL_E,SALAIRE_E,HEURDETRAVAIL_E FROM DB_EMPLOYEE  WHERE ID_E='"+id+"' or NOM_E='"+id+"' or PRENOM_E='"+id+"' or CIN_E='"+id+"' or TEL_E='"+id+"' or SALAIRE_E='"+id+"' or HEURDETRAVAIL_E='"+id+"' ");

    query.bindValue(":ID_E",id);
    query.bindValue(":NOM_E",id);
    query.bindValue(":PRENOM_E",id);
    query.bindValue(":CIN_E",id);
   // query.bindValue(":MOTPASS_E",res);
    query.bindValue(":TEL_E",id);
    query.bindValue(":SALAIRE_E",id);
    query.bindValue(":HEURDETRAVAIL_E",id);

    return model;
}
//****************


QSqlQueryModel* employee::afficher_task()
{
   QSqlQueryModel* model=new QSqlQueryModel();

   model->setQuery("select * from DB_EMPLOYEE_TODOLIST");
/*
   model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_E"));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("NOM_E"));
   model->setHeaderData(3, Qt::Horizontal, QObject::tr("PRENOM_E"));
   model->setHeaderData(4, Qt::Horizontal, QObject::tr("CIN_E"));
   model->setHeaderData(5, Qt::Horizontal, QObject::tr("TEL_E"));
   model->setHeaderData(6, Qt::Horizontal, QObject::tr("SALAIRE_E"));
   model->setHeaderData(7, Qt::Horizontal, QObject::tr("HEURDETRAVAIL_E"));*/
   return model;
}



//*******************
QSqlQueryModel* employee::afficher_m()
{
    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("select ID_E,MOTPASS_E from DB_EMPLOYEE_LOGIN");


    return model;


}
