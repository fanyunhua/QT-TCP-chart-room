#include "updatepassword.h"
#include "ui_updatepassword.h"
#include "databasehepler.h"
#include "QString"
#include "QMessageBox"
UpdatePassWord::UpdatePassWord(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UpdatePassWord)
{
    ui->setupUi(this);
}


UpdatePassWord::~UpdatePassWord()
{
    delete ui;
}

void UpdatePassWord::on_pushButton_update_pwd_clicked()
{
    QString pwd = ui->lineEdit_update_pwd->text();
    if(pwd.length()>3)
    {
        DataBaseHepler db;
        QString sql = "update test3 set pass_word= ";
        QString user = ui->label_update_name->text();
        QString pwd = ui->lineEdit_update_pwd->text();
        sql.append("'").append(pwd).append("' where user_name=").append("'").append(user).append("';");

        if(db.other(sql))
        {
            qDebug()<<"update Ok";
            QMessageBox::information(this,"prompt","update password successfully");
        }
        else
        {
            qDebug()<<"update error";
        }
        qDebug()<<sql;
    }
}
void UpdatePassWord::setUserName(QString userName)
{
    ui->label_update_name->setText(userName);
}
