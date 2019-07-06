#ifndef JSONPARSER_H
#define JSONPARSER_H


#include "QJsonObject"
#include "QJsonDocument"
#include "QDebug"
class JsonParser
{
public:
    JsonParser();
    QJsonObject getJsonObjectFromString(const QString jsonString);
};

#endif // JSONPARSER_H
