#ifndef DATABASEHEPLER_H
#define DATABASEHEPLER_H

#include "qdebug.h"
#include "QtSql/QSqlDatabase"
#include "QSqlQuery"
#include "QSqlError"
#include "QString"

class DataBaseHepler
{
public:
    DataBaseHepler();
    ~DataBaseHepler();

    QSqlDatabase db;
    bool select(QString *string,QString sql); //select
    bool other(QString sql); //update delete insert
    bool login(QString user_name,QString pass_word); //login
};

#endif // DATABASEHEPLER_H
