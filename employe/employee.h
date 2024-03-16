#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <QDialog>
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QTableWidget>

class employee
{

    QString nom;
    QString prenom;
    QString motpass;
    int id ;
    int cin;
    int tel;
    int heure;
    int salaire;



public:
    employee();
    employee(QString,QString,int,int,QString,int,int,int);
   employee(QString,QString,int,int,int,int);
   employee(QString);

    QString getNom(){return nom;}
    QString getPrenom(){return prenom;}
    QString getMotpass(){return motpass;}
    int getId(){return id;}
    int getHeure(){return heure;}
    int getCin(){return cin;}
    int getTel(){return tel;}
    int getSalaire(){return salaire;}

    void setNom(QString n){nom=n;}
    void setPrenom(QString p){prenom=p;}
    void setMotpass(QString m){motpass=m;}
    void setId(int i){id=i;}
    void setHeure(int h){heure=h;}
    void setCin(int c){cin=c;}
    void getTel(int t){tel=t;}
    void setSalaire(int s){salaire=s;}
public:

    bool ajouter();
    QSqlQueryModel* afficher();
    QSqlQueryModel* tri_nom();
    QSqlQueryModel* tri_salaire();
    QSqlQueryModel* tri_heure();
    bool supprimer(int);
    //*
    bool modifier(int);
    bool modifier_mot_passe(int,QString,QString);
    QSqlQueryModel* recherche(QString );
    QString motpass_kdim(int);
    bool login(int,QString);
    QSqlQueryModel* afficher_task();

    void open_gs();

    QSqlQueryModel* afficher_m();
};



#endif // EMPLOYEE_H
