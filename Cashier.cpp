#include "Cashier.h"
#include "users.h"
#include <iostream>
#include "windows.h"
#include <conio.h>
#include <string>
#include <fstream>
#include "fileManagement.h"

using namespace std;

fileManagement file_cashier;

int cashier::login_users(users *w, users *r)
{
    if(file_cashier.Search("cashiers.dat", w, r) == 1)
        return 1;
    else
        return 0;
}

int cashier::register_users(users *w)
{
    file_cashier.Add("cashiers.dat", w);
    return 1;
}

int cashier::add_cart(product *w, product *r, vector<product> &v, double *p)
{
    ifstream read;
    read.close();
    int checker = 0;
    read.open("inventory.dat", ios::app | ios::binary);
    for(;;)
    {
        if(read.read((char*) &(*r), sizeof(*r)))
        {
            if(strcmpi(r->bar_code, w->bar_code) == 0)
            {
                r->quantity = w->quantity;
                v.push_back(*r);
                *p = 0;
                checker = 1;
                read.close();
                vector<product>::iterator counter; //Check whole vector
                for ( counter = v.begin(); counter != v.end(); counter++ )
                *p += counter->price*counter->quantity;
                return checker;
            }
        }
        else
            break;
    }
    read.close();
    return checker;
}

int cashier::remove_cart(product *w, vector<product> &v, double *p)
{
    int checker = 0;
    vector<product>::iterator counter; //Check whole vector
    for ( counter = v.begin(); counter != v.end();)
    {
        if(strcmpi(w->bar_code, counter->bar_code) == 0)
        {
            checker = 1;
            *p -= counter->price*counter->quantity;
            v.erase(counter);
        }
        else
            counter++;
    }
    return checker;
}

int cashier::check_if_user_exist(users *w, users *r)
{
    ifstream read;
    read.open("cashiers.dat", ios::app | ios::binary);
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

int cashier::edit_password(users *w, users *r, char(&new_pass)[25])
{

    if(file_cashier.Edit("cashiers.dat", w, r, new_pass) == 1)
        return 1;
    else
        return 0;
}

int cashier::generate_receipt(receipt *w)
{
    ofstream write;
    ifstream read;
    long long int temp = -1, reader;
    read.open("ReceiptID.dat", ios::app | ios::binary);
    while(read.read((char*) &reader, sizeof(reader)))
        temp = reader;
    read.close();
    temp++;
    write.open("ReceiptID.dat", ios::binary);
    write.write((char*) &temp, sizeof(temp));
    write.close();
    w->setID(temp);
    write.open("receipts.dat", ios::app | ios::binary);
    write.write((char*) &(*w), sizeof(*w));
    write.close();
    return 1;
}

int cashier::search_inventory(product *w, product *r, int x, vector<product> &v)
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

int cashier::search_inventory(product *w, product *r, double low, double high, vector<product> &v)
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
