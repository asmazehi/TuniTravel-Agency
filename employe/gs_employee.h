#ifndef GS_EMPLOYEE_H
#define GS_EMPLOYEE_H

#include <QDialog>
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QMessageBox>

#include "employee.h"
#include "ajouter_task.h"
#include "supprimer_task.h"
#include "modifier_task.h"



#include <QtWidgets/QWidget>
#include <QtCharts/QChartGlobal>

QT_BEGIN_NAMESPACE
class QLineEdit;
class QPushButton;
class QCheckBox;
class QComboBox;
class QDoubleSpinBox;
QT_END_NAMESPACE

class PenTool;
class BrushTool;
class CustomSlice;

QT_CHARTS_BEGIN_NAMESPACE
class QChartView;
class QPieSeries;
class QPieSlice;
QT_CHARTS_END_NAMESPACE
class chartView;
QT_CHARTS_USE_NAMESPACE


#include <QtCharts/QPieSlice>

QT_CHARTS_BEGIN_NAMESPACE
class QAbstractSeries;
QT_CHARTS_END_NAMESPACE

QT_CHARTS_USE_NAMESPACE


#include "arduino.h"


namespace Ui {
class gs_employee;
}

class gs_employee : public QDialog
{
    Q_OBJECT

public:
    explicit gs_employee(QWidget *parent = nullptr);
    ~gs_employee();

void stat_todolist();
private slots:

    void on_pushButton_ajouter_e_clicked();
     void on_pushButton_supprimer_e_clicked();

     void on_pushButton_modifier_e_clicked();
     void on_pushButton_2_clicked();

     void on_radioButton_trinom_e_toggled(bool checked);

     void on_radioButton_trisalaire_e_toggled(bool checked);

     void on_radioButton_triheure_e_toggled(bool checked);

     void on_pushButton_modifier_metier_clicked();

     void on_pushButton_3_clicked();

     void on_lineEdit_idrecherche_e_textEdited(const QString &arg1);

     void on_pushButton_ajoutertask_e_2_clicked();

     void on_pushButton_supprimer_e_2_clicked();

     void on_pushButton_modifier_e_2_clicked();

     void on_pushButton_stat_clicked();


private:

    Ui::gs_employee *ui;
    employee Etmp,E;
    
    ajouter_task *Ajouter_task;
    supprimer_task *Supprimer_task;
    modifier_task *Modifier_task;
    QMessageBox *msgBox;

    gs_employee *Gs_employee;


    QChartView *m_chartView;
    QPieSeries *m_series;
    CustomSlice *m_slice;

};




#endif // GS_EMPLOYEE_H


