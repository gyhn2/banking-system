#ifndef ACCOUNTMAP_H
#define ACCOUNTMAP_H

#include <iostream>

// Mapping accountholder name & email to account number

struct person {
    std::string fname;
    std::string lname;
    std::string email;

    bool operator==(const person& other) const {
        return fname == other.fname 
            && lname == other.lname 
            && email == other.email;
    }
};

template <>
struct std::hash<person> {
    size_t operator()(const person& p) const {
        return std::hash<std::string>()(p.fname) & ((std::hash<std::string>()(p.lname) << 1) >> 1) ^ (std::hash<std::string>()(p.email) << 1); 
    }
};

#endif