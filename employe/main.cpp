#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>                     //el conection mta3 el oracle (pt4.1)
#include "login.h"

#include <QFile>                           //el THEME mta3 el application (pt.1)

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


     //**************************

    QFile styleSheetFile("C:/Users/dell/Documents/NOTION/2eme année (2-A-27)/subjects/Projet C++/Toolery.qss");         //el THME mta3 el application (pt.2.1)
    styleSheetFile.open(QFile::ReadOnly);                                                                               //el THME mta3 el application (pt.2.2)
    QString styleSheet = QLatin1String(styleSheetFile.readAll());                                                       //el THME mta3 el application (pt.2.3)
    a.setStyleSheet(styleSheet);                                                                                        //el THME mta3 el application (pt.2.f)

     //**************************
    MainWindow w;
    login l;

    //**************************
    bool test1=l.createconnect();           //el conection mta3 el oracle (pt4.2)


    if(test1)                               //el conection mta3 el oracle (pt4.f)
    {
        l.show();                           //***Overture de fenétre login

        QMessageBox::information(nullptr, QObject::tr("database is open"),
        QObject::tr("connection successful.\n""Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
    { QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                    QObject::tr("connection failed.\n""Click Cancel to exit."), QMessageBox::Cancel);
    }






    return a.exec();
}


