#ifndef UPDATEPASSWORD_H
#define UPDATEPASSWORD_H

#include <QDialog>

namespace Ui {
class UpdatePassWord;
}

class UpdatePassWord : public QDialog
{
    Q_OBJECT

public:
    explicit UpdatePassWord(QWidget *parent = 0);
    ~UpdatePassWord();
    void setUserName(QString userName);
private slots:
    void on_pushButton_update_pwd_clicked();

private:
    Ui::UpdatePassWord *ui;
};

#endif // UPDATEPASSWORD_H
