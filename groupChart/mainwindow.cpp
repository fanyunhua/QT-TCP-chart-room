#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QJsonObject"
#include "jsonparser.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setProperty();
    connect(ui->update_password,SIGNAL(triggered()),this,SLOT(on_tools_update_password_clicked()));
    connect(ui->actionLogOut,SIGNAL(triggered()),this,SLOT(on_tools_action_log_out()));
    ui->pushButton_send_message->setEnabled(false);
}
TcpConnect tcpCpnnect;
void MainWindow::setProperty()
{
    ui->lineEdit_server_port->setValidator(new QIntValidator(1,65535,this));//set port range
    ui->lineEdit_server_address->setMaxLength(15);  //length

    ui->lineEdit_server_address->setText("127.0.0.1"); //defalut address
    ui->lineEdit_server_port->setText("8090");  //defalut port
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setUserName(QString userName)
{
    this->userName = userName;
    ui->lable_main_user_name->setText(userName);
}

void MainWindow::on_tools_update_password_clicked()
{
    UpdatePassWord dialog;
    dialog.setUserName(ui->lable_main_user_name->text());
    dialog.exec();

    qDebug("update");
}

void MainWindow::on_tools_action_log_out()
{
    this->~MainWindow();  //exit
}

QString MainWindow::getUserName()
{
    return this->userName;
}

void MainWindow::on_socket_read()
{


//    qDebug()<<socket->readAll();
    QByteArray byte = socket->readAll();


    qDebug()<<byte.toHex();
    QString readALL;
    readALL.append(byte);

    qDebug()<<readALL;
    qDebug()<<readALL.toLocal8Bit().toHex();
    ui->textBrowser->setText(readALL);

    QJsonObject json; //= JsonParser::getJsonObjectFromString(readALL.append(byte));
    JsonParser parser;
    json = parser.getJsonObjectFromString(readALL);

    QJsonObject::iterator iter = json.find("action");

    //group_message
    //personal_message


    QJsonObject::iterator msg = json.find("message");
    QJsonObject::iterator fromUser = json.find("from_user");
    if(QString::compare("group_message",iter.value().toString())==0)
    {
//        ui->textBrowser->setText(
//                    ui->textBrowser->setText()
//                    .append(fromUser.value().toString())
//                    .append(":")
//                    .append(msg.value().toString()));
    }
    else if(QString::compare("personal_message",iter.value().toString())==0)
    {
//        ui->textBrowser->setText(
//                    ui->textBrowser->setText()
//                    .append(fromUser.value().toString())
//                    .append(":")
//                    .append(msg.value().toString()).append("\n"));
    }

}

void MainWindow::on_socket_disconnect()
{

    QMessageBox::information(this,"error","Server disconnected, please reconnect");
    ui->pushButton_connect_to_server->setEnabled(true);
    ui->pushButton_send_message->setEnabled(false);
}

void MainWindow::on_pushButton_connect_to_server_clicked()
{
    QString address = ui->lineEdit_server_address->text();
    QString mPort = ui->lineEdit_server_port->text();

    if(!address.isEmpty()&&!mPort.isEmpty())
    {
        int port = mPort.toInt();
        tcpCpnnect.initSocket(address,port);
        socket = tcpCpnnect.getSocket();
        if(socket->isOpen())
        {
            ui->pushButton_connect_to_server->setEnabled(false);
            connect(socket,SIGNAL(readyRead()),this,SLOT(on_socket_read()));
            connect(socket,SIGNAL(disconnected()),this,SLOT(on_socket_disconnect()));
            ui->pushButton_send_message->setEnabled(true);
            QJsonObject josnLogin;
            josnLogin.insert("action","login");
            josnLogin.insert("user",userName);
            tcpCpnnect.sendMessage(QString(QJsonDocument(josnLogin).toJson()));
        }
    }
    else
    {
        QMessageBox::information(this,"error","please input address or port");
    }
}

void MainWindow::on_pushButton_send_message_clicked()
{
    QString toUser = ui->lineEdit_to_user_name->text();
    QString message = ui->textEdit_input_message->toPlainText();
    if(!message.isEmpty())
    {
        if(!toUser.isEmpty())
        {
            //user is empty send group message
            QJsonObject josnLogin;
            josnLogin.insert("action","send_message");
            josnLogin.insert("from_user",userName);
            josnLogin.insert("to_user",toUser);
            josnLogin.insert("message",message);

            tcpCpnnect.sendMessage(QString(QJsonDocument(josnLogin).toJson()));
        }
        else
        {
            //user is empty send to user message
            QJsonObject josnLogin;
            josnLogin.insert("action","send_message");
            josnLogin.insert("from_user",userName);
            josnLogin.insert("to_user","ALL_USER");
            josnLogin.insert("message",message);
            tcpCpnnect.sendMessage(QString(QJsonDocument(josnLogin).toJson()));
        }
    }
    else
    {
        QMessageBox::information(this,"error","please input message");
    }
}
