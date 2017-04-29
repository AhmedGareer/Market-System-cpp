#include "Customer.h"
#include "users.h"
#include <iostream>
#include "windows.h"
#include <stdio.h>
#include <string>
#include <fstream>
#include "fileManagement.h"

using namespace std;

fileManagement file_customer;

int customer::edit_password(users *w, users *r, char(&new_pass)[25])
{
    if(file_customer.Edit("customers.dat", w, r, new_pass) == 1)
        return 1;
    else
        return 0;
}

int customer::add_question(question *w)
{
    ofstream write;
    ifstream read;
    long long int temp = -1, reader;
    read.open("CurrentID.dat", ios::app | ios::binary);
    while(read.read((char*) &reader, sizeof(reader)))
        temp = reader;
    read.close();
    temp++;
    write.open("CurrentID.dat", ios::binary);
    write.write((char*) &temp, sizeof(temp));
    write.close();
    w->id = temp;
    write.open("questions.dat", ios::app | ios::binary);
    write.write((char*) &(*w), sizeof(*w));
    write.close();
    return 1;
}

//-----------------------

int customer::login_users(users *w, users *r)
{
    if(file_customer.Search("customers.dat", w, r) == 1)
        return 1;
    else
        return 0;
}

int customer::register_users(users *w)
{
    file_customer.Add("customers.dat", w);
    return 1;
}

int customer::check_if_user_exist(users *w, users *r)
{
    ifstream read;
    read.open("customers.dat", ios::app | ios::binary);
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

int customer::search_inventory(product *w, product *r, int x, vector<product> &v)
{
    ifstream read;
    v.clear();
    read.close();
    int checker = 0;
    read.open("inventory.dat", ios::app | ios::binary);
    for(;;)
    {
        if(read.read((char*) &(*r), sizeof(*r)))
        {
            if(x==1) //Name
            {
                if(strcmpi(r->name, w->name) == 0)
                {
                    checker = 1;
                    v.push_back(*r);
                }
            }
            else if(x==2) //ID
            {
                if(strcmpi(r->bar_code, w->bar_code) == 0)
                {
                    checker = 1;
                    v.push_back(*r);
                    read.close();
                    return checker;
                }
            }
            else if(x==3) //Type
            {
                if(strcmpi(r->type, w->type) == 0)
                {
                    checker = 1;
                    v.push_back(*r);
                }
            }
            else if(x==4) //Price
            {
                if(r->price == w->price)
                {
                    checker = 1;
                    v.push_back(*r);
                }
            }
            else if(x==5) //Quantity
            {
                if(r->quantity == w->quantity)
                {
                    checker = 1;
                    v.push_back(*r);
                }
            }
            else if(x==6) //Company's Name
            {
                if(strcmpi(r->company_name, w->company_name) == 0)
                {
                    checker = 1;
                    v.push_back(*r);
                }
            }
            else if(x==7) //Company's PhoneNumber
            {
                if(strcmpi(r->company_phoneno, w->company_phoneno) == 0)
                {
                    checker = 1;
                    v.push_back(*r);
                }
            }
        }
        else
            break;
    }
    read.close();
    return checker;
}

//--------------------------------

int customer::search_inventory(product *w, product *r, double low, double high, vector<product> &v)
{
    ifstream read;
    v.clear();
    read.close();
    int checker = 0;
    read.open("inventory.dat", ios::app | ios::binary);
    for(;;)
    {
        if(read.read((char*) &(*r), sizeof(*r)))
        {
            if(high >= r->price && r->price >= low)
            {
                checker = 1;
                v.push_back(*r);
            }
        }
        else
            break;
    }
    read.close();
    return checker;
}

int customer::add_report(report *w)
{
    ofstream write;
    ifstream read;
    long long int temp = -1, reader;
    read.open("ReportID.dat", ios::app | ios::binary);
    while(read.read((char*) &reader, sizeof(reader)))
        temp = reader;
    read.close();
    temp++;
    write.open("ReportID.dat", ios::binary);
    write.write((char*) &temp, sizeof(temp));
    write.close();
    w->setID(temp);
    write.open("reports.dat", ios::app | ios::binary);
    write.write((char*) &(*w), sizeof(*w));
    write.close();
    return 1;
}
