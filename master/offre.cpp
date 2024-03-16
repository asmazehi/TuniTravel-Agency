#include "offre.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include <QtCharts>
#include <QDesktopServices>
#include <QtCharts/QAreaSeries>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QPieSlice>
#include <QPieSeries>
#include <QChartView>
#include <QCalendarWidget>
#include <QDate>
#include <QApplication>
Offre::Offre()
{
id=" ";prix=" ";contenu=" ";nbredeplace=" ";dated=" ";
}
Offre::Offre(QString id,QString prix,QString contenu,QString nbredeplace,QString dated)
{this->id=id;this->prix=prix;this->contenu=contenu;this->nbredeplace=nbredeplace;this->dated=dated;}
QString Offre::get_id(){return id;}
QString Offre::get_prix(){return prix;}
QString Offre::get_contenu(){return contenu;}
QString Offre::get_nbredeplace(){return nbredeplace;}
QString Offre::get_dated(){return dated;}
void Offre::setid(QString id){this->id=id;}
void Offre::setprix(QString prix){this->prix=prix;}
void Offre::setcontenu(QString contenu){this->contenu=contenu;}
void Offre::setnbredeplace(QString nbredeplace){this->nbredeplace=nbredeplace;}
void Offre::setdated(QString dated){this->dated=dated;}
bool Offre::ajouter()
{
    QSqlQuery query;

    query.prepare("INSERT INTO DB_OFFRE (id, prix, contenu,nbredeplace,dated) "
                  "VALUES (:id, :prix, :contenu,:nbredeplace,:dated)");
    query.bindValue(":id", id);
    query.bindValue(":prix", prix);
    query.bindValue(":contenu", contenu);
    query.bindValue(":nbredeplace", nbredeplace);
    query.bindValue(":dated", dated);
return query.exec();
}
bool Offre::supprimer(QString id)
{
    QSqlQuery query;

    query.prepare("Delete from DB_OFFRE where id=:id");
    query.bindValue(":id", id);
return query.exec();
}
QSqlQueryModel* Offre::afficher()
{
 QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("SELECT* FROM offre");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Identifiant"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Prix"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Contenu"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Nombre de place"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("dated"));
 return model;


}
bool Offre::modifier(QString id)
{
    QSqlQuery query;
    query.prepare("UPDATE DB_OFFRE set prix=:prix,contenu=:contenu,nbredeplace=:nbredeplace,dated=:dated where id=:id");
    query.bindValue(":id", id);
    query.bindValue(":prix", prix);
    query.bindValue(":contenu", contenu);
    query.bindValue(":nbredeplace", nbredeplace);
    query.bindValue(":dated", dated);
    return query.exec();
}
QSqlQueryModel * Offre::triid()

  {

      QSqlQueryModel * model=new QSqlQueryModel();

      model->setQuery("SELECT * FROM DB_OFFRE ORDER BY ID");

      model->setHeaderData(0, Qt::Horizontal,QObject:: tr("ID"));

      model->setHeaderData(1, Qt::Horizontal, QObject:: tr("PRIX"));

      model->setHeaderData(2, Qt::Horizontal, QObject:: tr("CONTENU"));

      model->setHeaderData(3, Qt::Horizontal, QObject:: tr("NBREDEPLACE"));
      model->setHeaderData(4, Qt::Horizontal, QObject:: tr("DATED"));
      return model;

  }

QSqlQueryModel * Offre::tric()

  {

      QSqlQueryModel * model=new QSqlQueryModel();

      model->setQuery("SELECT * FROM OFFRE ORDER BY contenu");

      model->setHeaderData(0, Qt::Horizontal,QObject:: tr("ID"));

      model->setHeaderData(1, Qt::Horizontal, QObject:: tr("PRIX"));

      model->setHeaderData(2, Qt::Horizontal, QObject:: tr("CONTENU"));

      model->setHeaderData(3, Qt::Horizontal, QObject:: tr("NBREDEPLACE"));
      model->setHeaderData(4, Qt::Horizontal, QObject:: tr("DATED"));
      return model;

  }

QSqlQueryModel * Offre::trin()

  {

      QSqlQueryModel * model=new QSqlQueryModel();

      model->setQuery("SELECT * FROM DB_OFFRE ORDER BY nbredeplace");

      model->setHeaderData(0, Qt::Horizontal,QObject:: tr("ID"));

      model->setHeaderData(1, Qt::Horizontal, QObject:: tr("PRIX"));

      model->setHeaderData(2, Qt::Horizontal, QObject:: tr("CONTENU"));

      model->setHeaderData(3, Qt::Horizontal, QObject:: tr("NBREDEPLACE"));
      model->setHeaderData(4, Qt::Horizontal, QObject:: tr("DATED"));
      return model;

  }

void recherche(QTableView * table, QString);


 void Offre::recherche(QTableView * table, QString rech)

 {

     QSqlQueryModel *model= new QSqlQueryModel();

     QSqlQuery *query=new QSqlQuery;

         query->prepare("select * from DB_OFFRE where ID like '%"+rech+"%' or CONTENU like '%"+rech+"%' ;");

         query->exec();

         model->setQuery(*query);

         table->setModel(model);

         table->show();

 }
 QSqlQueryModel * Offre::afficher_calendar(QString x)
 {
     QSqlQueryModel * model= new QSqlQueryModel();

 model->setQuery("select * from DB_OFFRE where DATED like '%"+x+"%'");
 model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
 model->setHeaderData(1, Qt::Horizontal, QObject::tr("PRIX"));
 model->setHeaderData(2, Qt::Horizontal, QObject::tr("CONTENU"));
 model->setHeaderData(3, Qt::Horizontal, QObject::tr("NBREDEPLACE"));
 model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATED"));

     return model;
 }
