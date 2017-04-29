#include "receipt.h"
#include <ctime>

string receipt::currentDateTime()
{
    time_t rawtime;
    struct tm * timeinfo;
    char buffer[25];
    time (&rawtime);
    timeinfo = localtime(&rawtime);
    strftime(buffer,sizeof(buffer),"%d-%m-%Y %I:%M:%S",timeinfo);
    string time = buffer;
    return time;
}

void receipt::setID(long long int input)
{
    this->id = input;
}

long long int receipt::getID()
{
    return this->id;
}
