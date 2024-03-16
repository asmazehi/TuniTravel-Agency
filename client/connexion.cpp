#include "connexion.h"


connexion::connexion()
{

}
bool connexion::createconnection()
{
bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("Tuni_Travel_DB");
db.setUserName("eya_ali");//inserer nom de l'utilisateur
db.setPassword("eyaali");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;

    return  test;
}

void connexion::closeconnection(){db.close();}
