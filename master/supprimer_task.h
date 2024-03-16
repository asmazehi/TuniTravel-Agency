#ifndef SUPPRIMER_TASK_H
#define SUPPRIMER_TASK_H

#include <QMessageBox>
#include <QDialog>

namespace Ui {
class supprimer_task;
}

class supprimer_task : public QDialog
{
    Q_OBJECT

public:
    explicit supprimer_task(QWidget *parent = nullptr);
    ~supprimer_task();



private slots:
    void on_pushButton_exittasksupp_e_clicked();

    void on_pushButton_supprimer_e_clicked();

private:
    Ui::supprimer_task *ui;

    QMessageBox *msgBox;
};

#endif // SUPPRIMER_TASK_H
