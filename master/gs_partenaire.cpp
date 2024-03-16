#include "gs_partenaire.h"
#include "ui_gs_partenaire.h"
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDoubleValidator>
#include <QtDebug>
#include <QObject>
#include <QMainWindow>
#include <QMessageBox>
#include <QIntValidator>
#include "partenaire.h"
#include <QTableWidget>
#include <QTableView>
#include <QPainter>
#include <QPdfWriter>
#include <QAbstractItemView>
#include <QDialog>
#include <QFrame>
#include <QLabel>
#include <QPlainTextEdit>
#include <QTextStream>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QDesktopServices>
#include <QDesktopWidget>
#include "notif.h"
#include<QtCharts/QChartView>
#include "mainwindow.h"
gs_partenaire::gs_partenaire(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gs_partenaire)
{
    ui->setupUi(this);
    ui->ID->setValidator( new QIntValidator(10000000, 99999999, this));
    ui->NOM->setValidator(new QRegExpValidator(QRegExp("[a-z]*")));
        ui->CTG->setValidator(new QRegExpValidator(QRegExp("[A-Z]*")));
        ui->ADR->setValidator(new QRegExpValidator(QRegExp("[a-z]*")));
        ui->PPA->setValidator( new QIntValidator(0, 99999999, this));
        ui->CTCT->setValidator(new QRegExpValidator(QRegExp("[a-z]*")));
}

gs_partenaire::~gs_partenaire()
{
    delete ui;
}

void gs_partenaire::on_ajouter_clicked()
{
    int id=ui->ID->text().toInt();
    QString nom=ui->NOM->text();
    QString ctg=ui->CTG->currentText();
    QString adr=ui->ADR->text();
    QString ppa=ui->PPA->text();
    QString ctct=ui->CTCT->text();
    int ddc=ui->DDC->currentText().toInt();
    Partenaire P(id,nom,ctg,adr,ppa,ctct,ddc);
   msgBox= new QMessageBox(this);
    bool test= P.ajouter();

        if (test){

            ui->table->setModel(P.afficher());

            msgBox->setText("effectué");
            msgBox->show();



        }

        else

          {          msgBox->setText("non effectué");
            msgBox->show();
    }


}


QSqlQueryModel* Partenaire::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();

          model->setQuery("SELECT * FROM Partenaire");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("CTG"));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("ADR"));
          model->setHeaderData(4, Qt::Horizontal, QObject::tr("PPA"));
          model->setHeaderData(5, Qt::Horizontal, QObject::tr("CTCT"));
          model->setHeaderData(6, Qt::Horizontal, QObject::tr("DDC"));

    return model;
}



void gs_partenaire::on_Supprimer_clicked()
{
    Partenaire P1;

            P1.setid(ui->ID->text().toInt());

            bool test=P1.Supprimer(P1.getid());
            msgBox= new QMessageBox(this);

            if (test){

                msgBox= new QMessageBox(this);
                         msgBox->setText("effectué");
                         msgBox->show();

                ui->table->setModel(P1.afficher());


            }

            else
            {
                msgBox->setText("non effectué");
                msgBox->show();
            }



}


void gs_partenaire::on_pb_pdf_clicked()
{
    QPdfWriter pdf("C:/Users/user/Desktop/PDF/PARTENAIRE.pdf");

   QPainter painter(&pdf);
   int i = 4000;
          painter.setPen(Qt::red);
          painter.setFont(QFont("Arial", 30));
          painter.drawText(2000,1400,"LISTES DES PARTENAIRE ");

          painter.setPen(Qt::black);
          painter.setFont(QFont("Arial", 15));
          painter.drawRect(100,100,9400,2500);
          painter.drawRect(100,3000,9400,500);


          painter.setFont(QFont("Arial", 10));
          painter.drawText(500,3300,"ID");
          painter.drawText(2000,3300,"NOM");
          painter.drawText(3000,3300,"CTG");
          painter.drawText(4000,3300,"ADR");
          painter.drawText(2000,3300,"PPA");
          painter.drawText(3000,3300,"CTCT");
          painter.drawText(4000,3300,"DDC");



          painter.drawRect(100,3000,9400,9000);

          QSqlQuery query;
          query.prepare("select * from PARTENAIRE");
          query.exec();
          while (query.next())
          {
              painter.drawText(500,i,query.value(0).toString());
              painter.drawText(2000,i,query.value(1).toString());
              painter.drawText(3000,i,query.value(2).toString());
              painter.drawText(4000,i,query.value(3).toString());
              painter.drawText(6000,i,query.value(4).toString());
              painter.drawText(8500,i,query.value(5).toString());

             i = i + 350;
          }
          QMessageBox::information(this, QObject::tr("PDF Enregistré!"),
          QObject::tr("PDF Enregistré!.\n" "Click Cancel to exit."), QMessageBox::Cancel);
}



void gs_partenaire::on_modifier_clicked()
{

    Partenaire P3;


    int id=ui->ID->text().toInt();
    QString nom=ui->NOM->text();
    QString ctg=ui->CTG->currentText();
    QString adr=ui->ADR->text();
    QString ppa=ui->PPA->text();
    QString ctct=ui->CTCT->text();
    int ddc=ui->DDC->currentText().toInt();

    msgBox= new QMessageBox(this);

           bool test=P3.modifier(id,nom,ctg,adr,ppa,ctct,ddc);

           if (test){

               msgBox->setText("effectué");
               msgBox->show();

             ui->table->setModel(P.afficher());

           }

           else

           {                         msgBox->setText("non effectué");
               msgBox->show();
}
  }

void gs_partenaire::on_actionplay_clicked()
{
    player= new QMediaPlayer ;
    vw=new QVideoWidget;

    auto filename=QFileDialog::getOpenFileName(this,"import mp4 file",QDir::rootPath(),"Excel Files(*.mp4)");

    vw->setGeometry(100,100,300,400);

    player->setVideoOutput(vw);
    player->setMedia(QUrl::fromLocalFile(filename));
    player->setMedia(QUrl::fromLocalFile("C:/Users/user/Desktop/VIDEO/final.mp4"));
    vw->show();
    player->play();
}

void gs_partenaire::on_Recherche_clicked()
{
    int id=ui->ID->text().toInt();
        QSqlQueryModel *verif=P.Recherche(id);
        msgBox= new QMessageBox(this);

                     if (verif!=nullptr)
                     {
                         ui->table->setModel((verif));
                         msgBox->setText("effectué");
                         msgBox->show();
           }
                     else
{
                         msgBox->setText("effectué");
                         msgBox->show();}
}

void gs_partenaire::on_actionstop_clicked()
{
    player->stop();
        vw->close();

}


QSqlQueryModel *Partenaire::tri1() // m sghir lel kbir
{
          QSqlQuery * q = new  QSqlQuery ();
                 QSqlQueryModel * model = new  QSqlQueryModel ();
                 q->prepare("SELECT * FROM DB_PARTENAIRE order by ID ");
                 q->exec();
                 model->setQuery(*q);
                 return model;
}
QSqlQueryModel *Partenaire::tri2() // m sghir lel kbir
{
          QSqlQuery * q = new  QSqlQuery ();
                 QSqlQueryModel * model = new  QSqlQueryModel ();
                 q->prepare("SELECT * FROM DB_PARTENAIRE order by NOM ");
                 q->exec();
                 model->setQuery(*q);
                 return model;
}
QSqlQueryModel *Partenaire::tri3() // m sghir lel kbir
{
          QSqlQuery * q = new  QSqlQuery ();
                 QSqlQueryModel * model = new  QSqlQueryModel ();
                 q->prepare("SELECT * FROM DB_PARTENAIRE order by PPA ");
                 q->exec();
                 model->setQuery(*q);
                 return model;
}

QSqlQueryModel *Partenaire::tri4() // m sghir lel kbir
{
          QSqlQuery * q = new  QSqlQuery ();
                 QSqlQueryModel * model = new  QSqlQueryModel ();
                 q->prepare("SELECT * FROM DB_PARTENAIRE order by DDC ");
                 q->exec();
                 model->setQuery(*q);
                 return model;
}
void gs_partenaire::on_rnom_clicked()
{

        Partenaire P;


        msgBox= new QMessageBox(this);


         ui->table->setModel(P.tri2());
         msgBox->setText("effectué");
         msgBox->show();

}

void gs_partenaire::on_rid_clicked()
{

    Partenaire P;

   msgBox= new QMessageBox(this);


     ui->table->setModel(P.tri1());
     msgBox->setText("effectué");
     msgBox->show();
}

void gs_partenaire::on_rppa_clicked()
{

    Partenaire P;

    msgBox= new QMessageBox(this);

     ui->table->setModel(P.tri3());
     msgBox->setText("effectué");
     msgBox->show();
}

void gs_partenaire::on_rddc_clicked()
{

    Partenaire P;

    msgBox= new QMessageBox(this);

     ui->table->setModel(P.tri4());
     msgBox->setText("effectué");
     msgBox->show();
}

void gs_partenaire::on_notif_clicked()
{

    Partenaire P;
    notif f;
    bool test = false;
    bool test2 = false;
    QMediaPlayer musicAdd;
    f.afficher();
    msgBox= new QMessageBox(this);

   musicAdd.setMedia(QUrl("C:/Users/user/Desktop/notification/bell.wav"));
    musicAdd.play();
    int num = ui->notif->text().toInt();
   // test = f.envoyer(num);
    //test2 = f.envoyer_s(num);
    if(test && test2)
    {
        ui->table->setModel(P.afficher());

        msgBox->setText("effectué");
        msgBox->show();

    }
    else
    {
        msgBox->setText("non effectué");
        msgBox->show();
    }

}

void gs_partenaire::on_pushButton_clicked()
{
    close();
    MainWindow *w ;
    w = new MainWindow (this);
    w->show();
}
