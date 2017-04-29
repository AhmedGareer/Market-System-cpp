#ifndef OFFICER_H
#define OFFICER_H
#include "users.h"
#include "product.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "IUser.h"
using namespace std;

class officer : public IUser, public users
{
public:
    int check_if_user_exist(users *w, users *r);
    int login_users(users *w, users *r);
    int register_users(users *w);
    int edit_password(users *w, users *r, char(&new_pass)[25]);
    int delete_inventory(product *w, product *r);
    int shortage_check(product *w, product *r, vector<product> &v);
    int add_inventory(product *w);
    int edit_inventory(product *w, product *r, int x);
    int search_inventory(product *w, product *r, int x, vector<product> &v);
    int search_inventory(product *w, product *r, double low, double high, vector<product> &v);
};
#endif // OFFICER_H
