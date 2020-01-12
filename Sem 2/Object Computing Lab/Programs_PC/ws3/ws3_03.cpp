#include <iostream>

int counter = 0;
class Account
{
    int accountNumber, balance;
    char accountType;

public:
    Account(char = 'S');
    bool deposit(int);
    int withdraw(int);
    int bal();
    bool hasMinbalance();
};

Account::Account(char type)
{
    accountNumber = ++counter;
    balance = 1000;
    accountType = 'S';
}

int Account::bal()
{
    return balance;
}

bool Account::deposit(int amount)
{
    if (amount > 0)
    {
        balance += amount;
        return true;
    }
    else
        return false;
}

int Account::withdraw(int amount)
{
    if (balance - amount > 1000)
    {
        balance -= amount;
        return amount;
    }
    else
    {
        return 0;
    }
}

bool Account::hasMinbalance()
{
    if (balance > 1000)
        return true;
    else
        return false;
}