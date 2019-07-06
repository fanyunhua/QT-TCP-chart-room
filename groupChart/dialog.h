/////////////////////login
#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
    QString getUserName();

private slots:
    void on_pushButton_user_reg_clicked();

    void on_pushButton_user_login_clicked();

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
