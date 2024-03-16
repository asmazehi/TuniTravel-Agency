
#include "ui_gs_employee.h"

#include <QMessageBox>

#include "login.h"

#include "gs_employee.h"

#include "employee.h"

#include"todolist_e.h"

#include "arduino.h"

//*************
#include <QIntValidator>
#include <QTextStream>
#include <QTextDocument>
#include <QPrintDialog>
#include <QPrinter>

//********
#include <QtWidgets/QPushButton>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFontDialog>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
//************************************
gs_employee::gs_employee(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gs_employee)
{
    ui->setupUi(this);
  // supprimer_task s;
    QPixmap pix("C:/Users/dell/Documents/NOTION/2eme année (2-A-27)/subjects/Projet C++/uni-removebg-preview");                  //el taswira eli bich t7otha fil login.ui (pt2.)
    ui->label_signin_pic->setPixmap(pix.scaled(50,50,Qt::KeepAspectRatio));                                                      //el taswira eli bich t7otha fil login.ui (pt3.)

    ui->tab_employee->setModel(Etmp.afficher());                                                                                    //Affichage de liste des employee
    ui->tab_employee_2->setModel(Etmp.afficher_task());
   //

///
    todolist_e e;
    float nbreT=e.nbre_totale();
    float  nbreTP=e.nbre_totalep();
    float nbreTD=e.nbre_totaled();

    ui->label_statusp_e->setNum((nbreTP*100)/nbreT);
    ui->label_statusd_e->setNum((nbreTD*100)/nbreT);
    ui->label_statust_e->setNum(nbreT);


    QSqlQueryModel* model=new QSqlQueryModel();         //*********************combo box ID affichage
    model->setQuery("select ID_E from DB_EMPLOYEE ");
    ui->comboBox_id_mod->setModel(model);
    ui->comboBox_id_mod_2->setModel(model);
   ui->comboBox_id_mod_3->setModel(model);

   QSqlQueryModel* model2=new QSqlQueryModel();         //*********************combo box ID affichage
   model2->setQuery("select ID_TASK_E from DB_EMPLOYEE_TODOLIST ");
   ui->comboBox_id_task_1->setModel(model2);
   ui->comboBox_id_task_2->setModel(model2);


   stat_todolist();


}

//***********************************


gs_employee::~gs_employee()
{
    delete ui;
}


//************************************

void gs_employee::on_pushButton_ajouter_e_clicked()
{

    //Récuperation des information saisies dans les champs
    QString nom=ui->lineEdit_nom_e->text();
    QString prenom=ui->lineEdit_prenom_e->text();
    int cin=ui->lineEdit_cin_e->text().toInt();
    int id=ui->lineEdit_id_e->text().toInt();
    QString motpass=ui->lineEdit_motpass_e->text();
    int salaire=ui->lineEdit_salaire_e->text().toInt();
    int tel=ui->lineEdit_numerotel_e->text().toInt();
    int heure=ui->lineEdit_heure_e->text().toInt();

    employee E(nom,prenom,cin,id,motpass,tel,salaire,heure);

   msgBox= new QMessageBox(this);
    if(E.ajouter())
    {


         msgBox->setText("effectué");
           ui->lineEdit_nom_e->clear();
           ui->lineEdit_prenom_e->clear();
           ui->lineEdit_cin_e->clear();
           ui->lineEdit_id_e->clear();
           ui->lineEdit_motpass_e->clear();
           ui->lineEdit_salaire_e->clear();
           ui->lineEdit_numerotel_e->clear();
           ui->lineEdit_heure_e->clear();

         ui->tab_employee->setModel(Etmp.afficher());


         QSqlQueryModel* model=new QSqlQueryModel();         //*********************combo box ID affichage
         model->setQuery("select ID_E from DB_EMPLOYEE ");
         ui->comboBox_id_mod->setModel(model);
         ui->comboBox_id_mod_2->setModel(model);
        ui->comboBox_id_mod_3->setModel(model);

        QSqlQueryModel* model2=new QSqlQueryModel();         //*********************combo box ID affichage
        model2->setQuery("select ID_TASK_E from DB_EMPLOYEE_TODOLIST ");
        ui->comboBox_id_task_1->setModel(model2);
        ui->comboBox_id_task_2->setModel(model2);


         msgBox->show();

    }
    else
   {

     msgBox->setText("non effectué");
     msgBox->show();
    }
}
//************************************
void gs_employee::on_pushButton_supprimer_e_clicked()
{
    employee E;
    E.setId(ui->comboBox_id_mod_2->currentText().toInt());
    bool test=E.supprimer(E.getId());
    msgBox= new QMessageBox(this);
    if(test)
    {

        msgBox->setText("effectué");
       // ui->lineEdit_idsupp_e->clear();
        ui->tab_employee->setModel(Etmp.afficher());
         msgBox->show();

     }
    else
        msgBox->setText("non effectué");
        msgBox->show();
}
//************************************


void gs_employee::on_pushButton_modifier_e_clicked()
{
     int id=ui->comboBox_id_mod->currentText().toInt();
    QString nom=ui->lineEdit_nommod_e->text();
    QString prenom=ui->lineEdit_prenommod_e->text();
    int cin=ui->lineEdit_cinmod_e->text().toInt();
    int salaire=ui->lineEdit_salairemod_e->text().toInt();
    int tel=ui->lineEdit_numerotelmod_e->text().toInt();
    int heure=ui->lineEdit_heuremod_e->text().toInt();

 //   QString motpass=ui->lineEdit_motpassmod_e->text();


    employee E(nom,prenom,cin,tel,salaire,heure);


            msgBox= new QMessageBox(this);
            bool test=E.modifier(id);
            if(test)
            {
                //ui->lineEdit_idmod_e->clear();
                 ui->lineEdit_nommod_e->clear();
                  ui->lineEdit_prenommod_e->clear();
                ui->lineEdit_cinmod_e->clear();
                ui->lineEdit_salairemod_e->clear();
              ui->lineEdit_numerotelmod_e->clear();
          ui->lineEdit_heuremod_e->clear();

                ui->tab_employee->setModel(Etmp.afficher());
                msgBox->setText("effectué");
                msgBox->show();
              }
            else
            {

            msgBox->setText("non effectué");
            msgBox->show();
            }

}
//************************************
/*void gs_employee::on_pushButton_clicked()    //rechercher
{
    int id=ui->lineEdit_idrecherche_e->text().toInt();

    ui->tab_employee->setModel(Etmp.recherche(id));

}*/
//************************************
void gs_employee::on_pushButton_2_clicked()  //button pour actualiser la liste apres rechercher
{
      ui->tab_employee->setModel(Etmp.afficher());
}

//************************************
void gs_employee::on_radioButton_trinom_e_toggled(bool checked)  //button radio  pour actualiser la liste apres rechercher ( ki tinzel 3ala "aller au slaut"-->"toggled" moch "clicked)
{
    employee Etmp;
    if(checked==true)
    {
        ui->tab_employee->setModel(Etmp.tri_nom());
    }
    else {
        ui->tab_employee->setModel(Etmp.afficher());
        }
}
//************************************
void gs_employee::on_radioButton_trisalaire_e_toggled(bool checked)
{
    employee Etmp;
    if(checked==true)
    {
        ui->tab_employee->setModel(Etmp.tri_salaire());
    }

     else {
              ui->tab_employee->setModel(Etmp.afficher());
        }
}
//************************************
void gs_employee::on_radioButton_triheure_e_toggled(bool checked)
{
      employee Etmp;
    if(checked==true)
    {
     ui->tab_employee->setModel(Etmp.tri_heure());
    }

        else
    {
        ui->tab_employee->setModel(Etmp.afficher());
        }
}
//************************************
void gs_employee::on_pushButton_modifier_metier_clicked()
{

    int id=ui->comboBox_id_mod_3->currentText().toInt();
    QString motpass=ui->lineEdit_motpassa_e->text();
    QString motpassn=ui->lineEdit_motpassn_e->text();
    QString motpassnv=ui->lineEdit_motpassnv_e->text();

    employee E(motpass);

   msgBox= new QMessageBox(this);
    if(motpassn==motpassnv)
    {

        if(E.modifier_mot_passe(id,motpass,motpassn))
        {
         msgBox->setText("effectué");
         msgBox->show();
        }
        else
        {
            msgBox->setText("non effectué");
            msgBox->show();
        }

    }
    else
   {
    msgBox->setText("verifier votre JDID mot de passe !");
    msgBox->show();
    }

}
//************************************

/*

void gs_employee::on_pushButton_ajoutertask_e_3_clicked()
{
    todolist_e e;


    int nbreT=e.nbre_totale(); //Hedha
    int nbreTP=e.nbre_totalep();
    int nbreTD=e.nbre_totaled();
    ui->tab_employee_2->setModel(Etmp.afficher_task());


    ui->label_statusp_e->setNum((nbreTP*100)/nbreT);
    ui->label_statusd_e->setNum((nbreTD*100)/nbreT);
    ui->label_statust_e->setNum(nbreT);


}
*/
/*
void gs_employee::on_pushButton_modifiertask_e_clicked()
{

}
*/





void gs_employee::on_pushButton_3_clicked()
{
                QString strStream;
                QTextStream out(&strStream);
                const int rowCount = ui->tab_employee->model()->rowCount();
                const int columnCount =ui->tab_employee->model()->columnCount();


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
                        if (!ui->tab_employee->isColumnHidden(column))
                            out << QString("<th>%1</th>").arg(ui->tab_employee->model()->headerData(column, Qt::Horizontal).toString());
                    out << "</tr></thead>\n";
                    // data table
                       for (int row = 0; row < rowCount; row++) {
                           out << "<tr>";
                           for (int column = 0; column < columnCount; column++) {
                               if (!ui->tab_employee->isColumnHidden(column)) {
                                   QString data = ui->tab_employee->model()->data(ui->tab_employee->model()->index(row, column)).toString().simplified();
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





void gs_employee::on_lineEdit_idrecherche_e_textEdited(const QString &arg1)
{

    QString id=ui->lineEdit_idrecherche_e->text();

    ui->tab_employee->setModel(Etmp.recherche(id));
    if (id=="")
    {
        ui->tab_employee->setModel(Etmp.afficher());

    }

}

void gs_employee::on_pushButton_ajoutertask_e_2_clicked()
{

todolist_e e;

int id_task=e.nbre_totale()+1;
    //int id_task=ui->lineEdit_id_task->text().toUInt();
     QString employee_task=ui->lineEdit_employee_task->text();
     QString etat_task=ui->comboBox_etatajout->currentText();
     QString task=ui->lineEdit_task->text();
     todolist_e t(id_task,employee_task,task,etat_task);

    // gs_employee e;
     msgBox= new QMessageBox(this);
      if(t.ajouter_task())
      {


           msgBox->setText("effectué");
   // ui->tab_employee->setModel(Etmp.afficher_task());
           msgBox->show();



           QSqlQueryModel* model2=new QSqlQueryModel();         //*********************combo box ID affichage
           model2->setQuery("select ID_TASK_E from DB_EMPLOYEE_TODOLIST ");
           ui->comboBox_id_task_1->setModel(model2);
           ui->comboBox_id_task_2->setModel(model2);


           int nbreT=e.nbre_totale(); //Hedha
           int nbreTP=e.nbre_totalep();
           int nbreTD=e.nbre_totaled();
           ui->tab_employee_2->setModel(Etmp.afficher_task());


           ui->label_statusp_e->setNum((nbreTP*100)/nbreT);
           ui->label_statusd_e->setNum((nbreTD*100)/nbreT);
           ui->label_statust_e->setNum(nbreT);



      }
      else
     {

       msgBox->setText("non effectué");
       msgBox->show();
      }
      stat_todolist();

}

void gs_employee::on_pushButton_supprimer_e_2_clicked()  //mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm
{

    //SUpprimer
    todolist_e E;
    E.setId_task(ui->comboBox_id_task_1->currentText().toInt());
    bool test=E.supprimer_task(E.getId_task());
    msgBox= new QMessageBox(this);
    if(test)
    {

        msgBox->setText("effectué");
        msgBox->show();


        todolist_e e;


        QSqlQueryModel* model2=new QSqlQueryModel();         //*********************combo box ID affichage
        model2->setQuery("select ID_TASK_E from DB_EMPLOYEE_TODOLIST ");
        ui->comboBox_id_task_1->setModel(model2);
        ui->comboBox_id_task_2->setModel(model2);

        int nbreT=e.nbre_totale(); //Hedha
        int nbreTP=e.nbre_totalep();
        int nbreTD=e.nbre_totaled();
        ui->tab_employee_2->setModel(Etmp.afficher_task());


        ui->label_statusp_e->setNum((nbreTP*100)/nbreT);
        ui->label_statusd_e->setNum((nbreTD*100)/nbreT);
        ui->label_statust_e->setNum(nbreT);


     }
    else
    {
        msgBox->setText("non effectué");
        msgBox->show();
    }
    stat_todolist();
}

void gs_employee::on_pushButton_modifier_e_2_clicked() //mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm
{
    int id=ui->comboBox_id_task_1->currentText().toInt();
    QString etat=ui->comboBox_e->currentText();

    todolist_e e(etat);


    msgBox= new QMessageBox(this);
    bool test=e.modifier_task(id);
    if(test)
    {

       // ui->tab_employee->setModel(Etmp.afficher());
        msgBox->setText("effectué");
        msgBox->show();


        QSqlQueryModel* model2=new QSqlQueryModel();         //*********************combo box ID affichage
        model2->setQuery("select ID_TASK_E from DB_EMPLOYEE_TODOLIST ");
        ui->comboBox_id_task_1->setModel(model2);
        ui->comboBox_id_task_2->setModel(model2);

        todolist_e e;


        int nbreT=e.nbre_totale(); //Hedha
        int nbreTP=e.nbre_totalep();
        int nbreTD=e.nbre_totaled();
        ui->tab_employee_2->setModel(Etmp.afficher_task());


        ui->label_statusp_e->setNum((nbreTP*100)/nbreT);
        ui->label_statusd_e->setNum((nbreTD*100)/nbreT);
        ui->label_statust_e->setNum(nbreT);


      }
    else
    {

    msgBox->setText("non effectué");
    msgBox->show();
    }
    stat_todolist();
}


/*void gs_employee::on_lineEdit_idrecherchetodo_e_textEdited(const QString &arg1)
{
    int id=ui->lineEdit_idrecherche_e->text().toInt();
    ui->tab_employee->setModel(Etmp.recherche(id));
    if (id==NULL)
    {
        ui->tab_employee->setModel(Etmp.afficher());

    }

}*/




void gs_employee::stat_todolist()
{
    QSqlQuery q1,q2,q3,q4;
    QSqlQuery query;

        qreal tot=0,c1=0,c2=0;/*c3=0*/
        QString etat_task1="in progress";
        query.bindValue(":ETAT_TASK_E",etat_task1);


        QString etat_task2="done";
        query.bindValue(":ETAT_TASK_E",etat_task2);



        q1.prepare("SELECT * FROM DB_EMPLOYEE_TODOLIST");
        q1.exec();

        q2.prepare("select * from DB_EMPLOYEE_TODOLIST where ETAT_TASK_E='"+etat_task1+"' ");
        q2.exec();

        q3.prepare("select * from DB_EMPLOYEE_TODOLIST where ETAT_TASK_E='"+etat_task2+"' ");
        q3.exec();

        while (q1.next()){tot++;}
        while (q2.next()){c1++;}
        while (q3.next()){c2++;}


        c1=(c1*100)/tot;
        c2=(c2*100)/tot;


        // Define slices and percentage of whole they take up
        QPieSeries *series = new QPieSeries();
        series->append("In Progress",c1);
        series->append("Done",c2);




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
