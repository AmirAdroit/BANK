#include <iostream>
#include <string> 
#include <fstream>
#include <ctime>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;



// define the class BankManager
class BankManager
{
    private:
        string name;
        long int national_id;
        string password;
        vector<Employee> employees; // dynamic arrays
        vector<Customer> customers;
        vector<Account> accounts;
        vector<Loan> loans;
        vector<Transaction> transactions;


    protected:
    // a function to load the employees data from a file into the vector
        void loadEmployees() {
            ifstream fin("employees.txt");
            if (fin.is_open()) { // check if the file is opened successfully
                Employee e;
                while (fin >> e) { // reading employee objects from the file
                    employees.push_back(e); // adding them to the vector till they are all added
                }
                fin.close();
            }
            else {
                cout << "Error: could not open employees.txt" << endl; //exception handeling
            }
        }

        // a function to save the employees data from the vector into a file
        void saveEmployees() {
            ofstream fout("employees.txt");
            if (fout.is_open()) { // check if the file is opened successfully
                for (Employee e : employees) { // loop for checking the employees
                    fout << e << endl; // writing and employee in the file
                }
                fout.close();
            }
            else {
                cout << "Error: could not open employees.txt" << endl; //exeption handling
            }
        }

        // a function to add an employee object to the vector and save it to the file
        void addEmployee(Employee e) {
            employees.push_back(e); // add it to the vector of employees
            saveEmployees(); // save it to the file of employees
        }

        // a function to remove an employee object from the vector and save it to the file, given its national id as input 
        void removeEmployee(long int id) {
            int index = -1; // a variable to store the index of the employee to be removed
            for (int i = 0; i < employees.size(); i++) { // loop through the vector of employees
                if (employees[i].getNationalId() == id) { // check if the national id matches
                    index = i; // store the index
                    break; // exit the loop
                }
            }
            if (index != -1) { // check if the employee is found
                employees.erase(employees.begin() + index); // erase the employee from the vector
                saveEmployees(); // save the changes to the file
            }
            else {
                cout << "Employee not found." << endl; // display an error message
            }
        }

        // a function to update an employee object in the vector and save it to the file, given its national id and a new employee object as input 
        void updateEmployee(long int id, Employee e) {
            int index = -1; // a variable to store the index of the employee to be updated
            for (int i = 0; i < employees.size(); i++) { // loop through the vector of employees
                if (employees[i].getNationalId() == id) { // check if the national id matches
                    index = i; // store the index
                    break; // exit the loop
                }
            }
            if (index != -1) { // check if the employee is found
                employees[index] = e; // update the employee in the vector
                saveEmployees(); // save the changes to the file
            }
            else {
                cout << "Employee not found." << endl; // display an error message
            }
        }

        // a function to search for an employee object in the vector and display its details, given one of these criteria as input: name, national id, salary range or position 
        void searchEmployee(string criteria) {
            bool found = false; // a flag to indicate if any employee is found or not
            cout << "Enter " << criteria << ": "; 
            if (criteria == "name") { // search by name
                string name; 
                cin >> name; 
                for (Employee e : employees) { // loop through the vector of employees
                    if (e.getName() == name) { // check if the name matches
                        e.displayDetails(); // display the employee details
                        found = true; 
                    }
                }
            }
            else if (criteria == "national id") { // search by national id
                long int id; 
                cin >> id; 
                for (Employee e : employees) { // loop through the vector of employees
                    if (e.getNationalId() == id) { // check if the national id matches
                        e.displayDetails(); // display the employee details
                        found = true; 
                    }
                }
            }
            else if (criteria == "salary range") { // search by salary range
                double min, max; 
                cin >> min >> max; 
                for (Employee e : employees) { // loop through the vector of employees
                    if (e.getSalary() >= min && e.getSalary() <= max) { // check if the salary is within the range
                        e.displayDetails(); // display the employee details
                        found = true; 
                    }
                }
            }
            else if (criteria == "position") { // search by position
                string position; 
                cin >> position; 
                for (Employee e : employees) { // loop through the vector of employees
                    if (e.getPosition() == position) { // check if the position matches
                        e.displayDetails(); // display the employee details
                        found = true; 
                    }
                }
            }
            else {
                cout << "Invalid criteria." << endl; // display an error message
            }

            if (!found) {
                cout << "No employee found." << endl; // display a message if no employee is found
            }
        }

        // a function to display all the employees in the vector in a tabular format
        void displayAllEmployees() {
            cout << left << setw(20) << "Name" << setw(15) << "National ID" << setw(15) << "Salary" << setw(15) << "Position" << endl;
            cout << "-----------------------------------------------------------------" << endl;
            for (Employee e : employees) {
                cout << left << setw(20) << e.getName() << setw(15) << e.getNationalId() << setw(15) << e.getSalary() << setw(15) << e.getPosition() << endl;
            }
        }


    public:
        // a parameterized constructor that takes the name, national id and password of the manager as input
        BankManager(string n, long int id, string p ) {
            name = n;
            national_id = id;
            password = pass;
            // load the data from the files into the vectors
            loadEmployees();
            loadCustomers();
            loadAccounts();
            loadLoans();
            loadTransactions();
        }
        // a function to load the customers data from a file into the vector
        void loadCustomers() {
            ifstream fin("customers.txt"); // open the file for reading
            if (fin.is_open()) { // check if the file is opened successfully
                Customer c; // create an empty customer object
                while (fin >> c) { // read a customer object from the file
                    customers.push_back(c); // add it to the vector
                }
                fin.close(); // close the file
            }
            else {
                cout << "Error: could not open customers.txt" << endl;
            }
        }

        // a function to save the customers data from the vector into a file
        void saveCustomers() {
            ofstream fout("customers.txt"); // open the file for writing
            if (fout.is_open()) { // check if the file is opened successfully
                for (Customer c : customers) { // loop through the vector of customers
                    fout << c << endl; // write a customer object to the file
                }
                fout.close(); // close the file
            }
            else {
                cout << "Error: could not open customers.txt" << endl;
            }
        }

        // a function to load the accounts data from a file into the vector
        void loadAccounts() {
            ifstream fin("accounts.txt"); // open the file for reading
            if (fin.is_open()) { // check if the file is opened successfully
                Account a; // create an empty account object
                while (fin >> a) { // read an account object from the file
                    accounts.push_back(a); // add it to the vector
                }
                fin.close(); // close the file
            }
            else {
                cout << "Error: could not open accounts.txt" << endl;
            }
        }

        // a function to save the accounts data from the vector into a file
        void saveAccounts() {
            ofstream fout("accounts.txt"); // open the file for writing
            if (fout.is_open()) { // check if the file is opened successfully
                for (Account a : accounts) { // loop through the vector of accounts
                    fout << a << endl; // write an account object to the file
                }
                fout.close(); // close the file
            }
            else {
                cout << "Error: could not open accounts.txt" << endl;
            }
        }

        // a function to load the loans data from a file into the vector
        void loadLoans() {
            ifstream fin("loans.txt"); // open the file for reading
            if (fin.is_open()) { // check if the file is opened successfully
                Loan l; // create an empty loan object
                while (fin >> l) { // read a loan object from the file
                    loans.push_back(l); // add it to the vector
                }
                fin.close(); // close the file
            }
            else {
                cout << "Error: could not open loans.txt" << endl;
            }
        }

        // a function to save the loans data from the vector into a file
        void saveLoans() {
            ofstream fout("loans.txt"); // open the file for writing
            if (fout.is_open()) { // check if the file is opened successfully
                for (Loan l : loans) { // loop through the vector of loans
                    fout << l << endl; // write a loan object to the file
                }
                fout.close(); // close the file
            }
            else {
                cout << "Error: could not open loans.txt" << endl;
            }
        }

        // a function to load the transactions data from a file into the vector
        void loadTransactions() {
            ifstream fin("transactions.txt"); // open the file for reading
            if (fin.is_open()) { // check if the file is opened successfully
                Transaction t; // create an empty transaction object
                while (fin >> t) { // read a transaction object from the file
                    transactions.push_back(t); // add it to the vector
                }
                fin.close(); // close the file
            }
            else {
                cout << "Error: could not open transactions.txt" << endl;
            }
        }

        // a function to save the transactions data from the vector into a file
        void saveTransactions() {
            ofstream fout("transactions.txt"); // open the file for writing
            if (fout.is_open()) { // check if the file is opened successfully
                for (Transaction t : transactions) { // loop through the vector of transactions
                    fout << t << endl; // write a transaction object to the file
                }
                fout.close(); // close the file
            }
            else {
                cout << "Error: could not open transactions.txt" << endl;
            }
        }

        
        // a function to add a customer object to the vector and save it to the file
        void addCustomer(Customer c) {
            customers.push_back(c); // add it to the vector of customers
            saveCustomers(); // save it to the file of customers
        }

        // a function to remove a customer object from the vector and save it to the file, given its national id as input 
        void removeCustomer(long int id) {
            int index = -1; // a variable to store the index of the customer to be removed
            for (int i = 0; i < customers.size(); i++) { // loop through the vector of customers
                if (customers[i].getNationalId() == id) { // check if the national id matches
                    index = i; // store the index
                    break; // exit the loop
                }
            }
            if (index != -1) { // checks if the customer is found
                customers.erase(customers.begin() + index); // erase the customer from the vector
                saveCustomers(); // save the changes to the file
            }
            else {
                cout << "Customer not found." << endl; // display an error message
            }
        }

        // a function to update a customer object in the vector and save it to the file, given its national id and a new customer object as input 
        void updateCustomer(long int id, Customer c) {
            int index = -1; // a variable to store the index of the customer to be updated
            for (int i = 0; i < customers.size(); i++) { // loop through the vector of customers
                if (customers[i].getNationalId() == id) { // check if the national id matches
                    index = i; // store the index
                    break; // exit the loop
                }
            }
            if (index != -1) { // check if the customer is found
                customers[index] = c; // update the customer in the vector
                saveCustomers(); // save the changes to the file
            }
            else {
                cout << "Customer not found." << endl; // display an error message
            }
        }

        // a function to add an account object to the vector and save it to the file
        void addAccount(Account a) {
            accounts.push_back(a); // add it to the vector of accounts
            saveAccounts(); // save it to the file of accounts
        }

        // a function to remove an account object from the vector and save it to the file, given its account number as input 
        void removeAccount(long int num) {
            int index = -1; // a variable to store the index of the account to be removed
            for (int i = 0; i < accounts.size(); i++) { // loop through the vector of accounts
                if (accounts[i].getAccountNumber() == num) { // check if the account number matches
                    index = i; // store the index
                    break; // exit the loop
                }
            }
            if (index != -1) { // check if the account is found
                accounts.erase(accounts.begin() + index); // erase the account from the vector
                saveAccounts(); // save the changes to the file
            }
            else {
                cout << "Account not found." << endl; // display an error message
            }
        }

        // a function to update an account object in the vector and save it to the file, given its account number and a new account object as input 
        void updateAccount(long int num, Account a) {
            int index = -1; // a variable to store the index of the account to be updated
            for (int i = 0; i < accounts.size(); i++) { // loop through the vector of accounts
                if (accounts[i].getAccountNumber() == num) { // check if the account number matches
                    index = i; // store the index
                    break; // exit the loop
                }
            }
            if (index != -1) { // check if the account is found
                accounts[index] = a; // update the account in the vector
                saveAccounts(); // save the changes to the file
            }
            else {
                cout << "Account not found." << endl; // display an error message
            }
        }

        // a function to add a loan object to the vector and save it to the file
        void addLoan(Loan l) {
            loans.push_back(l); // add it to the vector of loans
            saveLoans(); // save it to the file of loans
        }

        // a function to remove a loan object from the vector and save it to the file, given its loan number as input 
        void removeLoan(long int num) {
            int index = -1; // a variable to store the index of the loan to be removed
            for (int i = 0; i < loans.size(); i++) { // loop through the vector of loans
                if (loans[i].getLoanNumber() == num) { // check if the loan number matches
                    index = i; // store the index
                    break; // exit the loop
                }
            }
            if (index != -1) { // check if the loan is found
                loans.erase(loans.begin() + index); // erase the loan from the vector
                saveLoans(); // save the changes to the file
            }
            else {
                cout << "Loan not found." << endl; // display an error message
            }
        }


        // a function to update a loan object in the vector and save it to the file, given its loan number and a new loan object as input 
        void updateLoan(long int num, Loan l) {
            int index = -1; // a variable to store the index of the loan to be updated
            for (int i = 0; i < loans.size(); i++) { // loop through the vector of loans
                if (loans[i].getLoanNumber() == num) { // check if the loan number matches
                    index = i; // store the index
                    break; // exit the loop
                }
            }
            if (index != -1) { // check if the loan is found
                loans[index] = l; // update the loan in the vector
                saveLoans(); // save the changes to the file
            }
            else {
                cout << "Loan not found." << endl; // display an error message
            }
        }

        // a function to add a transaction object to the vector and save it to the file
        void addTransaction(Transaction t) {
            transactions.push_back(t); // add it to the vector of transactions
            saveTransactions(); // save it to the file of transactions
        }

        // a function to remove a transaction object from the vector and save it to the file, given its transaction number as input 
        void removeTransaction(long int num) {
            int index = -1; // a variable to store the index of the transaction to be removed
            for (int i = 0; i < transactions.size(); i++) { // loop through the vector of transactions
                if (transactions[i].getTransactionNumber() == num) { // check if the transaction number matches
                    index = i; // store the index
                    break; // exit the loop
                }
            }
            if (index != -1) { // check if the transaction is found
                transactions.erase(transactions.begin() + index); // erase the transaction from the vector
                saveTransactions(); // save the changes to the file
            }
            else {
                cout << "Transaction not found." << endl; // display an error message
            }
        }

        // a function to update a transaction object in the vector and save it to the file, given its transaction number and a new transaction object as input 
        void updateTransaction(long int num, Transaction t) {
            int index = -1; // a variable to store the index of the transaction to be updated
            for (int i = 0; i < transactions.size(); i++) { // loop through the vector of transactions
                if (transactions[i].getTransactionNumber() == num) { // check if the transaction number matches
                    index = i; // store the index
                    break; // exit the loop
                }
            }
            if (index != -1) { // check if the transaction is found
                transactions[index] = t; // update the transaction in the vector
                saveTransactions(); // save the changes to the file
            }
            else {
                cout << "Transaction not found." << endl; // display an error message
            }
        }

    
        // a function to search for a customer object in the vector and display its details, given one of these criteria as input: name, national id, account number or balance range 
        void searchCustomer(string criteria) {
            bool found = false; // a flag to indicate if any customer is found or not
            cout << "Enter " << criteria << ": "; 
            if (criteria == "name") { // search by name
                string name; 
                cin >> name; 
                for (Customer c : customers) { // loop through the vector of customers
                    if (c.getName() == name) { // check if the name matches
                        c.displayDetails(); // display the customer details
                        found = true; 
                    }
                }
            }
            else if (criteria == "national id") { // search by national id
                long int id; 
                cin >> id; 
                for (Customer c : customers) { // loop through the vector of customers
                    if (c.getNationalId() == id) { // check if the national id matches
                        c.displayDetails(); // display the customer details
                        found = true; 
                    }
                }
            }
            else if (criteria == "account number") { // search by account number
                long int num; 
                cin >> num; 
                for (Customer c : customers) { // loop through the vector of customers
                    if (c.getAccountNumber() == num) { // check if the account number matches
                        c.displayDetails(); // display the customer details
                        found = true; 
                    }
                }
            }
            else if (criteria == "balance range") { // search by balance range
                double min, max; 
                cin >> min >> max; 
                for (Customer c : customers) { // loop through the vector of customers
                    if (c.getBalance() >= min && c.getBalance() <= max) { // check if the balance is within the range
                        c.displayDetails(); // display the customer details
                        found = true; 
                    }
                }
            }
            else {
                cout << "Invalid criteria." << endl; // display an error message
            }

            if (!found) {
                cout << "No customer found." << endl; // display a message if no customer is found
            }
        }

               // a function to search for an account object in the vector and display its details, given one of these criteria as input: account number, account type, balance range or interest rate range 
        void searchAccount(string criteria) {
            bool found = false; // a flag to indicate if any account is found or not
            cout << "Enter " << criteria << ": "; 
            if (criteria == "account number") { // search by account number
                long int num; 
                cin >> num; 
                for (Account a : accounts) { // loop through the vector of accounts
                    if (a.getAccountNumber() == num) { // check if the account number matches
                        a.displayDetails(); // display the account details
                        found = true; 
                    }
                }
            }
            else if (criteria == "account type") { // search by account type
                char type; 
                cin >> type; 
                for (Account a : accounts) { // loop through the vector of accounts
                    if (a.getAccountType() == type) { // check if the account type matches
                        a.displayDetails(); // display the account details
                        found = true; 
                    }
                }
            }
            else if (criteria == "balance range") { // search by balance range
                double min, max; 
                cin >> min >> max; 
                for (Account a : accounts) { // loop through the vector of accounts
                    if (a.getBalance() >= min && a.getBalance() <= max) { // check if the balance is within the range
                        a.displayDetails(); // display the account details
                        found = true; 
                    }
                }
            }
            else if (criteria == "interest rate range") { // search by interest rate range
                double min, max; 
                cin >> min >> max; 
                for (Account a : accounts) { // loop through the vector of accounts
                    if (a.getInterestRate() >= min && a.getInterestRate() <= max) { // check if the interest rate is within the range
                        a.displayDetails(); // display the account details
                        found = true; 
                    }
                }
            }
            else {
                cout << "Invalid criteria." << endl; // display an error message
            }

            if (!found) {
                cout << "No account found." << endl; // display a message if no account is found
            }
        }

        // a function to search for a loan object in the vector and display its details, given one of these criteria as input: loan number, loan type, loan amount range or interest rate range 
        void searchLoan(string criteria) {
            bool found = false; // a flag to indicate if any loan is found or not
            cout << "Enter " << criteria << ": "; 
            if (criteria == "loan number") { // search by loan number
                long int num; 
                cin >> num; 
                for (Loan l : loans) { // loop through the vector of loans
                    if (l.getLoanNumber() == num) { // check if the loan number matches
                        l.displayDetails(); // display the loan details
                        found = true; 
                    }
                }
            }
            else if (criteria == "loan type") { // search by loan type
                char type; 
                cin >> type; 
                for (Loan l : loans) { // loop through the vector of loans
                    if (l.getLoanType() == type) { // check if the loan type matches
                        l.displayDetails(); // display the loan details
                        found = true; 
                    }
                }
            }
            else if (criteria == "loan amount range") { // search by loan amount range
                double min, max; 
                cin >> min >> max; 
                for (Loan l : loans) { // loop through the vector of loans
                    if (l.getLoanAmount() >= min && l.getLoanAmount() <= max) { // check if the loan amount is within the range
                        l.displayDetails(); // display the loan details
                        found = true; 
                    }
                }
            }
            else if (criteria == "interest rate range") { // search by interest rate range
                double min, max; 
                cin >> min >> max; 
                for (Loan l : loans) { // loop through the vector of loans
                    if (l.getInterestRate() >= min && l.getInterestRate() <= max) { // check if the interest rate is within the range
                        l.displayDetails(); // display the loan details
                        found = true; 
                    }
                }
            }
            else {
                cout << "Invalid criteria." << endl; // display an error message
            }

            if (!found) {
                cout << "No loan found." << endl; // display a message if no loan is found
            }
        }

        // a function to search for a transaction object in the vector and display its details, given one of these criteria as input: transaction number, transaction type, transaction amount range or transaction date range 
        void searchTransaction(string criteria) {
            bool found = false; // a flag to indicate if any transaction is found or not
            cout << "Enter " << criteria << ": "; 
            if (criteria == "transaction number") { // search by transaction number
                long int num; 
                cin >> num; 
                for (Transaction t : transactions) { // loop through the vector of transactions
                    if (t.getTransactionNumber() == num) { // check if the transaction number matches
                        t.displayDetails(); // display the transaction details
                        found = true; 
                    }
                }
            }
            else if (criteria == "transaction type") { // search by transaction type
                char type; 
                cin >> type; 
                for (Transaction t : transactions) { // loop through the vector of transactions
                    if (t.getTransactionType() == type) { // check if the transaction type matches
                        t.displayDetails(); // display the transaction details
                        found = true; 
                    }
                }
            }
            else if (criteria == "transaction amount range") { // search by transaction amount range
                double min, max; 
                cin >> min >> max; 
                for (Transaction t : transactions) { // loop through the vector of transactions
                    if (t.getTransactionAmount() >= min && t.getTransactionAmount() <= max) { // check if the transaction amount is within the range
                        t.displayDetails(); // display the transaction details
                        found = true; 
                    }
                }
            }
            else if (criteria == "transaction date range") { // search by transaction date range
                string start, end; 
                cin >> start >> end; 
                for (Transaction t : transactions) { // loop through the vector of transactions
                    if (t.getTransactionDate() >= start && t.getTransactionDate() <= end) { // check if the transaction date is within the range
                        t.displayDetails(); // display the transaction details
                        found = true; 
                    }
                }
            }
            else {
                cout << "Invalid criteria." << endl; // display an error message
            }

            if (!found) {
                cout << "No transaction found." << endl; // display a message if no transaction is found
            }
        }
                // a function to display all the customers in the vector in a tabular format
        void displayAllCustomers() {
            cout << left << setw(20) << "Name" << setw(15) << "National ID" << setw(15) << "Account Number" << setw(15) << "Balance" << endl;
            cout << "-----------------------------------------------------------------" << endl;
            for (Customer c : customers) {
                cout << left << setw(20) << c.getName() << setw(15) << c.getNationalId() << setw(15) << c.getAccountNumber() << setw(15) << c.getBalance() << endl;
            }
        }

           // a function to display all the accounts in the vector in a tabular format
        void displayAllAccounts() {
            cout << left << setw(15) << "Account Number" << setw(15) << "Account Type" << setw(15) << "Balance" << setw(15) << "Interest Rate" << endl;
            cout << "-----------------------------------------------------------------" << endl;
            for (Account a : accounts) {
                cout << left << setw(15) << a.getAccountNumber() << setw(15) << a.getAccountType() << setw(15) << a.getBalance() << setw(15) << a.getInterestRate() << endl;
            }
        }

                // a function to display all the loans in the vector in a tabular format
        void displayAllLoans() {
            cout << left << setw(15) << "Loan Number" << setw(15) << "Loan Type" << setw(15) << "Loan Amount" << setw(15) << "Interest Rate" << endl;
            cout << "-----------------------------------------------------------------" << endl;
            for (Loan l : loans) {
                cout << left << setw(15) << l.getLoanNumber() << setw(15) << l.getLoanType() << setw(15) << l.getLoanAmount() << setw(15) << l.getInterestRate() << endl;
            }
        }

                // a function to display all the transactions in the vector in a tabular format
        void displayAllTransactions() {
            cout << left << setw(20) << "Transaction Number" << setw(20) << "Transaction Type" << setw(20) << "Transaction Amount" << setw(20) << "Transaction Date" << endl;
            cout << "-----------------------------------------------------------------" << endl;
            for (Transaction t : transactions) {
                cout << left << setw(20) << t.getTransactionNumber() << setw(20) << t.getTransactionType() << setw(20) << t.getTransactionAmount() << setw(20) << t.getTransactionDate() << endl;
            }
        }

        // a function to get the name of the manager
        string getName() {
            return name;
        }

        // a function to get the national id of the manager
        long int getNationalId() {
            return national_id;
        }

        // a function to get the password of the manager
        string getPassword() {
            return password;
        }

        // a function to set the name of the manager
        void setName(string n) {
            name = n;
        }

        // a function to set the national id of the manager
        void setNationalId(long int id) {
            national_id = id;
        }

        // a function to set the password of the manager
        void setPassword(string pass) {
            password = pass;
        }
        // a function to display the details of the manager
        void displayDetails() {
            cout << "Name: " << name << endl;
            cout << "National ID: " << national_id << endl;
            cout << "Password: " << password << endl;
        }
};
// define the class Employee
class Employee: public BankManager
{
 private:
        string name; // the name of the employee
        long int national_id; // the national id of the employee
        double salary; // the salary of the employee
        string position; // the position of the employee
        string password;

    public:
        // a default constructor that sets the name to "Unknown", the national id to 0, the salary to 0 and the position to "None"
        Employee() {
            name = "Unknown";
            national_id = 0;
            salary = 0;
            position = "None";
        }
        // a parameterized constructor that takes the name, national id, salary and position of the employee as input
        Employee(string n, long int id, double s, string p, string pass) {
            name = n;
            national_id = id;
            salary = s;
            position = p;
            password = pass;
        }
        // a function to get the name of the employee
        string getName() {
            return name;
        }

        // a function to get the national id of the employee
        long int getNationalId() {
            return national_id;
        }

        // a function to get the salary of the employee
        double getSalary() {
            return salary;
        }

        // a function to get the position of the employee
        string getPosition() {
            return position;
        }
        string getPassword() {
            return password;
        }

        // a function to set the name of the employee
        void setName(string n) {
            name = n;
        }

        // a function to set the national id of the employee
        void setNationalId(long int id) {
            national_id = id;
        }

        // a function to set the salary of the employee
        void setSalary(double s) {
            salary = s;
        }

        // a function to set the position of the employee
        void setPosition(string p) {
            position = p;
        }
        // a function to set the password
        void setPassword(string pass) {
            password = pass;
        }
        // a function to display the details of the employee
        void displayDetails() {
            cout << "Name: " << name << endl;
            cout << "National ID: " << national_id << endl;
            cout << "Salary: " << salary << endl;
            cout << "Position: " << position << endl;
        }

        // a friend function to overload the insertion operator for writing an employee object to an output stream
        friend ostream& operator<<(ostream& out, const Employee& e) {
            out << e.name << " " << e.national_id << " " << e.salary << " " << e.position;
            return out;
        }

        // a friend function to overload the extraction operator for reading an employee object from an input stream
        friend istream& operator>>(istream& in, Employee& e) {
            in >> e.name >> e.national_id >> e.salary >> e.position;
            return in;
        }


    
};
class Customer
{

};
class Loan
{

};
class Account
{

};


class Transaction {
  private:
    // data members
    string number; // the number of the transaction
    string type; // the type of the transaction (deposit, withdraw, transfer)
    string account; // the number of the account involved in the transaction
    double amount; // the amount of the transaction
    string date; // the date of the transaction
    
  public:
    // constructors
    Transaction(); // default constructor
    Transaction(string n, string t, string a, double m, string d); // parameterized constructor
    Transaction(const Transaction& t); // copy constructor
    
    // destructor
    ~Transaction();
    
    // getters and setters
    string getTransactionNumber() const; // get the number
    void setTransactionNumber(string n); // set the number
    string getTransactionType() const; // get the type
    void setTransactionType(string t); // set the type
    string get_account() const; // get the account
    void set_account(string a); // set the account
    double getTransactionAmount() const; // get the amsssount
    void setTransactionAmount(double m); // set the amount
    string getTransactionDate() const; // get the date
    void setTransactionDate(string d); // set the date
    
};

void time()
{
  time_t now = time(0);
   char* dt = ctime(&now);
   cout << "           " <<dt;
}
void display_main_menu() 
{
  system("cls");
  cout<<"---------------------------------------------------\n";
  cout<<"           Welcome To The UT Bank            \n";
  cout<<"---------------------------------------------------\n";
  time();
  cout<<"---------------------------------------------------\n\n";
  cout << "1: Manager \n\n";
  cout << "2: Employee\n\n";
  cout << "3: Costumer\n\n";
  cout << "4: About us\n\n";
  cout << "5: Exit\n\n";
  cout<<"---------------------------------------------------\n\n";
  cout<<" Select your choice : ";
}
void display_manager_panel() {
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
  cout << "21: Logout\n";
  cout <<"22: Back to main menu\n\n";
  cout <<"---------------------------------------------------\n";
  cout <<" Select your choice : ";
}
void display_employee_panel()
{
  system("cls");
  cout<<"---------------------------------------------------\n";
  cout<<"                 Employee Panel                           \n";
  cout<<"---------------------------------------------------\n\n";
  cout<<"1: View accounts\n";
  cout<<"2: Search accounts\n";
  cout<<"3: View transactions\n";
  cout<<"4: View costumers\n";
  cout<<"5: Search costumers\n";
  cout<<"6: Request for loan\n";
  cout<<"7: View detail of accounts\n";
  cout<<"8: View detail of loans\n";
  cout<<"9: Request for transactions\n";
  cout<<"10: Back to main menu\n\n";
  cout <<"---------------------------------------------------\n";
  cout <<" Select your choice : ";
}
void display_costumer_panel()
{
  system("cls");
  cout<<"---------------------------------------------------\n";
  cout<<"                 Costumer Panel                           \n";
  cout<<"---------------------------------------------------\n\n";
  cout<<"1: View my accounts\n";
  cout<<"2: My transactions\n";
  cout<<"3: Card to card\n";
  cout<<"4: View my transactions\n";
  cout<<"5: Register for new account\n";
  cout<<"6: Request for delete my account\n";
  cout<<"7: Back to main menu\n\n";
  cout <<"---------------------------------------------------\n";
  cout <<" Select your choice : ";
}
void about_us_panel()
{
  system("cls");
  cout<<"---------------------------------------------------\n";
  cout<<"                 Members of Team                           \n";
  cout<<"---------------------------------------------------\n\n";
  cout <<"Name = Masoud Khodayari\n";
  cout <<"Student ID = 220701055\n\n";
  cout <<"---------------------------------------------------\n\n";
  cout <<"Name = Amir Masoud Ashouri\n";
  cout <<"Student ID = 220701033\n\n";
  cout <<"---------------------------------------------------\n\n";
  cout <<"Name = Amir Hossein Saberi\n";
  cout <<"Student ID = 220701072\n\n";
  cout <<"---------------------------------------------------\n";
  cout<<"1: Back to menu\n\n";
  cout <<"---------------------------------------------------\n";
  cout <<" Select your choice : ";

}
void select_panel()
{
  while(true)
  {
    display_main_menu();
    int select_choice;
    cin>>select_choice;
    if(select_choice==1)
    {
      display_manager_panel();
      cin>>select_choice;
      if (select_choice==1)
      {

      }
      else if(select_choice==2)
      {

      }
      else if(select_choice==3)
      {

      }
      else if(select_choice==4)
      {

      }
      else if(select_choice==5)
      {

      }
      else if(select_choice==6)
      {

      }
      else if(select_choice==7)
      {

      }
      else if(select_choice==8)
      {

      }
      else if(select_choice==9)
      {

      }
      else if(select_choice==10)
      {

      }
      else if(select_choice==11)
      {

      }
      else if(select_choice==12)
      {

      }
      else if(select_choice==13)
      {

      }
      else if(select_choice==15)
      {

      }
      else if(select_choice==16)
      {

      }
      else if(select_choice==17)
      {

      }
      else if(select_choice==18)
      {

      }
      else if(select_choice==19)
      {

      }
      else if(select_choice==20)
      {

      }
      else if(select_choice==21)
      {

      }
      else if(select_choice==22)
      {
        display_main_menu();
      }      
    }
    else if(select_choice==2)
    {
        display_employee_panel();
        cin>>select_choice;
        if(select_choice==1)
        {

        }
        else if(select_choice==2)
        {

        }
        else if (select_choice==3)
        {

        }
        else if(select_choice==4)
        {

        }
        else if(select_choice==5)
        {

        }
        else if(select_choice==6)
        {

        }
        else if(select_choice==7)
        {

        }
        else if(select_choice==8)
        {

        }
        else if(select_choice==9)
        {

        }
        else if(select_choice==10)
        {
          display_main_menu();
        }
    }
    else if(select_choice==3)
    {
      display_costumer_panel();
      cin>>select_choice;
      if(select_choice==1)
      {

      }
      else if(select_choice==2)
      {

      }
      else if(select_choice==3)
      {

      }
      else if(select_choice==4)
      {

      }
      else if(select_choice==5)
      {

      }
      else if(select_choice==6)
      {

      }
      else if(select_choice==7)
      {
        display_main_menu();
      }
    }
    else if(select_choice==4)
    {
      about_us_panel();
      cin>>select_choice;
      if(select_choice==1)
      {
        display_main_menu();
      }
    }
    else if(select_choice==5)
    {
      exit(0);
    }
  } 
}
int main()
{
  select_panel();
}