#include "dataparser.h"
DataParser::DataParser(QObject *parent) : QObject(parent)
{

}

bool DataParser::isLogin(QString *string)
{

//    qDebug()<<*string<<"parser";
    QJsonObject json = getJsonObjectFromString(*string);
    QJsonObject::iterator iter = json.find("action");
    QString action = iter.value().toString();
    if(QString::compare(action,"login")==0)  //login
    {
        qDebug()<<action;
        QJsonObject::iterator user = json.find("user");
        *string = user.value().toString();
        return true;
    }
    else if(QString::compare(action,"send_message")==0)  //senf message
    {
        *string = *string;
        return false;
    }
}
QJsonObject DataParser::getJsonObjectFromString(const QString jsonString)
{
    QJsonDocument jsonDocument = QJsonDocument::fromJson(jsonString.toLocal8Bit().data());
    if( jsonDocument.isNull() ){
        qDebug()<< "===> please check the string "<< jsonString.toLocal8Bit().data();
    }
    QJsonObject jsonObject = jsonDocument.object();
    return jsonObject;
}
bool DataParser::parserMessage(QString rawData,QString *fromUser,QString *toUser,QString *message)
{
    //“message”:”msg”,
    //“from_user”:”user_name”,
    //“to_user”:”user_name”
    QJsonObject json = getJsonObjectFromString(rawData);
    QJsonObject::iterator iter = json.find("message");
    *message = iter.value().toString();
    iter = json.find("from_user");
    *fromUser = iter.value().toString();
    iter = json.find("to_user");
    *toUser = iter.value().toString();
}
