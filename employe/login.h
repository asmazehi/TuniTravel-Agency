#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include <QMainWindow>

#include "mainwindow.h"                             //el menu eli bich n7ilo ki el login yi5dim (pt1.)
#include <QTableWidget>

#include <QSqlDatabase>                             //el conection mta3 el oracle (pt1.)
#include <QSqlError>                                //el conection mta3 el oracle (pt1.)
#include <QSqlQuery>                                //el conection mta3 el oracle (pt1.)

#include "employee.h"
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QMessageBox>
#include "arduino.h"
namespace Ui {
class login;
}

class login : public QDialog
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr);
    ~login();

    bool createconnect();                           //el conection mta3 el oracle (pt2.)
QByteArray username_arduino;
Arduino get_A(){return A;}
private slots:
void on_pushButton_signin_login_clicked();




  //  void on_pushButton_signin_login_2_clicked();



    void update_label();   // slot permettant la mise à jour du label état de la lampe 1,
    // ce slot est lancé à chaque réception d'un message de Arduino

  //  void on_comboBox_id_textActivated(const QString &arg1);

   // void on_comboBox_id_textHighlighted(const QString &arg1);

    //void on_comboBox_textHighlighted(const QString &arg1);

private:



    Ui::login *ui;
    MainWindow *mainWindow;                         //el menu eli bich n7ilo ki el login yi5dim (pt2.)
    employee Etmp,E;


    QByteArray somme="";

    QByteArray data; // variable contenant les données reçues
    QByteArray data2;
    Arduino A; // objet temporaire
    QSerialPort * serial;




};

#endif // LOGIN_H



