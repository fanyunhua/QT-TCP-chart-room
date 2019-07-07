#include "tcpconnect.h"
#include "dataparser.h"
#include "QMap"
TcpConnect::TcpConnect(QObject *parent) : QObject(parent)
{
    init_server();
}
QVector<QTcpSocket*> connect_vector;  //save connect
QVector<QString> connect_name;  //save connect name -->>>user name
QMap<QString,QTcpSocket*> map;
void TcpConnect::init_server()
{
    //init TCP server
    tcp_server = new QTcpServer();

    //connect to slots  new tcp connect
    connect(tcp_server,SIGNAL(newConnection()),this,SLOT(on_new_tcp_connect()));
    if(tcp_server->listen(QHostAddress::Any,port))
    {
        qDebug()<<"****************************************************************";
        qDebug()<<"********************server is started***************************";
        qDebug()<<"****************************************************************";
    }
    else
    {
        qDebug()<<"****************************************************************";
        qDebug()<<"********************server is started  error********************";
        qDebug()<<tcp_server->errorString();
        qDebug()<<"****************************************************************";
    }
}

TcpConnect::~TcpConnect()
{
    delete tcp_server;
}


void TcpConnect::on_new_tcp_connect()
{
    qDebug()<<"New connect";
    tcp_socket = tcp_server->nextPendingConnection();  //get new connect socket
    connect(tcp_socket,SIGNAL(readyRead()),this,SLOT(on_tcp_socket_reader())); //socket ready read
    connect(tcp_socket,SIGNAL(disconnected()),this,SLOT(on_tcp_socket_disconnected())); //socket disconnected

    connect_vector.append(tcp_socket);  //append to vector
    qDebug()<<"Current connect :"<<connect_vector.size();
}

void TcpConnect::on_tcp_socket_reader()
{
    QTcpSocket *socket = (QTcpSocket*)sender();//get current socket
    QString message = socket->readAll();
    DataParser parser;
    if(parser.isLogin(&message))
    {
        //NONE login;
        connect_name.append(message);
        qDebug()<<"current name :"<<connect_name.size();
        map.insert(message,socket);

    }
    else
    {
        //TODO parser message
        QString fromUser,toUser,msg;
        parser.parserMessage(message,&fromUser,&toUser,&msg);
        qDebug()<<fromUser<<"->"<<toUser<<"->>"<<msg;
        if(QString::compare(toUser,"ALL_USER")==0)
        {
            //group chart
            qDebug()<<"group chart";
            QVector<QTcpSocket*>::Iterator iter;
            QJsonObject jsonMessage;

            jsonMessage.insert("action","group_message");
            jsonMessage.insert("message",msg);
            jsonMessage.insert("from_user",fromUser);
            for(iter = connect_vector.begin();iter!=connect_vector.end();iter++)
            {
                QTcpSocket *soc = *iter;
                soc->write(QString(QJsonDocument(jsonMessage).toJson()).toLocal8Bit());
                qDebug()<<QString(QJsonDocument(jsonMessage).toJson()).toLatin1().toHex();
                qDebug()<<QString(QJsonDocument(jsonMessage).toJson()).toLocal8Bit();


//                QString ss = "{\"name\":\"ggg\"}";
//                soc->write(ss.toLocal8Bit());


//                QString(QJsonDocument(josnLogin).toJson())


                qDebug()<<*iter;
            }
        }
        else
        {

            QJsonObject jsonMessage;
            if(map.contains(toUser))
            {
                //to user online

                jsonMessage.insert("action","personal_message");
                jsonMessage.insert("message",msg);
                jsonMessage.insert("from_user",fromUser);
                map.value(toUser)->write(QString(QJsonDocument(jsonMessage).toJson()).toLatin1());
                
            }
            else
            {
                //to user offline
                jsonMessage.insert("action","personal_message");
                jsonMessage.insert("message","Server prompt user has been offline");
                jsonMessage.insert("from_user","Server");
                socket->write(QString(QJsonDocument(jsonMessage).toJson()).toLocal8Bit());
                
            }
            qDebug()<<"user chart to"<<toUser;
        }
    }
    qDebug()<<message;
}

void TcpConnect::on_tcp_socket_disconnected()
{
    QTcpSocket *socket = (QTcpSocket*)sender();//get current socket
    int index = connect_vector.indexOf(socket);
    connect_vector.remove(index);
    connect_name.remove(index);
    qDebug()<<"New customer disconnect link";
    qDebug()<<"Current connect :"<<connect_vector.size();
    qDebug()<<"current name :"<<connect_name.size();
}
