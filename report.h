#ifndef REPORT_H
#define REPORT_H
#include <string>

using namespace std;

class report
{
    public:
        char userName[25];
        char itemName[25];
        char comment[305];
        void setID(long long int input);
        long long int getID();
    private:
        long long int id;
};

#endif // REPORT_H
