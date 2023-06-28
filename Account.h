// Account.h
#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
#include <vector>
#include "Transaction.h"

class Account {
protected:
    std::string number; // the number of the account
    double balance; // the balance of the account
    std::vector<Transaction*> transactions; // a vector of pointers to transactions

public:
    // constructor
    Account(std::string number, double balance);

    // destructor
    virtual ~Account();

    // getters and setters for number and balance
    std::string getNumber() const;
    void setNumber(std::string number);
    double getBalance() const;
    void setBalance(double balance);

    // methods for depositing and withdrawing money
    virtual void deposit(double amount); // adds money to the account and records a transaction
    virtual void withdraw(double amount); // subtracts money from the account and records a transaction

    // methods for viewing the transactions of the account
    void viewTransactions() const; // prints the list of transactions

    // a virtual method for printing the details of the account
    virtual std::string toString() const = 0; // returns a string representation of the account

};

#endif
