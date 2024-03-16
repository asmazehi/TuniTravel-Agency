#include "ajouter_task.h"
#include "ui_ajouter_task.h"
#include <QMessageBox>
#include <QTextEdit>
#include <QMessageBox>

#include "ui_gs_employee.h"
#include "gs_employee.h"

#include "todolist_e.h"

ajouter_task::ajouter_task(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ajouter_task)
{
    ui->setupUi(this);

}

ajouter_task::~ajouter_task()
{
    delete ui;
}


void ajouter_task::on_pushButton_ajoutertask_e_clicked()
{
    int id_task=ui->lineEdit_idtask_e->text().toUInt();
     QString employee_task=ui->lineEdit_employee_task_e->text();
     QString etat_task=ui->lineEdit_etattask_e->text();
     QString task=ui->lineEdit_task_e->text();
     todolist_e t(id_task,employee_task,task,etat_task);

    // gs_employee e;
     msgBox= new QMessageBox(this);
      if(t.ajouter_task())
      {


           msgBox->setText("effectué");
   // ui->tab_employee->setModel(Etmp.afficher_task());
           msgBox->show();

      }
      else
     {

       msgBox->setText("non effectué");
       msgBox->show();
      }

}







