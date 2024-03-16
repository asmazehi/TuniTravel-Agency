#ifndef MODIFIER_TASK_H
#define MODIFIER_TASK_H

#include <QDialog>
#include <QMessageBox>


namespace Ui {
class modifier_task;
}

class modifier_task : public QDialog
{
    Q_OBJECT

public:
    explicit modifier_task(QWidget *parent = nullptr);
    ~modifier_task();

private slots:
    void on_pushButton_modifier_e_clicked();

    void on_pushButton_exitmod_e_clicked();

private:
    Ui::modifier_task *ui;
        QMessageBox *msgBox;
};

#endif // MODIFIER_TASK_H
