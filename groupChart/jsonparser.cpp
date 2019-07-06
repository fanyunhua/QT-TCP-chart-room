#include "jsonparser.h"
#include "QJsonObject"
#include "QJsonDocument"
JsonParser::JsonParser()
{

}
QJsonObject JsonParser::getJsonObjectFromString(const QString jsonString)
{


    QJsonParseError err;
    QJsonDocument jsonDocument = QJsonDocument::fromJson(jsonString.toLocal8Bit(),&err);
    if( jsonDocument.isNull()){
        qDebug()<<"parser"<<err.error<<jsonDocument<< "===> please check the string "<< jsonString.toLocal8Bit().data();
    }
    QJsonObject jsonObject = jsonDocument.object();
    return jsonObject;
}
