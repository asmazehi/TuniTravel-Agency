#include "modifier_task.h"
#include "ui_modifier_task.h"
#include "todolist_e.h"


modifier_task::modifier_task(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::modifier_task)
{
    ui->setupUi(this);
}

modifier_task::~modifier_task()
{
    delete ui;
}
/*
void modifier_task::on_pushButton_modifier_e_clicked()
{
    int id=ui->lineEdit_idmodtask_e->text().toInt();
    QString etat=ui->comboBox_e->currentText();

    todolist_e e(etat);


    msgBox= new QMessageBox(this);
    bool test=e.modifier_task(id);
    if(test)
    {

       // ui->tab_employee->setModel(Etmp.afficher());
        msgBox->setText("effectué");
        msgBox->show();
      }
    else
    {

    msgBox->setText("non effectué");
    msgBox->show();
    }

}

void modifier_task::on_pushButton_exitmod_e_clicked()
{
    hide();
}
*/
