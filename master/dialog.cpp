#include "dialog.h"
#include "ui_dialog.h"
#include "fourniture.h"
#include"mainwindow.h"
#include<QMessageBox>
//#include "connection.h"
#include <QTableView>
#include "mainwindow.h"
#include <QMessageBox>
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->tableView->setModel(Etmp.afficher());
   // ui->Lreference->setValidator( new QIntValidator(0, 99999999, this));
    ui->Lprix->setValidator(new QIntValidator(0,9999999,this));
    ui->Lquantite->setValidator(new QIntValidator(0,9999,this));
    ui->Lnom->setValidator(new QRegExpValidator(QRegExp("[a-z]*")));

    ui->Lfournisseur->setValidator(new QRegExpValidator(QRegExp("[a-z]*")));
    ui->tableView2->setModel(fourniture().afficherenpanne());
    QSqlQuery q,q1,q2,q3,q4,q5;

        q.exec("Select * from DB_FOURNITURE");
        int tot=0;
        while (q.next())
            tot++;
       qDebug() << "total =" << tot;
        q1.prepare("Select * from DB_FOURNITURE where etat = :nom ");
        q1.bindValue(":nom","Bonne");
        q1.exec();

        int tot_don=0;
        while (q1.next())
            tot_don++;
     qDebug() << "pourcentage don =" << tot_don;
        qreal pour_don=(tot_don*100)/tot;

        q2.prepare("Select * from DB_FOURNITURE where etat = :nom ");
        q2.bindValue(":nom","En panne");
        q2.exec();
        int tot_event=0;
        while (q2.next())
            tot_event++;

        qreal pour_event=(tot_event*100)/tot;





        QPieSeries *series = new QPieSeries();
         series->append("Bonne",pour_don);


         series->append("En panne",pour_event);

         QPieSlice *slice0= series->slices().at(0);
         slice0->setLabelVisible();
         QPieSlice *slice1 = series->slices().at(1);

         slice1->setLabelVisible();

         slice1->setBrush(Qt::green);


         QChart *chart = new QChart();
         chart->addSeries(series);
         chart->setTitle("Etat des fournitures");


         QChartView *chartview = new QChartView(chart,ui->widget);
         chartview->resize(500,400);
         chartview->setRenderHint(QPainter::Antialiasing);
/*
    int ret=A.connect_arduino(); // lancer la connexion à arduino
            switch(ret){
            case(0):qDebug()<< "arduino is available and connected to : "<< A.getarduino_port_name();
                break;
            case(1):qDebug() << "arduino is available but not connected to :" <<A.getarduino_port_name();
               break;
            case(-1):qDebug() << "arduino is not available";
            }
             QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label())); // permet de lancer
             //le slot update_label suite à la reception du signal readyRead (reception des données).
*/
}
/*

void Dialog::update_label()

{
data="";
while(A.getdata().size()<5)
{
     data=A.read_from_arduino();
     break;
}


  if(data!="")
  {qDebug()<<"id :"+data;
      if(A.chercherid(data)!=-1)
      {
QMessageBox::information(this,"search","fourniture existante");
          qDebug()<<"valide";



      }
      else
      {   qDebug()<<"invalide"; ;
      QMessageBox::information(this,"search","fourniture inexistante");}


  }
}
*/
Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_PBajouter_clicked()
{
  msgBox= new QMessageBox(this);



    QString reference=ui->Lreference->text() ;
        QString nom=ui->Lnom->text();
        float prix=ui->Lprix->text().toFloat();
        int quantite=ui->Lquantite->text().toInt();
        QString etat=ui->Letat->currentText();
        QString fournisseur=ui->Lfournisseur->text();
        QString image=ui->chemin->text();
        fourniture EP(reference,nom,prix,quantite,etat,fournisseur,image);

        bool test=EP.ajouter();
            if(test)
            {
                ui->tableView->setModel(Etmp.afficher());
                 ui->tableView2->setModel(fourniture().afficherenpanne());

                 msgBox->setText("effectué");
                 msgBox->show();
                /*QMessageBox::information(nullptr, QObject::tr("database is open"),
                            QObject::tr("ajout effectué.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);*/

        }
           else

              msgBox->setText("non effectué");
              msgBox->show();
              /*  QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                            QObject::tr("ajout non effectué.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);*/

}

void Dialog::on_PBsupprimer_clicked()
{
    QString reference=ui->Lreference->text() ;
        //bool test=false;
        //if(Etmp.rechercher(reference))
        bool test=Etmp.supprimer(reference);

        if(test)
        {
            ui->tableView->setModel(Etmp.afficher());
            QMessageBox::information(nullptr, QObject::tr("OK"),
                        QObject::tr("suppression effectué.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

    }
       else
            QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                        QObject::tr("suppression non effectué.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

        ui->Lreference->clear();
        ui->Lnom->clear();
        ui->Lprix->clear();
        ui->Lquantite->clear();
        ui->Letat->clear();
        ui->Lfournisseur->clear();
        ui->label_img->clear();
}

void Dialog::on_PBmodifier_clicked()
{
    QString reference=ui->Lreference->text();
    int prix=ui->Lprix->text().toInt();
    int quantite=ui->Lquantite->text().toInt();
    QString nom=ui->Lnom->text();
    QString etat=ui->Letat->currentText();
    QString fournisseur=ui->Lfournisseur->text();
    QString image=ui->chemin->text();
    fourniture f(reference,nom,prix,quantite,etat,fournisseur,image);
       bool test=f.modifier(reference);


            if(test)
            {
                ui->tableView->setModel(Etmp.afficher());
                 ui->tableView2->setModel(fourniture().afficherenpanne());
                QMessageBox::information(nullptr, QObject::tr("database is open"),
                            QObject::tr("modification effectué.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);

        }
           else
                QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                            QObject::tr("modification non effectué.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);

            ui->Lreference->clear();
            ui->Lnom->clear();
            ui->Lprix->clear();
            ui->Lquantite->clear();
            ui->Letat->clear();
            ui->Lfournisseur->clear();
}


void Dialog::on_pushButton_clicked()
{
    QMessageBox msgbox;
    QByteArray byte;
        QString filename= QFileDialog::getOpenFileName(this,tr("Selectionnez"),"",tr("Images(*.png *.jpeg *.jpg)"));
        QFile file(filename);
        if(QString::compare(filename, QString())!=0)
        {
           QImage img;
            bool valid = img.load(filename);

            if (valid)
           {

               img=img.scaledToWidth(ui->label_img->width(), Qt::SmoothTransformation);
                ui->label_img->setPixmap(QPixmap::fromImage(img));
                ui->chemin->setText(filename);
            }
            else
                msgbox.setText("failed");
       }
        if(file.open(QIODevice::ReadOnly))
            {
                byte = file.readAll();
                file.close();
            }
             QMessageBox :: critical(this,"Error",filename);
             QSqlQuery query;
             query.prepare("INSERT INTO DB_FOURNITURE(IMAGE)" "VALUES (:IMAGE)");
             query.bindValue(":LOGO", byte, QSql::In | QSql::Binary);
}

void Dialog::on_pdf_clicked()
{
    fourniture f;
        bool test=false;
            test=f.genererPDF();
            if(test)

                {
                ui->tableView->setModel(f.afficher());
                QMessageBox::information(nullptr, QObject::tr("créé"),

                                    QObject::tr(" PDF créé.\n"

                                                "Click Cancel to exit."), QMessageBox::Cancel);}
            else

                {

                    QMessageBox::critical(nullptr, QObject::tr("non créé"),

                                QObject::tr("PDF non créé !.\n"

                                            "Click Cancel to exit."), QMessageBox::Cancel);



        }
}


void Dialog::on_qua_toggled(bool checked)
{
    fourniture f;
    if (checked == true){
                  ui->tableView_2->setModel(f.trierparqua());
              } else {
                   ui->tableView_2->setModel(f.afficher());
              }
}

void Dialog::on_ref_toggled(bool checked)
{
    fourniture f;
    if (checked == true){
                  ui->tableView_2->setModel(f.trierparref());
              } else {
                   ui->tableView_2->setModel(f.afficher());
              }
}


void Dialog::on_nom_toggled(bool checked)
{
    fourniture f;
    if (checked == true){
                  ui->tableView_2->setModel(f.trierparnom());
              } else {
                   ui->tableView_2->setModel(f.afficher());
              }
}


void Dialog::on_pri_toggled(bool checked)
{
    fourniture f;
    if (checked == true){
                  ui->tableView_2->setModel(f.trierparpri());
              } else {
                   ui->tableView_2->setModel(f.afficher());
              }
}

void Dialog::on_eta_toggled(bool checked)
{
    fourniture f;
    if (checked == true){
                  ui->tableView_2->setModel(f.trierpareta());
              } else {
                   ui->tableView_2->setModel(f.afficher());
              }
}

void Dialog::on_fou_toggled(bool checked)
{
    fourniture f;
    if (checked == true){
                  ui->tableView_2->setModel(f.trierparfou());
              } else {
                   ui->tableView_2->setModel(f.afficher());
              }
}


void Dialog::on_pb_rech_clicked()
{  fourniture f;
    QString reference = ui->Lreference->text() ;
       bool test=f.rechercheparref(reference);
        if(test)
        {

            QMessageBox::information(nullptr, QObject::tr("reference existe"),
                        QObject::tr("reference existe.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
            ui->tableView->setModel( f. afficherparref(reference));//refresh

            //ui->tableView->clear();

        }
        else
            QMessageBox::critical(nullptr, QObject::tr("reference n'existe pas"),
                        QObject::tr("reference n'existe pas !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
           // ui->tableView->clear();
}

void Dialog::on_pushButton_2_clicked()
{
    QString id=ui->id->text();
    QString date=ui->date->text();
    QSqlQuery query;
    query.prepare("update  DB_FOURNITURE set date_reparation = to_date(:datee,'dd/MM/yyyy') where reference = :id");
    query.bindValue(":id",id);
    query.bindValue(":datee",date);
    query.exec();
 ui->tableView2->setModel(fourniture().afficherenpanne());
}

void Dialog::on_pushButton_3_clicked()
{
    QSqlQuery q;
    q.prepare("update DB_FOURNITURE set etat = :etat WHERE date_reparation < sysdate");
    q.bindValue(":etat","Bonne");
    q.exec();
    ui->tableView2->setModel(fourniture().afficherenpanne());
}

void Dialog::on_pushButton_4_clicked()
{
    close();
    MainWindow *w ;
    w = new MainWindow (this);
    w->show();
}
