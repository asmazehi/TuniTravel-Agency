#include "fourniture.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QPrinter>
#include <QPainter>
#include <iostream>

fourniture::fourniture()
{
 reference="";
 nom="";
 prix=0;
 quantite=0;
 etat="";
 fournisseur="";
 image="";
}

fourniture::fourniture(QString reference, QString nom , float prix , int quantite, QString etat, QString fournisseur,QString image)
{
    this->reference = reference;
    this->nom = nom;
    this->prix = prix;
    this->quantite = quantite;
    this->etat = etat;
    this->fournisseur = fournisseur;
    this->image = image;
}
QString fourniture::get_reference(){return reference;}
QString fourniture::get_nom(){return nom;}
float fourniture::get_prix(){return prix;}
int fourniture::get_quantite(){return quantite;}
QString fourniture::get_etat(){return etat;}
QString fourniture::get_fournisseur(){return fournisseur;}
QString fourniture::get_image(){return image;}

void fourniture::setreference(QString reference){this->reference=reference;}
void fourniture::setnom(QString nom){this->nom=nom;}
void fourniture::setprix(float prix){this->prix=prix;}
void fourniture::setquantite(int quantite){this->quantite=quantite;}
void fourniture::setetat(QString etat){this->etat=etat;}
void fourniture::setfournisseur(QString fournisseur){this->fournisseur=fournisseur;}
void fourniture::setimage(QString image){this->image=image;}
bool fourniture::ajouter()
{

    QSqlQuery query;
    QString reference_string= reference ;
    QString prix_string=QString::number(prix);
    QString quantite_string=QString::number(quantite);
          query.prepare("INSERT INTO DB_FOURNITURE(REFERENCE,NOM,PRIX,QUANTITE,ETAT,FOURNISSEUR,IMAGE) "
                        "VALUES (:reference,:nom,:prix,:quantite,:etat,:fournisseur,:image)");
          query.bindValue(":reference", reference_string);
          query.bindValue(":nom",nom);
          query.bindValue(":prix", prix_string);
          query.bindValue(":quantite", quantite_string);
          query.bindValue(":etat", etat);
      query.bindValue(":fournisseur", fournisseur);
      query.bindValue(":image", image);



          return query.exec();

}

bool fourniture::supprimer(QString reference)
{
QSqlQuery query;
QString res= reference ;
query.prepare("Delete from DB_FOURNITURE where REFERENCE = :reference ");
query.bindValue(":reference", res);
return    query.exec();
}



QSqlQueryModel * fourniture::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from DB_FOURNITURE");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("reference"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("prix"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("quantite"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("etat"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("fournisseur"));

    return model;
}



bool fourniture::modifier(QString reference)
{
    QSqlQuery query;
    QString res= reference ;
    QString res1= QString::number(prix);
   QString res2= QString::number(quantite);
    query.prepare("UPDATE DB_FOURNITURE SET REFERENCE=:reference,nom=:nom,prix=:prix,quantite=:quantite,etat=:etat, fournisseur=:fournisseur, image=:image WHERE REFERENCE=:reference");
    query.bindValue(":reference", res);
    query.bindValue(":nom", nom);
    query.bindValue(":prix", res1);
    query.bindValue(":quantite", res2);
    query.bindValue(":etat", etat);
    query.bindValue(":fournisseur", fournisseur);
    query.bindValue(":image",image);
    return    query.exec();

}

bool fourniture::genererPDF()
{
    QPdfWriter pdf("C:/Users/dell/Documents/NOTION/2eme année (2-A-27)/subjects/Projet C++/Integration FINALE/Dossier PDF/mypdf_file_fourniture.pdf");
    QPainter painter(&pdf);
    const QString &date=QDateTime::currentDateTime().toString("dd/MM/yyyy");
    qDebug()<<date;



    int i = 4000;
                             painter.setPen(Qt::red);
                            painter.drawImage(500,12000,QImage("D:/logo.jpg"));
                             painter.setFont(QFont("Arial", 32));
                             painter.drawText(2600,1100,"Liste des fournitures");
                             painter.setPen(Qt::black);
                             painter.setFont(QFont("Arial", 15));

                             painter.drawRect(1000,100,7700,1600);
                             painter.drawRect(1000,3000,7700,500);
                             painter.setFont(QFont("Arial", 9));
                             painter.drawText(1500,3300,"reference");
                             painter.drawText(2700,3300,"nom");
                             painter.drawText(3900,3300,"prix");
                             painter.drawText(5100,3300,"quantite");
                             painter.drawText(6300,3300,"etat");
                             painter.drawText(7500,3300,"fournisseur");
painter.drawText(8500,12000,date);

                                QSqlQuery query;

                                                         query.prepare("select * from DB_FOURNITURE");
                                                         query.exec();
                                                         while (query.next())
                                                         {
                                                             painter.drawText(1500,i,query.value(0).toString());
                                                             painter.drawText(2700,i,query.value(1).toString());
                                                             painter.drawText(3900,i,query.value(2).toString());
                                                             painter.drawText(5100,i,query.value(3).toString());
                                                             painter.drawText(6300,i,query.value(4).toString());
                                                             painter.drawText(7500,i,query.value(5).toString());



                                                            i = i + 500;

                                                         }
 return query.exec();



}


QSqlQueryModel* fourniture::trierparref()
{
    QSqlQueryModel* model=new QSqlQueryModel();

    model->setQuery("SELECT * FROM DB_FOURNITURE ORDER BY reference ASC");
    model->setHeaderData(0,Qt::Horizontal, QObject::tr("reference"));
    model->setHeaderData(1,Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2,Qt::Horizontal, QObject::tr("prix"));
    model->setHeaderData(3,Qt::Horizontal, QObject::tr("quantite"));
    model->setHeaderData(3,Qt::Horizontal, QObject::tr("etat"));
    model->setHeaderData(3,Qt::Horizontal, QObject::tr("fournisseur"));


    return model;
}
QSqlQueryModel* fourniture ::trierparnom()
{
    QSqlQueryModel* model=new QSqlQueryModel();

    model->setQuery("SELECT * FROM DB_FOURNITURE ORDER BY nom ASC");
    model->setHeaderData(0,Qt::Horizontal, QObject::tr("reference"));
    model->setHeaderData(1,Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2,Qt::Horizontal, QObject::tr("prix"));
    model->setHeaderData(3,Qt::Horizontal, QObject::tr("quantite"));
    model->setHeaderData(3,Qt::Horizontal, QObject::tr("etat"));
    model->setHeaderData(3,Qt::Horizontal, QObject::tr("fournisseur"));

    return model;
}
QSqlQueryModel* fourniture::trierparpri()
{
    QSqlQueryModel* model=new QSqlQueryModel();

    model->setQuery("SELECT * FROM DB_FOURNITURE ORDER BY prix ASC");
    model->setHeaderData(0,Qt::Horizontal, QObject::tr("reference"));
    model->setHeaderData(1,Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2,Qt::Horizontal, QObject::tr("prix"));
    model->setHeaderData(3,Qt::Horizontal, QObject::tr("quantite"));
    model->setHeaderData(3,Qt::Horizontal, QObject::tr("etat"));
    model->setHeaderData(3,Qt::Horizontal, QObject::tr("fournisseur"));

    return model;
}
QSqlQueryModel* fourniture::trierparqua()
{
    QSqlQueryModel* model=new QSqlQueryModel();


    model->setQuery("SELECT * FROM DB_FOURNITURE ORDER BY quantite ASC");
    model->setHeaderData(0,Qt::Horizontal, QObject::tr("reference"));
    model->setHeaderData(1,Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2,Qt::Horizontal, QObject::tr("prix"));
    model->setHeaderData(3,Qt::Horizontal, QObject::tr("quantite"));
    model->setHeaderData(3,Qt::Horizontal, QObject::tr("etat"));
    model->setHeaderData(3,Qt::Horizontal, QObject::tr("fournisseur"));

    return model;
}
QSqlQueryModel* fourniture::trierpareta()
{
    QSqlQueryModel* model=new QSqlQueryModel();


    model->setQuery("SELECT * FROM DB_FOURNITURE ORDER BY etat ASC");
    model->setHeaderData(0,Qt::Horizontal, QObject::tr("reference"));
    model->setHeaderData(1,Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2,Qt::Horizontal, QObject::tr("prix"));
    model->setHeaderData(3,Qt::Horizontal, QObject::tr("quantite"));
    model->setHeaderData(3,Qt::Horizontal, QObject::tr("etat"));
    model->setHeaderData(3,Qt::Horizontal, QObject::tr("fournisseur"));

    return model;
}
QSqlQueryModel* fourniture::trierparfou()
{
    QSqlQueryModel* model=new QSqlQueryModel();


    model->setQuery("SELECT * FROM DB_FOURNITURE ORDER BY fournisseur ASC");
    model->setHeaderData(0,Qt::Horizontal, QObject::tr("reference"));
    model->setHeaderData(1,Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2,Qt::Horizontal, QObject::tr("prix"));
    model->setHeaderData(3,Qt::Horizontal, QObject::tr("quantite"));
    model->setHeaderData(3,Qt::Horizontal, QObject::tr("etat"));
    model->setHeaderData(3,Qt::Horizontal, QObject::tr("fournisseur"));

    return model;
}



bool fourniture::rechercheparref(QString reference)
    {
        QSqlQuery query;
        //QSqlRecord CIN = query.record();
        QString str= reference ;

        query.prepare("SELECT * FROM DB_FOURNITURE WHERE REFERENCE=:reference");
        query.bindValue(":reference",str);
        query.exec();

        if (query.next())
        {
            return true;
             qDebug()<<"fourniture existe";

        }
        else
        {
            qDebug()<<"fourniture n'existe pas";
            return false;
        }
    }


    QSqlQueryModel *fourniture::afficherparref(QString reference)
        {
        QSqlQueryModel * model= new QSqlQueryModel();

         QString ref=  reference ;

        QSqlQuery *q = new QSqlQuery;
         q->prepare("SELECT * from DB_FOURNITURE where REFERENCE LIKE '%"+ref+"%'");
          q->addBindValue(ref);
           q->exec();
             model->setQuery(*q);


            return model;
        }


    QSqlQueryModel * fourniture::afficherenpanne(){
        QSqlQueryModel *model = new QSqlQueryModel();
     QSqlQuery q;
     q.prepare("SELECT * FROM DB_FOURNITURE where etat = :etat");
     q.bindValue(":etat","En panne");
     q.exec();

        model->setQuery(q);
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("reference"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("prix"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("quantite"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("etat"));
        model->setHeaderData(5, Qt::Horizontal, QObject::tr("fournisseur"));

            return model;




    }
