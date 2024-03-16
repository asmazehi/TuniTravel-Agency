#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "offre.h"
#include "arduino.h"
#include <QList>
#include <QDate>
#include <QTextBrowser>
#include <QAbstractItemView>
#include <QTimer>
#include <QNetworkReply>
#include <QSound>
#include <QtMultimedia/QMediaPlayer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void setQRData(QString data);


private slots:
 //   void paintEvent(QPaintEvent *);

//    void managerFinished(QNetworkReply *reply);

//    void managerFinished(QNetworkReply *reply);


    void on_pb_ajouter_clicked();

    void on_pb_supp_clicked();

   void on_pb_modifier_clicked();

   void on_pushButton_2_clicked();

   void on_pushButton_3_clicked();

   void on_pushButton_4_clicked();

   void on_lineEdit_textChanged(const QString &arg1);

   void on_pushButton_whatsapp_clicked();
   void on_calendarwidget_selectionChanged();

   void on_trii_toggled(bool checked);

   void on_Tric_toggled(bool checked);

   void on_trin_toggled(bool checked);
   void on_offButton_clicked();


   void on_refreshButton_clicked();

   //void on_refreshButton_clicked();

   void on_refreshButton_fire_clicked();

   void on_fire_windowIconTextChanged(const QString &iconText);

   void on_fire_objectNameChanged(const QString &objectName);

   void on_refreshButton_clicked(bool checked);

   void saveInDB();

   void loop();

   void check();

   void postRequest();



private:
    Ui::MainWindow *ui;
    Offre O;
    arduino C;
    QTimer timer;
QList<QString> dataList ;
QNetworkAccessManager * manager;
QNetworkRequest request;
QSound *click;

};


#endif // MAINWINDOW_H
