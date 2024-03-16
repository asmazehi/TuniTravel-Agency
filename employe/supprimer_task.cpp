#include "supprimer_task.h"
#include "ui_supprimer_task.h"
#include "todolist_e.h"
#include <QMessageBox>
supprimer_task::supprimer_task(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::supprimer_task)
{
    ui->setupUi(this);
}

supprimer_task::~supprimer_task()
{
    delete ui;
}
/*
void supprimer_task::on_pushButton_exittasksupp_e_clicked()
{
    hide();
}
*/
/*
void supprimer_task::on_pushButton_supprimer_e_clicked()
{

    todolist_e E;
    E.setId_task(ui->lineEdit_idsupp_task_e->text().toInt());
    bool test=E.supprimer_task(E.getId_task());
    msgBox= new QMessageBox(this);
    if(test)
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


*/
