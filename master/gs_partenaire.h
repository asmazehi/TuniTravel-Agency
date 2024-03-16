#ifndef GS_PARTENAIRE_H
#define GS_PARTENAIRE_H

#include <QMainWindow>
#include <QSqlQueryModel>
#include <QMainWindow>
#include <QTextStream>
#include <QSortFilterProxyModel>
#include <QTextTableFormat>
#include <QStandardItemModel>
#include <QDialog>
#include <QFileDialog>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QDialog>
#include <QDesktopWidget>
#include <QSettings>
#include <QPrinter>
#include <QTextStream>
#include <QFile>
#include <QDataStream>
#include <QMessageBox>

#include <QTabWidget>
#include "notif.h"
#include "partenaire.h"
namespace Ui {
class gs_partenaire;
}

class gs_partenaire : public QDialog
{
    Q_OBJECT

public:
    explicit gs_partenaire(QWidget *parent = nullptr);
    ~gs_partenaire();
private slots :
    void on_ajouter_clicked();

    void on_Supprimer_clicked();

   // void on_Print_clicked();

    void on_pb_pdf_clicked();

    void on_modifier_clicked();

    void on_actionplay_clicked();

    void on_Recherche_clicked();

    void on_actionstop_clicked();

    void on_rnom_clicked();

    void on_rid_clicked();

    void on_rppa_clicked();

    void on_rddc_clicked();

    void on_notif_clicked();

    //void on_stat_clicked();
    void on_pushButton_clicked();

private:
    Ui::gs_partenaire *ui;
    Partenaire P;
    QMediaPlayer* player;
    QVideoWidget* vw;
        QMessageBox *msgBox;
};

#endif // GS_PARTENAIRE_H
