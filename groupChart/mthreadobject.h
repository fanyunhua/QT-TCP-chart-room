#ifndef MTHREADOBJECT_H
#define MTHREADOBJECT_H

#include <QObject>
#include "QThread"
#include "QDebug"
class MThreadObject : public QObject
{
    Q_OBJECT
public:
    explicit MThreadObject(QObject *parent = 0);


signals:

public slots:
    void slot()
    {
//        for(int i = 0;i<10;i++)
//        {
//            qDebug()<<i;
//            QThread::sleep(2);
//        }

//        server.initSocket();
//        server.run();


    }
};

#endif // MTHREADOBJECT_H
