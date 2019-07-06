#include "tcpconnect.h"
#include "mainwindow.h"
TcpConnect::TcpConnect(QObject *parent) : QObject(parent)
{

}

TcpConnect::~TcpConnect()
{

}

void TcpConnect::initSocket(QString addr,int port)
{
    socket = new QTcpSocket();
    socket->connectToHost(addr,port,QTcpSocket::ReadWrite);
//    connect(socket,SIGNAL(readyRead()),this,SLOT(on_socket_read()));
//    connect(socket,SIGNAL(disconnected()),this,SLOT(on_socket_disconnected()));
}

void TcpConnect::sendMessage(QString message)
{
    socket->write(message.toLatin1());
}

void TcpConnect::on_socket_read()
{
     qDebug()<<"read";

}

void TcpConnect::on_socket_disconnected()
{

}
QTcpSocket* TcpConnect::getSocket()
{
    return this->socket;
}
