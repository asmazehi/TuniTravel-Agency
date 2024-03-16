#ifndef AJOUTER_TASK_H
#define AJOUTER_TASK_H

#include <QDialog>
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QMessageBox>

#include "todolist_e.h"
namespace Ui {
class ajouter_task;
}

class ajouter_task : public QDialog
{
    Q_OBJECT

public:
    explicit ajouter_task(QWidget *parent = nullptr);
    ~ajouter_task();

private slots:


    void on_pushButton_ajoutertask_e_clicked();

    void on_pushButton_exit_ajouter_e_clicked();

private:
    Ui::ajouter_task *ui;
    QMessageBox *msgBox;
    todolist_e Etmp;
};

#endif // AJOUTER_TASK_H
