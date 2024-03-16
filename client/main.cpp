#include "mainwindow.h"
#include "login.h"
#include <QtWidgets/QApplication>
#include <QMessageBox>
#include <QApplication>
#include <QFile>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QFile styleSheetFile("C:/Users/Eya/Downloads/oi/Toolery.qss");
      styleSheetFile.open(QFile::ReadOnly);
      QString styleSheet = QLatin1String(styleSheetFile.readAll());
      a.setStyleSheet(styleSheet);

    login l;
    bool test1=l.createconnect() ;
    if(test1)
    {
        l.show();
        QMessageBox::information(nullptr, QObject::tr("database is open"),
        QObject::tr("connection successful.\n""Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
    { QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                    QObject::tr("connection failed.\n""Click Cancel to exit."), QMessageBox::Cancel);
    }

    return a.exec();

}

