#include "partenaire.h"
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDoubleValidator>
#include <QtDebug>
#include <QObject>
#include <QMainWindow>
#include <QMessageBox>
#include <QTableWidget>


Partenaire::Partenaire()
{

   id=0 ;nom="" ;ctg=""; adr="";ppa="";ctct=""; ddc=0;
}


Partenaire::Partenaire(int id ,QString nom ,QString ctg,QString adr,QString ppa,QString ctct,int ddc)
{this -> id=id;this->nom=nom;this->ctg=ctg;this->adr=adr;this->ppa=ppa;this->ctct=ctct;this->ddc=ddc;}


    int Partenaire::getid() {return id;}
    QString Partenaire::getnom(){return nom;}
    QString Partenaire::getctg(){return ctg;}
    QString Partenaire::getadr(){return adr;}
    QString Partenaire::getppa(){return ppa;}
    QString Partenaire::getctct(){return ctct;}
    int Partenaire::getddc(){return ddc;}

    void Partenaire::setid(int id){this -> id=id;}
    void Partenaire::setnom(QString nom){this->nom=nom;}
    void Partenaire::setctg(QString ctg){this->ctg=ctg;}
    void Partenaire::setadr(QString adr){this->adr=adr;}
    void Partenaire::setppa(QString ppa){this->ppa=ppa;}
    void Partenaire::setctct(QString ctct){this->ctct=ctct;}
    void Partenaire::setddc(int ddc){this->ddc=ddc;}


    bool Partenaire::ajouter()
    {
        //bool test=false;

        QSqlQuery query;

        QString id_string=QString::number(id);
         QString ddc_string=QString::number(ddc);


        query.prepare("INSERT INTO DB_PARTENAIRE (id, nom, ctg, adr, ppa, ctct, ddc) "
                      "VALUES (:id, :nom, :ctg, :adr, :ppa, :ctct, :ddc)");
        query.bindValue(":id", id_string);
        query.bindValue(":nom", nom);
        query.bindValue(":ctg", ctg);
        query.bindValue(":adr", adr);
        query.bindValue(":ppa", ppa);
        query.bindValue(":ctct", ctct);
        query.bindValue(":ddc", ddc_string);
        return query.exec();

       // return test;

    }

    bool Partenaire::Supprimer(int id)
    {
        QSqlQuery query;

              query.prepare(" Delete from DB_PARTENAIRE where id=:ID");
              query.bindValue(0,id);

             return query.exec();
    }



    QSqlQueryModel * Partenaire::Recherche(int id)
     {
         QSqlQuery query;
         QString id_string=QString::number(id);

         query.prepare("select * from DB_PARTENAIRE where id=:id");
         query.bindValue(":id",id_string);
         query.exec();
         QSqlQueryModel *model= new QSqlQueryModel;
         model->setQuery(query);


        return model;
}


    bool Partenaire::modifier(int id,QString nom,QString ctg,QString adr,QString ppa,QString ctct, int ddc)

        {

        QSqlQuery query;


        query.prepare("UPDATE DB_PARTENAIRE SET id=:id, nom=:nom, ctg=:ctg, adr=:adr, ppa=:ppa, ctct=:ctct, ddc=:ddc WHERE id=:id");

        query.bindValue(":id", id);

        query.bindValue(":nom", nom);

        query.bindValue(":ctg", ctg);

        query.bindValue(":adr", adr);

         query.bindValue(":ppa", ppa);

         query.bindValue(":ctct", ctct);

         query.bindValue(":ddc", ddc);


        return  query.exec();

            }
