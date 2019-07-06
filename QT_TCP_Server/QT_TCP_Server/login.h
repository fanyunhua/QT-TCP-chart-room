#ifndef LOGIN_H
#define LOGIN_H

#include "QString"
class Login
{
public:
    Login();
    ~Login();
    bool to_login(QString user,QString pwd);
};

#endif // LOGIN_H
