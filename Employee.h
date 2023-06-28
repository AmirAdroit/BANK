// Employee.h
#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include <vector>
#include "Customer.h"
#include "Account.h"
#include "Loan.h"
#include "Transaction.h"

class Employee {
private:
    std::string id; // the id of the employee
    std::string password; // the password of the employee
    std::string name; // the name of the employee
    double salary; // the salary of the employee

public:
    // constructor
    Employee(std::string id, std::string password, std::string name, double salary);

    // destructor
    ~Employee();

    // getters and setters for id, password, name and salary
    std::string getId() const;
    void setId(std::string id);
    std::string getPassword() const;
    void setPassword(std::string password);
    std::string getName() const;
    void setName(std::string name);
    double getSalary() const;
    void setSalary(double salary);

    // methods for searching and viewing customers and accounts
    std::vector<Customer*> searchCustomers(std::string criteria) const; // returns a vector of customers that match the criteria
    void viewCustomers(std::vector<Customer*> customers) const; // prints a vector of customers
    std::vector<Account*> searchAccounts(std::string criteria) const; // returns a vector of accounts that match the criteria
    void viewAccounts(std::vector<Account*> accounts) const; // prints a vector of accounts
    void viewCustomerAccounts(Customer* customer) const; // prints the list of accounts of a customer

    // methods for performing transactions between accounts
    void performTransaction(Account* from, Account* to, double amount); // transfers money from one account to another and records a transaction

    // methods for approving or rejecting loan requests
    void approveLoan(Loan* loan); // approves a loan request and records a transaction
    void rejectLoan(Loan* loan); // rejects a loan request

    // methods for getting output from the status of an account, customer or loan
    void getOutput(Account* account) const; // prints the status of an account
    void getOutput(Customer* customer) const; // prints the status of a customer
    void getOutput(Loan* loan) const; // prints the status of a loan

};

#endif
