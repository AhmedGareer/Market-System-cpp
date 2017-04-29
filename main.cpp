#include <iostream>
#include <conio.h>
#include "windows.h"
#include "users.h"
#include <fstream>
#include "Admin.h"
#include "programManager.h"
#include "Customer.h"
#include "inventory.h"
#include "Cashier.h"
#include "officer.h"
#include "question.h"
#include "answer.h"
#include "receipt.h"
#include "cart.h"
#include "report.h"
#include "safe.h"

using namespace std;

enum userNames {Admins = 1, Officers = 2, Cashiers = 3, Customers = 4};

userNames operator+(userNames r, int menu_item)
{
   return static_cast<userNames>(0 + menu_item);
}

double safe::balance = 0;

int main()
{
    admin* type1_read = new admin;
    admin* type1_write = new admin;
    cashier* type2_read = new cashier;
    cashier* type2_write = new cashier;
    customer* type3_read = new customer;
    customer* type3_write = new customer;
    officer* type4_read = new officer;
    officer* type4_write = new officer;
    safe* manager = new safe;
    question* ask_read = new question;
    question* ask_write = new question;
    answer* answer_read = new answer;
    answer* answer_write = new answer;
    receipt* bill = new receipt;
    cart* hold = new cart;
    report* reports = new report;
    programManager* fs = new programManager;
    users* user_reader = new users;
    inventory* inv = new inventory;
    char rec_result[25], new_pass[25], recovered_pass[25], input[25];
    int menu_item=1;
    int x = 4, y = 1, fun_result;
    ofstream write;
    ifstream read;
    ifstream temp;
    userNames r;
    fs->ShowConsoleCursor(false);
    fs->load();
    fs->gotoXY(1,x); cout << "->";
    while(y==1)
    {
        fs->gotoXY(3,1);  cout << "Welcome to our HyperMarket's homepage";
	    fs->gotoXY(3,2);  cout << "=========================================";
	    fs->gotoXY(3,4);  cout << "[1] Login";
		fs->gotoXY(3,5);  cout << "[2] Register";
		fs->gotoXY(3,6);  cout << "[3] Close The Program";
		system("pause>null");
		fflush(stdin);
        cin.clear();
        if(GetAsyncKeyState(VK_DOWN) & 0x8000 && x != 6) //down button pressed >>>>>>>>>> 8
			{
				fs->gotoXY(1,x); cout << "  ";
				x++;
				fs->gotoXY(1,x); cout << "-> ";
				menu_item++;
				continue;
			}
			if(GetAsyncKeyState(VK_DOWN) & 0x8000 && x == 6) //down button pressed >>>>>>>>>> 8
			{
				fs->gotoXY(1,x); cout << "  ";
				fs->gotoXY(1,4); cout << "-> ";
				x=4;
				menu_item=1;
				continue;
			}
		if(GetAsyncKeyState(VK_UP) & 0x8000 && x != 4) //up button pressed
			{
				fs->gotoXY(1,x); cout << "  ";
				x--;
				fs->gotoXY(1,x); cout << "-> ";
				menu_item--;
				continue;
			}
			if(GetAsyncKeyState(VK_UP) & 0x8000 && x == 4) //up button pressed
			{
				fs->gotoXY(1,x); cout << "  ";
				fs->gotoXY(1,6); cout << "-> ";
				x=6;
				menu_item=3;
				continue;
			}
		if(GetAsyncKeyState(VK_RETURN)& 0x8000 )
        {
        switch(menu_item)
        {
        case 1 :
            y = 2;
            system("cls");
            x=4;
            menu_item=1;
            fs->gotoXY(1,x); cout << "-> ";
            while(y==2)
            {
                fs->gotoXY(3,1);  cout << "User Type (Login)";
                fs->gotoXY(3,2);  cout << "=========================================";
                fs->gotoXY(3,4);  cout << "[1] Admin";
                fs->gotoXY(3,5);  cout << "[2] Inventory Officer";
                fs->gotoXY(3,6);  cout << "[3] Cashier";
                fs->gotoXY(3,7);  cout << "[4] Customer";
                fs->gotoXY(3,8);  cout << "[5] Back";
                system("pause>null");
                fflush(stdin);
                cin.clear();
                if(GetAsyncKeyState(VK_DOWN) & 0x8000 && x != 8) //down button pressed >>>>>>>>>> 8
                {
                    fs->gotoXY(1,x); cout << "  ";
                    x++;
                    fs->gotoXY(1,x); cout << "->";
                    menu_item++;
                    continue;
                }
                if(GetAsyncKeyState(VK_DOWN) & 0x8000 && x == 8) //down button pressed >>>>>>>>>> 8
                {
                    fs->gotoXY(1,x); cout << "  ";
                    fs->gotoXY(1,4); cout << "->";
                    x=4;
                    menu_item=1;
                    continue;
                }
                if(GetAsyncKeyState(VK_UP) & 0x8000 && x != 4) //up button pressed
                {
                    fs->gotoXY(1,x); cout << "  ";
                    x--;
                    fs->gotoXY(1,x); cout << "->";
                    menu_item--;
                    continue;
                }
                if(GetAsyncKeyState(VK_UP) & 0x8000 && x == 4) //up button pressed
                {
                    fs->gotoXY(1,x); cout << "  ";
                    fs->gotoXY(1,8); cout << "->";
                    x=8;
                    menu_item=5;
                    continue;
                }
                if(GetAsyncKeyState(VK_RETURN)& 0x8000 )
                {
                r = r + menu_item;
                switch(r)
                {
                case Admins : //Admin login.
                    system("cls");
                    cout<<"Input Username : ";
                    fgets(type1_write->username, sizeof(type1_write->username), stdin);
                    fflush(stdin);
                    fs->newline_remover(type1_write->username);
                    fs->encrypt(type1_write->username);
                    cout<<"Input Password : ";
                    fs->passwordEntry(type1_write->password);
                    fs->encrypt(type1_write->password);
                    fun_result = type1_write->login_users(type1_write, type1_read);
                    if (fun_result == 1) //Admin's functions.
                    {
                        cout<<"Login successful. Press any key to proceed.\n"<<endl;
                        strcpy(rec_result, type1_write->username);
                        fs->decrypt(rec_result);
                        system("pause>null");
                        y = 3;
                        system("cls");
                        menu_item=1;
                        x=4;
                        fs->gotoXY(1,x); cout << "->";
                        while(y==3)
                        {
                            fs->gotoXY(3,1);  cout << "Logged in with username : "<<rec_result;
                            fs->gotoXY(3,2);  cout << "===============================================";
                            fs->gotoXY(3,4);  cout << "[1] Register Admin";
                            fs->gotoXY(3,5);  cout << "[2] Register Cashier";
                            fs->gotoXY(3,6);  cout << "[3] Register Inventory Officer";
                            fs->gotoXY(3,7);  cout << "[4] Passwords Recovery";
                            fs->gotoXY(3,8);  cout << "[5] Change Passwords";
                            fs->gotoXY(3,9);  cout << "[6] Answer Questions";
                            fs->gotoXY(3,10); cout << "[7] Delete Users";
                            fs->gotoXY(3,11); cout << "[8] View All Users";
                            fs->gotoXY(3,12); cout << "[9] View All Receipts";
                            fs->gotoXY(3,13); cout << "[10] Delete Receipt";
                            fs->gotoXY(3,14); cout << "[11] View All Reports";
                            fs->gotoXY(3,15); cout << "[12] Delete Report";
                            fs->gotoXY(3,16); cout << "[13] Add PhoneNumber";
                            fs->gotoXY(3,17); cout << "[14] Delete PhoneNumber";
                            fs->gotoXY(3,18); cout << "[15] Log off";
                            system("pause>null");
                            fflush(stdin);
                            cin.clear();
                            if(GetAsyncKeyState(VK_DOWN)& 0x8000 && x != 18) //down button pressed >>>>>>>>>> 8
                            {
                            fs->gotoXY(1,x); cout << "  ";
                            x++;
                            fs->gotoXY(1,x); cout << "->";
                            menu_item++;
                            continue;
                            }
                            if(GetAsyncKeyState(VK_DOWN)& 0x8000 && x == 18) //down button pressed >>>>>>>>>> 8
                            {
                            fs->gotoXY(1,x); cout << "  ";
                            fs->gotoXY(1,4); cout << "->";
                            x=4;
                            menu_item=1;
                            continue;
                            }
                            if(GetAsyncKeyState(VK_UP)& 0x8000 && x != 4) //up button pressed
                            {
                                fs->gotoXY(1,x); cout << "  ";
                                x--;
                                fs->gotoXY(1,x); cout << "->";
                                menu_item--;
                                continue;
                            }
                            if(GetAsyncKeyState(VK_UP)& 0x8000 && x == 4) //up button pressed
                            {
                                fs->gotoXY(1,x); cout << "  ";
                                fs->gotoXY(1,18); cout << "->";
                                x=18;
                                menu_item=15;
                                continue;
                            }
                            if(GetAsyncKeyState(VK_RETURN)& 0x8000 )
                            {
                            switch(menu_item)
                            {
                            case 1 : //Register Admin
                                system("cls");
                                cout<<"Input Username : ";
                                fgets(type1_write->username, sizeof(type1_write->username), stdin);
                                fflush(stdin);
                                fs->newline_remover(type1_write->username);
                                if(fs->constrains(type1_write->username, 4) == 1)
                                {
                                    cout<<"Usernames can't have symbols. Press any key to go back.\n";
                                    system("pause>null");
                                    system("cls");
                                    x=4;
                                    menu_item=1;
                                    fs->gotoXY(1,x); cout << "->";
                                    break;
                                }
                                if(fs->constrains(type1_write->username, 1) == 1)
                                {
                                    cout<<"Usernames and passwords are 1-20 characters long. Press any key to go back.\n";
                                    system("pause>null");
                                    system("cls");
                                    x=4;
                                    menu_item=1;
                                    fs->gotoXY(1,x); cout << "->";
                                    break;
                                }
                                fs->encrypt(type1_write->username);
                                cout<<"Input Password : ";
                                fs->passwordEntry(type1_write->password);
                                if(fs->constrains(type1_write->password, 4) == 1)
                                {
                                    cout<<"Passwords can't have symbols. Press any key to go back.\n";
                                    system("pause>null");
                                    system("cls");
                                    x=4;
                                    menu_item=1;
                                    fs->gotoXY(1,x); cout << "->";
                                    break;
                                }
                                if(fs->constrains(type1_write->password, 1) == 1)
                                {
                                    cout<<"Usernames and passwords are 1-20 characters long. Press any key to go back.\n";
                                    system("pause>null");
                                    system("cls");
                                    x=4;
                                    menu_item=1;
                                    fs->gotoXY(1,x); cout << "->";
                                    break;
                                }
                                fs->encrypt(type1_write->password);
                                fun_result = type1_write->check_if_user_exist(type1_write, type1_read);
                                if(fun_result == 1)
                                {
                                    cout<<"\nUser Name already in use, press any key to try again.\n";
                                    system("pause>null");
                                    system("cls");
                                    x=4;
                                    menu_item=1;
                                    fs->gotoXY(1,x); cout << "->";
                                    break;
                                }
                                fun_result = type1_write->register_users(type1_write);
                                if(fun_result == 1)
                                {
                                    cout<<"\nRegisteration successful\nPress any key to continue..\n";
                                    system("pause>null");
                                }
                                system("cls");
                                x=4;
                                menu_item=1;
                                fs->gotoXY(1,x); cout << "->";
                                break;
                            case 2 : //Register Cashier
                                system("cls");
                                cout<<"Input Username : ";
                                fgets(type2_write->username, sizeof(type2_write->username), stdin);
                                fflush(stdin);
                                fs->newline_remover(type2_write->username);
                                if(fs->constrains(type2_write->username, 4) == 1)
                                {
                                    cout<<"Usernames can't have symbols. Press any key to go back.\n";
                                    system("pause>null");
                                    system("cls");
                                    x=4;
                                    menu_item=1;
                                    fs->gotoXY(1,x); cout << "->";
                                    break;
                                }
                                if(fs->constrains(type2_write->username, 1) == 1)
                                {
                                    cout<<"Usernames and passwords are 1-20 characters long. Press any key to go back.\n";
                                    system("pause>null");
                                    system("cls");
                                    x=4;
                                    menu_item=1;
                                    fs->gotoXY(1,x); cout << "->";
                                    break;
                                }
                                fs->encrypt(type2_write->username);
                                cout<<"Input Password : ";
                                fs->passwordEntry(type2_write->password);
                                if(fs->constrains(type2_write->password, 4) == 1)
                                {
                                    cout<<"Passwords can't have symbols. Press any key to go back.\n";
                                    system("pause>null");
                                    system("cls");
                                    x=4;
                                    menu_item=1;
                                    fs->gotoXY(1,x); cout << "->";
                                    break;
                                }
                                if(fs->constrains(type2_write->password, 1) == 1)
                                {
                                    cout<<"Usernames and passwords are 1-20 characters long. Press any key to go back.\n";
                                    system("pause>null");
                                    system("cls");
                                    x=4;
                                    menu_item=1;
                                    fs->gotoXY(1,x); cout << "->";
                                    break;
                                }
                                fs->encrypt(type2_write->password);
                                cin.clear();
                                fun_result = type2_write->check_if_user_exist(type2_write, type2_read);
                                if(fun_result == 1)
                                {
                                    cout<<"\nUser Name already in use, press any key to try again.\n";
                                    system("pause>null");
                                    system("cls");
                                    x=4;
                                    menu_item=1;
                                    fs->gotoXY(1,x); cout << "->";
                                    break;
                                }
                                fun_result = type2_write->register_users(type2_write);
                                if(fun_result == 1)
                                {
                                    cout<<"\nRegisteration successful\nPress any key to continue..\n"; //Register Cashier [/end]
                                    system("pause>null");
                                }
                                system("cls");
                                x=4;
                                menu_item=1;
                                fs->gotoXY(1,x); cout << "->";
                                break;
                            case 3 : //Register Inventory Officer.
                                system("cls");
                                cout<<"Input Username : ";
                                fgets(type4_write->username, sizeof(type4_write->username), stdin);
                                fflush(stdin);
                                fs->newline_remover(type4_write->username);
                                if(fs->constrains(type4_write->username, 4) == 1)
                                {
                                    cout<<"Usernames can't have symbols. Press any key to go back.\n";
                                    system("pause>null");
                                    system("cls");
                                    x=4;
                                    menu_item=1;
                                    fs->gotoXY(1,x); cout << "->";
                                    break;
                                }
                                if(fs->constrains(type4_write->username, 1) == 1)
                                {
                                    cout<<"Usernames and passwords are 1-20 characters long. Press any key to go back.\n";
                                    system("pause>null");
                                    system("cls");
                                    x=4;
                                    menu_item=1;
                                    fs->gotoXY(1,x); cout << "->";
                                    break;
                                }
                                fs->encrypt(type4_write->username);
                                cout<<"Input Password : ";
                                fs->passwordEntry(type4_write->password);
                                if(fs->constrains(type4_write->password, 4) == 1)
                                {
                                    cout<<"Passwords can't have symbols. Press any key to go back.\n";
                                    system("pause>null");
                                    system("cls");
                                    x=4;
                                    menu_item=1;
                                    fs->gotoXY(1,x); cout << "->";
                                    break;
                                }
                                if(fs->constrains(type4_write->password, 1) == 1)
                                {
                                    cout<<"Usernames and passwords are 1-20 characters long. Press any key to go back.\n";
                                    system("pause>null");
                                    system("cls");
                                    x=4;
                                    menu_item=1;
                                    fs->gotoXY(1,x); cout << "->";
                                    break;
                                }
                                fs->encrypt(type4_write->password);
                                cin.clear();
                                fun_result = type4_write->check_if_user_exist(type4_write, type4_read);
                                if(fun_result == 1)
                                {
                                    cout<<"\nUser Name already in use, press any key to try again.\n";
                                    system("pause>null");
                                    system("cls");
                                    x=4;
                                    menu_item=1;
                                    fs->gotoXY(1,x); cout << "->";
                                    break;
                                }
                                fun_result = type4_write->register_users(type4_write);
                                if(fun_result == 1)
                                {
                                    cout<<"\nRegisteration successful\nPress any key to continue..\n"; //Register Inventory Officer [/end]
                                    system("pause>null");
                                }
                                system("cls");
                                x=4;
                                menu_item=1;
                                fs->gotoXY(1,x); cout << "->";
                                break;
                            case 4 : //Recovery Passwords
                                y = 4;
                                system("cls");
                                menu_item=1;
                                x=4;
                                fs->gotoXY(1,x); cout << "->";
                                while(y==4)
                                {
                                    fs->gotoXY(3,1);  cout << "User Type(Password Recovery)";
                                    fs->gotoXY(3,2);  cout << "=================================";
                                    fs->gotoXY(3,4);  cout << "[1] Admin";
                                    fs->gotoXY(3,5);  cout << "[2] Inventory Officer";
                                    fs->gotoXY(3,6);  cout << "[3] Cashier";
                                    fs->gotoXY(3,7);  cout << "[4] Customer";
                                    fs->gotoXY(3,8);  cout << "[5] Back";
                                    system("pause>null");
                                    if(GetAsyncKeyState(VK_DOWN) & 0x8000 && x != 8) //down button pressed >>>>>>>>>> 8
                                    {
                                        fs->gotoXY(1,x); cout << "  ";
                                        x++;
                                        fs->gotoXY(1,x); cout << "->";
                                        menu_item++;
                                        continue;
                                    }
                                    if(GetAsyncKeyState(VK_DOWN) & 0x8000 && x == 8) //down button pressed >>>>>>>>>> 8
                                    {
                                        fs->gotoXY(1,x); cout << "  ";

                                        fs->gotoXY(1,4); cout << "->";
                                        x=4;
                                        menu_item=1;
                                        continue;
                                    }
                                    if(GetAsyncKeyState(VK_UP) & 0x8000 && x != 4) //up button pressed
                                    {
                                        fs->gotoXY(1,x); cout << "  ";
                                        x--;
                                        fs->gotoXY(1,x); cout << "->";
                                        menu_item--;
                                        continue;
                                    }
                                    if(GetAsyncKeyState(VK_UP) & 0x8000 && x == 4) //up button pressed
                                    {
                                        fs->gotoXY(1,x); cout << "  ";

                                        fs->gotoXY(1,8); cout << "->";
                                        x=8;
                                        menu_item=5;
                                        continue;
                                    }
                                    if(GetAsyncKeyState(VK_RETURN)& 0x8000 )
                                    {
                                    switch(menu_item)
                                    {
                                    case 1 : //Admin's password recovery.
                                        system("cls");
                                        cout<<"Input Username : ";
                                        fgets(type1_write->username, sizeof(type1_write->username), stdin);
                                        fflush(stdin);
                                        fs->newline_remover(type1_write->username);
                                        fs->encrypt(type1_write->username);
                                        strcpy(recovered_pass, type1_write->recover_password(type1_write, type1_read, 1).c_str());
                                        if(strcmp(recovered_pass, "") == 0)
                                        {
                                            cout<<"No such a username exists, press any key to continue.\n";
                                            system("pause>null");

                                        }
                                        else
                                        {
                                            fs->decrypt(recovered_pass);
                                            cout<<"Current Password : "<<recovered_pass<<"\n\nPress any key to continue.\n";
                                            system("pause>null");
                                        }
                                        system("cls");
                                        x=4;
                                        menu_item=1;
                                        fs->gotoXY(1,x); cout << "->";
                                        break;
                                    case 2 : //Inventory Officer's password recovery.
                                        system("cls");
                                        cout<<"Input Username : ";
                                        fgets(type4_write->username, sizeof(type4_write->username), stdin);
                                        fflush(stdin);
                                        fs->newline_remover(type4_write->username);
                                        fs->encrypt(type4_write->username);
                                        strcpy(recovered_pass, type1_write->recover_password(type4_write, type4_read, 4).c_str());
                                        if(strcmp(recovered_pass, "") == 0)
                                        {
                                            cout<<"No such a username exists, press any key to continue.\n";
                                            system("pause>null");

                                        }
                                        else
                                        {
                                            fs->decrypt(recovered_pass);
                                            cout<<"Current Password : "<<recovered_pass<<"\n\nPress any key to continue.\n";
                                            system("pause>null");
                                        }
                                        system("cls");
                                        x=4;
                                        menu_item=1;
                                        fs->gotoXY(1,x); cout << "->";
                                        break;
                                    case 3 : //Cashier's password recovery.
                                        system("cls");
                                        cout<<"Input Username : ";
                                        fgets(type2_write->username, sizeof(type2_write->username), stdin);
                                        fflush(stdin);
                                        fs->newline_remover(type2_write->username);
                                        fs->encrypt(type2_write->username);
                                        strcpy(recovered_pass, type1_write->recover_password(type2_write, type2_read, 2).c_str());
                                        if(strcmp(recovered_pass, "") == 0)
                                        {
                                            cout<<"No such a username exists, press any key to continue.\n";
                                            system("pause>null");

                                        }
                                        else
                                        {
                                            fs->decrypt(recovered_pass);
                                            cout<<"Current Password : "<<recovered_pass<<"\n\nPress any key to continue.\n";
                                            system("pause>null");
                                        }
                                        system("cls");
                                        x=4;
                                        menu_item=1;
                                        fs->gotoXY(1,x); cout << "->";
                                        break;
                                    case 4 : //Customer's password recovery.
                                        system("cls");
                                        cout<<"Input Username : ";
                                        fgets(type3_write->username, sizeof(type3_write->username), stdin);
                                        fflush(stdin);
                                        fs->newline_remover(type3_write->username);
                                        fs->encrypt(type3_write->username);
                                        strcpy(recovered_pass, type1_write->recover_password(type3_write, type3_read, 3).c_str());
                                        if(strcmp(recovered_pass, "") == 0)
                                        {
                                            cout<<"No such a username exists, press any key to continue.\n";
                                            system("pause>null");

                                        }
                                        else
                                        {
                                            fs->decrypt(recovered_pass);
                                            cout<<"Current Password : "<<recovered_pass<<"\n\nPress any key to continue.\n";
                                            system("pause>null");
                                        }
                                        system("cls");
                                        x=4;
                                        menu_item=1;
                                        fs->gotoXY(1,x); cout << "->";
                                        break;
                                    case 5 :
                                        y--; //Go Back
                                        system("cls");
                                        x=4;
                                        menu_item=1;
                                        fs->gotoXY(1,x); cout << "->";
                                        break;
                                    }
                                    }
                                }
                                break;
                            case 5 : //Change Password
                                system("cls");
                                cout<<"Input Current Password : ";
                                fs->passwordEntry(type1_write->password);
                                fs->encrypt(type1_write->password);
                                cout<<"Input New Password : ";
                                fs->passwordEntry(new_pass);
                                if(fs->constrains(new_pass, 4) == 1)
                                {
                                    cout<<"Passwords can't have symbols. Press any key to go back.\n";
                                    system("pause>null");
                                    system("cls");
                                    x=4;
                                    menu_item=1;
                                    fs->gotoXY(1,x); cout << "->";
                                    break;
                                }
                                if(fs->constrains(new_pass, 1) == 1)
                                {
                                    cout<<"Passwords are 1-20 characters long. Press any key to go back.\n";
                                    system("pause>null");
                                    system("cls");
                                    x=4;
                                    menu_item=1;
                                    fs->gotoXY(1,x); cout << "->";
                                    break;
                                }
                                fs->encrypt(new_pass);
                                strcpy(type1_write->username, rec_result);
                                fs->encrypt(type1_write->username);
                                fun_result = type1_write->edit_password(type1_write, type1_read, new_pass);
                                if (fun_result == 1)
                                {
                                    cout<<"Password edited successfuly, press any key to continue.\n";
                                    system("pause>null");
                                }
                                else
                                {
                                    cout<<"\nIncorrect Password, press any key to continue.\n===============================================";
                                    system("pause>null");
                                }
                                system("cls");
                                x=4;
                                menu_item=1;
                                fs->gotoXY(1,x); cout << "->";
                                break;
                            case 6 : //Answer Questions
                                {
                                fun_result = 0;
                                int unanswered = 0;
                                system("cls");
                                read.open("questions.dat", ios::app | ios::binary);
                                temp.open("AnsweredID.dat", ios::app | ios::binary);
                                while(read.read((char*) &*(ask_read), sizeof*(ask_read)))
                                {
                                    fun_result = 1;
                                    temp.clear();
                                    temp.seekg(0, ios::beg);
                                    while(temp.read((char*) &answer_read->id, sizeof(answer_read->id)))
                                    {
                                        if(ask_read->id == answer_read->id) //If question was already answered
                                            fun_result = 0;
                                    }
                                    if(fun_result == 1)
                                    {
                                        unanswered = 1;
                                        cout
                                        <<"\nID : "<<ask_read->id
                                        <<"\nQuestion : "<<ask_read->asked_question
                                        <<"\nAsker : "<<ask_read->username
                                        <<"\n===========================================\n";
                                    }
                                }
                                read.close();
                                temp.close();
                                if(unanswered==0)
                                {
                                    cout<<"\nNo questions were found.\n===================================\n\nPress any key to go back.";
                                    system("pause>null");
                                    system("cls");
                                    x=4;
                                    menu_item=1;
                                    fs->gotoXY(1,x); cout << "->";
                                    break;
                                }
                                cout<<"\nPress [1] to answer questions, anything else to go back.\n==========================================================\n\n";
                                fs->ShowConsoleCursor(true);
                                system("pause>null");
                                if(GetKeyState('1') & 0x80 || GetKeyState(VK_NUMPAD1) & 0X80)
                                {
                                    fun_result = 1;
                                    cout<<"\n\nInput username : ";
                                    fgets(answer_write->username, sizeof(answer_write->username), stdin);
                                    fflush(stdin);
                                    fs->newline_remover(answer_write->username);
                                    cout<<"Input Question ID : ";
                                    fgets(input, sizeof(input), stdin);
                                    fflush(stdin);
                                    fs->newline_remover(input);
                                    answer_write->id = atoll(input);
                                    fs->ShowConsoleCursor(false);
                                }
                                else
                                {
                                    fs->ShowConsoleCursor(false);
                                    system("cls");
                                    x=4;
                                    menu_item=1;
                                    fs->gotoXY(1,x); cout << "->";
                                    break;
                                }
                                read.open("questions.dat", ios::app | ios::binary);
                                while(read.read((char*) &*(ask_read), sizeof*(ask_read)))
                                {
                                    if(strcmp(ask_read->username, answer_write->username) == 0 && ask_read->id == answer_write->id)
                                        fun_result++;
                                }
                                read.close();
                                if(fun_result==1)
                                {
                                    cout<<"Username or ID doesn't exist, press any key to go back.";
                                    system("pause>null");
                                    system("cls");
                                    x=4;
                                    menu_item=1;
                                    fs->gotoXY(1,x); cout << "->";
                                    break;
                                }
                                cout<<"Input Answer : ";
                                fgets(answer_write->answered_question, sizeof(answer_write->answered_question), stdin);
                                fflush(stdin);
                                fs->newline_remover(answer_write->answered_question);
                                if(fs->constrains(answer_write->answered_question, 8) == 1)
                                {
                                    cout<<"Answer exceeded range (1-300).";
                                    system("pause>null");
                                    system("cls");
                                    x=4;
                                    menu_item=1;
                                    fs->gotoXY(1,x); cout << "->";
                                    break;
                                }
                                if(type1_write->answer_question(answer_write) == 1)
                                    cout<<"Answer added successfuly, press any key to continue.";
                                else
                                    cout<<"Question was already answered.";
                                system("pause>null");
                                system("cls");
                                x=4;
                                menu_item=1;
                                fs->gotoXY(1,x); cout << "->";
                                break;
                                }
                            case 7 : //Remove users
                                y = 4;
                                system("cls");
                                menu_item=1;
                                x=4;
                                fs->gotoXY(1,x); cout << "->";
                                while(y==4)
                                {
                                    fs->gotoXY(3,1);  cout << "User Type(User Deletion)";
                                    fs->gotoXY(3,2);  cout << "==========================";
                                    fs->gotoXY(3,4);  cout << "[1] Admin";
                                    fs->gotoXY(3,5);  cout << "[2] Inventory Officer";
                                    fs->gotoXY(3,6);  cout << "[3] Cashier";
                                    fs->gotoXY(3,7);  cout << "[4] Customer";
                                    fs->gotoXY(3,8);  cout << "[5] Back";
                                    system("pause>null");
                                    if(GetAsyncKeyState(VK_DOWN)& 0x8000 && x != 8) //down button pressed >>>>>>>>>> 8
                                    {
                                        fs->gotoXY(1,x); cout << "  ";
                                        x++;
                                        fs->gotoXY(1,x); cout << "->";
                                        menu_item++;
                                        continue;
                                    }
                                    if(GetAsyncKeyState(VK_DOWN)& 0x8000 && x == 8) //down button pressed >>>>>>>>>> 8
                                    {
                                        fs->gotoXY(1,x); cout << "  ";

                                        fs->gotoXY(1,4); cout << "->";
                                        x=4;
                                        menu_item=1;
                                        continue;
                                    }
                                    if(GetAsyncKeyState(VK_UP) & 0x8000 && x != 4) //up button pressed
                                    {
                                        fs->gotoXY(1,x); cout << "  ";
                                        x--;
                                        fs->gotoXY(1,x); cout << "->";
                                        menu_item--;
                                        continue;
                                    }
                                    if(GetAsyncKeyState(VK_UP) & 0x8000 && x == 4) //up button pressed
                                    {
                                        fs->gotoXY(1,x); cout << "  ";

                                        fs->gotoXY(1,8); cout << "->";
                                        x=8;
                                        menu_item=5;
                                        continue;
                                    }
                                    if(GetAsyncKeyState(VK_RETURN)& 0x8000 )
                                    {
                                    switch(menu_item)
                                    {
                                    case 1 : //Admin(User Delete)
                                        system("cls");
                                        cout<<"Input Username : ";
                                        fgets(type1_write->username, sizeof(type1_write->username), stdin);
                                        fflush(stdin);
                                        fs->newline_remover(type1_write->username);
                                        fs->encrypt(type1_write->username);
                                        cout<<"Input Password : ";
                                        fs->passwordEntry(type1_write->password);
                                        fs->encrypt(type1_write->password);
                                        fun_result = type1_write->delete_user(type1_write, type1_read, 1);
                                        if (fun_result == 1)
                                        {
                                            cout<<"User deleted successfuly, press any key to continue.\n";
                                            system("pause>null");
                                        }
                                        else
                                        {
                                            cout<<"User Names doesn't exist, press any key to continue.\n===============================================";
                                            system("pause>null");
                                        }
                                        system("cls");
                                        x=4;
                                        menu_item=1;
                                        fs->gotoXY(1,x); cout << "->";
                                        break;
                                    case 2 : //Inventory Officer(User Delete)
                                        system("cls");
                                        cout<<"Input Username : ";
                                        fgets(type4_write->username, sizeof(type4_write->username), stdin);
                                        fflush(stdin);
                                        fs->newline_remover(type4_write->username);
                                        fs->encrypt(type4_write->username);
                                        cout<<"Input Password : ";
                                        fs->passwordEntry(type4_write->password);
                                        fs->encrypt(type4_write->password);
                                        fun_result = type1_write->delete_user(type4_write, type4_read, 4);
                                        if (fun_result == 1)
                                        {
                                            cout<<"User deleted successfuly, press any key to continue.\n";
                                            system("pause>null");
                                        }
                                        else
                                        {
                                            cout<<"User Names doesn't exist, press any key to continue.\n===============================================";
                                            system("pause>null");
                                        }
                                        system("cls");
                                        x=4;
                                        menu_item=1;
                                        fs->gotoXY(1,x); cout << "->";
                                        break;
                                    case 3 : //Cashier(User Delete)
                                        system("cls");
                                        cout<<"Input Username : ";
                                        fgets(type2_write->username, sizeof(type2_write->username), stdin);
                                        fflush(stdin);
                                        fs->newline_remover(type2_write->username);
                                        fs->encrypt(type2_write->username);
                                        cout<<"Input Password : ";
                                        fs->passwordEntry(type2_write->password);
                                        fs->encrypt(type2_write->password);
                                        fun_result = type1_write->delete_user(type2_write, type2_read, 2);
                                        if (fun_result == 1)
                                        {
                                            cout<<"User deleted successfuly, press any key to continue.\n";
                                            system("pause>null");
                                        }
                                        else
                                        {
                                            cout<<"User Names doesn't exist, press any key to continue.\n===============================================";
                                            system("pause>null");
                                        }
                                        system("cls");
                                        x=4;
                                        menu_item=1;
                                        fs->gotoXY(1,x); cout << "->";
                                        break;
                                    case 4 : //Customer(User Delete)
                                        system("cls");
                                        cout<<"Input Username : ";
                                        fgets(type3_write->username, sizeof(type3_write->username), stdin);
                                        fflush(stdin);
                                        fs->newline_remover(type3_write->username);
                                        fs->encrypt(type3_write->username);
                                        cout<<"Input Password : ";
                                        fs->passwordEntry(type3_write->password);
                                        fs->encrypt(type3_write->password);
                                        fun_result = type1_write->delete_user(type3_write, type3_read, 3);
                                        if (fun_result == 1)
                                        {
                                            cout<<"User deleted successfuly, press any key to continue.\n";
                                            system("pause>null");
                                        }
                                        else
                                        {
                                            cout<<"User Names doesn't exist, press any key to continue.\n===============================================";
                                            system("pause>null");
                                        }
                                        system("cls");
                                        x=4;
                                        menu_item=1;
                                        fs->gotoXY(1,x); cout << "->";
                                        break;
                                    case 5 : //Back
                                        y--;
                                        system("cls");
                                        x=4;
                                        menu_item=1;
                                        fs->gotoXY(1,x); cout << "->";
                                        break;
                                    }
                                    }
                                }
                                system("cls");
                                x=4;
                                menu_item=1;
                                fs->gotoXY(1,x); cout << "->";
                                break;
                            case 8 : // View All Users
                                system("cls");
                                cout<<"Users\n========\n";
                                read.close();
                                read.open("admins.dat", ios::app | ios::binary);
                                while(read.read((char*) &*(user_reader), sizeof*(user_reader)))
                                {
                                    fs->decrypt(user_reader->username);
                                    cout<<"Username : "<<user_reader->username<<" - Type : Admin\n";
                                }
                                read.close();
                                read.open("customers.dat", ios::app | ios::binary);
                                while(read.read((char*) &*(user_reader), sizeof*(user_reader)))
                                {
                                    fs->decrypt(user_reader->username);
                                    cout<<"Username : "<<user_reader->username<<" - Type : Customer\n";
                                }
                                read.close();
                                read.open("cashiers.dat", ios::app | ios::binary);
                                while(read.read((char*) &*(user_reader), sizeof*(user_reader)))
                                {
                                    fs->decrypt(user_reader->username);
                                    cout<<"Username : "<<user_reader->username<<" - Type : Cashier\n";
                                }
                                read.close();
                                read.open("inventory_officers.dat", ios::app | ios::binary);
                                while(read.read((char*) &*(user_reader), sizeof*(user_reader)))
                                {
                                    fs->decrypt(user_reader->username);
                                    cout<<"Username : "<<user_reader->username<<" - Type : Inventory Officer\n";
                                }
                                read.close();
                                cout<<"\n\nFinished, press any key to continue.\n";
                                system("pause>null");
                                system("cls");
                                x=4;
                                menu_item=1;
                                fs->gotoXY(1,x); cout << "->";
                                break;
                            case 9 :
                                {
                                system("cls");
                                cout<<"Receipts\n============\n";
                                read.open("receipts.dat", ios::app | ios::binary);
                                manager->setBalance(0);
                                while(read.read((char*) &*(bill), sizeof*(bill)))
                                {
                                    cout<<"Cashier : "<<bill->currentCashier<<"\n\n"
                                    <<"Receipt ID : "<<bill->getID()<<"\n\n"
                                    <<"Date : "<<bill->DateTime<<"\n\n"
                                    <<"Price : "<<bill->priceToPay<<" LE\n\n==========================================\n";
                                    manager->setBalance(manager->getBalance()+bill->priceToPay);
                                }
                                read.close();
                                if(manager->getBalance()==0)
                                    cout<<"\n\nFinished, press any key to continue.\n";
                                else
                                    cout<<"\n\nTotal Balance : "<<type1_write->getCurrentProfit(manager)<<" LE\n\nFinished, press any key to continue.\n";
                                system("pause>null");
                                system("cls");
                                x=4;
                                menu_item=1;
                                fs->gotoXY(1,x); cout << "->";
                                break;
                                }
                            case 10 :
                                system("cls");
                                cout<<"Input ID : ";
                                fgets(input, sizeof(input), stdin);
                                fflush(stdin);
                                fs->newline_remover(input);
                                bill->setID(atoll(input));
                                fun_result = type1_write->delete_receipt(bill);
                                if(fun_result == 1)
                                    cout<<"Receipt deleted.\n";
                                else
                                    cout<<"No such ID exists.\n";
                                system("pause>null");
                                system("cls");
                                x=4;
                                menu_item=1;
                                fs->gotoXY(1,x); cout << "->";
                                break;
                            case 11 :
                                system("cls");
                                cout<<"Reports\n============\n";
                                read.open("reports.dat", ios::app | ios::binary);
                                while(read.read((char*) &*(reports), sizeof*(reports)))
                                    cout<<"UserName : "<<reports->userName<<"\n\n"
                                    <<"Defective Item's Name : "<<reports->itemName<<"\n\n"
                                    <<"Report ID : "<<reports->getID()<<"\n\n"
                                    <<"Comment : "<<reports->comment<<"\n\n==========================================\n";
                                read.close();
                                cout<<"\n\nFinished, press any key to continue.\n";
                                system("pause>null");
                                system("cls");
                                x=4;
                                menu_item=1;
                                fs->gotoXY(1,x); cout << "->";
                                break;
                            case 12 :
                                system("cls");
                                cout<<"Input ID : ";
                                fgets(input, sizeof(input), stdin);
                                fflush(stdin);
                                fs->newline_remover(input);
                                reports->setID(atoll(input));
                                fun_result = type1_write->delete_report(reports);
                                if(fun_result == 1)
                                    cout<<"Report deleted.\n";
                                else
                                    cout<<"No such ID exists.\n";
                                system("pause>null");
                                system("cls");
                                x=4;
                                menu_item=1;
                                fs->gotoXY(1,x); cout << "->";
                                break;
                            case 13 :
                                system("cls");
                                cout<<"Input Phonenumber : ";
                                fgets(input, sizeof(input), stdin);
                                fflush(stdin);
                                fs->newline_remover(input);
                                if(fs->constrains(input, 10) == 1)
                                {
                                    cout<<"Error! Invalid Input.\n";
                                    system("pause>null");
                                    system("cls");
                                    x=4;
                                    menu_item=1;
                                    fs->gotoXY(1,x); cout << "->";
                                    break;
                                }
                                fun_result = type1_write->add_phonenumber(input);
                                if(fun_result == 1)
                                    cout<<"PhoneNumber Added.\n";
                                system("pause>null");
                                system("cls");
                                x=4;
                                menu_item=1;
                                fs->gotoXY(1,x); cout << "->";
                                break;
                            case 14 :
                                system("cls");
                                cout<<"Input PhoneNumber : ";
                                fgets(input, sizeof(input), stdin);
                                fflush(stdin);
                                fs->newline_remover(input);
                                fun_result = type1_write->delete_phonenumber(input);
                                if(fun_result == 1)
                                    cout<<"Phonenumber deleted.\n";
                                else
                                    cout<<"No such Number exists.\n";
                                system("pause>null");
                                system("cls");
                                x=4;
                                menu_item=1;
                                fs->gotoXY(1,x); cout << "->";
                                break;
                            case 15 : //Go Back
                                y--;
                                system("cls");
                                x=4;
                                menu_item=1;
                                fs->gotoXY(1,x); cout << "->";
                                break;
                            }
                            }
                        }
                    }//Admin's functions [/end]
                    else //Admin login failure.
                    {
                        cout<<"\nIncorrect Password or User Name.\n=====================================";
                        system("pause>null");
                    }
                    system("cls");
                    x=4;
                    menu_item=1;
                    fs->gotoXY(1,x); cout << "->";
                    break;
                case Officers : //Inventory Officer login.
                    system("cls");
                    cout<<"Input Username : ";
                    fgets(type4_write->username, sizeof(type4_write->username), stdin);
                    fflush(stdin);
                    fs->newline_remover(type4_write->username);
                    fs->encrypt(type4_write->username);
                    cout<<"Input Password : ";
                    fs->passwordEntry(type4_write->password);
                    fs->encrypt(type4_write->password);
                    fun_result = type4_write->login_users(type4_write, type4_read);
                    if (fun_result == 1) //Inventory Officer's functions.
                    {
                        cout<<"Login successful. Press any key to proceed.\n"<<endl;
                        strcpy(rec_result, type4_write->username);
                        fs->decrypt(rec_result);
                        system("pause>null");
                        fflush(stdin);
                        fun_result = type4_write->shortage_check(inv->write_products, inv->read_products, hold->vectorName);
                        if(fun_result == 0)
                        {
                            cout<<"\nAutomatic shortage check was launched\n========================================\n\nNo shortage was found, press any key to proceed.\n";
                            system("pause>null");
                        }
                        else
                        {
                            system("cls");
                            cout<<"\nAutomatic shortage check was launcher\n========================================\n\nShortage Report\n===============================\n";
                            vector<product>::iterator counter; //Check whole vector
                            for ( counter = hold->vectorName.begin(); counter != hold->vectorName.end(); counter++ )
                                cout
                                <<"\nProduct's Name : "<<counter->name
                                <<"\nProduct's Barcode : "<<counter->bar_code
                                <<"\nProduct's Type : "<<counter->type
                                <<"\nProduct's Price : "<<counter->price
                                <<" LE\nProduct's Quantity : "<<counter->quantity
                                <<"\nProduct's Shipping Company's Name : "<<counter->company_name
                                <<"\nProduct's Shipping Company's no. : "<<counter->company_phoneno
                                <<"\n================================================================================\n";
                            cout<<"\nSearch completed, press any key to proceed.\n";
                            system("pause>null");
                        }
                        y = 3;
                        system("cls");
                        menu_item=1;
                        x=4;
                        fs->gotoXY(1,x); cout << "->";
                        while(y==3)
                        {
                            fs->gotoXY(3,1);  cout << "Logged in with username : "<<rec_result;
                            fs->gotoXY(3,2);  cout << "===============================================";
                            fs->gotoXY(3,4);  cout << "[1] Add Product";
                            fs->gotoXY(3,5);  cout << "[2] Delete Product";
                            fs->gotoXY(3,6);  cout << "[3] Product Search";
                            fs->gotoXY(3,7);  cout << "[4] Edit Product";
                            fs->gotoXY(3,8);  cout << "[5] Shortage Check";
                            fs->gotoXY(3,9);  cout << "[6] View Products";
                            fs->gotoXY(3,10); cout << "[7] Change Passwords";
                            fs->gotoXY(3,11); cout << "[8] Log off";
                            system("pause>null");

                            if(GetAsyncKeyState(VK_DOWN) & 0x8000 && x != 11) //down button pressed >>>>>>>>>> 8
                            {fs->gotoXY(1,x); cout << "  ";
                            x++;
                            fs->gotoXY(1,x); cout << "->";
                            menu_item++;
                            continue;
                            }
                             if(GetAsyncKeyState(VK_DOWN) & 0x8000 && x == 11) //down button pressed >>>>>>>>>> 8
                            {fs->gotoXY(1,x); cout << "  ";

                            fs->gotoXY(1,4); cout << "->";
                            x=4;
                            menu_item=1;
                            continue;
                            }
                            if(GetAsyncKeyState(VK_UP) & 0x8000 && x != 4) //up button pressed
                            {
                                fs->gotoXY(1,x); cout << "  ";
                                x--;
                                fs->gotoXY(1,x); cout << "->";
                                menu_item--;
                                continue;
                            }
                            if(GetAsyncKeyState(VK_UP) & 0x8000 && x == 4) //up button pressed
                            {
                                fs->gotoXY(1,x); cout << "  ";

                                fs->gotoXY(1,11); cout << "->";
                                x=11;
                                menu_item=8;
                                continue;
                            }
                            if(GetAsyncKeyState(VK_RETURN)& 0x8000 )
                            {
                            switch(menu_item)
                            {
                            case 1 : //Add Product.
                                system("cls");
                                cout<<"Adding Shipment\n\n";
                                cout<<"Product's Barcode : ";
                                fgets(inv->write_products->bar_code, sizeof(inv->write_products->bar_code), stdin);
                                fflush(stdin);
                                fs->newline_remover(inv->write_products->bar_code);
                                if(fs->constrains(inv->write_products->bar_code, 4) == 1)
                                {
                                    cout<<"Barcodes can't have symbols. Press any key to go back.\n";
                                    system("pause>null");
                                    system("cls");
                                    x=4;
                                    menu_item=1;
                                    fs->gotoXY(1,x); cout << "->";
                                    break;
                                }
                                if(fs->constrains(inv->write_products->bar_code, 0) == 1)
                                {
                                    cout<<"Barcodes can't be left blank. Press any key to go back.\n";
                                    system("pause>null");
                                    system("cls");
                                    x=4;
                                    menu_item=1;
                                    fs->gotoXY(1,x); cout << "->";
                                    break;
                                }
                                fun_result = type4_write->search_inventory(inv->write_products, inv->read_products, 2, hold->vectorName);
                                if(fun_result == 0)
                                {
                                    cout<<"Product's name : ";
                                    fgets(inv->write_products->name, sizeof(inv->write_products->name), stdin);
                                    fflush(stdin);
                                    fs->newline_remover(inv->write_products->name);
                                    if(fs->constrains(inv->write_products->name, 5) == 1)
                                    {
                                        cout<<"Product names can't have symbols. Press any key to go back.\n";
                                        system("pause>null");
                                        system("cls");
                                        x=4;
                                        menu_item=1;
                                        fs->gotoXY(1,x); cout << "->";
                                        break;
                                    }
                                    cin.clear();
                                    cout<<"Product's category : ";
                                    fgets(inv->write_products->type, sizeof(inv->write_products->type), stdin);
                                    fflush(stdin);
                                    fs->newline_remover(inv->write_products->type);
                                    if(fs->constrains(inv->write_products->type, 2) == 1)
                                    {
                                        cout<<"Product types can't have symbols or numbers. Press any key to go back.\n";
                                        system("pause>null");
                                        system("cls");
                                        x=4;
                                        menu_item=1;
                                        fs->gotoXY(1,x); cout << "->";
                                        break;
                                    }
                                    cin.clear();
                                    cout<<"Product's price (1-6) : ";
                                    fgets(input, sizeof(input), stdin);
                                    fflush(stdin);
                                    fs->newline_remover(input);
                                    inv->write_products->price = atof(input);
                                    if(fs->constrains_num(inv->write_products->price, 6) == 1)
                                    {
                                        cout<<"Error! Invalid Input. Press any key to go back.\n";
                                        system("pause>null");
                                        system("cls");
                                        x=4;
                                        menu_item=1;
                                        fs->gotoXY(1,x); cout << "->";
                                        break;
                                    }
                                    cout<<"Product's quantity (1-14) : ";
                                    fgets(input, sizeof(input), stdin);
                                    fflush(stdin);
                                    fs->newline_remover(input);
                                    inv->write_products->quantity = atoll(input);
                                    if(fs->constrains_num(inv->write_products->quantity, 7) == 1)
                                    {
                                        cout<<"Error! Invalid Input. Press any key to go back.\n";
                                        system("pause>null");
                                        system("cls");
                                        x=4;
                                        menu_item=1;
                                        fs->gotoXY(1,x); cout << "->";
                                        break;
                                    }
                                    cout<<"Shipping company's name : ";
                                    fgets(inv->write_products->company_name, sizeof(inv->write_products->company_name), stdin);
                                    fflush(stdin);
                                    fs->newline_remover(inv->write_products->company_name);
                                    if(fs->constrains(inv->write_products->company_name, 5) == 1)
                                    {
                                        cout<<"Company names can't have symbols. Press any key to go back.\n";
                                        system("pause>null");
                                        system("cls");
                                        x=4;
                                        menu_item=1;
                                        fs->gotoXY(1,x); cout << "->";
                                        break;
                                    }
                                    cout<<"Shipping company's phone no. : ";
                                    fgets(inv->write_products->company_phoneno, sizeof(inv->write_products->company_phoneno), stdin);
                                    fflush(stdin);
                                    fs->newline_remover(inv->write_products->company_phoneno);
                                    if(fs->constrains(inv->write_products->company_phoneno, 3) == 1)
                                    {
                                        cout<<"Phonenumbers can't have letters nor symbols. Press any key to go back.\n";
                                        system("pause>null");
                                        system("cls");
                                        x=4;
                                        menu_item=1;
                                        fs->gotoXY(1,x); cout << "->";
                                        break;
                                    }
                                    fun_result = type4_write->add_inventory(inv->write_products);
                                    if(fun_result == 1)
                                    {
                                        cout<<"\nProduct Added\nPress any key to continue..\n";
                                        system("pause>null");
                                    }
                                }
                                else
                                {

                                    cout<<"\nSuch Barcode already exists, please check your product's Barcode and try again.\n";
                                    vector<product>::iterator counter; //Check whole vector
                                    for ( counter = hold->vectorName.begin(); counter != hold->vectorName.end(); counter++ )
                                        cout
                                        <<"\nProduct's Name : "<<counter->name
                                        <<"\nProduct's Barcode : "<<counter->bar_code
                                        <<"\nProduct's Type : "<<counter->type
                                        <<"\nProduct's Price : "<<counter->price
                                        <<" LE\nProduct's Quantity : "<<counter->quantity
                                        <<"\nProduct's Shipping Company's Name : "<<counter->company_name
                                        <<"\nProduct's Shipping Company's no. : "<<counter->company_phoneno
                                        <<"\n================================================================================\n";
                                    system("pause>null");
                                }
                                system("cls");
                                x=4;
                                menu_item=1;
                                fs->gotoXY(1,x); cout << "->";
                                break;
                            case 2 : //Delete Product.
                                system("cls");
                                cout<<"Product's Barcode : ";
                                fgets(inv->write_products->bar_code, sizeof(inv->write_products->bar_code), stdin);
                                fflush(stdin);
                                fs->newline_remover(inv->write_products->bar_code);
                                fun_result = type4_write->search_inventory(inv->write_products, inv->read_products, 2, hold->vectorName);
                                if(fun_result == 1)
                                {
                                    fflush(stdin);
                                    fun_result = type4_write->delete_inventory(inv->write_products, inv->write_products);
                                    if(fun_result == 1)
                                    {
                                        cout<<"Deletion complete, press any key to proceed.\n";
                                        system("pause>null");
                                    }
                                    else
                                    {
                                        cout<<"An error occured while deleting, press any key to continue.\n";
                                        system("pause>null");
                                    }

                                }
                                else
                                {
                                    cout<<"No such product exists, press any key to continue.\n";
                                    system("pause>null");
                                }
                                system("cls");
                                x=4;
                                menu_item=1;
                                fs->gotoXY(1,x); cout << "->";
                                break;
                            case 3 : //Search for a product.
                                system("cls");
                                y = 4;
                                menu_item = 1;
                                x = 4;
                                fs->gotoXY(1,x); cout << "->";
                                while(y==4)
                                {
                                    hold->vectorName.clear();
                                    fs->gotoXY(3,1);  cout << "Search for a product";
                                    fs->gotoXY(3,2);  cout << "=======================";
                                    fs->gotoXY(3,4);  cout << "[1] Search by Name";
                                    fs->gotoXY(3,5);  cout << "[2] Search by Barcode";
                                    fs->gotoXY(3,6);  cout << "[3] Search by Type";
                                    fs->gotoXY(3,7);  cout << "[4] Search by Price (Range)";
                                    fs->gotoXY(3,8);  cout << "[5] Search by Quantity";
                                    fs->gotoXY(3,9);  cout << "[6] Search by Company Name";
                                    fs->gotoXY(3,10); cout << "[7] Search by Company's Phoneno.";
                                    fs->gotoXY(3,11); cout << "[8] Go Back.";
                                    system("pause>null");
                                    if(GetAsyncKeyState(VK_DOWN) & 0x8000 && x != 11) //down button pressed >>>>>>>>>> 8
                                        {
                                            fs->gotoXY(1,x); cout << "  ";
                                            x++;
                                            fs->gotoXY(1,x); cout << "->";
                                            menu_item++;
                                            continue;
                                        }
                                        if(GetAsyncKeyState(VK_DOWN) & 0x8000 && x == 11) //down button pressed >>>>>>>>>> 8
                                        {
                                            fs->gotoXY(1,x); cout << "  ";

                                            fs->gotoXY(1,4); cout << "->";
                                            x=4;
                                            menu_item=1;
                                            continue;
                                        }
                                        if(GetAsyncKeyState(VK_UP) & 0x8000 && x != 4) //up button pressed
                                        {
                                            fs->gotoXY(1,x); cout << "  ";
                                            x--;
                                            fs->gotoXY(1,x); cout << "->";
                                            menu_item--;
                                            continue;
                                        }
                                        if(GetAsyncKeyState(VK_UP) & 0x8000 && x == 4) //up button pressed
                                        {
                                            fs->gotoXY(1,x); cout << "  ";

                                            fs->gotoXY(1,11); cout << "->";
                                            x=11;
                                            menu_item=8;
                                            continue;
                                        }
                                        if(GetAsyncKeyState(VK_RETURN)& 0x8000 )
                                        {
                                            switch(menu_item)
                                            {
                                                case 1: //Search by Name
                                                    system("cls");
                                                    cout<<"Product's Name : ";
                                                    fgets(inv->write_products->name, sizeof(inv->write_products->name), stdin);
                                                    fflush(stdin);
                                                    fs->newline_remover(inv->write_products->name);
                                                    fun_result = type4_write->search_inventory(inv->write_products, inv->read_products, 1, hold->vectorName);
                                                    if(fun_result == 1)
                                                    {
                                                        cout<<"\nMatching found\n===============================\n";
                                                        vector<product>::iterator counter; //Check whole vector
                                                        for ( counter = hold->vectorName.begin(); counter != hold->vectorName.end(); counter++ )
                                                            cout
                                                            <<"\nProduct's Name : "<<counter->name
                                                            <<"\nProduct's Barcode : "<<counter->bar_code
                                                            <<"\nProduct's Type : "<<counter->type
                                                            <<"\nProduct's Price : "<<counter->price
                                                            <<" LE\nProduct's Quantity : "<<counter->quantity
                                                            <<"\nProduct's Shipping Company's Name : "<<counter->company_name
                                                            <<"\nProduct's Shipping Company's no. : "<<counter->company_phoneno
                                                            <<"\n================================================================================\n";
                                                        cout<<"\nSearch completed, press any key to proceed.\n";
                                                        system("pause>null");
                                                        system("cls");
                                                        x=4;
                                                        menu_item=1;
                                                        fs->gotoXY(1,x); cout << "->";
                                                        break;
                                                    }
                                                    else
                                                    {
                                                        cout<<"No such product exists, press any key to continue.\n";
                                                        system("pause>null");
                                                        system("cls");
                                                        x=4;
                                                        menu_item=1;
                                                        fs->gotoXY(1,x); cout << "->";
                                                        break;
                                                    }
                                                    system("cls");
                                                    x=4;
                                                    menu_item=1;
                                                    fs->gotoXY(1,x); cout << "->";
                                                    break;
                                                case 2: //Search by Barcode
                                                    system("cls");
                                                    cout<<"Product's Barcode : ";
                                                    fgets(inv->write_products->bar_code, sizeof(inv->write_products->bar_code), stdin);
                                                    fflush(stdin);
                                                    fs->newline_remover(inv->write_products->bar_code);
                                                    fun_result = type4_write->search_inventory(inv->write_products, inv->read_products, 2, hold->vectorName);
                                                    if(fun_result == 1)
                                                    {
                                                        cout<<"\nMatching found\n===============================\n";
                                                        vector<product>::iterator counter; //Check whole vector
                                                        for ( counter = hold->vectorName.begin(); counter != hold->vectorName.end(); counter++ )
                                                            cout
                                                            <<"\nProduct's Name : "<<counter->name
                                                            <<"\nProduct's Barcode : "<<counter->bar_code
                                                            <<"\nProduct's Type : "<<counter->type
                                                            <<"\nProduct's Price : "<<counter->price
                                                            <<" LE\nProduct's Quantity : "<<counter->quantity
                                                            <<"\nProduct's Shipping Company's Name : "<<counter->company_name
                                                            <<"\nProduct's Shipping Company's no. : "<<counter->company_phoneno
                                                            <<"\n================================================================================\n";
                                                        cout<<"\nSearch completed, press any key to proceed.\n";
                                                        system("pause>null");
                                                        system("cls");
                                                        x=4;
                                                        menu_item=1;
                                                        fs->gotoXY(1,x); cout << "->";
                                                        break;
                                                    }
                                                    else
                                                    {
                                                        cout<<"No such product exists, press any key to continue.\n";
                                                        system("pause>null");
                                                        system("cls");
                                                        x=4;
                                                        menu_item=1;
                                                        fs->gotoXY(1,x); cout << "->";
                                                        break;
                                                    }
                                                    system("cls");
                                                    x=4;
                                                    menu_item=1;
                                                    fs->gotoXY(1,x); cout << "->";
                                                    break;
                                                case 3: //Search by Type
                                                    system("cls");
                                                    cout<<"Product's Type : ";
                                                    fgets(inv->write_products->type, sizeof(inv->write_products->type), stdin);
                                                    fflush(stdin);
                                                    fs->newline_remover(inv->write_products->type);
                                                    fun_result = type4_write->search_inventory(inv->write_products, inv->read_products, 3, hold->vectorName);
                                                    if(fun_result == 1)
                                                    {
                                                        cout<<"\nMatching found\n===============================\n";
                                                        vector<product>::iterator counter; //Check whole vector
                                                        for ( counter = hold->vectorName.begin(); counter != hold->vectorName.end(); counter++ )
                                                            cout
                                                            <<"\nProduct's Name : "<<counter->name
                                                            <<"\nProduct's Barcode : "<<counter->bar_code
                                                            <<"\nProduct's Type : "<<counter->type
                                                            <<"\nProduct's Price : "<<counter->price
                                                            <<" LE\nProduct's Quantity : "<<counter->quantity
                                                            <<"\nProduct's Shipping Company's Name : "<<counter->company_name
                                                            <<"\nProduct's Shipping Company's no. : "<<counter->company_phoneno
                                                            <<"\n================================================================================\n";
                                                        cout<<"\nSearch completed, press any key to proceed.\n";
                                                        system("pause>null");
                                                        system("cls");
                                                        x=4;
                                                        menu_item=1;
                                                        fs->gotoXY(1,x); cout << "->";
                                                        break;
                                                    }
                                                    else
                                                    {
                                                        cout<<"No such product exists, press any key to continue.\n";
                                                        system("pause>null");
                                                        system("cls");
                                                        x=4;
                                                        menu_item=1;
                                                        fs->gotoXY(1,x); cout << "->";
                                                        break;
                                                    }
                                                    system("cls");
                                                    x=4;
                                                    menu_item=1;
                                                    fs->gotoXY(1,x); cout << "->";
                                                    break;
                                                case 4: //Search by Price
                                                    {
                                                    double low, high;
                                                    system("cls");
                                                    cout<<"Lowest Price : ";
                                                    fgets(input, sizeof(input), stdin);
                                                    fflush(stdin);
                                                    fs->newline_remover(input);
                                                    low = atof(input);
                                                    cout<<"Highest Price : ";
                                                    fgets(input, sizeof(input), stdin);
                                                    fflush(stdin);
                                                    fs->newline_remover(input);
                                                    high = atof(input);
                                                    fun_result = type4_write->search_inventory(inv->write_products, inv->read_products, low, high, hold->vectorName);
                                                    if(fun_result == 1)
                                                    {
                                                        cout<<"\nMatching found\n===============================\n";
                                                        vector<product>::iterator counter; //Check whole vector
                                                        for ( counter = hold->vectorName.begin(); counter != hold->vectorName.end(); counter++ )
                                                            cout
                                                            <<"\nProduct's Name : "<<counter->name
                                                            <<"\nProduct's Barcode : "<<counter->bar_code
                                                            <<"\nProduct's Type : "<<counter->type
                                                            <<"\nProduct's Price : "<<counter->price
                                                            <<" LE\nProduct's Quantity : "<<counter->quantity
                                                            <<"\nProduct's Shipping Company's Name : "<<counter->company_name
                                                            <<"\nProduct's Shipping Company's no. : "<<counter->company_phoneno
                                                            <<"\n================================================================================\n";
                                                        cout<<"\nSearch completed, press any key to proceed.\n";
                                                        system("pause>null");
                                                        system("cls");
                                                        x=4;
                                                        menu_item=1;
                                                        fs->gotoXY(1,x); cout << "->";
                                                        break;
                                                    }
                                                    else
                                                    {
                                                        cout<<"No such product exists, press any key to continue.\n";
                                                        system("pause>null");
                                                        system("cls");
                                                        x=4;
                                                        menu_item=1;
                                                        fs->gotoXY(1,x); cout << "->";
                                                        break;
                                                    }
                                                    system("cls");
                                                    x=4;
                                                    menu_item=1;
                                                    fs->gotoXY(1,x); cout << "->";
                                                    break;
                                                    }
                                                case 5: //Search by Quantity
                                                    system("cls");
                                                    cout<<"Product's Quantity : ";
                                                    fgets(input, sizeof(input), stdin);
                                                    fflush(stdin);
                                                    fs->newline_remover(input);
                                                    inv->write_products->quantity = atoll(input);
                                                    fun_result = type4_write->search_inventory(inv->write_products, inv->read_products, 5, hold->vectorName);
                                                    if(fun_result == 1)
                                                    {
                                                        cout<<"\nMatching found\n===============================\n";
                                                        vector<product>::iterator counter; //Check whole vector
                                                        for ( counter = hold->vectorName.begin(); counter != hold->vectorName.end(); counter++ )
                                                            cout
                                                            <<"\nProduct's Name : "<<counter->name
                                                            <<"\nProduct's Barcode : "<<counter->bar_code
                                                            <<"\nProduct's Type : "<<counter->type
                                                            <<"\nProduct's Price : "<<counter->price
                                                            <<" LE\nProduct's Quantity : "<<counter->quantity
                                                            <<"\nProduct's Shipping Company's Name : "<<counter->company_name
                                                            <<"\nProduct's Shipping Company's no. : "<<counter->company_phoneno
                                                            <<"\n================================================================================\n";
                                                        cout<<"\nSearch completed, press any key to proceed.\n";
                                                        system("pause>null");
                                                        system("cls");
                                                        x=4;
                                                        menu_item=1;
                                                        fs->gotoXY(1,x); cout << "->";
                                                        break;
                                                    }
                                                    else
                                                    {
                                                        cout<<"No such product exists, press any key to continue.\n";
                                                        system("pause>null");
                                                        system("cls");
                                                        x=4;
                                                        menu_item=1;
                                                        fs->gotoXY(1,x); cout << "->";
                                                        break;
                                                    }
                                                    system("cls");
                                                    x=4;
                                                    menu_item=1;
                                                    fs->gotoXY(1,x); cout << "->";
                                                    break;
                                                case 6: //Search by Company's Name
                                                    system("cls");
                                                    cout<<"Product's Company's Name : ";
                                                    fgets(inv->write_products->company_name, sizeof(inv->write_products->company_name), stdin);
                                                    fflush(stdin);
                                                    fs->newline_remover(inv->write_products->company_name);
                                                    fun_result = type4_write->search_inventory(inv->write_products, inv->read_products, 6, hold->vectorName);
                                                    if(fun_result == 1)
                                                    {
                                                        cout<<"\nMatching found\n===============================\n";
                                                        vector<product>::iterator counter; //Check whole vector
                                                        for ( counter = hold->vectorName.begin(); counter != hold->vectorName.end(); counter++ )
                                                            cout
                                                            <<"\nProduct's Name : "<<counter->name
                                                            <<"\nProduct's Barcode : "<<counter->bar_code
                                                            <<"\nProduct's Type : "<<counter->type
                                                            <<"\nProduct's Price : "<<counter->price
                                                            <<" LE\nProduct's Quantity : "<<counter->quantity
                                                            <<"\nProduct's Shipping Company's Name : "<<counter->company_name
                                                            <<"\nProduct's Shipping Company's no. : "<<counter->company_phoneno
                                                            <<"\n================================================================================\n";
                                                        cout<<"\nSearch completed, press any key to proceed.\n";
                                                        system("pause>null");
                                                        system("cls");
                                                        x=4;
                                                        menu_item=1;
                                                        fs->gotoXY(1,x); cout << "->";
                                                        break;
                                                    }
                                                    else
                                                    {
                                                        cout<<"No such product exists, press any key to continue.\n";
                                                        system("pause>null");
                                                        system("cls");
                                                        x=4;
                                                        menu_item=1;
                                                        fs->gotoXY(1,x); cout << "->";
                                                        break;
                                                    }
                                                    system("cls");
                                                    x=4;
                                                    menu_item=1;
                                                    fs->gotoXY(1,x); cout << "->";
                                                    break;
                                                case 7: //Search by Company's phoneno
                                                    system("cls");
                                                    cout<<"Product's Company's Phoneno : ";
                                                    fgets(inv->write_products->company_phoneno, sizeof(inv->write_products->company_phoneno), stdin);
                                                    fflush(stdin);
                                                    fs->newline_remover(inv->write_products->company_phoneno);
                                                    fun_result = type4_write->search_inventory(inv->write_products, inv->read_products, 7, hold->vectorName);
                                                    if(fun_result == 1)
                                                    {
                                                        cout<<"\nMatching found\n===============================\n";
                                                        vector<product>::iterator counter; //Check whole vector
                                                        for ( counter = hold->vectorName.begin(); counter != hold->vectorName.end(); counter++ )
                                                            cout
                                                            <<"\nProduct's Name : "<<counter->name
                                                            <<"\nProduct's Barcode : "<<counter->bar_code
                                                            <<"\nProduct's Type : "<<counter->type
                                                            <<"\nProduct's Price : "<<counter->price
                                                            <<" LE\nProduct's Quantity : "<<counter->quantity
                                                            <<"\nProduct's Shipping Company's Name : "<<counter->company_name
                                                            <<"\nProduct's Shipping Company's no. : "<<counter->company_phoneno
                                                            <<"\n================================================================================\n";
                                                        cout<<"\nSearch completed, press any key to proceed.\n";
                                                        system("pause>null");
                                                        system("cls");
                                                        x=4;
                                                        menu_item=1;
                                                        fs->gotoXY(1,x); cout << "->";
                                                        break;
                                                    }
                                                    else
                                                    {
                                                        cout<<"No such product exists, press any key to continue.\n";
                                                        system("pause>null");
                                                        system("cls");
                                                        x=4;
                                                        menu_item=1;
                                                        fs->gotoXY(1,x); cout << "->";
                                                        break;
                                                    }
                                                    system("cls");
                                                    x=4;
                                                    menu_item=1;
                                                    fs->gotoXY(1,x); cout << "->";
                                                    break;
                                                case 8:
                                                    y--; //Back
                                                    system("cls");
                                                    x=4;
                                                    menu_item=1;
                                                    fs->gotoXY(1,x); cout << "->";
                                                    break;
                                            }
                                        }
                                }
                                system("cls");
                                x=4;
                                menu_item=1;
                                fs->gotoXY(1,x); cout << "->";
                                break;
                            case 4 : //Edit product
                                system("cls");
                                cout<<"Product's Barcode : ";
                                fgets(inv->write_products->bar_code, sizeof(inv->write_products->bar_code), stdin);
                                fflush(stdin);
                                fs->newline_remover(inv->write_products->bar_code);
                                fun_result = type4_write->search_inventory(inv->write_products, inv->read_products, 2, hold->vectorName);
                                if(fun_result == 1)
                                {
                                    y = 4;
                                    system("cls");
                                    menu_item=1;
                                    x=4;
                                    fs->gotoXY(1,x); cout << "->";
                                    while(y==4)
                                    {
                                        fs->gotoXY(3,1);  cout << "Matching found (Edit)";
                                        fs->gotoXY(3,2);  cout << "=======================";
                                        fs->gotoXY(3,4);  cout << "[1] Name";
                                        fs->gotoXY(3,5);  cout << "[2] Barcode";
                                        fs->gotoXY(3,6);  cout << "[3] Type";
                                        fs->gotoXY(3,7);  cout << "[4] Price";
                                        fs->gotoXY(3,8);  cout << "[5] Quantity";
                                        fs->gotoXY(3,9);  cout << "[6] Company Name";
                                        fs->gotoXY(3,10); cout << "[7] Company's Phoneno.";
                                        fs->gotoXY(3,11); cout << "[8] Edit Everything";
                                        fs->gotoXY(3,12); cout << "[9] Go back";
                                        vector<product>::iterator counter; //Check whole vector
                                        for ( counter = hold->vectorName.begin(); counter != hold->vectorName.end(); counter++ )
                                        {
                                            fs->gotoXY(3,15); cout << "Product's Name : "<<counter->name;
                                            fs->gotoXY(3,16); cout << "Product's Barcode : "<<counter->bar_code;
                                            fs->gotoXY(3,17); cout << "Product's Type : "<<counter->type;
                                            fs->gotoXY(3,18); cout << "Product's Price : "<<counter->price<<" LE";
                                            fs->gotoXY(3,19); cout << "Product's Quantity : "<<counter->quantity;
                                            fs->gotoXY(3,20); cout << "Product's Shipping Company's Name : "<<counter->company_name;
                                            fs->gotoXY(3,21); cout << "Product's Shipping Company's no. : "<<counter->company_phoneno;
                                            fs->gotoXY(3,22); cout << "================================================================\n\n";
                                        }
                                        system("pause>null");
                                        if(GetAsyncKeyState(VK_DOWN) & 0x8000 && x != 12) //down button pressed >>>>>>>>>> 8
                                            {
                                                fs->gotoXY(1,x); cout << "  ";
                                                x++;
                                                fs->gotoXY(1,x); cout << "->";
                                                menu_item++;
                                                continue;
                                            }
                                             if(GetAsyncKeyState(VK_DOWN) & 0x8000 && x == 12) //down button pressed >>>>>>>>>> 8
                                            {
                                                fs->gotoXY(1,x); cout << "  ";

                                                fs->gotoXY(1,4); cout << "->";
                                                x=4;
                                                menu_item=1;
                                                continue;
                                            }
                                            if(GetAsyncKeyState(VK_UP) & 0x8000 && x != 4) //up button pressed
                                            {
                                                fs->gotoXY(1,x); cout << "  ";
                                                x--;
                                                fs->gotoXY(1,x); cout << "->";
                                                menu_item--;
                                                continue;
                                            }
                                            if(GetAsyncKeyState(VK_UP) & 0x8000 && x == 4) //up button pressed
                                            {
                                                fs->gotoXY(1,x); cout << "  ";

                                                fs->gotoXY(1,12); cout << "->";
                                                x=12;
                                                menu_item=9;
                                                continue;
                                            }
                                            if(GetAsyncKeyState(VK_RETURN)& 0x8000 )
                                            {
                                        switch(menu_item)
                                        {
                                        case 1: //Edit Name
                                            cout<<"Product's Name : ";
                                            fgets(inv->write_products->name, sizeof(inv->write_products->name), stdin);
                                            fflush(stdin);
                                            fs->newline_remover(inv->write_products->name);
                                            if(fs->constrains(inv->write_products->name, 5) == 1)
                                            {
                                                cout<<"Product names can't have symbols. Press any key to go back.\n";
                                                system("pause>null");
                                                system("cls");
                                                x=4;
                                                menu_item=1;
                                                fs->gotoXY(1,x); cout << "->";
                                                break;
                                            }
                                            cin.clear();
                                            fflush(stdin);
                                            fun_result = type4_write->edit_inventory(inv->write_products, inv->read_products, 1);
                                            if(fun_result == 1)
                                            {
                                                cout<<"Product was edited successfuly.\n";
                                                system("pause>null");
                                                system("cls");
                                                y--;
                                                x=4;
                                                menu_item=1;
                                                fs->gotoXY(1,x); cout << "->";
                                                break;
                                            }
                                            else
                                            {
                                                cout<<"An error occured while editing, press any key to continue.\n";
                                                system("pause>null");
                                            }
                                            system("cls");
                                            x=4;
                                            menu_item=1;
                                            fs->gotoXY(1,x); cout << "->";
                                            break;
                                        case 2: //Edit Barcode
                                            cout<<"Product's Barcode : ";
                                            fgets(inv->write_products->bar_code, sizeof(inv->write_products->bar_code), stdin);
                                            fflush(stdin);
                                            fs->newline_remover(inv->write_products->bar_code);
                                            if(fs->constrains(inv->write_products->bar_code, 4) == 1)
                                            {
                                                cout<<"Barcodes can't have symbols. Press any key to go back.\n";
                                                system("pause>null");
                                                system("cls");
                                                x=4;
                                                menu_item=1;
                                                fs->gotoXY(1,x); cout << "->";
                                                break;
                                            }
                                            cin.clear();
                                            fflush(stdin);
                                            if(type4_write->search_inventory(inv->write_products, inv->read_products, 2, hold->vectorName) == 1)
                                            {
                                                cout<<"Similar Barcode's already in use, editing was denied. Press any key to go back.\n";
                                                system("pause>null");
                                                system("cls");
                                                x=4;
                                                menu_item=1;
                                                fs->gotoXY(1,x); cout << "->";
                                                break;
                                            }
                                            if(fs->constrains(inv->write_products->bar_code, 0) == 1)
                                            {
                                                cout<<"Barcodes can't be left blank. Press any key to go back.\n";
                                                system("pause>null");
                                                system("cls");
                                                x=4;
                                                menu_item=1;
                                                fs->gotoXY(1,x); cout << "->";
                                                break;
                                            }
                                            cin.clear();
                                            fflush(stdin);
                                            fun_result = type4_write->edit_inventory(inv->write_products, inv->read_products, 2);
                                            if(fun_result == 1)
                                            {
                                                cout<<"Product was edited successfuly. Changing barcodes requires refreshing, press any key to refresh items.\n";
                                                system("pause>null");
                                                system("cls");
                                                y--;
                                                x=4;
                                                menu_item=1;
                                                fs->gotoXY(1,x); cout << "->";
                                                break;
                                            }
                                            else
                                            {
                                                cout<<"An error occured while editing, press any key to continue.\n";
                                                system("pause>null");
                                            }
                                            system("cls");
                                            x=4;
                                            menu_item=1;
                                            fs->gotoXY(1,x); cout << "->";
                                            break;
                                        case 3: //Edit Type
                                            cout<<"Product's Type : ";
                                            fgets(inv->write_products->type, sizeof(inv->write_products->type), stdin);
                                            fflush(stdin);
                                            fs->newline_remover(inv->write_products->type);
                                            if(fs->constrains(inv->write_products->type, 2) == 1)
                                            {
                                                cout<<"Product types can't have numbers. Press any key to go back.\n";
                                                system("pause>null");
                                                system("cls");
                                                x=4;
                                                menu_item=1;
                                                fs->gotoXY(1,x); cout << "->";
                                                break;
                                            }
                                            cin.clear();
                                            fflush(stdin);
                                            fun_result = type4_write->edit_inventory(inv->write_products, inv->read_products, 3);
                                            if(fun_result == 1)
                                            {
                                                cout<<"Product was edited successfuly.\n";
                                                system("pause>null");
                                                system("cls");
                                                y--;
                                                x=4;
                                                menu_item=1;
                                                fs->gotoXY(1,x); cout << "->";
                                                break;
                                            }
                                            else
                                            {
                                                cout<<"An error occured while editing, press any key to continue.\n";
                                                system("pause>null");
                                            }
                                            system("cls");
                                            x=4;
                                            menu_item=1;
                                            fs->gotoXY(1,x); cout << "->";
                                            break;
                                        case 4: //Edit Price
                                            cout<<"Product's Price (1-6) : ";
                                            fgets(input, sizeof(input), stdin);
                                            fflush(stdin);
                                            fs->newline_remover(input);
                                            inv->write_products->price = atof(input);
                                            if(fs->constrains_num(inv->write_products->price, 6) == 1)
                                            {
                                                cout<<"Error! Invalid Input. Press any key to go back.\n";
                                                system("pause>null");
                                                system("cls");
                                                x=4;
                                                menu_item=1;
                                                fs->gotoXY(1,x); cout << "->";
                                                break;
                                            }
                                            cin.clear();
                                            fflush(stdin);
                                            fun_result = type4_write->edit_inventory(inv->write_products, inv->read_products, 4);
                                            if(fun_result == 1)
                                            {
                                                cout<<"Product was edited successfuly.\n";
                                                system("pause>null");
                                                system("cls");
                                                y--;
                                                x=4;
                                                menu_item=1;
                                                fs->gotoXY(1,x); cout << "->";
                                                break;
                                            }
                                            else
                                            {
                                                cout<<"An error occured while editing, press any key to continue.\n";
                                                system("pause>null");
                                            }
                                            system("cls");
                                            x=4;
                                            menu_item=1;
                                            fs->gotoXY(1,x); cout << "->";
                                            break;
                                        case 5: //Edit Quantity
                                            cout<<"Product's Quantity (1-14) : ";
                                            fgets(input, sizeof(input), stdin);
                                            fflush(stdin);
                                            fs->newline_remover(input);
                                            inv->write_products->quantity = atoll(input);
                                            if(fs->constrains_num(inv->write_products->quantity, 7) == 1)
                                            {
                                                cout<<"Error! Invalid Input. Press any key to go back.\n";
                                                system("pause>null");
                                                system("cls");
                                                x=4;
                                                menu_item=1;
                                                fs->gotoXY(1,x); cout << "->";
                                                break;
                                            }
                                            cin.clear();
                                            fflush(stdin);
                                            fun_result = type4_write->edit_inventory(inv->write_products, inv->read_products, 5);
                                            if(fun_result == 1)
                                            {
                                                cout<<"Product was edited successfuly.\n";
                                                system("pause>null");
                                                system("cls");
                                                y--;
                                                x=4;
                                                menu_item=1;
                                                fs->gotoXY(1,x); cout << "->";
                                                break;

                                            }
                                            else
                                            {
                                                cout<<"An error occured while editing, press any key to continue.\n";
                                                system("pause>null");
                                            }
                                            system("cls");
                                            x=4;
                                            menu_item=1;
                                            fs->gotoXY(1,x); cout << "->";
                                            break;
                                        case 6: //Edit Company's Name
                                            cout<<"Product's Company's Name : ";
                                            fgets(inv->write_products->company_name, sizeof(inv->write_products->company_name), stdin);
                                            fflush(stdin);
                                            fs->newline_remover(inv->write_products->company_name);
                                            if(fs->constrains(inv->write_products->company_name, 5) == 1)
                                            {
                                                cout<<"Company names can't have symbols. Press any key to go back.\n";
                                                system("pause>null");
                                                system("cls");
                                                x=4;
                                                menu_item=1;
                                                fs->gotoXY(1,x); cout << "->";
                                                break;
                                            }
                                            cin.clear();
                                            fflush(stdin);
                                            fun_result = type4_write->edit_inventory(inv->write_products, inv->read_products, 6);
                                            if(fun_result == 1)
                                            {
                                                cout<<"Product was edited successfuly.\n";
                                                system("pause>null");
                                                system("cls");
                                                y--;
                                                x=4;
                                                menu_item=1;
                                                fs->gotoXY(1,x); cout << "->";
                                                break;
                                            }
                                            else
                                            {
                                                cout<<"An error occured while editing, press any key to continue.\n";
                                                system("pause>null");
                                            }
                                            system("cls");
                                            x=4;
                                            menu_item=1;
                                            fs->gotoXY(1,x); cout << "->";
                                            break;
                                        case 7: //Edit Company's PhoneNumber
                                            cout<<"Product's Company's PhoneNumber : ";
                                            fgets(inv->write_products->company_phoneno, sizeof(inv->write_products->company_phoneno), stdin);
                                            fflush(stdin);
                                            fs->newline_remover(inv->write_products->company_phoneno);
                                            if(fs->constrains(inv->write_products->company_phoneno, 3) == 1)
                                            {
                                                cout<<"Company's phonenumbers must be numbers. Press any key to go back.\n";
                                                system("pause>null");
                                                system("cls");
                                                x=4;
                                                menu_item=1;
                                                fs->gotoXY(1,x); cout << "->";
                                                break;
                                            }
                                            cin.clear();
                                            fflush(stdin);
                                            fun_result = type4_write->edit_inventory(inv->write_products, inv->read_products, 7);
                                            if(fun_result == 1)
                                            {
                                                cout<<"Product was edited successfuly.\n";
                                                system("pause>null");
                                                system("cls");
                                                y--;
                                                x=4;
                                                menu_item=1;
                                                fs->gotoXY(1,x); cout << "->";
                                                break;
                                            }
                                            else
                                            {
                                                cout<<"An error occured while editing, press any key to continue.\n";
                                                system("pause>null");
                                            }
                                            system("cls");
                                            x=4;
                                            menu_item=1;
                                            fs->gotoXY(1,x); cout << "->";
                                            break;
                                        case 8: //Edit Everything
                                            cout<<"Product's Name : ";
                                            fgets(inv->write_products->name, sizeof(inv->write_products->name), stdin);
                                            fflush(stdin);
                                            fs->newline_remover(inv->write_products->name);
                                            cout<<"Product's Barcode : ";
                                            fgets(inv->write_products->bar_code, sizeof(inv->write_products->bar_code), stdin);
                                            fflush(stdin);
                                            fs->newline_remover(inv->write_products->bar_code);
                                            if(type4_write->search_inventory(inv->write_products, inv->read_products, 2, hold->vectorName) == 1)
                                            {
                                                cout<<"Barcode's already in use, editing was denied. Press any key to go back.\n";
                                                system("pause>null");
                                                system("cls");
                                                x=4;
                                                menu_item=1;
                                                fs->gotoXY(1,x); cout << "->";
                                                break;
                                            }
                                            if(fs->constrains(inv->write_products->bar_code, 4) == 1)
                                            {
                                                cout<<"Barcodes can't have symbols. Press any key to go back.\n";
                                                system("pause>null");
                                                system("cls");
                                                x=4;
                                                menu_item=1;
                                                fs->gotoXY(1,x); cout << "->";
                                                break;
                                            }
                                            if(fs->constrains(inv->write_products->bar_code, 0) == 1)
                                            {
                                                cout<<"Barcodes can't be left blank. Press any key to go back.\n";
                                                system("pause>null");
                                                system("cls");
                                                x=4;
                                                menu_item=1;
                                                fs->gotoXY(1,x); cout << "->";
                                                break;
                                            }
                                            cin.clear();
                                            cout<<"Product's Price (1-6) : ";
                                            fgets(input, sizeof(input), stdin);
                                            fflush(stdin);
                                            fs->newline_remover(input);
                                            inv->write_products->price = atof(input);
                                            if(fs->constrains_num(inv->write_products->price, 6) == 1)
                                            {
                                                cout<<"Error! Invalid Input. Press any key to go back.\n";
                                                system("pause>null");
                                                system("cls");
                                                x=4;
                                                menu_item=1;
                                                fs->gotoXY(1,x); cout << "->";
                                                break;
                                            }
                                            cin.clear();
                                            cout<<"Product's Quantity (1-14) : ";
                                            fgets(input, sizeof(input), stdin);
                                            fflush(stdin);
                                            fs->newline_remover(input);
                                            inv->write_products->quantity = atoll(input);
                                            if(fs->constrains_num(inv->write_products->quantity, 7) == 1)
                                            {
                                                cout<<"Error! Invalid Input. Press any key to go back.\n";
                                                system("pause>null");
                                                system("cls");
                                                x=4;
                                                menu_item=1;
                                                fs->gotoXY(1,x); cout << "->";
                                                break;
                                            }
                                            cin.clear();
                                            cout<<"Product's Type : ";
                                            fgets(inv->write_products->type, sizeof(inv->write_products->type), stdin);
                                            fflush(stdin);
                                            fs->newline_remover(inv->write_products->type);
                                            if(fs->constrains(inv->write_products->type, 2) == 1)
                                            {
                                                cout<<"Product types can't have symbols. Press any key to go back.\n";
                                                system("pause>null");
                                                system("cls");
                                                x=4;
                                                menu_item=1;
                                                fs->gotoXY(1,x); cout << "->";
                                                break;
                                            }
                                            cin.clear();
                                            cout<<"Product's Company's Name : ";
                                            fgets(inv->write_products->company_name, sizeof(inv->write_products->company_name), stdin);
                                            fflush(stdin);
                                            fs->newline_remover(inv->write_products->company_name);
                                            if(fs->constrains(inv->write_products->company_name, 5) == 1)
                                            {
                                                cout<<"Company names can't have symbols. Press any key to go back.\n";
                                                system("pause>null");
                                                system("cls");
                                                x=4;
                                                menu_item=1;
                                                fs->gotoXY(1,x); cout << "->";
                                                break;
                                            }
                                            cin.clear();
                                            cout<<"Product's Company's PhoneNumber : ";
                                            fgets(inv->write_products->company_phoneno, sizeof(inv->write_products->company_name), stdin);
                                            fflush(stdin);
                                            fs->newline_remover(inv->write_products->company_name);
                                            if(fs->constrains(inv->write_products->company_phoneno, 3) == 1)
                                            {
                                                cout<<"Company phonenumbers must be numbers. Press any key to go back.\n";
                                                system("pause>null");
                                                system("cls");
                                                x=4;
                                                menu_item=1;
                                                fs->gotoXY(1,x); cout << "->";
                                                break;
                                            }
                                            cin.clear();
                                            fflush(stdin);
                                            fun_result = type4_write->edit_inventory(inv->write_products, inv->read_products, 8);
                                            if(fun_result == 1)
                                            {
                                                cout<<"Product was edited successfuly. Changing barcodes requires refreshing, press any key to refresh items.\n";
                                                system("pause>null");
                                                system("cls");
                                                y--;
                                                x=4;
                                                menu_item=1;
                                                fs->gotoXY(1,x); cout << "->";
                                                break;
                                            }
                                            else
                                            {
                                                cout<<"An error occured while editing, press any key to continue.\n";
                                                system("pause>null");
                                            }
                                            system("cls");
                                            x=4;
                                            menu_item=1;
                                            fs->gotoXY(1,x); cout << "->";
                                            break;
                                        case 9:
                                            y--; //Back
                                            system("cls");
                                            x=4;
                                            menu_item=1;
                                            fs->gotoXY(1,x); cout << "->";
                                            break;
                                        }
                                            }
                                    }
                                }
                                else
                                {
                                    cout<<"No such product exists, press any key to continue.\n";
                                    system("pause>null");
                                }
                                system("cls");
                                x=4;
                                menu_item=1;
                                fs->gotoXY(1,x); cout << "->";
                                break;
                            case 5 : //Shortage Check.
                                system("cls");
                                fflush(stdin);
                                fun_result = type4_write->shortage_check(inv->write_products, inv->read_products, hold->vectorName);
                                if(fun_result == 0)
                                {
                                    cout<<"\n\nNo shortage was found, press any key to proceed.\n";
                                    system("pause>null");
                                }
                                else
                                {
                                    system("cls");
                                    cout<<"\n\nShortage Report\n===============================\n";
                                    vector<product>::iterator counter; //Check whole vector
                                    for ( counter = hold->vectorName.begin(); counter != hold->vectorName.end(); counter++ )
                                        cout
                                        <<"\nProduct's Name : "<<counter->name
                                        <<"\nProduct's Barcode : "<<counter->bar_code
                                        <<"\nProduct's Type : "<<counter->type
                                        <<"\nProduct's Price : "<<counter->price
                                        <<" LE\nProduct's Quantity : "<<counter->quantity
                                        <<"\nProduct's Shipping Company's Name : "<<counter->company_name
                                        <<"\nProduct's Shipping Company's no. : "<<counter->company_phoneno
                                        <<"\n================================================================================\n";
                                    cout<<"\nSearch completed, press any key to proceed.\n";
                                    system("pause>null");
                                }
                                system("cls");
                                x=4;
                                menu_item=1;
                                fs->gotoXY(1,x); cout << "->";
                                break;
                            case 6 : //Show all products
                                system("cls");
                                read.open("inventory.dat", ios::app | ios::binary);
                                cout<<"\nProducts\n==================\n";
                                while(read.read((char*) &*(inv->read_products), sizeof*(inv->read_products)))
                                    cout
                                    <<"Product's name : "<<inv->read_products->name
                                    <<"\nProduct's Barcode : "<<inv->read_products->bar_code
                                    <<"\nCurrent Quantity : "<<inv->read_products->quantity
                                    <<"\nProduct's price : "<<inv->read_products->price
                                    <<" LE\nCompany's name : "<<inv->read_products->company_name
                                    <<"\nCompany's phone no. : "<<inv->read_products->company_phoneno
                                    <<"\n=============================================================\n";
                                cout<<"\nCompleted.\n";
                                read.close();
                                system("pause>null");
                                system("cls");
                                x=4;
                                menu_item=1;
                                fs->gotoXY(1,x); cout << "->";
                                break;
                            case 7 : //Change Password
                                system("cls");
                                cout<<"Input Current Password : ";
                                fs->passwordEntry(type4_write->password);
                                fs->encrypt(type4_write->password);
                                cout<<"Input New Password : ";
                                fs->passwordEntry(new_pass);
                                if(fs->constrains(new_pass, 4) == 1)
                                {
                                    cout<<"Passwords can't have symbols. Press any key to go back.\n";
                                    system("pause>null");
                                    system("cls");
                                    x=4;
                                    menu_item=1;
                                    fs->gotoXY(1,x); cout << "->";
                                    break;
                                }
                                if(fs->constrains(new_pass, 1) == 1)
                                {
                                    cout<<"Usernames and passwords are 1-20 characters long. Press any key to go back.\n";
                                    system("pause>null");
                                    system("cls");
                                    x=4;
                                    menu_item=1;
                                    fs->gotoXY(1,x); cout << "->";
                                    break;
                                }
                                fs->encrypt(new_pass);
                                strcpy(type4_write->username, rec_result);
                                fs->encrypt(type4_write->username);
                                fun_result = type4_write->edit_password(type4_write, type4_read, new_pass);
                                if (fun_result == 1)
                                {
                                    cout<<"Password edited successfuly, press any key to continue.\n";
                                    system("pause>null");
                                }
                                else
                                {
                                    cout<<"\nIncorrect Password, press any key to continue.\n===============================================";
                                    system("pause>null");
                                }
                                system("cls");
                                x=4;
                                menu_item=1;
                                fs->gotoXY(1,x); cout << "->";
                                break;
                            case 8 :
                                y--;
                                system("cls");
                                x=4;
                                menu_item=1;
                                fs->gotoXY(1,x); cout << "->";
                                break;
                            }
                            }
                        }
                    } //Inventory Officer's functions [/end]
                    else //Inventory Officer login failure.
                    {
                        cout<<"\nIncorrect Password or User Name.\n=====================================";
                        system("pause>null");
                    }
                    system("cls");
                    x=4;
                    menu_item=1;
                    fs->gotoXY(1,x); cout << "->";
                    break;
                case Cashiers : //Cashier's case.
                    system("cls");
                    cout<<"Input Username : ";
                    fgets(type2_write->username, sizeof(type2_write->username), stdin);
                    fflush(stdin);
                    fs->newline_remover(type2_write->username);
                    fs->encrypt(type2_write->username);
                    cout<<"Input Password : ";
                    fs->passwordEntry(type2_write->password);
                    fs->encrypt(type2_write->password);
                    fun_result = type2_write->login_users(type2_write, type2_read);
                    if(fun_result == 1) //Cashier's functions.
                    {
                        cout<<"Login successful. Press any key to proceed.\n"<<endl;
                        strcpy(rec_result, type2_write->username);
                        fs->decrypt(rec_result);
                        system("pause>null");
                        system("cls");
                        menu_item=1;
                        x=4;
                        fs->gotoXY(1,x); cout << "->";
                        y = 3;
                        while(y==3)
                        {
                            fs->gotoXY(3,1);  cout << "Logged in with username : "<<rec_result;
                            fs->gotoXY(3,2);  cout << "===========================================";
                            fs->gotoXY(3,4);  cout << "[1] Change Passwords";
                            fs->gotoXY(3,5);  cout << "[2] Check out";
                            fs->gotoXY(3,6);  cout << "[3] Search For Product";
                            fs->gotoXY(3,7);  cout << "[4] Log off";
                            system("pause>null");
                            if(GetAsyncKeyState(VK_DOWN) & 0x8000 && x != 7) //down button pressed >>>>>>>>>> 8
                            {
                                fs->gotoXY(1,x); cout << "  ";
                                x++;
                                fs->gotoXY(1,x); cout << "->";
                                menu_item++;
                                continue;
                            }
                            if(GetAsyncKeyState(VK_DOWN) & 0x8000 && x == 7) //down button pressed >>>>>>>>>> 8
                            {
                                fs->gotoXY(1,x); cout << "  ";

                                fs->gotoXY(1,4); cout << "->";
                                x=4;
                                menu_item=1;
                                continue;
                            }
                            if(GetAsyncKeyState(VK_UP) & 0x8000 && x != 4) //up button pressed
                            {
                                fs->gotoXY(1,x); cout << "  ";
                                x--;
                                fs->gotoXY(1,x); cout << "->";
                                menu_item--;
                                continue;
                            }
                            if(GetAsyncKeyState(VK_UP) & 0x8000 && x == 4) //up button pressed
                            {
                                fs->gotoXY(1,x); cout << "  ";

                                fs->gotoXY(1,7); cout << "->";
                                x=7;
                                menu_item=4;
                                continue;
                            }
                            if(GetAsyncKeyState(VK_RETURN)& 0x8000 )
                            {
                            switch(menu_item)
                            {
                            case 1 : //Change Password
                                system("cls");
                                cout<<"Input Current Password : ";
                                fs->passwordEntry(type2_write->password);
                                fs->encrypt(type2_write->password);
                                cout<<"Input New Password : ";
                                fs->passwordEntry(new_pass);
                                if(fs->constrains(new_pass, 4) == 1)
                                {
                                    cout<<"Passwords can't have symbols. Press any key to go back.\n";
                                    system("pause>null");
                                    system("cls");
                                    x=4;
                                    menu_item=1;
                                    fs->gotoXY(1,x); cout << "->";
                                    break;
                                }
                                if(fs->constrains(new_pass, 1) == 1)
                                {
                                    cout<<"Usernames and passwords are 1-20 characters long. Press any key to go back.\n";
                                    system("pause>null");
                                    system("cls");
                                    x=4;
                                    menu_item=1;
                                    fs->gotoXY(1,x); cout << "->";
                                    break;
                                }
                                fs->encrypt(new_pass);
                                strcpy(type2_write->username, rec_result);
                                fs->encrypt(type2_write->username);
                                fun_result = type2_write->edit_password(type2_write, type2_read, new_pass);
                                if (fun_result == 1)
                                {
                                    cout<<"Password edited successfuly, press any key to continue.\n";
                                    system("pause>null");
                                }
                                else
                                {
                                    cout<<"\nIncorrect Password, press any key to continue.\n===============================================";
                                    system("pause>null");
                                }
                                system("cls");
                                x=4;
                                menu_item=1;
                                fs->gotoXY(1,x); cout << "->";
                                break;
                            case 2 : //Check out
                                {
                                hold->vectorName.clear();
                                bill->priceToPay = 0;
                                y = 4;
                                system("cls");
                                x=4;
                                menu_item=1;
                                fs->gotoXY(1,x); cout << "->";
                                while(y == 4)
                                {
                                    fs->gotoXY(3,1);  cout << "Check Out";
                                    fs->gotoXY(3,2);  cout << "===========================================";
                                    fs->gotoXY(3,4);  cout << "[1] Add Item";
                                    fs->gotoXY(3,5);  cout << "[2] Remove Item";
                                    fs->gotoXY(3,6);  cout << "[3] View Cart";
                                    fs->gotoXY(3,7);  cout << "[4] Generate Receipt";
                                    fs->gotoXY(3,8);  cout << "[5] Clear Cart";
                                    fs->gotoXY(3,9);  cout << "[6] Close";
                                    fs->gotoXY(3,11); cout << "Current Price :w "<<bill->priceToPay<<" LE";
                                    system("pause>null");
                                    if(GetAsyncKeyState(VK_DOWN) & 0x8000 && x != 9) //down button pressed >>>>>>>>>> 8
                                    {
                                        fs->gotoXY(1,x); cout << "  ";
                                        x++;
                                        fs->gotoXY(1,x); cout << "->";
                                        menu_item++;
                                        continue;
                                    }
                                    if(GetAsyncKeyState(VK_DOWN) & 0x8000 && x == 9) //down button pressed >>>>>>>>>> 8
                                    {
                                        fs->gotoXY(1,x); cout << "  ";

                                        fs->gotoXY(1,4); cout << "->";
                                        x=4;
                                        menu_item=1;
                                        continue;
                                    }
                                    if(GetAsyncKeyState(VK_UP) & 0x8000 && x != 4) //up button pressed
                                    {
                                        fs->gotoXY(1,x); cout << "  ";
                                        x--;
                                        fs->gotoXY(1,x); cout << "->";
                                        menu_item--;
                                        continue;
                                    }
                                    if(GetAsyncKeyState(VK_UP) & 0x8000 && x == 4) //up button pressed
                                    {
                                        fs->gotoXY(1,x); cout << "  ";

                                        fs->gotoXY(1,9); cout << "->";
                                        x=9;
                                        menu_item=6;
                                        continue;
                                    }
                                    if(GetAsyncKeyState(VK_RETURN)& 0x8000 )
                                    {
                                        switch(menu_item)
                                        {
                                        case 1:
                                            system("cls");
                                            cout<<"Input product's ID : ";
                                            fgets(inv->write_products->bar_code, sizeof(inv->write_products->bar_code), stdin);
                                            fs->newline_remover(inv->write_products->bar_code);
                                            fflush(stdin);
                                            cout<<"Input Quantity : ";
                                            fgets(input, sizeof(input), stdin);
                                            fflush(stdin);
                                            fs->newline_remover(input);
                                            inv->write_products->quantity = atoll(input);
                                            if(fs->constrains_num(inv->write_products->quantity, 7 ) == 1)
                                            {
                                                cout<<"Error! Invalid Input. Press any key to go back.\n";
                                                system("pause>null");
                                                system("cls");
                                                x=4;
                                                menu_item=1;
                                                fs->gotoXY(1,x); cout << "->";
                                                break;
                                            }
                                            fun_result = type2_write->add_cart(inv->write_products, inv->read_products, hold->vectorName, &bill->priceToPay);
                                            if(fun_result == 0)
                                            {
                                                cout<<"No such a product exist, please re-check product's ID.";
                                                system("pause>null");
                                            }
                                            system("cls");
                                            x=4;
                                            menu_item=1;
                                            fs->gotoXY(1,x); cout << "->";
                                            break;
                                        case 2:
                                            system("cls");
                                            cout<<"Input product's ID : ";
                                            fgets(inv->write_products->bar_code, sizeof(inv->write_products->bar_code), stdin);
                                            fflush(stdin);
                                            fs->newline_remover(inv->write_products->bar_code);
                                            fun_result = type2_write->remove_cart(inv->write_products, hold->vectorName, &bill->priceToPay);
                                            if(fun_result == 0)
                                            {
                                                cout<<"You didn't include such a product.";
                                                system("pause>null");
                                            }
                                            system("cls");
                                            x=4;
                                            menu_item=1;
                                            fs->gotoXY(1,x); cout << "->";
                                            break;
                                        case 3:
                                            system("cls");
                                            if(menu_item==3)
                                            {
                                                vector<product>::iterator counter; //Check whole vector
                                                for ( counter = hold->vectorName.begin(); counter != hold->vectorName.end(); counter++ )
                                                {
                                                    menu_item=2;
                                                    cout<<counter->quantity<<"x "<<counter->name<<" = "<<counter->price*counter->quantity<<" LE - ID : "<<counter->bar_code<<"\n";
                                                }
                                                if(menu_item==3)
                                                {
                                                    cout<<"You didn't add any products";
                                                    system("pause>null");
                                                }
                                                else
                                                    system("pause>null");
                                            }
                                            system("cls");
                                            x=4;
                                            menu_item=1;
                                            fs->gotoXY(1,x); cout << "->";
                                            break;
                                        case 4:
                                            system("cls");
                                            if(bill->priceToPay!=0)
                                            {
                                                strcpy(bill->currentCashier, rec_result);
                                                strcpy(bill->DateTime, bill->currentDateTime().c_str());
                                                type2_write->generate_receipt(bill);
                                                cout<<"\t\t\t\t\t\n\nCashier : "<<bill->currentCashier<<"\n\n"
                                                    <<"Receipt ID : "<<bill->getID()<<"\n\n"
                                                    <<"Date : "<<bill->DateTime<<"\n\n"
                                                    <<"Price : "<<bill->priceToPay<<" LE\n\n"
                                                    <<"Items Purchased\n==================\n\n";
                                                vector<product>::iterator counter; //Check whole vector
                                                for ( counter = hold->vectorName.begin(); counter != hold->vectorName.end(); counter++ )
                                                {
                                                    cout<<counter->quantity<<"x "<<counter->name<<" = "<<counter->price*counter->quantity<<" LE - ID : "<<counter->bar_code<<"\n\n";
                                                    strcpy(inv->read_products->bar_code, counter->bar_code);
                                                    inv->read_products->quantity = counter->quantity;
                                                    fun_result = type4_write->edit_inventory(inv->write_products, inv->read_products, 9);
                                                }
                                                system("pause>null");

                                            }
                                            else
                                            {
                                                cout<<"You didn't add any products.";
                                                system("pause>null");
                                            }
                                            system("cls");
                                            x=4;
                                            menu_item=1;
                                            fs->gotoXY(1,x); cout << "->";
                                            break;
                                        case 5:
                                            hold->vectorName.clear();
                                            bill->priceToPay = 0;
                                            system("cls");
                                            x=4;
                                            menu_item=1;
                                            fs->gotoXY(1,x); cout << "->";
                                            break;
                                        case 6:
                                            y--;
                                            x=4;
                                            menu_item=1;
                                            fs->gotoXY(1,x); cout << "->";
                                            break;
                                        }

                                    }
                                }
                                system("cls");
                                x=4;
                                menu_item=1;
                                fs->gotoXY(1,x); cout << "->";
                                break;
                                }
                            case 3 : //Search for a product.
                                system("cls");
                                y = 4;
                                menu_item = 1;
                                x = 4;
                                fs->gotoXY(1,x); cout << "->";
                                while(y==4)
                                {
                                    hold->vectorName.clear();
                                    fs->gotoXY(3,1);  cout << "Search for a product";
                                    fs->gotoXY(3,2);  cout << "=======================";
                                    fs->gotoXY(3,4);  cout << "[1] Search by Name";
                                    fs->gotoXY(3,5);  cout << "[2] Search by Type";
                                    fs->gotoXY(3,6);  cout << "[3] Search by Price (Range)";
                                    fs->gotoXY(3,7);  cout << "[4] Search by Company Name";
                                    fs->gotoXY(3,8);  cout << "[5] Go Back.";
                                    system("pause>null");
                                    if(GetAsyncKeyState(VK_DOWN) & 0x8000 && x != 8) //down button pressed >>>>>>>>>> 8
                                        {
                                            fs->gotoXY(1,x); cout << "  ";
                                            x++;
                                            fs->gotoXY(1,x); cout << "->";
                                            menu_item++;
                                            continue;
                                        }
                                        if(GetAsyncKeyState(VK_DOWN) & 0x8000 && x == 8) //down button pressed >>>>>>>>>> 8
                                        {
                                            fs->gotoXY(1,x); cout << "  ";

                                            fs->gotoXY(1,4); cout << "->";
                                            x=4;
                                            menu_item=1;
                                            continue;
                                        }
                                        if(GetAsyncKeyState(VK_UP) & 0x8000 && x != 4) //up button pressed
                                        {
                                            fs->gotoXY(1,x); cout << "  ";
                                            x--;
                                            fs->gotoXY(1,x); cout << "->";
                                            menu_item--;
                                            continue;
                                        }
                                        if(GetAsyncKeyState(VK_UP) & 0x8000 && x == 4) //up button pressed
                                        {
                                            fs->gotoXY(1,x); cout << "  ";

                                            fs->gotoXY(1,8); cout << "->";
                                            x=8;
                                            menu_item=5;
                                            continue;
                                        }
                                        if(GetAsyncKeyState(VK_RETURN)& 0x8000 )
                                        {
                                            switch(menu_item)
                                            {
                                                case 1: //Search by Name
                                                    system("cls");
                                                    cout<<"Product's Name : ";
                                                    fgets(inv->write_products->name, sizeof(inv->write_products->name), stdin);
                                                    fflush(stdin);
                                                    fs->newline_remover(inv->write_products->name);
                                                    fun_result = type2_write->search_inventory(inv->write_products, inv->read_products, 1, hold->vectorName);
                                                    if(fun_result == 1)
                                                    {
                                                        cout<<"\nMatching found\n===============================\n";
                                                        vector<product>::iterator counter; //Check whole vector
                                                        for ( counter = hold->vectorName.begin(); counter != hold->vectorName.end(); counter++ )
                                                            cout
                                                            <<"\nProduct's Name : "<<counter->name
                                                            <<"\nProduct's Barcode : "<<counter->bar_code
                                                            <<"\nProduct's Type : "<<counter->type
                                                            <<"\nProduct's Price : "<<counter->price
                                                            <<" LE\nProduct's Quantity : "<<counter->quantity
                                                            <<"\nProduct's Shipping Company's Name : "<<counter->company_name
                                                            <<"\nProduct's Shipping Company's no. : "<<counter->company_phoneno
                                                            <<"\n================================================================================\n";
                                                        cout<<"\nSearch completed, press any key to proceed.\n";
                                                        system("pause>null");
                                                        system("cls");
                                                        x=4;
                                                        menu_item=1;
                                                        fs->gotoXY(1,x); cout << "->";
                                                        break;
                                                    }
                                                    else
                                                    {
                                                        cout<<"No such product exists, press any key to continue.\n";
                                                        system("pause>null");
                                                        system("cls");
                                                        x=4;
                                                        menu_item=1;
                                                        fs->gotoXY(1,x); cout << "->";
                                                        break;
                                                    }
                                                    system("cls");
                                                    x=4;
                                                    menu_item=1;
                                                    fs->gotoXY(1,x); cout << "->";
                                                    break;
                                                case 2: //Search by Type
                                                    system("cls");
                                                    cout<<"Product's Type : ";
                                                    fgets(inv->write_products->type, sizeof(inv->write_products->type), stdin);
                                                    fflush(stdin);
                                                    fs->newline_remover(inv->write_products->type);
                                                    fun_result = type2_write->search_inventory(inv->write_products, inv->read_products, 3, hold->vectorName);
                                                    if(fun_result == 1)
                                                    {
                                                        cout<<"\nMatching found\n===============================\n";
                                                        vector<product>::iterator counter; //Check whole vector
                                                        for ( counter = hold->vectorName.begin(); counter != hold->vectorName.end(); counter++ )
                                                            cout
                                                            <<"\nProduct's Name : "<<counter->name
                                                            <<"\nProduct's Barcode : "<<counter->bar_code
                                                            <<"\nProduct's Type : "<<counter->type
                                                            <<"\nProduct's Price : "<<counter->price
                                                            <<" LE\nProduct's Quantity : "<<counter->quantity
                                                            <<"\nProduct's Shipping Company's Name : "<<counter->company_name
                                                            <<"\nProduct's Shipping Company's no. : "<<counter->company_phoneno
                                                            <<"\n================================================================================\n";
                                                        cout<<"\nSearch completed, press any key to proceed.\n";
                                                        system("pause>null");
                                                        system("cls");
                                                        x=4;
                                                        menu_item=1;
                                                        fs->gotoXY(1,x); cout << "->";
                                                        break;
                                                    }
                                                    else
                                                    {
                                                        cout<<"No such product exists, press any key to continue.\n";
                                                        system("pause>null");
                                                        system("cls");
                                                        x=4;
                                                        menu_item=1;
                                                        fs->gotoXY(1,x); cout << "->";
                                                        break;
                                                    }
                                                    system("cls");
                                                    x=4;
                                                    menu_item=1;
                                                    fs->gotoXY(1,x); cout << "->";
                                                    break;
                                                case 3: //Search by Price
                                                    {
                                                    double low, high;
                                                    system("cls");
                                                    cout<<"Lowest Price : ";
                                                    fgets(input, sizeof(input), stdin);
                                                    fflush(stdin);
                                                    fs->newline_remover(input);
                                                    low = atof(input);
                                                    cout<<"Highest Price : ";
                                                    fgets(input, sizeof(input), stdin);
                                                    fflush(stdin);
                                                    fs->newline_remover(input);
                                                    high = atof(input);
                                                    fun_result = type2_write->search_inventory(inv->write_products, inv->read_products, low, high, hold->vectorName);
                                                    if(fun_result == 1)
                                                    {
                                                        cout<<"\nMatching found\n===============================\n";
                                                        vector<product>::iterator counter; //Check whole vector
                                                        for ( counter = hold->vectorName.begin(); counter != hold->vectorName.end(); counter++ )
                                                            cout
                                                            <<"\nProduct's Name : "<<counter->name
                                                            <<"\nProduct's Barcode : "<<counter->bar_code
                                                            <<"\nProduct's Type : "<<counter->type
                                                            <<"\nProduct's Price : "<<counter->price
                                                            <<" LE\nProduct's Quantity : "<<counter->quantity
                                                            <<"\nProduct's Shipping Company's Name : "<<counter->company_name
                                                            <<"\nProduct's Shipping Company's no. : "<<counter->company_phoneno
                                                            <<"\n================================================================================\n";
                                                        cout<<"\nSearch completed, press any key to proceed.\n";
                                                        system("pause>null");
                                                        system("cls");
                                                        x=4;
                                                        menu_item=1;
                                                        fs->gotoXY(1,x); cout << "->";
                                                        break;
                                                    }
                                                    else
                                                    {
                                                        cout<<"No such product exists, press any key to continue.\n";
                                                        system("pause>null");
                                                        system("cls");
                                                        x=4;
                                                        menu_item=1;
                                                        fs->gotoXY(1,x); cout << "->";
                                                        break;
                                                    }
                                                    system("cls");
                                                    x=4;
                                                    menu_item=1;
                                                    fs->gotoXY(1,x); cout << "->";
                                                    break;
                                                    }
                                                case 4: //Search by Company's Name
                                                    system("cls");
                                                    cout<<"Product's Company's Name : ";
                                                    fgets(inv->write_products->company_name, sizeof(inv->write_products->company_name), stdin);
                                                    fflush(stdin);
                                                    fs->newline_remover(inv->write_products->company_name);
                                                    fun_result = type2_write->search_inventory(inv->write_products, inv->read_products, 6, hold->vectorName);
                                                    if(fun_result == 1)
                                                    {
                                                        cout<<"\nMatching found\n===============================\n";
                                                        vector<product>::iterator counter; //Check whole vector
                                                        for ( counter = hold->vectorName.begin(); counter != hold->vectorName.end(); counter++ )
                                                            cout
                                                            <<"\nProduct's Name : "<<counter->name
                                                            <<"\nProduct's Barcode : "<<counter->bar_code
                                                            <<"\nProduct's Type : "<<counter->type
                                                            <<"\nProduct's Price : "<<counter->price
                                                            <<" LE\nProduct's Quantity : "<<counter->quantity
                                                            <<"\nProduct's Shipping Company's Name : "<<counter->company_name
                                                            <<"\nProduct's Shipping Company's no. : "<<counter->company_phoneno
                                                            <<"\n================================================================================\n";
                                                        cout<<"\nSearch completed, press any key to proceed.\n";
                                                        system("pause>null");
                                                        system("cls");
                                                        x=4;
                                                        menu_item=1;
                                                        fs->gotoXY(1,x); cout << "->";
                                                        break;
                                                    }
                                                    else
                                                    {
                                                        cout<<"No such product exists, press any key to continue.\n";
                                                        system("pause>null");
                                                        system("cls");
                                                        x=4;
                                                        menu_item=1;
                                                        fs->gotoXY(1,x); cout << "->";
                                                        break;
                                                    }
                                                    system("cls");
                                                    x=4;
                                                    menu_item=1;
                                                    fs->gotoXY(1,x); cout << "->";
                                                    break;
                                                case 5:
                                                    y--; //Back
                                                    system("cls");
                                                    x=4;
                                                    menu_item=1;
                                                    fs->gotoXY(1,x); cout << "->";
                                                    break;
                                            }
                                        }
                                }
                                system("cls");
                                x=4;
                                menu_item=1;
                                fs->gotoXY(1,x); cout << "->";
                                break;
                            case 4 :
                                y--;
                                system("cls");
                                x=4;
                                menu_item=1;
                                fs->gotoXY(1,x); cout << "->";
                                break;
                            }
                        }
                        }
                    } //Cashier's functions [/end]
                    else //Cashier's login failure.
                    {
                        cout<<"\nIncorrect Password or User Name.\n=====================================";
                        system("pause>null");
                    }
                    system("cls");
                    x=4;
                    menu_item=1;
                    fs->gotoXY(1,x); cout << "->";
                    break;
                case Customers : //Customer's case.
                    system("cls");
                    cout<<"Input Username : ";
                    fgets(type3_write->username, sizeof(type3_write->username), stdin);
                    fflush(stdin);
                    fs->newline_remover(type3_write->username);
                    fs->encrypt(type3_write->username);
                    cout<<"Input Password : ";
                    fs->passwordEntry(type3_write->password);
                    fs->encrypt(type3_write->password);
                    fun_result = type3_write->login_users(type3_write, type3_read);
                    if(fun_result == 1) //Customer's functions.
                    {
                        cout<<"Login successful. Press any key to proceed.\n"<<endl;
                        strcpy(rec_result, type3_write->username);
                        fs->decrypt(rec_result);
                        system("pause>null");
                        y = 3;
                        system("cls");
                        menu_item=1;
                        x=4;
                        fs->gotoXY(1,x); cout << "->";
                        while(y==3)
                        {
                            fs->gotoXY(3,1);  cout << "Logged in with username : "<<rec_result;
                            fs->gotoXY(3,2);  cout << "==========================================";
                            fs->gotoXY(3,4);  cout << "[1] Ask Questions";
                            fs->gotoXY(3,5);  cout << "[2] Your Questions";
                            fs->gotoXY(3,6);  cout << "[3] Change Password";
                            fs->gotoXY(3,7);  cout << "[4] Browse Products";
                            fs->gotoXY(3,8);  cout << "[5] Report Defective Purchase";
                            fs->gotoXY(3,9);  cout << "[6] Call Us";
                            fs->gotoXY(3,10); cout << "[7] Log off";
                            system("pause>null");
                            if(GetAsyncKeyState(VK_DOWN) & 0x8000 && x != 10) //down button pressed >>>>>>>>>> 8
                            {
                                fs->gotoXY(1,x); cout << "  ";
                                x++;
                                fs->gotoXY(1,x); cout << "->";
                                menu_item++;
                                continue;
                            }
                            if(GetAsyncKeyState(VK_DOWN) & 0x8000 && x == 10) //down button pressed >>>>>>>>>> 8
                            {
                                fs->gotoXY(1,x); cout << "  ";

                                fs->gotoXY(1,4); cout << "->";
                                x=4;
                                menu_item=1;
                                continue;
                            }
                            if(GetAsyncKeyState(VK_UP) & 0x8000 && x != 4) //up button pressed
                            {
                                fs->gotoXY(1,x); cout << "  ";
                                x--;
                                fs->gotoXY(1,x); cout << "->";
                                menu_item--;
                                continue;
                            }
                            if(GetAsyncKeyState(VK_UP) & 0x8000 && x == 4) //up button pressed
                            {
                                fs->gotoXY(1,x); cout << "  ";

                                fs->gotoXY(1,10); cout << "->";
                                x=10;
                                menu_item=7;
                                continue;
                            }
                            if(GetAsyncKeyState(VK_RETURN)& 0x8000 )
                            {
                            switch(menu_item)
                            {
                            case 1 : //Ask a question
                                system("cls");
                                cout<<"Input question : ";
                                fgets(ask_write->asked_question, sizeof(ask_write->asked_question), stdin);
                                fflush(stdin);
                                fs->newline_remover(ask_write->asked_question);
                                if(fs->constrains(ask_write->asked_question, 8) == 1)
                                {
                                    cout<<"Question exceeded range (1-300).";
                                    system("pause>null");
                                    system("cls");
                                    x=4;
                                    menu_item=1;
                                    fs->gotoXY(1,x); cout << "->";
                                    break;
                                }
                                strcpy(ask_write->username, rec_result);
                                if(type3_write->add_question(ask_write) == 1)
                                    cout<<"Questions added successfuly.";
                                system("pause>null");
                                system("cls");
                                x=4;
                                menu_item=1;
                                fs->gotoXY(1,x); cout << "->";
                                break;
                            case 2 : //Check your questions
                                {
                                system("cls");
                                strcpy(ask_write->username, rec_result);
                                fun_result = 0;
                                read.open("questions.dat", ios::app | ios::binary);
                                temp.open("answers.dat", ios::app | ios::binary);
                                while(read.read((char*) &*(ask_read), sizeof*(ask_read)))
                                {
                                    if(strcmp(ask_write->username, ask_read->username) == 0)
                                    {
                                        int answer_found = 0;
                                        fun_result++;
                                        cout
                                        <<"\nID : "<<ask_read->id
                                        <<"\nQuestion : "<<ask_read->asked_question
                                        <<"\nAnswer : ";
                                        temp.clear() ;
                                        temp.seekg(0, ios::beg);
                                        while(temp.read((char*) &*(answer_read), sizeof*(answer_read)))
                                        {
                                            if(ask_read->id == answer_read->id && strcmp(ask_read->username, answer_read->username) == 0)
                                            {
                                                cout<<answer_read->answered_question<<"\n";
                                                answer_found++;
                                            }
                                        }
                                        if(answer_found == 0)
                                            cout<<"Not answered yet\n";
                                        cout<<"\n===========================================\n";
                                    }
                                }
                                if(fun_result==0)
                                    cout<<"You didn't ask any questions.";
                                read.close();
                                temp.close();
                                system("pause>null");
                                system("cls");
                                x=4;
                                menu_item=1;
                                fs->gotoXY(1,x); cout << "->";
                                break;
                                }
                            case 3 : //Change Password
                                system("cls");
                                cout<<"Input Current Password : ";
                                fs->passwordEntry(type3_write->password);
                                fs->encrypt(type3_write->password);
                                cout<<"Input New Password : ";
                                fs->passwordEntry(new_pass);
                                if(fs->constrains(new_pass, 4) == 1)
                                {
                                    cout<<"Passwords can't have symbols. Press any key to go back.\n";
                                    system("pause>null");
                                    system("cls");
                                    x=4;
                                    menu_item=1;
                                    fs->gotoXY(1,x); cout << "->";
                                    break;
                                }
                                if(fs->constrains(new_pass, 1) == 1)
                                {
                                    cout<<"Usernames and passwords are 1-20 characters long. Press any key to go back.\n";
                                    system("pause>null");
                                    system("cls");
                                    x=4;
                                    menu_item=1;
                                    fs->gotoXY(1,x); cout << "->";
                                    break;
                                }
                                fs->encrypt(new_pass);
                                strcpy(type3_write->username, rec_result);
                                fs->encrypt(type3_write->username);
                                fun_result = type3_write->edit_password(type3_write, type3_read, new_pass);
                                if (fun_result == 1)
                                {
                                    cout<<"Password edited successfuly, press any key to continue.\n";
                                    system("pause>null");
                                }
                                else
                                {
                                    cout<<"\nIncorrect Password, press any key to continue.\n===============================================";
                                    system("pause>null");
                                }
                                system("cls");
                                x=4;
                                menu_item=1;
                                fs->gotoXY(1,x); cout << "->";
                                break;
                            case 4 : //Search for a product.
                                system("cls");
                                y = 4;
                                menu_item = 1;
                                x = 4;
                                fs->gotoXY(1,x); cout << "->";
                                while(y==4)
                                {
                                    hold->vectorName.clear();
                                    fs->gotoXY(3,1);  cout << "Search for a product";
                                    fs->gotoXY(3,2);  cout << "=======================";
                                    fs->gotoXY(3,4);  cout << "[1] Search by Name";
                                    fs->gotoXY(3,5);  cout << "[2] Search by Type";
                                    fs->gotoXY(3,6);  cout << "[3] Search by Price (Range)";
                                    fs->gotoXY(3,7);  cout << "[4] Search by Company Name";
                                    fs->gotoXY(3,8);  cout << "[5] Go Back.";
                                    system("pause>null");
                                    if(GetAsyncKeyState(VK_DOWN) & 0x8000 && x != 8) //down button pressed >>>>>>>>>> 8
                                        {
                                            fs->gotoXY(1,x); cout << "  ";
                                            x++;
                                            fs->gotoXY(1,x); cout << "->";
                                            menu_item++;
                                            continue;
                                        }
                                        if(GetAsyncKeyState(VK_DOWN) & 0x8000 && x == 8) //down button pressed >>>>>>>>>> 8
                                        {
                                            fs->gotoXY(1,x); cout << "  ";

                                            fs->gotoXY(1,4); cout << "->";
                                            x=4;
                                            menu_item=1;
                                            continue;
                                        }
                                        if(GetAsyncKeyState(VK_UP) & 0x8000 && x != 4) //up button pressed
                                        {
                                            fs->gotoXY(1,x); cout << "  ";
                                            x--;
                                            fs->gotoXY(1,x); cout << "->";
                                            menu_item--;
                                            continue;
                                        }
                                        if(GetAsyncKeyState(VK_UP) & 0x8000 && x == 4) //up button pressed
                                        {
                                            fs->gotoXY(1,x); cout << "  ";

                                            fs->gotoXY(1,8); cout << "->";
                                            x=8;
                                            menu_item=5;
                                            continue;
                                        }
                                        if(GetAsyncKeyState(VK_RETURN)& 0x8000 )
                                        {
                                            switch(menu_item)
                                            {
                                                case 1: //Search by Name
                                                    system("cls");
                                                    cout<<"Product's Name : ";
                                                    fgets(inv->write_products->name, sizeof(inv->write_products->name), stdin);
                                                    fflush(stdin);
                                                    fs->newline_remover(inv->write_products->name);
                                                    fun_result = type3_write->search_inventory(inv->write_products, inv->read_products, 1, hold->vectorName);
                                                    if(fun_result == 1)
                                                    {
                                                        cout<<"\nMatching found\n===============================\n";
                                                        vector<product>::iterator counter; //Check whole vector
                                                        for ( counter = hold->vectorName.begin(); counter != hold->vectorName.end(); counter++ )
                                                            cout
                                                            <<"\nProduct's Name : "<<counter->name
                                                            <<"\nProduct's Barcode : "<<counter->bar_code
                                                            <<"\nProduct's Type : "<<counter->type
                                                            <<"\nProduct's Price : "<<counter->price
                                                            <<" LE\nProduct's Quantity : "<<counter->quantity
                                                            <<"\nProduct's Shipping Company's Name : "<<counter->company_name
                                                            <<"\nProduct's Shipping Company's no. : "<<counter->company_phoneno
                                                            <<"\n================================================================================\n";
                                                        cout<<"\nSearch completed, press any key to proceed.\n";
                                                        system("pause>null");
                                                        system("cls");
                                                        x=4;
                                                        menu_item=1;
                                                        fs->gotoXY(1,x); cout << "->";
                                                        break;
                                                    }
                                                    else
                                                    {
                                                        cout<<"No such product exists, press any key to continue.\n";
                                                        system("pause>null");
                                                        system("cls");
                                                        x=4;
                                                        menu_item=1;
                                                        fs->gotoXY(1,x); cout << "->";
                                                        break;
                                                    }
                                                    system("cls");
                                                    x=4;
                                                    menu_item=1;
                                                    fs->gotoXY(1,x); cout << "->";
                                                    break;
                                                case 2: //Search by Type
                                                    system("cls");
                                                    cout<<"Product's Type : ";
                                                    fgets(inv->write_products->type, sizeof(inv->write_products->type), stdin);
                                                    fflush(stdin);
                                                    fs->newline_remover(inv->write_products->type);
                                                    fun_result = type3_write->search_inventory(inv->write_products, inv->read_products, 3, hold->vectorName);
                                                    if(fun_result == 1)
                                                    {
                                                        cout<<"\nMatching found\n===============================\n";
                                                        vector<product>::iterator counter; //Check whole vector
                                                        for ( counter = hold->vectorName.begin(); counter != hold->vectorName.end(); counter++ )
                                                            cout
                                                            <<"\nProduct's Name : "<<counter->name
                                                            <<"\nProduct's Barcode : "<<counter->bar_code
                                                            <<"\nProduct's Type : "<<counter->type
                                                            <<"\nProduct's Price : "<<counter->price
                                                            <<" LE\nProduct's Quantity : "<<counter->quantity
                                                            <<"\nProduct's Shipping Company's Name : "<<counter->company_name
                                                            <<"\nProduct's Shipping Company's no. : "<<counter->company_phoneno
                                                            <<"\n================================================================================\n";
                                                        cout<<"\nSearch completed, press any key to proceed.\n";
                                                        system("pause>null");
                                                        system("cls");
                                                        x=4;
                                                        menu_item=1;
                                                        fs->gotoXY(1,x); cout << "->";
                                                        break;
                                                    }
                                                    else
                                                    {
                                                        cout<<"No such product exists, press any key to continue.\n";
                                                        system("pause>null");
                                                        system("cls");
                                                        x=4;
                                                        menu_item=1;
                                                        fs->gotoXY(1,x); cout << "->";
                                                        break;
                                                    }
                                                    system("cls");
                                                    x=4;
                                                    menu_item=1;
                                                    fs->gotoXY(1,x); cout << "->";
                                                    break;
                                                case 3: //Search by Price
                                                    {
                                                    double low, high;
                                                    system("cls");
                                                    cout<<"Lowest Price : ";
                                                    fgets(input, sizeof(input), stdin);
                                                    fflush(stdin);
                                                    fs->newline_remover(input);
                                                    low = atof(input);
                                                    cout<<"Highest Price : ";
                                                    fgets(input, sizeof(input), stdin);
                                                    fflush(stdin);
                                                    fs->newline_remover(input);
                                                    high = atof(input);
                                                    fun_result = type3_write->search_inventory(inv->write_products, inv->read_products, low, high, hold->vectorName);
                                                    if(fun_result == 1)
                                                    {
                                                        cout<<"\nMatching found\n===============================\n";
                                                        vector<product>::iterator counter; //Check whole vector
                                                        for ( counter = hold->vectorName.begin(); counter != hold->vectorName.end(); counter++ )
                                                            cout
                                                            <<"\nProduct's Name : "<<counter->name
                                                            <<"\nProduct's Barcode : "<<counter->bar_code
                                                            <<"\nProduct's Type : "<<counter->type
                                                            <<"\nProduct's Price : "<<counter->price
                                                            <<" LE\nProduct's Quantity : "<<counter->quantity
                                                            <<"\nProduct's Shipping Company's Name : "<<counter->company_name
                                                            <<"\nProduct's Shipping Company's no. : "<<counter->company_phoneno
                                                            <<"\n================================================================================\n";
                                                        cout<<"\nSearch completed, press any key to proceed.\n";
                                                        system("pause>null");
                                                        system("cls");
                                                        x=4;
                                                        menu_item=1;
                                                        fs->gotoXY(1,x); cout << "->";
                                                        break;
                                                    }
                                                    else
                                                    {
                                                        cout<<"No such product exists, press any key to continue.\n";
                                                        system("pause>null");
                                                        system("cls");
                                                        x=4;
                                                        menu_item=1;
                                                        fs->gotoXY(1,x); cout << "->";
                                                        break;
                                                    }
                                                    system("cls");
                                                    x=4;
                                                    menu_item=1;
                                                    fs->gotoXY(1,x); cout << "->";
                                                    break;
                                                    }
                                                case 4: //Search by Company's Name
                                                    system("cls");
                                                    cout<<"Product's Company's Name : ";
                                                    fgets(inv->write_products->company_name, sizeof(inv->write_products->company_name), stdin);
                                                    fflush(stdin);
                                                    fs->newline_remover(inv->write_products->company_name);
                                                    fun_result = type3_write->search_inventory(inv->write_products, inv->read_products, 6, hold->vectorName);
                                                    if(fun_result == 1)
                                                    {
                                                        cout<<"\nMatching found\n===============================\n";
                                                        vector<product>::iterator counter; //Check whole vector
                                                        for ( counter = hold->vectorName.begin(); counter != hold->vectorName.end(); counter++ )
                                                            cout
                                                            <<"\nProduct's Name : "<<counter->name
                                                            <<"\nProduct's Barcode : "<<counter->bar_code
                                                            <<"\nProduct's Type : "<<counter->type
                                                            <<"\nProduct's Price : "<<counter->price
                                                            <<" LE\nProduct's Quantity : "<<counter->quantity
                                                            <<"\nProduct's Shipping Company's Name : "<<counter->company_name
                                                            <<"\nProduct's Shipping Company's no. : "<<counter->company_phoneno
                                                            <<"\n================================================================================\n";
                                                        cout<<"\nSearch completed, press any key to proceed.\n";
                                                        system("pause>null");
                                                        system("cls");
                                                        x=4;
                                                        menu_item=1;
                                                        fs->gotoXY(1,x); cout << "->";
                                                        break;
                                                    }
                                                    else
                                                    {
                                                        cout<<"No such product exists, press any key to continue.\n";
                                                        system("pause>null");
                                                        system("cls");
                                                        x=4;
                                                        menu_item=1;
                                                        fs->gotoXY(1,x); cout << "->";
                                                        break;
                                                    }
                                                    system("cls");
                                                    x=4;
                                                    menu_item=1;
                                                    fs->gotoXY(1,x); cout << "->";
                                                    break;
                                                case 5:
                                                    y--; //Back
                                                    system("cls");
                                                    x=4;
                                                    menu_item=1;
                                                    fs->gotoXY(1,x); cout << "->";
                                                    break;
                                            }
                                        }
                                }
                                system("cls");
                                x=4;
                                menu_item=1;
                                fs->gotoXY(1,x); cout << "->";
                                break;
                            case 5 : //Report Defective Purchase
                                system("cls");
                                cout<<"Input Item's Name : ";
                                fgets(reports->itemName, sizeof(reports->itemName), stdin);
                                fflush(stdin);
                                fs->newline_remover(reports->itemName);
                                if(fs->constrains(reports->itemName, 1) == 1)
                                {
                                    cout<<"Item's name exceeded range (1-20).";
                                    system("pause>null");
                                    system("cls");
                                    x=4;
                                    menu_item=1;
                                    fs->gotoXY(1,x); cout << "->";
                                    break;
                                }
                                cout<<"Comment : ";
                                fgets(reports->comment, sizeof(reports->comment), stdin);
                                fflush(stdin);
                                fs->newline_remover(reports->comment);
                                if(fs->constrains(reports->comment, 8) == 1)
                                {
                                    cout<<"Item's name exceeded range (1-300).";
                                    system("pause>null");
                                    system("cls");
                                    x=4;
                                    menu_item=1;
                                    fs->gotoXY(1,x); cout << "->";
                                    break;
                                }
                                strcpy(reports->userName, rec_result);
                                if(type3_write->add_report(reports) == 1)
                                    cout<<"Report added successfuly.";
                                system("pause>null");
                                system("cls");
                                x=4;
                                menu_item=1;
                                fs->gotoXY(1,x); cout << "->";
                                break;
                            case 6 :
                                system("cls");
                                cout<<"Telephone Numbers\n====================\n";
                                read.open("phonenumbers.dat", ios::app | ios::binary);
                                while(read.read((char*) &input, sizeof(input)))
                                    cout<<input<<"\n";
                                read.close();
                                cout<<"\n\nFinished, press any key to continue.\n";
                                system("pause>null");
                                system("cls");
                                x=4;
                                menu_item=1;
                                fs->gotoXY(1,x); cout << "->";
                                break;
                            case 7 : //Go Back
                                y--;
                                system("cls");
                                x=4;
                                menu_item=1;
                                fs->gotoXY(1,x); cout << "->";
                                break;
                            }
                            }
                        }
                    } //Customer's functions [/end]
                    else //Customer's login failure.
                    {
                        cout<<"\nIncorrect Password or User Name.\n=====================================";
                        system("pause>null");
                    }
                    system("cls");
                    x=4;
                    menu_item=1;
                    fs->gotoXY(1,x); cout << "->";
                    break;
                case 5:
                    y--; //Back to main page.
                    system("cls");
                    x=4;
                    menu_item=1;
                    fs->gotoXY(1,x); cout << "->";
                    break;
                }
                }
            }
            menu_item=1;
            x=4;
            system("cls");
            fs->gotoXY(1,x); cout << "->";
            break;
        case 2 :
            fflush(stdin); //Register as a new customer.
            system("cls");
            cout<<"\nRegistering a new customer\n================================\n\n";
            cout<<"Input Username : ";
            fgets(type3_write->username, sizeof(type3_write->username), stdin);
            fflush(stdin);
            fs->newline_remover(type3_write->username);
            if(fs->constrains(type3_write->username, 4) == 1)
            {
                cout<<"Usernames can't have symbols. Press any key to go back.\n";
                system("pause>null");
                system("cls");
                x=4;
                menu_item=1;
                fs->gotoXY(1,x); cout << "->";
                break;
            }
            if(fs->constrains(type3_write->username, 1) == 1)
            {
                cout<<"Usernames and passwords are 1-20 characters long. Press any key to go back.\n";
                system("pause>null");
                system("cls");
                x=4;
                menu_item=1;
                fs->gotoXY(1,x); cout << "->";
                break;
            }
            fs->encrypt(type3_write->username);
            cin.clear();
            cout<<"Input Password : ";
            fs->passwordEntry(type3_write->password);
            if(fs->constrains(type3_write->password, 4) == 1)
            {
                cout<<"Passwords can't have symbols. Press any key to go back.\n";
                system("pause>null");
                system("cls");
                x=4;
                menu_item=1;
                fs->gotoXY(1,x); cout << "->";
                break;
            }
            if(fs->constrains(type3_write->password, 1) == 1)
            {
                cout<<"Usernames and passwords are 1-20 characters long. Press any key to go back.\n";
                system("pause>null");
                system("cls");
                x=4;
                menu_item=1;
                fs->gotoXY(1,x); cout << "->";
                break;
            }
            fs->encrypt(type3_write->password);
            cin.clear();
            fun_result = type3_write->check_if_user_exist(type3_write, type3_read);
            if(fun_result == 1)
            {
                cout<<"\nUser Name already in use, press any key to try again.\n";
                system("pause>null");
                system("cls");
                x=4;
                menu_item=1;
                fs->gotoXY(1,x); cout << "->";
                break;
            }
            fun_result = type3_write->register_users(type3_write);
            if(fun_result == 1)
            {
                cout<<"\nRegisteration successful\nPress any key to continue..\n"; //Register as a new customer [/end]
                system("pause>null");
            }
            system("cls");
            x=4;
            menu_item=1;
            fs->gotoXY(1,x); cout << "->";
            break;
        case 3 :
            y--; //Exit main program.
            system("cls");
            menu_item=1;
            fs->gotoXY(1,x); cout << "->";
            break;
        }
        }
    }
    system("cls");
    cout<<"\nProgram is now terminated.\n=============================\n";
    return 0;
}
