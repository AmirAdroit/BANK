
// Customer.h
#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <vector>
#include "Account.h"
#include "Transaction.h"

class Customer {
private:
    std::string id; // the id of the customer
    std::string password; // the password of the customer
    std::string name; // the name of the customer
    std::string address; // the address of the customer
    std::string phone; // the phone number of the customer
    std::vector<Account*> accounts; // a vector of pointers to accounts
    std::vector<Transaction*> transactions; // a vector of pointers to transactions

public:
    // constructor
    Customer(std::string id, std::string password, std::string name, std::string address, std::string phone);

    // destructor
    ~Customer();

    // getters and setters for id, password, name, address and phone
    std::string getId() const;
    void setId(std::string id);
    std::string getPassword() const;
    void setPassword(std::string password);
    std::string getName() const;
    void setName(std::string name);
    std::string getAddress() const;
    void setAddress(std::string address);
    std::string getPhone() const;
    void setPhone(std::string phone);

    // methods for viewing the list of accounts
    void viewAccounts() const; // prints the list of accounts

    // methods for performing transactions and transferring money between accounts
    void performTransaction(Account* from, Account* to, double amount); // transfers money from one account to another and records a transaction

    // methods for requesting to delete an existing account or create a new account
    void requestDeleteAccount(Account* account); // requests to delete an account
    void requestCreateAccount(Account* account); // requests to create an account

    // methods for viewing the transactions of an account
    void viewTransactions(Account* account) const; // prints the list of transactions of an account

};

#endif
