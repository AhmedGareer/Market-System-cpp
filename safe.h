#ifndef SAFE_H
#define SAFE_H


class safe
{
public:
    void setBalance(double input);
    double getBalance();
private:
    static double balance;
};

#endif // SAFE_H
