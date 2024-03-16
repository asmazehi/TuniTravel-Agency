#include "login.h"
#include "ui_login.h"
#include <QMessageBox>

login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
    QPixmap pix ("C:/Users/Eya/Downloads/piwpiw/uni-removebg-preview.png");
    ui->lpic->setPixmap(pix.scaled(200,200,Qt::KeepAspectRatio));
}

login::~login()
{
    delete ui;
}

bool login::createconnect()
{
bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("Tuni_Travel_DB");
    db.setUserName("eya_ali"); //inserer nom de l'utilisateur
    db.setPassword("eyaali"); //inserer mot de passe de cet utilisateur
    if (db.open()) test=true;

       return  test;

}


void login::on_login_2_clicked()
{
    QString username = ui->linename->text();
       QString password = ui->linepass->text();

       if(username=="eya" && password=="piwpiw")
       {
          QMessageBox::information(this,"Login","User name and password are correct");
          hide();
          mainwindow = new MainWindow(this);
          mainwindow->show();
       }
       else QMessageBox::warning(this,"Login","Incorrect Username or Password !");
}
