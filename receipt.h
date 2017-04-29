#ifndef RECEIPT_H
#define RECEIPT_H
#include <string>

using namespace std;
class receipt
{
    public:
        double priceToPay;
        char currentCashier[25];
        char DateTime[25];
        string currentDateTime();
        void setID(long long int input);
        long long int getID();
    private:
        long long int id;
};

#endif // RECEIPT_H
