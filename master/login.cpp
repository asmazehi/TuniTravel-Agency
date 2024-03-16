#include "login.h"
#include "ui_login.h"
#include <QMessageBox>              //el conection mta3 el oracle (pt3.)
#include <QPixmap>                  //el taswira eli bich t7otha fil login.ui (pt1.)
#include "employee.h"
#include "arduino.h"

#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QDebug>


login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{

    ui->setupUi(this);

   QPixmap pix("C:/Users/dell/Documents/NOTION/2eme année (2-A-27)/subjects/Projet C++/uni-removebg-preview");                           //el taswira eli bich t7otha fil login.ui (pt2.)
   ui->label_signin_pic->setPixmap(pix.scaled(200,200,Qt::KeepAspectRatio));                                                              //el taswira eli bich t7otha fil login.ui (pt3.)
  // ui->tableWidget_pass->setModel(Etmp.afficher_m());


  int ret=A.connect_arduino_a(); // lancer la connexion à arduino
   switch(ret){
   case(0):qDebug()<< "arduino is available and connected to : "<< A.getarduino_port_name();
       break;
   case(1):qDebug() << "arduino is available but not connected to :" <<A.getarduino_port_name();
      break;
   case(-1):qDebug() << "arduino is not available";
   }
    QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label())); // permet de lancer
    //le slot update_label suite à la reception du signal readyRead (reception des données).

}

login::~login()
{
    delete ui;
}

void login::update_label()
{

data=A.read_from_arduino();
if(somme.size()!=4)
somme+=data;

 ui->label_69->setText(somme); // si les données reçues de arduino via la liaison série sont égales à 1
 ui->lineEdit_signin_password->setText(somme);

      if(data=="#")
      {
       qDebug() <<data;
      // ****
       QString username_pass= ui->lineEdit_signin_username->text();
      int username = ui->comboBox_id->currentText().toUInt();
       QString password = ui->lineEdit_signin_password->text();

       QSqlQuery  query;
       QString res1=QString::number(username);
       query.bindValue(":ID_E",res1);
        // ****
       query.prepare("select * from DB_EMPLOYEE_LOGIN where ID_E='"+res1+"' and MOTPASS_E='"+somme+"'");
       int i=0;
       if (query.exec())
       {
           while(query.next()){i++;}
           if (i==1)
           {
               QMessageBox::information(this,"Login","User name and password are correct");
           }
           if (i<1) //QMessageBox::warning(this,"Login","Incorrect Username or Password !");
           {
               somme="";
                A.write_to_arduino("0"); //envoyer 2 à arduino


                ui->label_etatlogin->setText("Incorrect Username or Password !");
                ui->lineEdit_signin_password->clear();

           }
           //if(i>1) QMessageBox::warning(this,"Login","duplique!");
       }

       if(i==1)
       {
           A.write_to_arduino("9"); //envoyer 1 à arduino
          username_arduino = ui->comboBox_id->currentText().toUtf8();
         A.write_to_arduino(username_arduino); //envoyer id à arduino
         hide();                                  //el menu eli bich n7ilo ki el login yi5dim (pt3.1)
         mainWindow = new MainWindow(this);       //el menu eli bich n7ilo ki el login yi5dim (pt3.2)
         mainWindow->show();                      //el menu eli bich n7ilo ki el login yi5dim (pt3.f)
       }

             somme="";

        }


}


void login::on_pushButton_signin_login_clicked()
{

         // ****
    QString username_pass= ui->lineEdit_signin_username->text();
    int username = ui->comboBox_id->currentText().toUInt();
    QString password = ui->lineEdit_signin_password->text();

    QSqlQuery  query;
    QString res1=QString::number(username);
    query.bindValue(":ID_E",res1);
     // ****
    query.prepare("select * from DB_EMPLOYEE_LOGIN where ID_E='"+res1+"' and MOTPASS_E='"+somme+"' or ID_E='"+res1+"' and MOTPASS_E='"+password+"' ");

    int i=0;

    if (query.exec())
    {
        while(query.next()){i++;}
        if (i==1)
        {
            QMessageBox::information(this,"Login","User name and password are correct");
        }
        if (i<1) //QMessageBox::warning(this,"Login","Incorrect Username or Password !");
        {
             A.write_to_arduino("0"); //envoyer 2 à arduino

         ui->label_etatlogin->setText("Incorrect Username or Password !");


        }
        //if(i>1) QMessageBox::warning(this,"Login","duplique!");
    }

    if(i==1)
    {

            A.write_to_arduino("9"); //envoyer 9 à arduino
          username_arduino = ui->comboBox_id->currentText().toUtf8();
          A.write_to_arduino(username_arduino); //envoyer id à arduino

          close();                                  //el menu eli bich n7ilo ki el login yi5dim (pt3.1)
          mainWindow = new MainWindow(this);       //el menu eli bich n7ilo ki el login yi5dim (pt3.2)
          mainWindow->show();                      //el menu eli bich n7ilo ki el login yi5dim (pt3.f)
    }

}

bool login::createconnect()                     //el conection mta3 el oracle (pt3.)
{
    bool test=false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("Tuni_Travel_DB");
    db.setUserName("boudali");//inserer nom de l'utilisateur
    db.setPassword("esprit18");//inserer mot de passe de cet utilisateur

    if (db.open()) test=true;



    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("select ID_E from DB_EMPLOYEE_LOGIN ");
  //ui->tableView_id->setModel(model);
  ui->comboBox_id->setModel(model);


    return  test;
}
