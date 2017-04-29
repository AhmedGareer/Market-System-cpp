#include "officer.h"
#include <iostream>
#include "windows.h"
#include <stdio.h>
#include <string>
#include <fstream>
#include "fileManagement.h"

using namespace std;

fileManagement file_officer;

int officer::edit_password(users *w, users *r, char(&new_pass)[25])
{
    if(file_officer.Edit("inventory_officers.dat", w, r, new_pass) == 1)
        return 1;
    else
        return 0;
}

int officer::check_if_user_exist(users *w, users *r)
{
    ifstream read;
    read.open("inventory_officers.dat", ios::app | ios::binary);
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


int officer::add_inventory(product *w)
{
    file_officer.Add("inventory.dat", w);
    return 1;
}

//--------------------------------
int officer::delete_inventory(product *w, product *r)
{
    ifstream read;
    ofstream write;
    int checker = 0, result;
    read.open("inventory.dat", ios::app | ios::binary);
    write.open("inventory1.txt", ios::app | ios::binary);
    for(;;)
    {
        if(read.read((char*) &(*r), sizeof(*r)))
        {
            if(strcmpi(r->bar_code, w->bar_code ) ==0 )
                checker = 1;
            else
                write.write((char*) &(*r), sizeof(*r));
        }
        else
            break;
    }
    read.close();
    write.close();
    result = remove("inventory.dat");
    result = rename("inventory1.txt","inventory.dat");
    return checker;
}

//--------------------------------

int officer::edit_inventory(product *w, product *r, int x)
{
    int checker = 0, result;
    char found[25];
    strcpy(found, r->bar_code);
    fstream update;
    update.open("inventory.dat", ios::app | ios::binary);
    update.close();
    update.open("inventory.dat", ios::in | ios::out | ios::binary);
    for(;;)
    {
        int startposition = update.tellg();
        if(update.read((char*) &(*r), sizeof(*r)))
        {
            if(strcmpi(r->bar_code, found) == 0)
            {
                checker = 1;
                update.seekp(startposition);
                if(x==1) //Name
                {
                    strcpy(r->name, w->name);
                    update.write((char*) &(*r), sizeof(*r));
                }
                else if(x==2) //ID
                {
                    strcpy(r->bar_code, w->bar_code);
                    update.write((char*) &(*r), sizeof(*r));
                }
                else if(x==3) //Type
                {
                    strcpy(r->type, w->type);
                    update.write((char*) &(*r), sizeof(*r));
                }
                else if(x==4) //Price
                {
                    r->price = w->price;
                    update.write((char*) &(*r), sizeof(*r));
                }
                else if(x==5) //Quantity
                {
                    r->quantity = w->quantity;
                    update.write((char*) &(*r), sizeof(*r));
                }
                else if(x==6) //Company's Name
                {
                    strcpy(r->company_name, w->company_name);
                    update.write((char*) &(*r), sizeof(*r));
                }
                else if(x==7) //Company's PhoneNumber
                {
                    strcpy(r->company_phoneno, w->company_phoneno);
                    update.write((char*) &(*r), sizeof(*r));
                }
                else if(x==8)
                {
                    strcpy(r->name, w->name);
                    strcpy(r->bar_code, w->bar_code);
                    strcpy(r->type, w->type);
                    r->price = w->price;
                    r->quantity = w->quantity;
                    strcpy(r->company_name, w->company_name);
                    strcpy(r->company_phoneno, w->company_phoneno);
                    update.write((char*) &(*r), sizeof(*r));
                }
                else if(x==9) //Purchases manipulating quantity
                {
                    r->quantity -= w->quantity;
                    update.write((char*) &(*r), sizeof(*r));
                }
            }
        }
        else
            break;
    }
    update.close();
    return checker;
}

//--------------------------------

int officer::search_inventory(product *w, product *r, int x, vector<product> &v)
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

int officer::search_inventory(product *w, product *r, double low, double high, vector<product> &v)
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

//----------------------------------------------------------------

int officer::shortage_check(product *w, product *r, vector<product> &v)
{
    ifstream read;
    v.clear();
    int checker = 0;
    read.open("inventory.dat", ios::app | ios::binary);
    for(;;)
    {
        if(read.read((char*) &(*r), sizeof(*r)))
        {
            if(r->quantity < 10)
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

//--------------------------------------------------------

int officer::login_users(users *w, users *r)
{
    if(file_officer.Search("inventory_officers.dat", w, r) == 1)
        return 1;
    else
        return 0;
}

int officer::register_users(users *w)
{
    file_officer.Add("inventory_officers.dat", w);
    return 1;
}
