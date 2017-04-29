#ifndef IUSER_H
#define IUSER_H
#include <iostream>
#include <string>
#include <fstream>
#include "users.h"

using namespace std;

class IUser
{
    public:
        virtual int login_users(users *w, users *r) = 0;
        virtual int register_users(users *w) = 0;
        virtual int check_if_user_exist(users *w, users *r) = 0;
        virtual int edit_password(users *w, users *r, char(&new_pass)[25]) = 0;
};


#endif // IUSER_H
