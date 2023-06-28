// Customer.cpp

#include "Customer.h"
#include <iostream>

// constructor
Customer::Customer(std::string id, std::string password, std::string name, std::string address, std::string phone) {
  this->id = id;
  this->password = password;
  this->name = name;
  this->address = address;
  this->phone = phone;
}

// destructor
Customer::~Customer() {
  for (Account* account : accounts) {
      delete account;
  }
  for (Transaction* transaction : transactions) {
      delete transaction;
  }
}

// getters and setters for id, password, name, address and phone
std::string Customer::getId() const {
  return id;
}

void Customer::setId(std::string id) {
  this->id = id;
}

std::string Customer::getPassword() const {
  return password;
}

void Customer::setPassword(std::string password) {
  this->password = password;
}

std::string Customer::getName() const {
  return name;
}

void Customer::setName(std::string name) {
  this->name = name;
}

std::string Customer::getAddress() const {
  return address;
}

void Customer::setAddress(std::string address) {
  this->address = address;
}

std::string Customer::getPhone() const {
  return phone;
}

void Customer::setPhone(std::string phone) {
  this->phone = phone;
}

// methods for viewing the list of accounts
void Customer::viewAccounts() const {
  std::cout << "List of accounts:\n";
  for (Account* account : accounts) {
      std::cout << account->toString() << "\n";
  }
}

// methods for performing transactions and transferring money between accounts
void Customer::performTransaction(Account* from, Account* to, double amount) {
  // TODO: implement this method
}

// methods for requesting to delete an existing account or create a new account
void Customer::requestDeleteAccount(Account* account) {
  // TODO: implement this method
}

void Customer::requestCreateAccount(Account* account) {
  // TODO: implement this method
}

// methods for viewing the transactions of an account
void Customer::viewTransactions(Account* account) const {
  std::cout << "List of transactions of account " << account->getNumber() << ":\n";
  for (Transaction* transaction : account->getTransactions()) {
      std::cout << transaction->toString() << "\n";
  }
}
