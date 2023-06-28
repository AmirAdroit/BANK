#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
#include <iostream>

class Transaction {
    private:
        std::string date; // the date of the transaction in YYYY-MM-DD format
        double amount; // the amount of the transaction in dollars
        std::string description; // a brief description of the transaction
    public:
        // default constructor
        Transaction();

        // parameterized constructor
        Transaction(std::string date, double amount, std::string description);

        // getter methods
        std::string getDate() const;
        double getAmount() const;
        std::string getDescription() const;

        // setter methods
        void setDate(std::string date);
        void setAmount(double amount);
        void setDescription(std::string description);

        // display method
        void display() const;
};

#endif