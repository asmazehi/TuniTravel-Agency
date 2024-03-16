#include "client.h"
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>

client::client()
{
    cin=0;nom="";prenom="";email="";telephone=0;adresse="";

}

client::client(int cin,QString nom,QString prenom,QString email,int telephone,QString adresse)
{this->cin=cin;this->nom=nom;this->prenom=prenom;this->email=email;this->telephone=telephone;this->adresse=adresse;}
int client::getcin(){return cin;}
QString client::getnom(){return nom;}
QString client::getprenom(){return prenom;}
QString client::getemail(){return email;}
int client::gettelephone(){return telephone;}
QString client::getadresse(){return adresse;}
void client::setcin (int id){id=cin;}
void client::setnom (QString nomd){nomd=nom;}
void client::setprenom (QString prenomd){prenomd=prenom;}
void client::setemail (QString emaild){emaild=email;}
void client::settelephone (int telephon){telephon=telephone;}
void client::setadresse (QString adressed){adressed=adresse;}

bool client::ajouter()
{   QSqlQuery query ;
    QString etat="AJOUTER";
    QSqlQuery queryh;
    QString id_string= QString::number(cin);
    QString tel_string= QString::number(telephone);

    query.prepare("INSERT INTO  DB_CLIENT (CIN_C,NOM_C,PRENOM_C,EMAIL_C,TEL_C,ADRESSE_C)"
                  "VALUES (:cin, :nom, :prenom, :email, :telephone, :adresse)");
    queryh.prepare("INSERT INTO  CLIENT_HIS (ETAT_H,CIN_H)" "VALUES (:etat,:cinh)");

    queryh.bindValue(":etat",etat);
    queryh.bindValue(":cinh",id_string);

    query.bindValue(":cin",id_string);
            query.bindValue(":nom",nom);
            query.bindValue(":prenom",prenom);
            query.bindValue(":email",email);
            query.bindValue(":telephone",tel_string);
            query.bindValue(":adresse",adresse);

            return (query.exec() && queryh.exec());

}

QSqlQueryModel *client::afficher()
{
   QSqlQueryModel *model=new QSqlQueryModel ();
   model->setQuery("SELECT * FROM DB_CLIENT");
   model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
           model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
           model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
           model->setHeaderData(3, Qt::Horizontal, QObject::tr("email"));
           model->setHeaderData(4, Qt::Horizontal, QObject::tr("telephone"));
           model->setHeaderData(5, Qt::Horizontal, QObject::tr("adresse"));

    return model;
}



bool client::supprimer(int cin)
{

    QSqlQuery query;
    QString etat="SUPPRIMER";
    QSqlQuery queryh;

    QString id_string=QString::number(cin);
          query.prepare("DELETE FROM DB_CLIENT WHERE CIN_C= :cin");



          queryh.prepare("INSERT INTO  CLIENT_HIS (ETAT_H,CIN_H)" "VALUES (:etat,:cinh)");

          queryh.bindValue(":etat",etat);
          queryh.bindValue(":cinh",id_string);

          query.addBindValue(id_string);

          return (query.exec() && queryh.exec());
}


bool client::modifier(int cin)
{
  QSqlQuery query;
  QString etat="MODIFIER";
  QSqlQuery queryh;

  QString id_string= QString::number(cin);
  QString tel_string= QString::number(telephone);

  query.prepare("UPDATE DB_CLIENT SET nom_c='"+this->nom+"',prenom_c='"+this->prenom+"',cin_c='"+id_string+"',tel_c='"+tel_string+"',email_c='"+this->email+"',adresse_c='"+this->adresse+"' WHERE cin_C='"+id_string+"'");
  queryh.prepare("INSERT INTO  CLIENT_HIS (ETAT_H,CIN_H)" "VALUES (:etat,:cinh)");

  queryh.bindValue(":etat",etat);
  queryh.bindValue(":cinh",id_string);

  query.bindValue(":cin", id_string);
      query.bindValue(":nom", nom);
      query.bindValue(":prenom", prenom);
      query.bindValue(":email", email);
      query.bindValue(":telephone", tel_string);
      query.bindValue(":adresse", adresse);
      return (query.exec() && queryh.exec());

}


QSqlQueryModel *client::afficher_HIS()
{
   QSqlQueryModel *model=new QSqlQueryModel ();
   model->setQuery("SELECT * FROM CLIENT_HIS");
   model->setHeaderData(0, Qt::Horizontal, QObject::tr("etat"));
   model->setHeaderData(1, Qt::Horizontal, QObject::tr("cin"));

    return model;
}

QSqlQueryModel * client::recherche(int cin)
  {QString etat="RECHERCHE";
    QSqlQuery queryh;
    QSqlQuery query;
   QString id_string= QString::number(cin);
    QString tel_string= QString::number(telephone);

    QString res=QString::number(cin);
    QSqlQueryModel *model=new QSqlQueryModel();

    queryh.prepare("INSERT INTO  CLIENT_HIS (ETAT_H,CIN_H)" "VALUES (:etat,:cinh)");

    queryh.bindValue(":etat",etat);
    queryh.bindValue(":cinh",id_string);
     queryh.exec();

  model->setQuery("SELECT* FROM DB_CLIENT where cin_c='"+res+"'");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("email"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("telephone"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("adresse"));



    return model ;
}




QSqlQueryModel* client::tri_cin()
{
    QString etat="TRI_CIN";
        QSqlQuery queryh;
        QString id_string= QString::number(cin);


    queryh.prepare("INSERT INTO  CLIENT_HIS (ETAT_H,CIN_H)" "VALUES (:etat,:cinh)");

    queryh.bindValue(":etat",etat);
    queryh.bindValue(":cinh",id_string);
     queryh.exec();

     QSqlQueryModel* model=new QSqlQueryModel();


    model->setQuery("select * from DB_CLIENT ORDER BY CIN_C ASC");

   /* model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_E"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("NOM_E"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("PRENOM_E"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("CIN_E"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("TEL_E"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("SALAIRE_E"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("HEURDETRAVAIL_E"));*/
    return model;
}

QSqlQueryModel* client::tri_nom()
{
    QSqlQueryModel* model=new QSqlQueryModel();
    QString etat="TRI_NOM";
        QSqlQuery queryh;
        QString id_string= QString::number(cin);


    queryh.prepare("INSERT INTO  CLIENT_HIS (ETAT_H,CIN_H)" "VALUES (:etat,:cinh)");

    queryh.bindValue(":etat",etat);
    queryh.bindValue(":cinh",id_string);
     queryh.exec();

    model->setQuery("select * from DB_CLIENT ORDER BY NOM_C ASC");

   /* model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_E"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("NOM_E"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("PRENOM_E"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("CIN_E"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("TEL_E"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("SALAIRE_E"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("HEURDETRAVAIL_E"));*/
    return model;
}
 QSqlQueryModel* client::tri_prenom()
 {
     QSqlQueryModel* model=new QSqlQueryModel();
     QString etat="TRI_PRENOM";
         QSqlQuery queryh;
         QString id_string= QString::number(cin);


     queryh.prepare("INSERT INTO  CLIENT_HIS (ETAT_H,CIN_H)" "VALUES (:etat,:cinh)");

     queryh.bindValue(":etat",etat);
     queryh.bindValue(":cinh",id_string);
      queryh.exec();

     model->setQuery("select * from DB_CLIENT ORDER BY PRENOM_C ASC");

 /*    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_E"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("NOM_E"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("PRENOM_E"));
     model->setHeaderData(4, Qt::Horizontal, QObject::tr("CIN_E"));
     model->setHeaderData(5, Qt::Horizontal, QObject::tr("TEL_E"));
     model->setHeaderData(6, Qt::Horizontal, QObject::tr("SALAIRE_E"));
     model->setHeaderData(7, Qt::Horizontal, QObject::tr("HEURDETRAVAIL_E"));*/
     return model;

 }

  QSqlQueryModel* client::tri_email()
  {
      QSqlQueryModel* model=new QSqlQueryModel();
      QString etat="TRI_EMAIL";
          QSqlQuery queryh;
          QString id_string= QString::number(cin);


      queryh.prepare("INSERT INTO  CLIENT_HIS (ETAT_H,CIN_H)" "VALUES (:etat,:cinh)");

      queryh.bindValue(":etat",etat);
      queryh.bindValue(":cinh",id_string);
       queryh.exec();

      model->setQuery("select * from DB_CLIENT ORDER BY EMAIL_C ASC");

   /*   model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_E"));
      model->setHeaderData(2, Qt::Horizontal, QObject::tr("NOM_E"));
      model->setHeaderData(3, Qt::Horizontal, QObject::tr("PRENOM_E"));
      model->setHeaderData(4, Qt::Horizontal, QObject::tr("CIN_E"));
      model->setHeaderData(5, Qt::Horizontal, QObject::tr("TEL_E"));
      model->setHeaderData(6, Qt::Horizontal, QObject::tr("SALAIRE_E"));
      model->setHeaderData(7, Qt::Horizontal, QObject::tr("HEURDETRAVAIL_E"));*/
      return model;
  }


  float client::nbre_totale()
   {
       QSqlQuery query;

     /*  QString res1=QString::number(username);
       query.bindValue(":ID_E",res1);*/

       query.prepare("select * from CLIENT_HIS");

       float i=0;

       if (query.exec())
       {
           while(query.next()){i++;}
          }
          return i ;
   }

   //**********************************
  float client::nbre_totalea()
   {
       QSqlQuery query;
       QString etat="AJOUTER";
       query.bindValue(":ETAT_H",etat);

       query.prepare("select * from CLIENT_HIS where ETAT_H='"+etat+"' ");

       float i=0;

       if (query.exec())
       {
           while(query.next()){i++;}
        }
       return i ;
   }
   //***********************************

  float client::nbre_totales()
   {
       QSqlQuery query;
       QString etat="SUPPRIMER";
       query.bindValue(":ETAT_H",etat);

       query.prepare("select * from CLIENT_HIS where ETAT_H='"+etat+"' ");

       float  i=0;

       if (query.exec())
       {
           while(query.next()){i++;}
        }
       return i ;
   }
  //**********************

  float client::nbre_totalem()
   {
       QSqlQuery query;
       QString etat="MODIFIER";
       query.bindValue(":ETAT_H",etat);

       query.prepare("select * from CLIENT_HIS where ETAT_H='"+etat+"' ");

       float  i=0;

       if (query.exec())
       {
           while(query.next()){i++;}
        }
       return i ;
   }


/*  bool client::supprimerh(int cin)
  {

      QSqlQuery query;

      QString id_string=QString::number(cin);
            query.prepare("DELETE FROM CLIENT_HIS WHERE CIN_C= :cin");

            query.addBindValue(id_string);

            return query.exec();
  }
*/
