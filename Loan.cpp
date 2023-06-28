// Loan.cpp

#include "Loan.h"
#include <iostream>

// constructor
Loan::Loan(std::string number, Customer* customer, Account* account, double amount, double interestRate, int duration) {
  this->number = number;
  this->customer = customer;
  this->account = account;
  this->amount = amount;
  this->interestRate = interestRate;
  this->duration = duration;
  this->remainingMonths = duration;
  this->approved = false;
  this->transaction = nullptr;
}

// destructor
Loan::~Loan() {
  delete transaction;
}

// getters and setters for number, customer, account, amount, interestRate, duration, remainingMonths, approved and transaction
std::string Loan::getNumber() const {
  return number;
}

void Loan::setNumber(std::string number) {
  this->number = number;
}

Customer* Loan::getCustomer() const {
  return customer;
}

void Loan::setCustomer(Customer* customer) {
  this->customer = customer;
}

Account* Loan::getAccount() const {
  return account;
}

void Loan::setAccount(Account* account) {
  this->account = account;
}

double Loan::getAmount() const {
  return amount;
}

void Loan::setAmount(double amount) {
  this->amount = amount;
}

double Loan::getInterestRate() const {
  return interestRate;
}

void Loan::setInterestRate(double interestRate) {
  this->interestRate = interestRate;
}

int Loan::getDuration() const {
  return duration;
}

void Loan::setDuration(int duration) {
  this->duration = duration;
}

int Loan::getRemainingMonths() const {
  return remainingMonths;
}

void Loan::setRemainingMonths(int remainingMonths) {
  this->remainingMonths = remainingMonths;
}

bool Loan::isApproved() const {
  return approved;
}

void Loan::setApproved(bool approved) {
  this->approved = approved;
}

Transaction* Loan::getTransaction() const {
  return transaction;
}

void Loan::setTransaction(Transaction* transaction) {
  this->transaction = transaction;
}

// methods for calculating the monthly installment and the total payment of the loan
double Loan::getMonthlyInstallment() const {
  // TODO: implement this method
}

double Loan::getTotalPayment() const {
  // TODO: implement this method
}

// a method for printing the details of the loan
std::string Loan::toString() const {
  return "Loan number: " + number + "\n" +
         "Customer id: " + customer->getId() + "\n" +
         "Account number: " + account->getNumber() + "\n" +
         "Loan amount: " + std::to_string(amount) + "\n" +
         "Interest rate: " + std::to_string(interestRate) + "\n" +
         "Duration: " + std::to_string(duration) + "\n" +
         "Remaining months: " + std::to_string(remainingMonths) + "\n" +
         "Approved: " + (approved ? "Yes" : "No") + "\n";
}
