#ifndef CASHIER_H
#define CASHIER_H
#include <vector>
#include "users.h"
#include "product.h"
#include <iostream>
#include <string>
#include <fstream>
#include "IUser.h"
#include "receipt.h"
using namespace std;

class cashier : public IUser, public users
{
    public:
        int check_if_user_exist(users *w, users *r);
        int login_users(users *w, users *r);
        int register_users(users *w);
        int edit_password(users *w, users *r, char(&new_pass)[25]);
        int add_cart(product *w, product *r, vector<product> &v, double *p);
        int remove_cart(product *w, vector<product> &v, double *p);
        int generate_receipt(receipt *w);
        int search_inventory(product *w, product *r, int x, vector<product> &v);
        int search_inventory(product *w, product *r, double low, double high, vector<product> &v);
};
#endif // CASHIER_H
