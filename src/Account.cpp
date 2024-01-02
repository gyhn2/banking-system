#include "Account.h"

int Account::nextNum = 10000;

// Account::Account(): acc_num(nextNum++)
// {
//     this->balance = 0;
//     this->fname = "";
//     this->lname = "";
// }

Account::Account(double balance, string fname, string lname): 
    acc_num(nextNum++), balance(balance), fname(fname), lname(lname)
{
}


Account::Account(string fname, string lname): 
    acc_num(nextNum++), fname(fname), lname(lname)
{
    this->balance = 0;
}

Account::Account(int acc_num, double balance, string fname, string lname):
    acc_num(acc_num), balance(balance), fname(fname), lname(lname)
{
}

Account::~Account() {}

bool Account::deposit(double amt)
{
    balance += amt;
    std::cout << "Deposit of $" << amt << " success!" << std::endl;
    return true;
}

bool Account::withdraw(double amt)
{
    if (amt > balance) {
        std::cout << "Cannot withdraw amount greater than balance." << std::endl;
        return false;
    }
    balance -= amt;
    std::cout << "Withdrawal of $" << amt << " success!" << std::endl;
    return true;
}

bool Account::pay(Account *& acc, double amt)
{
    if (this->withdraw(amt)) {
        if (acc->deposit(amt)) {
            std::cout << "Transfer of $" << amt 
            << " from acc no. " << this->acc_num
            << " to acc no. " << acc->acc_num
            << " success!" << std::endl;
            return true;
        } else {
            balance += amt;
        }
    }
    std::cout << "Transaction failed: reverted" << std::endl;
    return false;        
}

bool Account::changeFName(string newname)
{
    if (newname.length() > 0) {
        fname = newname;
        std::cout << "New First Name: " << newname << std::endl;
        return true;
    }
    return false;
}

bool Account::changeLName(string newname)
{
    if (newname.length() > 0) {
        lname = newname;
        std::cout << "New Last Name: " << newname << std::endl;
        return true;
    }
    return false;
}

double Account::getBalance() const
{
    return balance;
}

void Account::print() const
{
    std::cout << acc_num << " (" << fname << " " << lname << "): $" 
    << balance << std::endl;
}
