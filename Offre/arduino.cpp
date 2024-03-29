#include "arduino.h"
#include<QDebug>

arduino::arduino()
{

}

int arduino::connect_arduino()
{

    serial=new QSerialPort;
    foreach(const QSerialPortInfo &serial_port_info,QSerialPortInfo::availablePorts()){
        if(serial_port_info.hasVendorIdentifier() && serial_port_info.hasProductIdentifier()){
            qDebug() << serial_port_info.vendorIdentifier();
            qDebug() << serial_port_info.productIdentifier();
            if(serial_port_info.vendorIdentifier()==arduino_uno_vendor_id && serial_port_info.productIdentifier()==arduino_uno_producy_id ){
                arduino_is_available=true;
                arduino_port_name=serial_port_info.portName();


            }
        }
        }

        if(arduino_is_available){
            qDebug()<<"arduino port name is :"<<arduino_port_name;
                serial->setPortName(arduino_port_name);
             if(serial->open(QSerialPort::ReadWrite))
             {
                 serial->open(QIODevice::ReadWrite);

                serial->setBaudRate(QSerialPort::Baud9600);
                serial->setDataBits(QSerialPort::Data8);
                serial->setParity(QSerialPort::NoParity);
                serial->setStopBits(QSerialPort::OneStop);
                serial->setFlowControl(QSerialPort::NoFlowControl);
                return 0;
             }
            return  1;
        }
}
int arduino::close_arduino()
{
    if(serial->isOpen())
    {
        serial->close();
        return 0;
    }
    return 1;
}
QString arduino::read_from_arduino()
{
    QByteArray data="";
    QString output;
    int da = serial->bytesAvailable();

    data=serial->readLine();
    output = QString::fromUtf8(data.toUpper());

    return output;


}
int arduino::write_to_arduino(QByteArray d)
{

    if(serial->isWritable())
    {
        serial->write(d);
    }else qDebug()<<"couldn't write to serial ";
}
