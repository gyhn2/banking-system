#include "Account.h"

int Account::nextNum = 10000;

// Account::Account(): acc_num(nextNum++)
// {
//     this->balance = 0;
//     this->fname = "";
//     this->lname = "";
// }

Account::Account(const double balance, 
    const std::string&  fname, const std::string&  lname, const std::string& email): 
    acc_num(nextNum++), balance(balance), fname(fname), lname(lname), email(email)
{
}


Account::Account(const std::string&  fname, const std::string&  lname, const std::string&  email): 
    acc_num(nextNum++), fname(fname), lname(lname), email(email)
{
    this->balance = 0;
}

Account::Account(const int acc_num, const double balance, 
    const std::string&  fname, const std::string&  lname, const std::string&  email):
    acc_num(acc_num), balance(balance), fname(fname), lname(lname), email(email)
{
}

Account::~Account() {}

bool Account::deposit(const double amt)
{
    balance += amt;
    std::cout << "Deposit of $" << amt << " success!" << std::endl;
    return true;
}

bool Account::withdraw(const double amt)
{
    if (amt > balance) {
        std::cout << "Cannot withdraw amount greater than balance." << std::endl;
        return false;
    }
    balance -= amt;
    std::cout << "Withdrawal of $" << amt << " success!" << std::endl;
    return true;
}

bool Account::pay(Account *& acc, const double amt)
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

bool Account::changeFName(const std::string& newname)
{
    if (newname.length() > 0) {
        fname = newname;
        std::cout << "New First Name: " << newname << std::endl;
        return true;
    }
    return false;
}

bool Account::changeLName(const std::string& newname)
{
    if (newname.length() > 0) {
        lname = newname;
        std::cout << "New Last Name: " << newname << std::endl;
        return true;
    }
    return false;
}

bool Account::changeEmail(const std::string& newEmail)
{
    if (newEmail.length() > 0) {
        email = newEmail;
        std::cout << "New Email: " << email << std::endl;
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

