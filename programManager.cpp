#include "programManager.h"
#include <conio.h>
#include <iostream>
#include "windows.h"
#include <string>
#include <fstream>

using namespace std;

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE); // used for goto
COORD CursorPosition; // used for goto

HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE); //Removing cursor
CONSOLE_CURSOR_INFO cursorInfo; //Removing cursor

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

//---------------------------------

void programManager::load()
{
    ifstream read;
    char loading = 219;
    string loading_screen;
    int loading_counter = 5;
    read.open("loading_screen.txt", ios::app);
    SetConsoleTextAttribute(hConsole, (FOREGROUND_GREEN | FOREGROUND_INTENSITY));
    //system("COLOR 0A");
    while(getline(read, loading_screen))
    {
        gotoXY(8,loading_counter); cout<<"|"<<loading_screen<<" |"<<"\n";
        loading_counter++;
    }
    read.close();
    gotoXY(8,15);

    for (int i=0;i<64;i++)
    {
        Sleep(20);
        cout<<loading;
    }
    Sleep(500);
    system("cls");
}

//--------------------------------

void programManager::gotoXY(int x, int y)
{
	CursorPosition.X = x;
	CursorPosition.Y = y;
	SetConsoleCursorPosition(console,CursorPosition);
}

//--------------------------------

void programManager::ShowConsoleCursor(bool showFlag)
{
    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = showFlag; // Cursor avaliability
    SetConsoleCursorInfo(out, &cursorInfo);
}

//---------------------------------

void programManager::encrypt(char(&x)[25])
{
    for(int i=0;i<strlen(x);i++)
    {
        x[i]=x[i]+1;
    }
}

//--------------------------------

void programManager::decrypt(char(&x)[25])
{
    for(int i=0;i<strlen(x);i++)
    {
        x[i]=x[i]-1;
    }
}

void programManager::passwordEntry(char(&password)[25])
{
    int i;
    char c;
    for(i=0;(c=getch())!='\r';)
    {
        if(c!=8) // 8 dah el ASCII code bta3 el backspace.
        {
            if(i<20)
            {
                password[i]=c;
                cout<<"*";
                i++;
            }
        }
        else
        {
            i--;
            if(i<0) //3shan lw dosna backspace w hwa asasn mfesh 7roof aw el "i" wslt lel zero, mtb2ash bel negative.
                i++;
            else
                cout<<"\b \b";
        }
    }
    password[i]='\0';//B3ml terminate point 3shan anhe el klma.
    cout<<"\n";
}
