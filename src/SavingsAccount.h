#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H

#include "Account.h"
#include <chrono>
#include <functional>
#include <thread>

#define INTEREST_RATE 0.01
#define YEAR_INTERVAL 6000
#define MIN_BALANCE 50.00

class SavingsAccount: public Account {
    public:
        SavingsAccount(const double=0.0, const std::string& = "", const std::string& = "", const std::string& = "");
        SavingsAccount(const std::string&, const std::string&, const std::string&);
        SavingsAccount(const int, const double=0.0, const std::string& = "", const std::string& = "", const std::string& = "");
        // ~SavingsAccount();
        int getMinBalance() const;

    private:
        double interestRate;
        double minimumBalance;
        Account* chequingAccount, creditAccount;
        void payInterest();
        void yearlyInterest(unsigned int);
};

#endif