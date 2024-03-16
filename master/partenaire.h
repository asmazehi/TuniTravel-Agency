#ifndef PARTENAIRE_H
#define PARTENAIRE_H
#include <QString>
#include <QSqlQueryModel>
#include <QTableWidget>
#include <QDebug>
#include <QObject>

class Partenaire

{
public:
    Partenaire();
    Partenaire(int,QString,QString,QString,QString,QString,int);
    int getid() ;
    QString getnom();
    QString getctg();
    QString getadr();
    QString getppa();
    QString getctct();
    int getddc();

    void setid(int);
    void setnom(QString);
    void setctg(QString);
    void setadr(QString);
    void setppa(QString);
    void setctct(QString);
    void setddc(int);



    bool ajouter();

    QSqlQueryModel* afficher();
            bool Supprimer(int);
            bool modifier(int,QString,QString,QString,QString,QString,int);
            QSqlQueryModel *tri1();
            QSqlQueryModel *tri2();
            QSqlQueryModel *tri3();
            QSqlQueryModel *tri4();

           // bool Recherche(int id);
             QSqlQueryModel * Recherche(int id);
            QSqlQueryModel *afficher(int id);




private :
    int id;
    QString nom;
    QString ctg;
    QString adr;
    QString ppa;
    QString ctct;
    int ddc;



};
#endif // PARTENAIRE_H
