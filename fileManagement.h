#ifndef FILEMANAGEMENT_H
#define FILEMANAGEMENT_H
#include <string>
#include <fstream>
#include "users.h"

using namespace std;

class fileManagement
{
    public:
        template <typename ObjectAdd>
        int Add(string fileName, ObjectAdd *w)
        {
            ofstream write;
            write.open(fileName.c_str(), ios::app | ios::binary);
            write.write((char*) &(*w), sizeof(*w));
            write.close();
            return 1;
        }
        template <typename ObjectDelete>
        int Delete(string fileName, ObjectDelete *w, ObjectDelete *r)
        {
            int checker = 0;
            string fileName1;
            ifstream read;
            ofstream write;
            fileName1 = fileName + "1";
            read.open(fileName.c_str(), ios::app | ios::binary);
            write.open(fileName1.c_str(), ios::app | ios::binary);
            for(;;)
            {
                if(read.read((char*) &(*r), sizeof(*r)))
                {
                    if( (strcmp(r->username, w->username) == 0) && (strcmp(r->password, w->password) == 0) )
                        checker = 1;
                    else
                        write.write((char*) &(*r), sizeof(*r));
                }
                else
                    break;
            }
            read.close();
            write.close();
            remove(fileName.c_str());
            rename(fileName1.c_str(),fileName.c_str());
            return checker;
        }
        template <typename ObjectEdit>
        int Edit(string fileName, ObjectEdit *w, ObjectEdit *r, char(&editedValue)[25])
        {
            fstream update;
            int checker = 0;
            update.open(fileName.c_str(), ios::in | ios::out | ios::binary);
            for(;;)
            {
                int startposition = update.tellg();
                if(update.read((char*) &(*r), sizeof(*r)))
                {
                    if( (strcmp(r->username, w->username) == 0 )&& (strcmp(r->password, w->password) == 0) )
                    {
                        checker = 1;
                        strcpy(r->password, editedValue);
                        update.seekp(startposition);
                        update.write((char*) &(*r), sizeof(*r));
                    }
                }
                else
                    break;
            }
            update.close();
            return checker;
        }
        template <typename ObjectSearch>
        int Search(string fileName, ObjectSearch *w, ObjectSearch *r)
        {
            ifstream read;
            read.open(fileName.c_str(), ios::app | ios::binary);
            for(;;)
            {
                if(read.read((char*) &(*r), sizeof(*r)))
                {
                    if( (strcmp(r->username, w->username) == 0) && (strcmp(r->password, w->password) == 0) )
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
};

#endif // FILEMANAGEMENT_H
