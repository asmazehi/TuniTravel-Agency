#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gs_employee.h"
#include "gs_client.h"
#include "gs_offre.h"
#include "gs_partenaire.h"
#include "dialog.h"
#include <QPixmap>                                                                     //el taswira eli bich t7otha fil login.ui (pt1.)
#include <QDialog>
#include "login.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    QPixmap pix("C:/Users/dell/Documents/NOTION/2eme année (2-A-27)/subjects/Projet C++/uni-removebg-preview");                           //el taswira eli bich t7otha fil login.ui (pt2.)
    ui->label_signin_pic->setPixmap(pix.scaled(250,250,Qt::KeepAspectRatio));           //el taswira eli bich t7otha fil login.ui (pt3.)
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_gs_e_clicked()
{

this->close();
GS_employee= new gs_employee(this);
GS_employee->show();

}

void MainWindow::on_pushButton_gs_c_clicked()
{
    hide();
GS_client = new gs_client();
GS_client->exec();
}

void MainWindow::on_pushButton_gs_f_clicked()
{
hide();
dialog = new Dialog(this);
dialog->exec();
}

void MainWindow::on_pushButton_gs_o_clicked()
{
    hide();
    Gs_offre = new gs_offre(this);
    Gs_offre->exec();
}

void MainWindow::on_pushButton_gs_p_clicked()
{
        hide();
        Gs_partenaire = new gs_partenaire(this);
        Gs_partenaire->exec();
}
