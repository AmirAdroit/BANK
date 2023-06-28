// BankManager.h
#ifndef BANKMANAGER_H
#define BANKMANAGER_H

#include <string>
#include <vector>
#include "Employee.h"
#include "Customer.h"
#include "Account.h"
#include "Loan.h"
#include "Transaction.h"

class BankManager {
private:
    std::string id; // the id of the bank manager
    std::string password; // the password of the bank manager
    std::vector<Employee*> employees; // a vector of pointers to employees
    std::vector<Customer*> customers; // a vector of pointers to customers
    std::vector<Account*> accounts; // a vector of pointers to accounts
    std::vector<Loan*> loans; // a vector of pointers to loans
    std::vector<Transaction*> transactions; // a vector of pointers to transactions

public:
    // constructor
    BankManager(std::string id, std::string password);

    // destructor
    ~BankManager();

    // getters and setters for id and password
    std::string getId() const;
    void setId(std::string id);
    std::string getPassword() const;
    void setPassword(std::string password);

    // methods for viewing, adding, modifying and deleting employees
    void viewEmployees() const; // prints the list of employees
    void addEmployee(Employee* employee); // adds an employee to the vector
    void modifyEmployee(std::string id); // modifies an employee by id
    void deleteEmployee(std::string id); // deletes an employee by id

    // methods for viewing, adding, modifying and deleting customers
    void viewCustomers() const; // prints the list of customers
    void addCustomer(Customer* customer); // adds a customer to the vector
    void modifyCustomer(std::string id); // modifies a customer by id
    void deleteCustomer(std::string id); // deletes a customer by id

    // methods for viewing, adding, modifying and deleting accounts
    void viewAccounts() const; // prints the list of accounts
    void addAccount(Account* account); // adds an account to the vector
    void modifyAccount(std::string number); // modifies an account by number
    void deleteAccount(std::string number); // deletes an account by number

    // methods for viewing and modifying loans and transactions
    void viewLoans() const; // prints the list of loans
    void modifyLoan(std::string number); // modifies a loan by number
    void viewTransactions() const; // prints the list of transactions
    void modifyTransaction(std::string number); // modifies a transaction by number

    // methods for searching and displaying lists of employees, customers, loans and transactions
    std::vector<Employee*> searchEmployees(std::string criteria) const; // returns a vector of employees that match the criteria
    void displayEmployees(std::vector<Employee*> employees) const; // prints a vector of employees
    std::vector<Customer*> searchCustomers(std::string criteria) const; // returns a vector of customers that match the criteria
    void displayCustomers(std::vector<Customer*> customers) const; // prints a vector of customers
    std::vector<Loan*> searchLoans(std::string criteria) const; // returns a vector of loans that match the criteria
    void displayLoans(std::vector<Loan*> loans) const; // prints a vector of loans
    std::vector<Transaction*> searchTransactions(std::string criteria) const; // returns a vector of transactions that match the criteria
    void displayTransactions(std::vector<Transaction*> transactions) const; // prints a vector of transactions

};

#endif