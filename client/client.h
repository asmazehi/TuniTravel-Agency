#ifndef CLIENT_H
#define CLIENT_H
#include <QSqlQueryModel>
#include <QDialog>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QString>


class client
{

public:


    client();
    client(int,QString,QString,QString,int,QString);
    int getcin();
    QString getnom();
    QString getprenom();
    QString getemail();
    int gettelephone();
    QString getadresse();
    void setcin (int id);
    void setnom (QString nomd);
    void setprenom (QString prenomd);
    void setemail (QString prenomd);
    void settelephone (int telephon);
    void setadresse (QString prenomd);
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int);
    bool modifier (int);
    QSqlQueryModel * recherche(int);
//  QSqlQueryModel* afficherTri(int) ;
    QSqlQueryModel * tri_cin ();
    QSqlQueryModel * tri_nom ();
    QSqlQueryModel * tri_prenom ();
    QSqlQueryModel * tri_email ();
    QSqlQueryModel * afficher_HIS();
    bool supprimerh (int);
    float nbre_totalea();
    float nbre_totale() ;
    float nbre_totales();
    float nbre_totalem();





private:
    int cin,telephone;
    QString nom, prenom,email,adresse;


};

#endif // CLIENT_H
