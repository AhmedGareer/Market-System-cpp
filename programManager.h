#ifndef PROGRAMMANAGER_H
#define PROGRAMMANAGER_H
#include "windows.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class programManager
{
public:
    void passwordEntry(char(&password)[25]);
    void load();
    void gotoXY(int x, int y);
    void ShowConsoleCursor(bool showFlag);
    void encrypt(char(&x)[25]);
    void decrypt(char(&x)[25]);
    template <typename Type>
    void newline_remover(Type& x)
    {
        x[strlen(x)-1] = '\0';
    }
    template <typename Type3>
    int constrains_num(Type3& x, int y)
    {
        if(y==6) //Numbers and dots (Price)
        {
            if(x <= 0)
                return 1;
            char y[25];
            sprintf(y, "%f", x);
            if(strlen(y)>=14)
                return 1;
            return 0;
        }
        if(y==7) //Positive Numbers only (Quantity)
        {
            if(x <= 0)
                return 1;
            char y[25];
            sprintf(y, "%lld", x);
            if(strlen(y) >=15)
                return 1;
            return 0;
        }
    }
    template <typename Type2>
    int constrains(Type2& x, int y)
    {
        fflush(stdin);
        cin.clear();
        if(y==1) //UserNames, Passwords 1-20
        {
            if((strlen(x) > 20)||(strlen(x)==0))
                return 1;
            else
                return 0;
        }
        if(y==0) //Empty barcodes
        {
            if(strlen(x) == 0)
                return 1;
            else
                return 0;
        }
        if(y==2) //Letters and spaces only. (Product type)
        {
            if(strlen(x) > 20)
                return 1;
            for(int i=0;i<strlen(x);i++)
            {
                if(!(isalpha(x[i])) && (!isspace(x[i])))
                    return 1;
            }
            return 0;
        }
        if(y==3) //Numbers (Company Phoneno)
        {
            if(strlen(x) > 45)
                return 1;
            for(int i=0;i<strlen(x);i++)
            {
                if(!(isdigit(x[i])) && (!isspace(x[i])) && (x[i] != ','))
                    return 1;
            }
            return 0;
        }
        if(y==4) //Letters and numbers only. (UserNames and Passwords, barcodes)
        {
            if(strlen(x) > 20)
                return 1;
            for(int i=0;i<strlen(x);i++)
            {
                if(!(isalnum(x[i])))
                    return 1;
            }
            return 0;
        }
        if(y==5) //Letters, numbers and spaces (Product Names, company names)
        {
            if(strlen(x) > 20)
                return 1;
            for(int i=0;i<strlen(x);i++)
            {
                if(!(isalnum(x[i])) && (!isspace(x[i])))
                    return 1;
            }
            return 0;
        }
        if(y==8) //Questions, Answers 1-300
        {
            if((strlen(x) > 300)||(strlen(x)==0))
                return 1;
            else
                return 0;
        }
        if(y==9) //All product inputs 1-20
        {
            if((strlen(x) > 20)||(strlen(x)==0))
                return 1;
            else
                return 0;
        }
        if(y==10) //Numbers (Company Phoneno)
        {
            if(strlen(x) > 20)
                return 1;
            for(int i=0;i<strlen(x);i++)
            {
                if(!(isdigit(x[i])))
                    return 1;
            }
            return 0;
        }
    }
};


#endif // PROGRAMMANAGER_H
