#include "Admin.h"
#include "users.h"
#include <iostream>
#include "windows.h"
#include <stdio.h>
#include <string>
#include <fstream>
#include "fileManagement.h"

using namespace std;

fileManagement file_admin;



int admin::edit_password(users *w, users *r, char(&new_pass)[25])
{
    if(file_admin.Edit("admins.dat", w, r, new_pass) == 1)
        return 1;
    else
        return 0;
}


string admin::recover_password(users *w, users *r, int x)
{
    ifstream read;
    string enter, rec_pass;
    if(x==1)
        enter = "admins.dat";
    if(x==2)
        enter = "cashiers.dat";
    if(x==3)
        enter = "customers.dat";
    if(x==4)
        enter = "inventory_officers.dat";
    read.open(enter.c_str(), ios::app | ios::binary);
    for(;;)
    {
        if(read.read((char*) &(*r), sizeof(*r)))
        {
            if(strcmp(r->username, w->username) == 0)
            {
                read.close();
                rec_pass = r->password;
                return rec_pass;
            }
        }
        else
            break;
    }
    read.close();
    return "";
}

//--------------------------------

int admin::delete_user(users *w, users *r, int x)
{
    string enter;
    if(x==1)
        enter = "admins.dat";
    if(x==2)
        enter = "cashiers.dat";
    if(x==3)
        enter = "customers.dat";
    if(x==4)
        enter = "inventory_officers.dat";
    if(file_admin.Delete(enter, w, r) == 1)
        return 1;
    else
        return 0;
}

//-------------------------------------------------------- admin login

int admin::login_users(users *w, users *r)
{
    if(file_admin.Search("admins.dat", w, r) == 1)
        return 1;
    else
        return 0;
}

int admin::register_users(users *w)
{
    file_admin.Add("admins.dat", w);
    return 1;
}

int admin::answer_question(answer *w)
{
    ifstream read;
    ofstream write;
    long long int reader;
    read.open("AnsweredID.dat", ios::app | ios::binary);
    while(read.read((char*) &reader, sizeof(reader)))
    {
        if(w->id == reader)
        {
            read.close();
            return 0;
        }
    }
    read.close();
    write.open("answers.dat", ios::app | ios::binary);
    write.write((char*) &(*w), sizeof(*w));
    write.close();
    write.open("AnsweredID.dat", ios::app | ios::binary);
    write.write((char*) &w->id, sizeof(w->id));
    write.close();
    return 1;
}

//--------------------------------------------------

int admin::check_if_user_exist(users *w, users *r)
{
    ifstream read;
    read.open("admins.dat", ios::app | ios::binary);
    for(;;)
    {
        if(read.read((char*) &(*r), sizeof(*r)))
        {
            if( (strcmp(r->username, w->username) == 0) )
            {
                read.close();
                return 1;
            }
        }
        else
            break;
    }
    read.close();
    return 0;
}

int admin::delete_receipt(receipt *w)
{
    receipt *r = new receipt;
    ifstream read;
    ofstream write;
    int checker = 0, result;
    read.open("receipts.dat", ios::app | ios::binary);
    write.open("receipts1", ios::app | ios::binary);
    for(;;)
    {
        if(read.read((char*) &(*r), sizeof(*r)))
        {
            if(r->getID() == w->getID())
                checker = 1;
            else
                write.write((char*) &(*r), sizeof(*r));
        }
        else
            break;
    }
    read.close();
    write.close();
    result = remove("receipts.dat");
    result = rename("receipts1","receipts.dat");
    return checker;
}

int admin::delete_report(report *w)
{
    report *r = new report;
    ifstream read;
    ofstream write;
    int checker = 0, result;
    read.open("reports.dat", ios::app | ios::binary);
    write.open("reports1", ios::app | ios::binary);
    for(;;)
    {
        if(read.read((char*) &(*r), sizeof(*r)))
        {
            if(r->getID() == w->getID())
                checker = 1;
            else
                write.write((char*) &(*r), sizeof(*r));
        }
        else
            break;
    }
    read.close();
    write.close();
    result = remove("reports.dat");
    result = rename("reports1","reports.dat");
    return checker;
}

int admin::add_phonenumber(char(&phoneNumber)[25])
{
    ofstream write;
    write.open("phonenumbers.dat", ios::app | ios::binary);
    write.write((char*) &(phoneNumber), sizeof(phoneNumber));
    write.close();
    return 1;
}

double admin::getCurrentProfit(safe *w)
{
     return w->getBalance();
}

int admin::delete_phonenumber(char(&phoneNumber) [25])
{
    char reader[25];
    ifstream read;
    ofstream write;
    int checker = 0, result;
    read.open("phonenumbers.dat", ios::app | ios::binary);
    write.open("phonenumbers1", ios::app | ios::binary);
    for(;;)
    {
        if(read.read((char*) &reader, sizeof(reader)))
        {
            if(strcmpi(reader, phoneNumber) == 0)
                checker = 1;
            else
                write.write((char*) &reader, sizeof(reader));
        }
        else
            break;
    }
    read.close();
    write.close();
    result = remove("phonenumbers.dat");
    result = rename("phonenumbers1","phonenumbers.dat");
    return checker;
}
