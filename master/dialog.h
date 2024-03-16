#ifndef DIALOG_H
#define DIALOG_H
#include"fourniture.h"
#include <QDialog>
#include <QFileDialog>
#include <iostream>
#include <QTableView>
#include "arduino.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    void setfourniture(fourniture f);
    ~Dialog();

private slots:
    void on_PBajouter_clicked();
    void update_label();
    void on_PBsupprimer_clicked();

    void on_PBmodifier_clicked();

    void on_pushButton_clicked();

    void on_pdf_clicked();

    void on_qua_toggled(bool checked);

    void on_ref_toggled(bool checked);

    void on_nom_toggled(bool checked);

    void on_pri_toggled(bool checked);

    void on_eta_toggled(bool checked);

    void on_fou_toggled(bool checked);


    void on_pb_rech_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::Dialog *ui;
    fourniture Etmp;
    QByteArray data; // variable contenant les données reçues
    QMessageBox *msgBox;
       Arduino A; // objet temporaire

          Dialog *dialog;
};

#endif // DIALOG_H

