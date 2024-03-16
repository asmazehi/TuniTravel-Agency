#ifndef NOTIF_H
#define NOTIF_H
#include <QSystemTrayIcon>
#include <QString>
#include <QMediaPlayer>

class notif
{
public:
    notif();
    notif(QString,QString);
    //void refresh();
    void sound();
    void afficher();
    bool envoyer(int );
    bool envoyer_s(int );
    bool verif(int );
private:
    int NUM,SURFACE, NBR_PLACES;
    QString NOM,ETAT,DATE_CREATION;
    QMediaPlayer musicAdd;
};

#endif // NOTIF_H
