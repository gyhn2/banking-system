#ifndef ACCOUNT_H
#define ACCOUNT_H
#include "Node.h"

using std::string;

/* Bank Acoount */

class Account : public Node {
    friend class AccountTree;

    public:
        // Account();
        Account(double=0.0, string="", string="");
        Account(string, string);
        Account(int, double=0.0, string="", string="");
        ~Account();
        bool deposit(double);
        bool withdraw(double);
        bool pay(Account*&, double);
        bool changeFName(string);
        bool changeLName(string);
        double getBalance() const;
        virtual void print() const;

    private:
        static int nextNum;
        int acc_num = key;
        double balance;
        std::string fname;
        std::string lname;
        Account* left;
        Account* right;
        
};

#endif