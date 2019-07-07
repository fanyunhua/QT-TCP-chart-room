#include "databasehepler.h"

DataBaseHepler::DataBaseHepler()
{
    db = QSqlDatabase::addDatabase("QMYSQL");//driver mode
    db.setHostName("127.0.0.1");
    db.setPort(3306);
    db.setUserName("root");
    db.setPassword("123456");
    db.setDatabaseName("fyh_test");
    //connect to mysql , must have this sentence
    if(db.open())
    {
        qDebug("connect to MySql successfully  ");
    }
    else
    {
        qDebug("connect error connect failed");
    }
}
DataBaseHepler::~DataBaseHepler()
{
    db.close();
}
bool DataBaseHepler::select(QString *string,QString sql)
{
    QSqlQuery query(db);
    QString ss;

    bool isOK = query.exec(sql);
    ss.append("User name")
            .append("\t\t\t\t").append("Pass word")
            .append("\n");
    while(query.next())
    {
        ss.append(query.value(0).toString())
                .append("\t\t\t\t").append(query.value(1).toString())
                .append("\n");
//        qDebug()<<query.value(0).toString()<<"\t\t\t"<<query.value(1).toString();
    }
    *string = ss;
    return isOK;
}
bool DataBaseHepler::other(QString sql)
{
    QSqlQuery query(db);
    if(query.exec(sql))
    {
        return true;
    }
    return false;
}
bool  DataBaseHepler::login(QString user_name,QString pass_word)
{
    QSqlQuery query(db);
    if(!query.exec("select * from test3"))
    {
        qDebug()<< "select * failed";
    }
    else
    {
        while(query.next())
        {
            qDebug()<<query.value(0)<<query.value(1);
            if(user_name==query.value(0)&&pass_word==query.value(1))
            {
                qDebug()<< "login success ";
                return true;
            }
        }
    }
       return false;
}
