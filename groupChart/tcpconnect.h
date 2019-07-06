#ifndef TCPCONNECT_H
#define TCPCONNECT_H

#include <QObject>
#include "QTcpSocket"
#include "QHostAddress"
class TcpConnect : public QObject
{
    Q_OBJECT
public:
    explicit TcpConnect(QObject *parent = 0);
    ~TcpConnect();
    void initSocket(QString addr,int port);
    void sendMessage(QString message);
    QTcpSocket* getSocket();
signals:

public slots:
    void on_socket_read();
    void on_socket_disconnected();
private:
    QTcpSocket *socket;
};

#endif // TCPCONNECT_H
