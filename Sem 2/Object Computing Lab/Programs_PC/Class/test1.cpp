#include <iostream>

using namespace std;

class Account{
    const float interestRate;
    int no;
    public:
    Account(int,int);
    void print();
};

Account::Account(int rate,int no1):interestRate(rate){
    no = no1;
}


void Account::print()
{
    cout<<interestRate <<"  "<<no;

}

int main()
{
    Account A1(123,10);
    A1.print();
    return 0;
}