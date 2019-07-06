#ifndef TCPCONNECT_H
#define TCPCONNECT_H

#include <QObject>
#include <QObject>
#include "QTcpServer"
#include "QTcpSocket"
#include "QtNetwork/QHostAddress"
#include "QDebug"
#include "QVector"
class TcpConnect : public QObject
{
    Q_OBJECT
public:
    explicit TcpConnect(QObject *parent = 0);
    ~TcpConnect();
signals:
private:
    void init_server();
public slots:
    void on_new_tcp_connect();  //new connect  -->>tcp_server
    void on_tcp_socket_reader();
    void on_tcp_socket_disconnected();
private:
    QTcpServer *tcp_server; //server
    QTcpSocket *tcp_socket;  //socket

    quint16 port = 8090;

};

#endif // TCPCONNECT_H
