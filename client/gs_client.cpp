#include "gs_client.h"
#include "ui_gs_client.h"
#include "client.h"
#include "adresseemail.h"
#include <QMessageBox>
#include <QFile>
#include <QFileDialog>
#include <QIntValidator>
#include <QTextStream>
#include <QTextDocument>
#include <QPrintDialog>
#include <QPrinter>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>


gs_client::gs_client(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gs_client)
{
    ui->setupUi(this);
    client Etmp;
    ui->tablec->setModel(Etmp.afficher());
    client c;
       /*float nbreT=c.nbre_totale();
       float  nbreTA=c.nbre_totalea();
       float nbreTS=c.nbre_totales();
       float nbreTM=c.nbre_totalem();

       ui->ajoup->setNum((nbreTA*100)/nbreT);
       ui->updatep->setNum((nbreTM*100)/nbreT);
       ui->suppp->setNum((nbreTS*100)/nbreT);*/



       ui->lineEdit_cind->setValidator(new QIntValidator(0,999999999, this));
       ui->lineEdit_telephoned->setValidator(new QIntValidator(0,888888888, this));

       ui->lineEdit_nomd ->setValidator(new QRegExpValidator(QRegExp("[A-Za-z- _]+"), this ));
       ui->lineEdit_prenomd ->setValidator(new QRegExpValidator(QRegExp("[A-Za-z- _]+"), this ));
       ui->lineEdit_emaild ->setValidator(new QRegExpValidator(QRegExp("[A-Za-z-@. _]+"), this ));
       ui->lineEdit_adressed ->setValidator(new QRegExpValidator(QRegExp("[A-Za-z- _]+"), this ));



}

gs_client::~gs_client()
{
    delete ui;
}


void gs_client::on_Ajouterc_clicked()
{
    {
        int cin=ui->lineEdit_cind->text().toInt();
         QString nom=ui->lineEdit_nomd->text() ;
         QString prenom=ui->lineEdit_prenomd->text() ;
         QString email=ui->lineEdit_emaild->text() ;
         int telephone=ui->lineEdit_telephoned->text().toInt();
         QString adresse=ui->lineEdit_adressed->text() ;

         client c(cin,nom,prenom,email,telephone,adresse);

        if (c.ajouter())
        {QMessageBox msgBox;


           client Etmp;
           ui->tablec->setModel(Etmp.afficher());
           ui->His->setModel(Etmp.afficher_HIS());

           QMessageBox::information(this,"ajout","The document has been modified");
           /*
           msgBox.setText("The document has been modified.");
           msgBox.exec();
*/}
        else
        {
            QMessageBox msgBox;
            QMessageBox::information(this,"Ajout","leeee");

        }

    }
}


void gs_client::on_update_clicked()
{
    int cin=ui->lineEdit_cin->text().toInt();
    QString nom=ui->lineEdit_nom->text() ;
    QString prenom=ui->lineEdit_prenom->text() ;
    QString email=ui->lineEdit_email->text() ;
    int telephone=ui->lineEdit_telephone->text().toInt();
    QString adresse=ui->lineEdit_adresse->text() ;
    client c(cin,nom,prenom,email,telephone,adresse);

  QMessageBox msgBox;
  bool test=c.modifier(cin);

  if(test)
  {
      client Etmp;
          ui->tablec->setModel(Etmp.afficher());
          ui->His->setModel(Etmp.afficher_HIS());

          QMessageBox::information(this,"Modifier","cbn");

                           /*   ui->lineEdit_cin->clear();
                              ui->lineEdit_nom->clear();
                              ui->lineEdit_prenom->clear();
                              ui->lineEdit_email->clear();
                              ui->lineEdit_telephone->clear();
                              ui->lineEdit_adresse->clear();*/
   }
  else
      QMessageBox::information(this,"Modifier","Leeeeee");
}

void gs_client::on_suppc_clicked()
{
    client c;

                int num = ui->cimsupp->text().toInt();
                bool test=c.supprimer(num);
                    if(test)
                    {
                        ui->tablec->setModel(c.afficher());
                        ui->His->setModel(c.afficher_HIS());

                        QMessageBox::information(this,"suppression","The document has been modified");


                    }
                   else
                    {
                        QMessageBox msgBox;
                        QMessageBox::information(this,"suppression","leeee");
                    }
}

void gs_client::on_rechc_clicked()
{
    client Etmp;

    int id=ui->lineRech->text().toInt();
    ui->tablec->setModel(Etmp.recherche(id));
    ui->His->setModel(Etmp.afficher_HIS());


}

void gs_client::on_pushButton_clicked()
{
    client Etmp;
    ui->tablec->setModel(Etmp.afficher());

}

void gs_client::on_radioButton_6_toggled(bool checked)
{
    client Etmp;
  if(checked==true)
  {
      ui->tablec->setModel(Etmp.tri_cin());
      ui->His->setModel(Etmp.afficher_HIS());

  }
  else {
      ui->tablec->setModel(Etmp.afficher());
      }

}

void gs_client::on_radioButton_toggled(bool checked)
{
    client Etmp;
  if(checked==true)
  {
      ui->tablec->setModel(Etmp.tri_nom());
      ui->His->setModel(Etmp.afficher_HIS());

  }
  else {
      ui->tablec->setModel(Etmp.afficher());
      }
}


void gs_client::on_radioButton_2_toggled(bool checked)
{
    client Etmp;
  if(checked==true)
  {
      ui->tablec->setModel(Etmp.tri_prenom());
      ui->His->setModel(Etmp.afficher_HIS());

  }
  else {
      ui->tablec->setModel(Etmp.afficher());
      }
}


void gs_client::on_radioButton_3_toggled(bool checked)
{
    client Etmp;
  if(checked==true)
  {
      ui->tablec->setModel(Etmp.tri_email());
      ui->His->setModel(Etmp.afficher_HIS());

  }
  else {
      ui->tablec->setModel(Etmp.afficher());
      }
}



/*void gs_client::on_ajoutm_clicked()
{

    int cin=ui->cina->text().toInt();
     QString add=ui->emaila->text() ;
     QString password=ui->passa->text() ;

     adresseemail a (cin,add,password);

    if (a.ajouterE())
    {QMessageBox msgBox;


       adresseemail Etmp;
       ui->emailss->setModel(Etmp.afficherE());
       ui->His->setModel(Etmp.afficher_HI());

       QMessageBox::information(this,"ajout","The document has been modified");
      }
    else
    {
        QMessageBox msgBox;
        QMessageBox::information(this,"Ajout","leeee");

    }


}*/

void gs_client::on_pdf_clicked()
{
    QString strStream;
               QTextStream out(&strStream);
               const int rowCount = ui->tablec->model()->rowCount();
               const int columnCount =ui->tablec->model()->columnCount();


               out <<  "<html>\n"
                       "<head>\n"
                       "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                       <<  QString("<title>%1</title>\n").arg("eleve")
                       <<  "</head>\n"
                       "<body bgcolor=#CFC4E1 link=#5000A0>\n"
                           "<h1>Liste des Evenements</h1>"

                           "<table border=1 cellspacing=0 cellpadding=2>\n";

               // headers
                   out << "<thead><tr bgcolor=#f0f0f0>";
                   for (int column = 0; column < columnCount; column++)
                       if (!ui->tablec->isColumnHidden(column))
                           out << QString("<th>%1</th>").arg(ui->tablec->model()->headerData(column, Qt::Horizontal).toString());
                   out << "</tr></thead>\n";
                   // data table
                      for (int row = 0; row < rowCount; row++) {
                          out << "<tr>";
                          for (int column = 0; column < columnCount; column++) {
                              if (!ui->tablec->isColumnHidden(column)) {
                                  QString data = ui->tablec->model()->data(ui->tablec->model()->index(row, column)).toString().simplified();
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


       //QTextDocument document;
       //document.setHtml(html);
       QPrinter printer(QPrinter::PrinterResolution);
       printer.setOutputFormat(QPrinter::PdfFormat);
       printer.setOutputFileName("C:/QT pdf files/mypdf_file_employee.pdf");
       document->print(&printer);

    }


/*void gs_client::on_Supph_clicked()
{
    client c ;

                int num = ui->supphi->text().toInt();
                bool test=c.supprimerh(num);
                    if(test)
                    {
                        ui->His->setModel(c.afficher_HIS());

                        QMessageBox::information(this,"suppression","Historique supprimé");


                    }
                   else
                    {
                        QMessageBox msgBox;
                        QMessageBox::information(this,"suppression","leeee");
                    }
}
*/

void gs_client::on_pushButton_3_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Excel file"), qApp->applicationDirPath (),
                                                    tr("Excel Files (*.xls)"));
    if (fileName.isEmpty())
        return;

    ExportExcelObject obj(fileName, "mydata", ui->tablec);

    //colums to export
    obj.addField(0, "entier", "char(20)");
    obj.addField(1, "reel", "char(20)");
    obj.addField(2, "combobox", "char(20)");
    obj.addField(3, "lineedit", "char(20)");
    obj.addField(4, "textedit", "char(20)");
    obj.addField(5, "dateedit", "char(20)");
    obj.addField(5, "timeedit", "char(20)");


    int retVal = obj.export2Excel();
    if( retVal > 0)
    {
        QMessageBox::information(this, tr("Done"),
                                 QString(tr("%1 records exported!")).arg(retVal)
                                 );
    }
}




void gs_client::stat_his()
{
    QSqlQuery q1,q2,q3,q4,q5;
    QSqlQuery query;

        qreal tot=0,c1=0,c2=0,c3=0,c4=0;
        QString etat1="AJOUTER";
        query.bindValue(":ETAT_H",etat1);


        QString etat2="RECHERCHE";
        query.bindValue(":ETAT_H",etat2);

        QString etat3="SUPPRIMER";
        query.bindValue(":ETAT_H",etat3);

        QString etat4="MODIFIER";
        query.bindValue(":ETAT_H",etat4);


        q1.prepare("SELECT * FROM CLIENT_HIS");
        q1.exec();

        q2.prepare("select * from CLIENT_HIS where ETAT_H='"+etat1+"' ");
        q2.exec();

        q3.prepare("select * from CLIENT_HIS where ETAT_H='"+etat2+"' ");
        q3.exec();

        q4.prepare("select * from CLIENT_HIS where ETAT_H='"+etat3+"' ");
        q4.exec();

        q5.prepare("select * from CLIENT_HIS where ETAT_H='"+etat4+"' ");
        q5.exec();


        while (q1.next()){tot++;}
        while (q2.next()){c1++;}
        while (q3.next()){c2++;}
        while (q4.next()){c3++;}
        while (q5.next()){c4++;}


        c1=(c1*100)/tot;
        c2=(c2*100)/tot;
        c3=(c3*100)/tot;
        c4=(c4*100)/tot;


        // Define slices and percentage of whole they take up
        QPieSeries *series = new QPieSeries();
        series->append("Ajouter",c1);
        series->append("Rechercher",c2);
        series->append("Supprimer",c3);
        series->append("Modifier",c4);




        // Create the chart widget
        QChart *chart = new QChart();

        // Add data to chart with title and show legend
        chart->addSeries(series);
        chart->legend()->show();


        // Used to display the chart

        m_chartView = new QChartView(chart,ui->label_stat);
        m_chartView->setRenderHint(QPainter::Antialiasing);
        m_chartView->setMinimumSize(280,280);
        m_chartView->show();
}



