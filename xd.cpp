// This is a C++ code for a bank management system
// It implements the features requested by the user
// It uses classes and inheritance to represent different types of accounts and transactions
// It uses vectors and maps to store and access data
// It uses input and output streams to interact with the user

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <iomanip>
using namespace std;

// A class to represent a person (customer or employee)
class Person {
  protected:
    string name; // the name of the person
    string id; // the id of the person
  public:
    // A constructor that takes the name and id as parameters
    Person(string name, string id) {
      this->name = name;
      this->id = id;
    }

    // A getter method for the name
    string getName() {
      return name;
    }

    // A getter method for the id
    string getId() {
      return id;
    }
};

// A class to represent an account
class Account {
  protected:
    string number; // the account number
    double balance; // the account balance
    double interestRate; // the interest rate of the account
  public:
    // A constructor that takes the number, balance and interest rate as parameters
    Account(string number, double balance, double interestRate) {
      this->number = number;
      this->balance = balance;
      this->interestRate = interestRate;
    }

    // A getter method for the number
    string getNumber() {
      return number;
    }

    // A getter method for the balance
    double getBalance() {
      return balance;
    }

    // A getter method for the interest rate
    double getInterestRate() {
      return interestRate;
    }

    // A setter method for the balance
    void setBalance(double balance) {
      this->balance = balance;
    }

    // A virtual method to calculate the monthly interest of the account
    virtual double calculateInterest() {
      return balance * interestRate / 12;
    }

    // A virtual method to print the account details
    virtual void printDetails() {
      cout << "Account number: " << number << endl;
      cout << "Account balance: $" << fixed << setprecision(2) << balance << endl;
      cout << "Account interest rate: " << fixed << setprecision(2) << interestRate * 100 << "%" << endl;
      cout << "Account monthly interest: $" << fixed << setprecision(2) << calculateInterest() << endl;
    }
};

// A class to represent a current account (derived from Account)
class CurrentAccount : public Account {
  public:
    // A constructor that takes the number and balance as parameters and sets the interest rate to zero
    CurrentAccount(string number, double balance) : Account(number, balance, 0) {}

    // A method to print the account details (overrides the base class method)
    void printDetails() override {
      cout << "Current account details:" << endl;
      Account::printDetails();
      cout << endl;
    }
};

// A class to represent a long-term deposit account (derived from Account)
class LongTermDepositAccount : public Account {
  private:
    int term; // the term of the deposit in months
  public:
    // A constructor that takes the number, balance, interest rate and term as parameters
    LongTermDepositAccount(string number, double balance, double interestRate, int term) : Account(number, balance, interestRate) {
      this->term = term;
    }

    // A getter method for the term
    int getTerm() {
      return term;
    }

     // A method to print the account details (overrides the base class method)
     void printDetails() override {
       cout << "Long-term deposit account details:" << endl;
       Account::printDetails();
       cout << "Account term: " << term << " months" << endl;
       cout << endl;
     }
};

// A class to represent a short-term deposit account (derived from Account)
class ShortTermDepositAccount : public Account {
  private:
     int term; // the term of the deposit in months
  public:
     // A constructor that takes the number, balance, interest rate and term as parameters
     ShortTermDepositAccount(string number, double balance, double interestRate, int term) : Account(number, balance, interestRate) {
       this->term = term;
     }

     // A getter method for the term
     int getTerm() {
       return term;
     }

     // A method to print the account details (overrides the base class method)
     void printDetails() override {
       cout << "Short-term deposit account details:" << endl;
       Account::printDetails();
       cout << "Account term: " << term << " months" << endl;
       cout << endl;
     }
};

// A class to represent a transaction
class Transaction {
  private:
    string id; // the transaction id
    string from; // the account number of the sender
    string to; // the account number of the receiver
    double amount; // the amount of money transferred
  public:
    // A constructor that takes the id, from, to and amount as parameters
    Transaction(string id, string from, string to, double amount) {
      this->id = id;
      this->from = from;
      this->to = to;
      this->amount = amount;
    }

    // A getter method for the id
    string getId() {
      return id;
    }

    // A getter method for the from
    string getFrom() {
      return from;
    }

    // A getter method for the to
    string getTo() {
      return to;
    }

    // A getter method for the amount
    double getAmount() {
      return amount;
    }

    // A method to print the transaction details
    void printDetails() {
      cout << "Transaction id: " << id << endl;
      cout << "Transaction from: " << from << endl;
      cout << "Transaction to: " << to << endl;
      cout << "Transaction amount: $" << fixed << setprecision(2) << amount << endl;
      cout << endl;
    }
};

// A class to represent a loan
class Loan {
  private:
    string id; // the loan id
    string account; // the account number of the borrower
    double amount; // the loan amount
    double interestRate; // the interest rate of the loan
    int period; // the repayment period of the loan in months
  public:
    // A constructor that takes the id, account, amount, interest rate and period as parameters
    Loan(string id, string account, double amount, double interestRate, int period) {
      this->id = id;
      this->account = account;
      this->amount = amount;
      this->interestRate = interestRate;
      this->period = period;
    }

     // A getter method for the id
     string getId() {
       return id;
     }

     // A getter method for the account
     string getAccount() {
       return account;
     }

     // A getter method for the amount
     double getAmount() {
       return amount;
     }

     // A getter method for the interest rate
     double getInterestRate() {
       return interestRate;
     }

     // A getter method for the period
     int getPeriod() {
       return period;
     }

     // A setter method for the amount
     void setAmount(double amount) {
       this->amount = amount;
     }

     // A method to calculate the monthly installment of the loan
     double calculateInstallment() {
       return (amount * interestRate / 12) / (1 - pow(1 + interestRate / 12, -period));
     }

     // A method to print the loan details
     void printDetails() {
       cout << "Loan id: " << id << endl;
       cout << "Loan account: " << account << endl;
       cout << "Loan amount: $" << fixed << setprecision(2) << amount << endl;
       cout << "Loan interest rate: " << fixed << setprecision(2) << interestRate * 100 << "%" << endl;
       cout << "Loan period: " << period << " months" << endl;
       cout << "Loan monthly installment: $" << fixed << setprecision(2) << calculateInstallment() << endl;
       cout << endl;
     }
};

// A class to represent a bank manager (derived from Person)
class BankManager : public Person {
  public:
    // A constructor that takes the name and id as parameters and passes them to the base class constructor
    BankManager(string name, string id) : Person(name, id) {}

    // A method to view all employees in a vector of employees
    void viewEmployees(vector<Employee*> employees) {
      cout << "List of employees:" << endl;
      for (int i = 0; i < employees.size(); i++) {
        cout << i + 1<< ". Name: " << employees[i]->getName() 
             <<" Id: "<< employees[i]->getId()
             <<" Salary: $"<< fixed<< setprecision(2)<< employees[i]->getSalary()<<endl;

      }
      cout<<endl;

