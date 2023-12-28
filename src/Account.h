#ifndef ACCOUNT_H
#define ACCOUNT_H
#include "Node.h"

/* Bank Acoount */

class Account : public Node {

    public:
        Account();
        Account(int);
        bool deposit();
        bool withdraw();
        bool transfer();
        bool pay();

    private:
        int account_num = key;
};

#endif