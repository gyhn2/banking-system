#include "Account.h"

int Account::nextNum = 10000;

Account::Account(): acc_num(nextNum++)
{

}

Account::Account(int acc_num, double balance, std::string fname, std::string lname):
    acc_num(acc_num), balance(balance), fname(fname), lname(lname)
{
}

bool Account::deposit(double amt)
{
    balance += amt;
    return true;
}

bool Account::withdraw(double amt)
{
    if (amt > balance) {
        std::cout << "Cannot withdraw amount greater than balance." << std::endl;
        return false;
    }
    balance -= amt;
    return true;
}

bool Account::transfer(Account * acc, double amt)
{
    return false;
}

bool Account::pay(Account * acc, double amt)
{
    return false;
}

void Account::print()
{
    std::cout << acc_num << " (" << fname << " " << lname << "): $" 
    << balance << std::endl;
}
