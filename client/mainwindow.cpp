#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)

{
    ui->setupUi(this);
    QPixmap pix ("C:/Users/Eya/Downloads/piwpiw/uni-removebg-preview.png");
    ui->lpiic->setPixmap(pix.scaled(200,200,Qt::KeepAspectRatio));

}

MainWindow::~MainWindow()
{
    delete ui;
}



/*void MainWindow::on_pushButton_clicked()
{
   hide();
   GS_client = new gs_client(this) ;
   GS_client->show();
}*/

void MainWindow::on_pushButton_gs_c_clicked()
{
    hide();
    GS_client = new gs_client(this) ;
    GS_client->show();
}
