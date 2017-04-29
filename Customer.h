#ifndef CUSTOMER_H
#define CUSTOMER_H
#include "users.h"
#include "question.h"
#include <iostream>
#include <string>
#include "IUser.h"
#include <fstream>
#include "product.h"
#include <vector>
#include "report.h"

using namespace std;

class customer : public IUser, public users
{
public:
    int check_if_user_exist(users *w, users *r);
    int login_users(users *w, users *r);
    int register_users(users *w);
    int edit_password(users *w, users *r, char(&new_pass)[25]);
    int add_question(question *w);
    int add_report(report *w);
    int search_inventory(product *w, product *r, int x, vector<product> &v);
    int search_inventory(product *w, product *r, double low, double high, vector<product> &v);
};

#endif // CUSTOMER_H
