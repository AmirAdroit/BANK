#include <iostream>
#include <iomanip>
#include "BankManager.h"
#include "Employee.h"
#include "Customer.h"
#include "Account.h"
#include "Loan.h"
#include "Transaction.h"
using namespace std;
// a function to load data from files
void loadData(vector<BankManager*>& managers, vector<Employee*>& employees, vector<Customer*>& customers, vector<Account*>& accounts, vector<Loan*>& loans, vector<Transaction*>& transactions) {
  // TODO: implement this function
}

// a function to save data to files
void saveData(vector<BankManager*>& managers, vector<Employee*>& employees, vector<Customer*>& customers, vector<Account*>& accounts, vector<Loan*>& loans, vector<Transaction*>& transactions) {
  // TODO: implement this function
}

// a function to display the main menu
void displayMainMenu() {
  cout<<"---------------------------------------------------\n";
  cout<<"           Welcome To The Farabi Bank            \n";
  cout<<"---------------------------------------------------\n\n";
  cout << " 1: Manager \n\n";
  cout << " 2: Employee\n\n";
  cout << " 3: Costumer\n\n";
  cout << " 4: Exit\n\n";
  cout<<"---------------------------------------------------\n\n";
  cout<<" Select your choice : ";
}
// a function to display the bank manager menu
void displayBankManagerMenu() {
  system("cls");
  cout<<"---------------------------------------------------\n";
  cout<<"                 Manager Panel                           \n";
  cout<<"---------------------------------------------------\n\n";
  cout << "1: View employees\n";
  cout << "2: Add employee\n";
  cout << "3: Modify employee\n";
  cout << "4: Delete employee\n";
  cout << "5: View customers\n";
  cout << "6: Add customer\n";
  cout << "7: Modify customer\n";
  cout << "8: Delete customer\n";
  cout << "9: View accounts\n";
  cout << "10: Add account\n";
  cout << "11: Modify account\n";
  cout << "12: Delete account\n";
  cout << "13: View loans\n";
  cout << "14: Modify loan\n";
  cout << "15: View transactions\n";
  cout << "16: Modify transaction\n";
  cout << "17: Search employees\n";
  cout << "18: Search customers\n";
  cout << "19: Search loans\n";
  cout << "20: Search transactions\n";
  cout << "21: Logout\n\n";
  cout<<"---------------------------------------------------\n\n";
  cout<<" Select your choice : ";
}

// a function to display the employee menu
void displayEmployeeMenu() {
  // TODO: implement this function
}

// a function to display the customer menu
void displayCustomerMenu() {
  // TODO: implement this function
}

// a function to handle the login process
bool login(string role, const vector<BankManager*>& managers, const vector<Employee*>& employees, const vector<Customer*>& customers, BankManager*& currentManager, Employee*& currentEmployee, Customer*& currentCustomer) {
  // TODO: implement this function
}

// a function to handle the bank manager actions
void handleBankManagerAction(int choice, const vector<BankManager*>& managers, const vector<Employee*>& employees, const vector<Customer*>& customers, const vector<Account*>& accounts, const vector<Loan*>& loans, const vector<Transaction*>& transactions, BankManager* currentManager) {
  // TODO: implement this function
}

// a function to handle the employee actions
void handleEmployeeAction(int choice, const vector<BankManager*>& managers, const vector<Employee*>& employees, const vector<Customer*>& customers, const vector<Account*>& accounts, const vector<Loan*>& loans, const vector<Transaction*>& transactions, Employee* currentEmployee) {
  // TODO: implement this function
}

// a function to handle the customer actions
void handleCustomerAction(int choice, const vector<BankManager*>& managers, const vector<Employee*>& employees, const vector<Customer*>& customers, const vector<Account*>& accounts, const vector<Loan*>& loans, const vector<Transaction*>& transactions, Customer* currentCustomer) {
  // TODO: implement this function
}

// the main function
int main() {
  // declare the vectors to store the data
  vector<BankManager*> managers;
  vector<Employee*> employees;
  vector<Customer*> customers;
  vector<Account*> accounts;
  vector<Loan*> loans;
  vector<Transaction*> transactions;

  // load the data from files
  loadData(managers, employees, customers, accounts, loans, transactions);

  // declare the variables to store the current user
  BankManager* currentManager = nullptr;
  Employee* currentEmployee = nullptr;
  Customer* currentCustomer = nullptr;

  // declare the variable to store the user choice
  int choice = 0;

  // display the main menu and get the user choice
  displayMainMenu();
  cin >> choice;

  // loop until the user chooses to exit
  while (choice != 4) {
    // check the user choice
    switch (choice) {
      case 1: // login as a bank manager
        if (login("bank manager", managers, employees, customers, currentManager, currentEmployee, currentCustomer)) {
          // display the bank manager menu and get the user choice
          displayBankManagerMenu();
          cin >> choice;

          // loop until the user chooses to logout
          while (choice != 21) {
            // handle the bank manager action
            handleBankManagerAction(choice, managers, employees, customers, accounts, loans, transactions, currentManager);

            // display the bank manager menu and get the user choice
            displayBankManagerMenu();
            cin >> choice;
          }

          // set the current user to null
          currentManager = nullptr;
        }
        break;
      case 2: // login as an employee
        if (login("employee", managers, employees, customers, currentManager, currentEmployee, currentCustomer)) {
          // display the employee menu and get the user choice
          displayEmployeeMenu();
          cin >> choice;

          // loop until the user chooses to logout
          while (choice != -1) { // TODO: change -1 to the correct value
            // handle the employee action
            handleEmployeeAction(choice, managers, employees, customers, accounts, loans, transactions, currentEmployee);

            // display the employee menu and get the user choice
            displayEmployeeMenu();
            cin >> choice;
          }

          // set the current user to null
          currentEmployee = nullptr;
        }
        break;
      case 3: // login as a customer
        if (login("customer", managers, employees, customers, currentManager, currentEmployee, currentCustomer)) {
          // display the customer menu and get the user choice
          displayCustomerMenu();
          cin >> choice;

          // loop until the user chooses to logout
          while (choice != -1) { // TODO: change -1 to the correct value
            // handle the customer action
            handleCustomerAction(choice, managers, employees, customers, accounts, loans, transactions, currentCustomer);

            // display the customer menu and get the user choice
            displayCustomerMenu();
            cin >> choice;
          }

          // set the current user to null
          currentCustomer = nullptr;
        }
        break;
      default: // invalid choice
        cout << "Invalid choice. Please try again.\n";
    }

    // display the main menu and get the user choice
    displayMainMenu();
    cin >> choice;
  }

  // save the data to files
  saveData(managers, employees, customers, accounts, loans, transactions);

  return 0;
}

