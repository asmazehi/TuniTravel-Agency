#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "arduino.h"

#include <QMainWindow>
#include "gs_employee.h"
#include "gs_client.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_gs_e_clicked();

    void on_pushButton_gs_c_clicked();



private:
    Ui::MainWindow *ui;
    gs_employee *GS_employee;
    gs_client *GS_client;

};


#endif // MAINWINDOW_H
