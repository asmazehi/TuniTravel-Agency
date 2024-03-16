#ifndef ARDUINO_H
#define ARDUINO_H
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QDebug>


class Arduino
{
public:     //méthodes de la classe Arduino
   Arduino();
    int connect_arduino_a(); // permet de connecter le PC à Arduino
    int connect_arduino_k(); // permet de connecter le PC à Arduino

    int close_arduino(); // permet de femer la connexion
    int write_to_arduino( QByteArray ); // envoyer des données vers arduino
    QByteArray read_from_arduino();  //recevoir des données de la carte Arduino
    QSerialPort* getserial();   // accesseur
    QString getarduino_port_name();

    //***************** Arduino asma
    int chercherid(QString code);
     QByteArray getdata();



private:

QSerialPort * serial; //Cet objet rassemble des informations (vitesse, bits de données, etc.)
//et des fonctions (envoi, lecture de réception,…) sur ce qu’est une voie série pour Arduino.

static const quint16 arduino_uno_vendor_id_1=9025;
static const quint16 arduino_uno_producy_id_2=67;

/*
static const quint16 arduino_uno_vendor_id_k=6790;
static const quint16 arduino_uno_producy_id_k=29987;
*/
QString arduino_port_name;
bool arduino_is_available;
QByteArray data;  // contenant les données lues à partir d'Arduino


//************************Arduino karim/dali
int hum;// contenant les données lues à partir d'Arduino

};



#endif // ARDUINO_H
