#include "SavingsAccount.h"

SavingsAccount::SavingsAccount(const double balance, 
    const std::string&  fname, const std::string&  lname, const std::string& email):
    Account(balance, fname, lname, email), interestRate(INTEREST_RATE), minimumBalance(MIN_BALANCE)
{
    yearlyInterest(YEAR_INTERVAL);
}

SavingsAccount::SavingsAccount(const std::string&  fname, const std::string&  lname, const std::string&  email):
    Account(fname, lname, email), interestRate(INTEREST_RATE), minimumBalance(MIN_BALANCE)
{
    yearlyInterest(YEAR_INTERVAL);
}

SavingsAccount::SavingsAccount(const int acc_num, const double balance, 
    const std::string&  fname, const std::string&  lname, const std::string&  email):
    Account(acc_num, balance, fname, lname, email), interestRate(INTEREST_RATE), minimumBalance(MIN_BALANCE)
{
    yearlyInterest(YEAR_INTERVAL);
}

int SavingsAccount::getMinBalance() const
{
    return minimumBalance;
}

void SavingsAccount::payInterest()
{
    balance = balance * (1 + interestRate);
    std::cout << acc_num << ": balance after interest: " << balance << std::endl;
}

void SavingsAccount::yearlyInterest(unsigned int interval) {
    std::thread([this, interval]() {
        while(true) {
            auto x = std::chrono::steady_clock::now() + std::chrono::milliseconds(interval);
            std::this_thread::sleep_until(x);
            this->payInterest();
        }
    }).detach();
}
