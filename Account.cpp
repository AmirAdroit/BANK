// Account.cpp

#include "Account.h"
#include <iostream>

// constructor
Account::Account(std::string number, double balance) {
  this->number = number;
  this->balance = balance;
}

// destructor
Account::~Account() {
  for (Transaction* transaction : transactions) {
      delete transaction;
  }
}

// getters and setters for number and balance
std::string Account::getNumber() const {
  return number;
}

void Account::setNumber(std::string number) {
  this->number = number;
}

double Account::getBalance() const {
  return balance;
}

void Account::setBalance(double balance) {
  this->balance = balance;
}

// methods for depositing and withdrawing money
void Account::deposit(double amount) {
  // TODO: implement this method
}

void Account::withdraw(double amount) {
  // TODO: implement this method
}

// methods for viewing the transactions of the account
void Account::viewTransactions() const {
  std::cout << "List of transactions of account " << number << ":\n";
  for (Transaction* transaction : transactions) {
      std::cout << transaction->toString() << "\n";
  }
}

// a virtual method for printing the details of the account
std::string Account::toString() const {
  return "Account number: " + number + "\n" +
         "Account balance: " + std::to_string(balance) + "\n";
}
