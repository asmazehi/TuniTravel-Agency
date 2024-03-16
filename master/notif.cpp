#include "notif.h"

#include <QSystemTrayIcon>
#include <QString>
#include <QSqlQuery>
#include <QtDebug>
notif::notif()
{
 NUM=0;
}

notif::notif(QString NOM , QString ETAT)
{
    this->NOM=NOM;
    this->ETAT=ETAT;
}

void notif::sound()
{
    musicAdd.setMedia(QUrl("C:/Users/user/Desktop/notification/bell.wav"));
    musicAdd.play();
}
void notif::afficher()
{
    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

    notifyIcon->setIcon(QIcon("C:/Users/user/Desktop/notification/bell.png"));

    notifyIcon->showMessage(NOM,ETAT,QSystemTrayIcon::Information,15000);
     notifyIcon->show();

}
