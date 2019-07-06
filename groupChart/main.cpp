#include "mainwindow.h"
#include <QApplication>
#include "dialog.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
//    w.show();

   Dialog dialog;
   dialog.setWindowTitle("Login");
   dialog.show();

   if(dialog.exec()==QDialog::Accepted)//判断login窗口的登陆状态
   {
       w.setUserName(dialog.getUserName());
       w.show();
       dialog.~Dialog();
       return a.exec();
   }
//   return a.exec();
}
