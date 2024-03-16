#ifndef LOGIN_H
#define LOGIN_H
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class login;
}

class login : public QDialog
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr);
    ~login();
      bool createconnect();

private slots:


    void on_login_2_clicked();

private:
    Ui::login *ui;
    MainWindow *mainwindow ;
};

#endif // LOGIN_H
