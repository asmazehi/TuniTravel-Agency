#ifndef GS_OFFRE_H
#define GS_OFFRE_H


#include <QDialog>
#include "offre.h"

#include <QList>
#include <QDate>
#include <QTextBrowser>
#include <QAbstractItemView>
#include <QTimer>
#include <QNetworkReply>
#include <QSound>
#include <QtMultimedia/QMediaPlayer>
#include "arduino_kd.h"
namespace Ui {
class gs_offre;
}

class gs_offre : public QDialog
{
    Q_OBJECT

public:
    explicit gs_offre(QWidget *parent = nullptr);
    ~gs_offre();
     void setQRData(QString data);
private slots :


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


    void on_lineEdit_textEdited(const QString &arg1);

    void on_pushButton_clicked();

    //void on_offButton_2_clicked();

private:
    Ui::gs_offre *ui;

    Offre O;
    arduino C;
    QTimer timer;
    QList<QString> dataList ;
    QNetworkAccessManager * manager;
    QNetworkRequest request;
    QSound *click;
   // gs_offre *Gs_offre;
  //  Arduino A; // objet temporaire



};

#endif // GS_OFFRE_H
