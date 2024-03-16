#include "connection.h"

Connection::Connection()
{

}

bool Connection::createconnect()
{
bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("source_projet2a");
db.setUserName("karim");
db.setPassword("karim123");

if (db.open())
test=true;

    return  test;
}
void Connection::closeConnection(){db.close();}
