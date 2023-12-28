#ifndef ACCOUNT_H
#define ACCOUNT_H
#include "Node.h"

/* Bank Acoount */

class Account : public Node {

    public:
        Account();
        Account(int, int=0, std::string="", std::string="");
        bool deposit(int);
        bool withdraw(int);
        bool transfer(Account*, int);
        bool pay(Account*, int);
        void print();

    private:
        int account_num = key;
        int balance;
        std::string fname;
        std::string lname;
        
};

#endif