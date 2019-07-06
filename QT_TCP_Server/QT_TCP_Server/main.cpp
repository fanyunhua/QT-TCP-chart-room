#include <QCoreApplication>
#include "tcpconnect.h"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    TcpConnect connect;

    return a.exec();
}
