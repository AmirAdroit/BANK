// Employee.cpp

#include "Employee.h"
#include <iostream>

// constructor
Employee::Employee(std::string id, std::string password, std::string name, double salary) {
  this->id = id;
  this->password = password;
  this->name = name;
  this->salary = salary;
}

// destructor
Employee::~Employee() {
  // nothing to do here
}

// getters and setters for id, password, name and salary
std::string Employee::getId() const {
  return id;
}

void Employee::setId(std::string id) {
  this->id = id;
}

std::string Employee::getPassword() const {
  return password;
}

void Employee::setPassword(std::string password) {
  this->password = password;
}

std::string Employee::getName() const {
  return name;
}

void Employee::setName(std::string name) {
  this->name = name;
}

double Employee::getSalary() const {
  return salary;
}

void Employee::setSalary(double salary) {
  this->salary = salary;
}

// methods for searching and viewing customers and accounts
std::vector<Customer*> Employee::searchCustomers(std::string criteria) const {
  // TODO: implement this method
}

void Employee::viewCustomers(std::vector<Customer*> customers) const {
  std::cout << "List of customers:\n";
  for (Customer* customer : customers) {
      std::cout << customer->toString() << "\n";
  }
}

std::vector<Account*> Employee::searchAccounts(std::string criteria) const {
  // TODO: implement this method
}

void Employee::viewAccounts(std::vector<Account*> accounts) const {
  std::cout << "List of accounts:\n";
  for (Account* account : accounts) {
      std::cout << account->toString() << "\n";
  }
}

void Employee::viewCustomerAccounts(Customer* customer) const {
  std::cout << "List of accounts of " << customer->getName() << ":\n";
  for (Account* account : customer->getAccounts()) {
      std::cout << account->toString() << "\n";
  }
}

// methods for performing transactions between accounts
void Employee::performTransaction(Account* from, Account* to, double amount) {
  // TODO: implement this method
}

// methods for approving or rejecting loan requests
void Employee::approveLoan(Loan* loan) {
  // TODO: implement this method
}

void Employee::rejectLoan(Loan* loan) {
  // TODO: implement this method
}

// methods for getting output from the status of an account, customer or loan
void Employee::getOutput(Account* account) const {
  std::cout << "Status of account " << account->getNumber() << ":\n";
  std::cout << account->toString() << "\n";
}

void Employee::getOutput(Customer* customer) const {
  std::cout << "Status of customer " << customer->getId() << ":\n";
  std::cout << customer->toString() << "\n";
}

void Employee::getOutput(Loan* loan) const {
  std::cout << "Status of loan " << loan->getNumber() << ":\n";
  std::cout << loan->toString() << "\n";
}
