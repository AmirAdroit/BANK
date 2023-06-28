// BankManager.cpp

#include "BankManager.h"
#include <iostream>

// constructor
BankManager::BankManager(std::string id, std::string password) {
  this->id = id;
  this->password = password;
}

// destructor
BankManager::~BankManager() {
  for (Employee* employee : employees) {
      delete employee;
  }
  for (Customer* customer : customers) {
      delete customer;
  }
  for (Account* account : accounts) {
      delete account;
  }
  for (Loan* loan : loans) {
      delete loan;
  }
  for (Transaction* transaction : transactions) {
      delete transaction;
  }
}

// getters and setters for id and password
std::string BankManager::getId() const {
  return id;
}

void BankManager::setId(std::string id) {
  this->id = id;
}

std::string BankManager::getPassword() const {
  return password;
}

void BankManager::setPassword(std::string password) {
  this->password = password;
}

// methods for viewing, adding, modifying and deleting employees
void BankManager::viewEmployees() const {
  displayEmployees(employees);
}

void BankManager::addEmployee(Employee* employee) {
  employees.push_back(employee);
}

void BankManager::modifyEmployee(std::string id) {
  // TODO: implement this method
}

void BankManager::deleteEmployee(std::string id) {
  // TODO: implement this method
}

// methods for viewing, adding, modifying and deleting customers
void BankManager::viewCustomers() const {
  displayCustomers(customers);
}

void BankManager::addCustomer(Customer* customer) {
  customers.push_back(customer);
}

void BankManager::modifyCustomer(std::string id) {
  // TODO: implement this method
}

void BankManager::deleteCustomer(std::string id) {
  // TODO: implement this method
}

// methods for viewing, adding, modifying and deleting accounts
void BankManager::viewAccounts() const {
  displayAccounts(accounts);
}

void BankManager::addAccount(Account* account) {
  accounts.push_back(account);
}

void BankManager::modifyAccount(std::string number) {
  // TODO: implement this method
}

void BankManager::deleteAccount(std::string number) {
  // TODO: implement this method
}

// methods for viewing and modifying loans and transactions
void BankManager::viewLoans() const {
  displayLoans(loans);
}

void BankManager::modifyLoan(std::string number) {
  // TODO: implement this method
}

void BankManager::viewTransactions() const {
  displayTransactions(transactions);
}

void BankManager::modifyTransaction(std::string number) {
  // TODO: implement this method
}

// methods for searching and displaying lists of employees, customers, loans and transactions
std::vector<Employee*> BankManager::searchEmployees(std::string criteria) const {
  // TODO: implement this method
}

void BankManager::displayEmployees(std::vector<Employee*> employees) const {
  std::cout << "List of employees:\n";
  for (Employee* employee : employees) {
      std::cout << employee->toString() << "\n";
  }
}

std::vector<Customer*> BankManager::searchCustomers(std::string criteria) const {
  // TODO: implement this method
}

void BankManager::displayCustomers(std::vector<Customer*> customers) const {
  std::cout << "List of customers:\n";
  for (Customer* customer : customers) {
      std::cout << customer->toString() << "\n";
  }
}

std::vector<Loan*> BankManager::searchLoans(std::string criteria) const {
  // TODO: implement this method
}

void BankManager::displayLoans(std::vector<Loan*> loans) const {
  std::cout << "List of loans:\n";
  for (Loan* loan : loans) {
      std::cout << loan->toString() << "\n";
  }
}

std::vector<Transaction*> BankManager::searchTransactions(std::string criteria) const {
  // TODO: implement this method
}

void BankManager::displayTransactions(std::vector<Transaction*> transactions) const {
  std::cout << "List of transactions:\n";
  for (Transaction* transaction : transactions) {
      std::cout << transaction->toString() << "\n";
  }
}
