#ifndef DATAPARSER_H
#define DATAPARSER_H

#include <QObject>
#include "QJsonObject"
#include "QJsonDocument"
#include "QDebug"
class DataParser : public QObject
{
    Q_OBJECT
public:
    explicit DataParser(QObject *parent = 0);
    bool isLogin(QString *string);
    QJsonObject getJsonObjectFromString(const QString jsonString);
    bool parserMessage(QString rawData,QString *fromUser,QString *toUser,QString *message);
signals:

public slots:
};

#endif // DATAPARSER_H
