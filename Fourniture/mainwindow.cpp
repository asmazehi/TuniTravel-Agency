#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"fourniture.h"
#include"dialog.h"
#include "connection.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButtonmain_clicked()
{
    dialog=new Dialog(this);
        dialog->show();
}
