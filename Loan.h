// Loan.h
#ifndef LOAN_H
#define LOAN_H

#include <string>
#include "Customer.h"
#include "Account.h"
#include "Transaction.h"

class Loan {
private:
    std::string number; // the number of the loan
    Customer* customer; // a pointer to the customer who requested the loan
    Account* account; // a pointer to the account from which the loan will be deducted
    double amount; // the amount of the loan
    double interestRate; // the interest rate of the loan
    int duration; // the duration of the loan in months
    int remainingMonths; // the remaining months to pay off the loan
    bool approved; // a flag to indicate whether the loan is approved or not
    Transaction* transaction; // a pointer to the transaction that records the loan

public:
    // constructor
    Loan(std::string number, Customer* customer, Account* account, double amount, double interestRate, int duration);

    // destructor
    ~Loan();

    // getters and setters for number, customer, account, amount, interestRate, duration, remainingMonths, approved and transaction
    std::string getNumber() const;
    void setNumber(std::string number);
    Customer* getCustomer() const;
    void setCustomer(Customer* customer);
    Account* getAccount() const;
    void setAccount(Account* account);
    double getAmount() const;
    void setAmount(double amount);
    double getInterestRate() const;
    void setInterestRate(double interestRate);
    int getDuration() const;
    void setDuration(int duration);
    int getRemainingMonths() const;
    void setRemainingMonths(int remainingMonths);
    bool isApproved() const;
    void setApproved(bool approved);
    Transaction* getTransaction() const;
    void setTransaction(Transaction* transaction);

    // methods for calculating the monthly installment and the total payment of the loan
    double getMonthlyInstallment() const; // returns the amount of money that should be paid each month
    double getTotalPayment() const; // returns the amount of money that should be paid in total

    // a method for printing the details of the loan
    std::string toString() const; // returns a string representation of the loan

};

#endif