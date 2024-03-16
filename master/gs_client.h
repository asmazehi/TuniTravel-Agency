#ifndef GS_CLIENT_H
#define GS_CLIENT_H
#include <QSqlQueryModel>
#include <QDialog>

#include <QMessageBox>

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

namespace Ui {
class gs_client;
}

class gs_client : public QDialog
{
    Q_OBJECT

public:
    explicit gs_client(QWidget *parent = nullptr);
    ~gs_client();


private slots:
    void on_Ajouterc_clicked();

    void on_update_clicked();

    void on_suppc_clicked();

    void on_rechc_clicked();

    void on_pushButton_clicked();

    void on_radioButton_6_toggled(bool checked);

    void on_radioButton_toggled(bool checked);

    void on_radioButton_2_toggled(bool checked);

    void on_radioButton_3_toggled(bool checked);

   // void on_ajoutm_clicked();

    void on_pdf_clicked();

    //void on_Supph_clicked();

    void on_pushButton_3_clicked();
    void stat_todolist();
    void on_excel_clicked();

private:
    Ui::gs_client *ui;

     gs_client *GS_client;
    QMessageBox *msgBox;

     QChartView *m_chartView;
     QPieSeries *m_series;
     CustomSlice *m_slice;
};

#endif // GS_CLIENT_H
