#ifndef FOURNITURE_H
#define FOURNITURE_H
#include <QString>
#include<QSqlQueryModel>
#include <QPrinter>
#include <QPdfWriter>
#include <QPainter>
#include <QtCharts>
#include <iostream>

class fourniture
{
public:
    void setreference(QString n);
    void setnom(QString n);
    void setprix(float n);
    void setquantite(int n);
    void setetat(QString n);
    void setfournisseur(QString n);
    void setimage(QString n);
    QString get_reference();
    QString get_nom();
    float get_prix();
    int get_quantite();
    QString get_etat();
    QString get_fournisseur();
    QString get_image();
    bool ajouter();
    bool supprimer(QString);
    QSqlQueryModel * afficher();
    bool modifier(QString);
    fourniture();
    fourniture(QString, QString, float, int, QString, QString,QString);
    bool genererPDF();
    QSqlQueryModel* trierparref();
    QSqlQueryModel* trierparnom();
    QSqlQueryModel* trierparpri();
    QSqlQueryModel* trierparqua();
    QSqlQueryModel* trierpareta();
    QSqlQueryModel* trierparfou();
    bool rechercheparref(QString reference);
    QSqlQueryModel * afficherparref(QString reference);
    QSqlQueryModel * afficherenpanne();

private:
    QString nom,reference,etat,fournisseur,image;
    int quantite;
    float prix;
};



#endif // FOURNITURE_H
