#include "dialog.h"
#include "ui_dialog.h"
#include "databasehepler.h"
#include "QDebug"
#include "QMessageBox"
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->lineEdit_login_user_pwd->setEchoMode(QLineEdit::Password);

}

DataBaseHepler db;
Dialog::~Dialog()
{

    db.~DataBaseHepler();

    delete ui;
}

void Dialog::on_pushButton_user_reg_clicked()
{
    QString user = ui->lineEdit_login_user_name->text();
    QString pwd = ui->lineEdit_login_user_pwd->text();
    QString sql = "insert into test3 values(";
    sql.append("'").append(user).append("',").append("'").append(pwd).append("')");

    if(user.length()>3&&pwd.length()>3)
    {
        if(db.other(sql))
        {
               qDebug()<<"reg is OK";

               QMessageBox::information(this,"prompt","registration success");
        }
        else
        {
            qDebug()<<"reg is Error";
        }
    }
    else
    {
         QMessageBox::information(this,"Warning","Username or password is not in the correct format");
    }


}

void Dialog::on_pushButton_user_login_clicked()
{
    QString user = ui->lineEdit_login_user_name->text();
    QString pwd = ui->lineEdit_login_user_pwd->text();
    if(user.length()>3&&pwd.length()>3)
    {
        if(db.login(user,pwd))
        {
             accept();// login is ok
        }
        else
        {
            QMessageBox::information(this,"Warning","Username or password is incorrect");
        }
    }
    else
    {
         QMessageBox::information(this,"Warning","Username or password is not in the correct format");
    }
}

QString  Dialog::getUserName()
{
    return ui->lineEdit_login_user_name->text();
}
