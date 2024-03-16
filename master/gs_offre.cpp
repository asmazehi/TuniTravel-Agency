#include "gs_offre.h"
#include "ui_gs_offre.h"

#include "mainwindow.h"
#include <QString>
#include<QTextStream>
#include<QTextDocument>
#include<QtPrintSupport/QPrinter>
#include<QtPrintSupport/QPrintDialog>
#include<QDialog>
#include<QSqlQuery>
#include <QMessageBox>
#include <QFileDialog>
#include <QFileInfo>
#include <QtCharts>
#include <QDesktopServices>
#include <QtCharts/QAreaSeries>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QPieSlice>
#include <QPieSeries>
#include <QChartView>
#include <QDesktopServices>
#include <QCalendarWidget>
#include <QDate>
#include <QApplication>
#include <QNetworkRequest>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QHttpPart>
#include "arduino_kd.h"



gs_offre::gs_offre(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gs_offre)
{
    ui->setupUi(this);

   /* click=new QSound("C:/Users/21654/Desktop/Atelier_Connexion/click.wav");

    ui->tab_offre->setModel(O.afficher());
    C.connect_arduino();
    connect(&timer, SIGNAL(timeout()), this,SLOT(check()));
    timer.start(20);*/
    int ret=C.connect_arduino(); // lancer la connexion à arduino
    switch(ret){
    case(0):qDebug()<< "arduino is available and connected to : "<< C.getarduino_port_name();
        break;
    case(1):qDebug() << "arduino is available but not connected to :" <<C.getarduino_port_name();
       break;
    case(-1):qDebug() << "arduino is not available";
    }
check();
}

gs_offre::~gs_offre()
{
    delete ui;
}


void gs_offre::on_pb_ajouter_clicked()
{
    //click->play();

    QWidget::setMouseTracking(true);
  QString id=ui->identifiant->text();
   QString prix=ui->prix->text();
  QString contenu=ui->contenu->text();
  QString nbredeplace=ui->place->text();
  QString dated=ui->dated->text();
   Offre O(id,prix,contenu,nbredeplace,dated);
   bool test=O.ajouter();
   if(test)
   {
       QMessageBox::information(nullptr, QObject::tr("OK"),
                                QObject::tr("Ajout effectué\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);
       ui->tab_offre->setModel(O.afficher());

   }
   else
       QMessageBox::critical(nullptr,QObject::tr("Not OK"),
                             QObject::tr("Ajout non effectué.\n"
                                         "Click Cancel to exit."), QMessageBox::Cancel);

}

//**********************

void gs_offre::on_pb_supp_clicked()
{
    click->play();

    Offre O1; O1.setid(ui->lineEdit_supp->text());
    bool test=O1.supprimer(O1.get_id());
    QMessageBox msgBox;
    if(test)
    {msgBox.setText("Suppression avec succes.");
     ui->tab_offre->setModel(O.afficher());
    }
    else
        msgBox.setText("Echec de suppression.");
    msgBox.exec();
}
//*************************


void gs_offre::on_pb_modifier_clicked()
{
    click->play();


        QString id=ui->identifiantm->text();
        QString prix=ui->prixm->text();
        QString contenu=ui->contenum->text();
        QString nbredeplace=ui->placem->text();
        QString dated=ui->datem->text();
        Offre O(id,prix,contenu,nbredeplace,dated);
         bool test=O.modifier(id);
            if(test)
            {
                ui->tab_offre->setModel(O.afficher());
                QMessageBox::information(nullptr, QObject::tr("ok"),QObject::tr("Modification avec succes.\n" "Click Close to exit."), QMessageBox::Close);
        }
            else
                QMessageBox::critical(nullptr, QObject::tr("not ok"),QObject::tr("Modification echoue.\n" "Click Close to exit."), QMessageBox::Close);
}

//***********************

void gs_offre::on_pushButton_2_clicked()
{
    click->play();

    QString strStream;
                QTextStream out(&strStream);

                const int rowCount = ui->tab_offre->model()->rowCount();
                const int columnCount = ui->tab_offre->model()->columnCount();

                out <<  "<html>\n"
                    "<head>\n"
                    "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                    <<  QString("<title>%1</title>\n").arg("col1")
                    <<  "</head>\n"
                    "<body bgcolor=#ffffff link=#5000A0>\n"
                    "<table border=1 cellspacing=0 cellpadding=2>\n";

                // headers
                out << "<thead><tr bgcolor=#f0f0f0>";
                for (int column = 0; column < columnCount; column++)
                    if (!ui->tab_offre->isColumnHidden(column))
                        out << QString("<th>%1</th>").arg(ui->tab_offre->model()->headerData(column, Qt::Horizontal).toString());
                out << "</tr></thead>\n";

                // data table
                for (int row = 0; row < rowCount; row++) {
                    out << "<tr>";
                    for (int column = 0; column < columnCount; column++) {
                        if (!ui->tab_offre->isColumnHidden(column)) {
                            QString data = ui->tab_offre->model()->data(ui->tab_offre->model()->index(row, column)).toString().simplified();
                            out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                        }
                    }
                    out << "</tr>\n";
                }
                out <<  "</table>\n"
                    "</body>\n"
                    "</html>\n";

                QTextDocument *document = new QTextDocument();
                document->setHtml(strStream);

                QPrinter printer;

                QPrintDialog *dialog = new QPrintDialog(&printer, NULL);
                if (dialog->exec() == QDialog::Accepted) {
                    document->print(&printer);
                }

                delete document;

}
//***************************

void gs_offre::on_pushButton_3_clicked()
{
    click->play();

    QString imageFile = QFileDialog ::getOpenFileName(0,"Select Image","/home/","Image Files (*.png)");

          QFileInfo info(imageFile);
        QFileInfo  filename = info.fileName(); //path de l'image

        QPixmap image (imageFile);
          ui->label_6->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );
          image = image.scaled(110,110,Qt::IgnoreAspectRatio,Qt::FastTransformation);
          ui->label_6->setPixmap(image);
          ui->label_6->show();

}
//********************************

void gs_offre::on_pushButton_4_clicked()
{
    click->play();

        QSqlQueryModel * model= new QSqlQueryModel();
                       model->setQuery("select * from OFFRE where CONTENU = 'Angleterre'");
                       float dispo1=model->rowCount();

                       model->setQuery("select * from OFFRE where CONTENU = 'Allemagne'");
                       float dispo=model->rowCount();

                       model->setQuery("select * from OFFRE where CONTENU = 'France'");
                       float dispo3=model->rowCount();

                       float total=dispo1+dispo+dispo3;
                           QString a=QString("Angleterre " +QString::number((dispo1*100)/total,'f',2)+"%" );
                           QString b=QString("Allemagne  " +QString::number((dispo*100)/total,'f',2)+"%" );
                           QString c=QString("France  " +QString::number((dispo3*100)/total,'f',2)+"%" );
                           QPieSeries *series = new QPieSeries();
                           series->append(a,dispo1);
                           series->append(b,dispo);
                           series->append(c,dispo3);
                       if (dispo1!=0)
                       {QPieSlice *slice = series->slices().at(0);
                           slice->setLabelVisible();
                           slice->setPen(QPen());}
                       if ( dispo!=0)
                       {
                           QPieSlice *slice1 = series->slices().at(1);
                           slice1->setLabelVisible();
                           slice1->setPen(QPen());
                       }
                       if (dispo3!=0)
                       {QPieSlice *slice = series->slices().at(2);
                           slice->setLabelVisible();
                           slice->setPen(QPen());}

                       QChart *chart = new QChart();


                       chart->addSeries(series);
                       chart->setTitle("Nombre: "+ QString::number(total));



                       QChartView *chartView = new QChartView(chart);
                       chartView->setRenderHint(QPainter::Antialiasing);
                       chartView->resize(1300,800);
                       chartView->show();


}
//******************************

void gs_offre::on_lineEdit_textChanged(const QString &arg1)
{
ui->tab_offre->setModel(O.afficher());
QString rech = ui->lineEdit->text();
O.recherche(ui->tab_offre,rech);

if (ui->lineEdit->text().isEmpty())
 {
 ui->tab_offre->setModel(O.afficher());
 }
}
//*******************************


void gs_offre::on_pushButton_whatsapp_clicked()
{

click->play();


}
//**********************************
void gs_offre::on_calendarwidget_selectionChanged()
{

    QString x=ui->calendarwidget->selectedDate().toString();
    ui->lineEdit_calendar_affichage->setText(x);
    ui->tableView_calendar->setModel(O.afficher_calendar(x));

}
//*********************************

void gs_offre::on_trii_toggled(bool checked)
{
    Offre off;
    if (checked==true)
    {
      ui->tab_offre->setModel(off.triid()) ;
    } else {        ui->tab_offre->setModel(off.afficher()) ; }


}



void gs_offre::on_Tric_toggled(bool checked)
{
    Offre off;
    if (checked==true)
    {
      ui->tab_offre->setModel(off.tric()) ;
    } else {        ui->tab_offre->setModel(off.afficher()) ; }


}

void gs_offre::on_trin_toggled(bool checked)
{
    Offre off;
    if (checked==true)
    {
      ui->tab_offre->setModel(off.trin()) ;
    } else {        ui->tab_offre->setModel(off.afficher()) ; }
}




void gs_offre::on_refreshButton_fire_clicked()
{
    click->play();

    QString data = C.read_from_arduino();
    QList<QString> dataList = data.split( "," );
    int result = dataList[dataList.length()-2].toInt();
   // qDebug()<<data;
    //qDebug()<<result;
    if (result == 1 )
        ui->label_9->setText("FIRE");
    else
        ui->label_9->setText("NO FIRE");
}




void gs_offre::saveInDB()
{


        QSqlQuery query;
            qDebug() << QDate::currentDate().toString();
            qDebug() << QTime::currentTime().toString();
            query.prepare("INSERT INTO FIREHISTORY(DATEE,TIME)"
                          "VALUES (:datee,:time);");
            query.bindValue(":datee", QDate::currentDate().toString());
            query.bindValue(":time",QTime::currentTime().toString());
            query.exec();
    }


void gs_offre::on_refreshButton_clicked()
{

}



void gs_offre::check(){
//    click->play();

    QString data = C.read_from_arduino();
    QList<QString> dataList = data.split( "," );
    int result ;
    if(dataList.length()<=2)
        result = 0;
    else
        result = dataList[1].toInt();
 // qDebug()<<data;
   qDebug()<<result;
    if (result == 1 ){
        ui->label_9->setText("FIRE");
    }
    else
        ui->label_9->setText("NO FIRE");
}
void gs_offre::on_pushButton_clicked()
{
    close();
    MainWindow *w ;
    w = new MainWindow (this);
    w->show();
}


