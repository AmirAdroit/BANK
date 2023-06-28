#include "Transaction.h"

// default constructor
Transaction::Transaction() {
    date = "";
    amount = 0.0;
    description = "";
}

// parameterized constructor
Transaction::Transaction(std::string date, double amount, std::string description) {
    this->date = date;
    this->amount = amount;
    this->description = description;
}

// getter methods
std::string Transaction::getDate() const {
    return date;
}

double Transaction::getAmount() const {
    return amount;
}

std::string Transaction::getDescription() const {
    return description;
}

// setter methods
void Transaction::setDate(std::string date) {
    this->date = date;
}

void Transaction::setAmount(double amount) {
    this->amount = amount;
}

void Transaction::setDescription(std::string description) {
    this->description = description;
}

// display method
void Transaction::display() const {
    std::cout << "Date: " << date << std::endl;
    std::cout << "Amount: $" << amount << std::endl;
    std::cout << "Description: " << description << std::endl;
}