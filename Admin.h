#ifndef ADMIN_H
#define ADMIN_H
#include <iostream>
#include <string>
#include <fstream>
#include "question.h"
#include "users.h"
#include "IUser.h"
#include "answer.h"
#include "receipt.h"
#include "report.h"
#include "safe.h"

using namespace std;

class admin : public IUser, public users
{
public:
    int check_if_user_exist(users *w, users *r);
    int login_users(users *w, users *r);
    int register_users(users *w);
    int edit_password(users *w, users *r, char(&new_pass)[25]);
    int answer_question(answer *w);
    string recover_password(users *w, users *r, int x);
    int delete_user(users *w, users *r, int x);
    int delete_receipt(receipt *w);
    int delete_report(report *w);
    int add_phonenumber(char(&phoneNumber)[25]);
    int delete_phonenumber(char(&phoneNumber)[25]);
    double getCurrentProfit(safe *w);
};

#endif // ADMIN_H
