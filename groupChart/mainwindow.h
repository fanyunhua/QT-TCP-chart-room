#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "QtSql/QSqlDatabase"
#include <QMainWindow>
#include "QThread"
#include "QtCore/QObject"
#include "mthreadobject.h"
#include <QtNetwork/QUdpSocket>
#include <QtNetwork/QHostAddress>
#include "databasehepler.h"
#include "qdebug.h"
#include "QtSql/QSqlDatabase"
#include "QSqlQuery"
#include "QSqlError"
#include "QString"
#include "QList"
#include <QBrush>
#include <QRadialGradient>
#include "QStandardItemModel"
#include "updatepassword.h"
#include "QMessageBox"
#include "tcpconnect.h"
#include "QMessageBox"
#include "QJsonDocument"
namespace Ui {
class MainWindow;

}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void setUserName(QString userName);
    QString getUserName();
    ~MainWindow();

private slots:
    void on_tools_update_password_clicked();

    void on_tools_action_log_out();

    void on_pushButton_connect_to_server_clicked();

    void on_socket_read();

    void on_socket_disconnect();

    void on_pushButton_send_message_clicked();

private:
    void setProperty();
private:
    Ui::MainWindow *ui;
    QString userName;
    QTcpSocket *socket;

};

#endif // MAINWINDOW_H
