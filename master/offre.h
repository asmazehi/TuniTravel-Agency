#ifndef OFFRE_H
#define OFFRE_H
#include <QString>
#include <QSqlQueryModel>
#include<QTableView>

class Offre
{
public:
    Offre();
    Offre(QString,QString,QString,QString,QString);
    QString get_id();
    QString get_prix();
    QString get_contenu();
    QString get_nbredeplace();
    QString get_dated();
    void setid(QString n);
    void setprix(QString n);
    void setcontenu(QString n);
    void setnbredeplace(QString n);
    void setdated(QString n);
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(QString);
   bool modifier(QString);
   QSqlQueryModel * triid();
   QSqlQueryModel * tric();
   QSqlQueryModel * trin();

   void recherche(QTableView * table, QString);
   QSqlQueryModel * afficher_calendar(QString x);

private:
    QString id, prix, contenu, nbredeplace, dated;
};

#endif // OFFRE_H
