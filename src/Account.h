#ifndef ACCOUNT_H
#define ACCOUNT_H
#include "Node.h"

/* Bank Acoount */

class Account : public Node {

    public:
        Account();
        Account(int, double=0, std::string="", std::string="");
        bool deposit(double);
        bool withdraw(double);
        bool transfer(Account*, double);
        bool pay(Account*, double);
        virtual void print() const;

    private:
        static int nextNum;
        int acc_num = key;
        double balance;
        std::string fname;
        std::string lname;
        
};

#endif