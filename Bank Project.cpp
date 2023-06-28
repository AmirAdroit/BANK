#include <iostream>                                                      //opne cpp libraries 
#include <string> 
#include <fstream>
#include <ctime>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;                                                       //use of std space
class BankManager                                                          //bank manager class
{
    private:                                                               //part of private 
        string name;
        long int national_id;
        string password;
        vector<Employee> employees;                                         //use of dynamic array 
        vector<Customer> customers;
        vector<Account> accounts;
        vector<Loan> loans;
        vector<Transaction> transactions;

    protected:                                                          

        void loadEmployees()                                                //open list for all of employees
        {
            ifstream fin("employees.txt");
            if (fin.is_open())
            { 
                Employee e;
                while (fin >> e) 
                { 
                    employees.push_back(e); 
                }
                fin.close();
            }
            else 
            {
                cout << "Error: could not open employees.txt" << endl;
            }
        }

        void saveEmployees()                                                 //save name of an employee to list 
        {
            ofstream fout("employees.txt");
            if (fout.is_open()) 
            {
                for (Employee e : employees) 
                {
                    fout << e << endl; 
                }
                fout.close();
            }
            else 
            {
                cout << "Error: could not open employees.txt" << endl;
            }
        }

        void addEmployee(Employee e)                                         //add an employee to list
        {
            employees.push_back(e);
            saveEmployees(); 
        }

        void removeEmployee(long int id)                                     //delete an employee to list
        {
            int index = -1;
            for (int i = 0; i < employees.size(); i++) 
            {
                if (employees[i].getNationalId() == id) 
                { 
                    index = i;
                    break;
                }
            }
            if (index != -1)
            { 
                employees.erase(employees.begin() + index);
                saveEmployees();
            }
            else 
            {
                cout << "Employee not found." << endl;
            }
        }

        void updateEmployee(long int id, Employee e)                         //modify an employee 
        {
            int index = -1; 
            for (int i = 0; i < employees.size(); i++) 
            {
                if (employees[i].getNationalId() == id) 
                {
                    index = i;
                    break;
                }
            }
            if (index != -1) 
            { 
                employees[index] = e;
                saveEmployees(); 
            }
            else
            {
                cout << "Employee not found." << endl;
            }
        }

        void searchEmployee(string criteria)                                 //search for an employee
        {
            bool found = false; 
            cout << "Enter " << criteria << ": "; 
            if (criteria == "name") 
            {
                string name; 
                cin >> name; 
                for (Employee e : employees) 
                {
                    if (e.getName() == name) 
                    {
                        e.displayDetails();
                        found = true; 
                    }
                }
            }
            else if (criteria == "national id") 
            { 
                long int id; 
                cin >> id; 
                for (Employee e : employees) 
                { 
                    if (e.getNationalId() == id) 
                    {
                        e.displayDetails(); 
                        found = true; 
                    }
                }
            }
            else if (criteria == "salary range") 
            {
                double min, max; 
                cin >> min >> max; 
                for (Employee e : employees) 
                {
                    if (e.getSalary() >= min && e.getSalary() <= max) 
                    {
                        e.displayDetails();
                        found = true; 
                    }
                }
            }
            else if (criteria == "position") 
            {
                string position; 
                cin >> position; 
                for (Employee e : employees) 
                {
                    if (e.getPosition() == position) 
                    { 
                        e.displayDetails();
                        found = true; 
                    }
                }
            }
            else 
            {
                cout << "Invalid criteria." << endl; 
            }

            if (!found) 
            {
                cout << "No employee found." << endl;
            }
        }

        void displayAllEmployees()                                  //display all of employees
         {
            cout << left << setw(20) << "Name" << setw(15) << "National ID" << setw(15) << "Salary" << setw(15) << "Position" << endl;
            cout << "-----------------------------------------------------------------" << endl;
            for (Employee e : employees) 
            {
                cout << left << setw(20) << e.getName() << setw(15) << e.getNationalId() << setw(15) << e.getSalary() << setw(15) << e.getPosition() << endl;
            }
        }


    public:                                                        //part of public for bank manager class
       
        BankManager(string n, long int id, string p ) 
        {
            name = n;
            national_id = id;
            password = pass;
            loadEmployees();
            loadCustomers();
            loadAccounts();
            loadLoans();
            loadTransactions();
        }
        
        void loadCustomers() 
        {
            ifstream fin("customers.txt"); 
            if (fin.is_open()) 
            { 
                Customer c; 
                while (fin >> c) 
                { 
                    customers.push_back(c);
                }
                fin.close(); 
            }
            else 
            {
                cout << "Error: could not open customers.txt" << endl;
            }
        }

      
        void saveCustomers()
        {
            ofstream fout("customers.txt"); 
            if (fout.is_open()) 
            {
                for (Customer c : customers) 
                { 
                    fout << c << endl;
                }
                fout.close();
            }
            else 
            {
                cout << "Error: could not open customers.txt" << endl;
            }
        }

        void loadAccounts() 
        {
            ifstream fin("accounts.txt");
            if (fin.is_open())
                Account a;
                while (fin >> a) 
                { 
                    accounts.push_back(a); 
                }
                fin.close();
            }
            else 
            {
                cout << "Error: could not open accounts.txt" << endl;
            }
        }

        
        void saveAccounts() 
        {
            ofstream fout("accounts.txt");
            if (fout.is_open()) 
            { 
                for (Account a : accounts) 
                { 
                    fout << a << endl; 
                }
                fout.close(); 
            }
            else 
            {
                cout << "Error: could not open accounts.txt" << endl;
            }
        }

      
        void loadLoans() 
        {
            ifstream fin("loans.txt"); 
            if (fin.is_open()) 
            { 
                Loan l; 
                while (fin >> l) 
                { 
                    loans.push_back(l); 
                }
                fin.close(); 
            }
            else 
            {
                cout << "Error: could not open loans.txt" << endl;
            }
        }

       
        void saveLoans() 
        {
            ofstream fout("loans.txt");
            if (fout.is_open()) 
            { 
                for (Loan l : loans) 
                { 
                    fout << l << endl;
                }
                fout.close();
            }
            else 
            {
                cout << "Error: could not open loans.txt" << endl;
            }
        }

        void loadTransactions() 
        {
            ifstream fin("transactions.txt");
            if (fin.is_open()) 
            { 
                Transaction t; 
                while (fin >> t) 
                { 
                    transactions.push_back(t); 
                }
                fin.close(); 
            }
            else 
            {
                cout << "Error: could not open transactions.txt" << endl;
            }
        }

        void saveTransactions() 
        {
            ofstream fout("transactions.txt");
            if (fout.is_open()) 
            {
                for (Transaction t : transactions) 
                { 
                    fout << t << endl; 
                }
                fout.close();
            }
            else 
            {
                cout << "Error: could not open transactions.txt" << endl;
            }
        }

        
        
        void addCustomer(Customer c) 
        {
            customers.push_back(c);
            saveCustomers();
        }

        
        void removeCustomer(long int id) 
        {
            int index = -1;
            for (int i = 0; i < customers.size(); i++) 
            { /
                if (customers[i].getNationalId() == id) 
                {
                    index = i; 
                    break;
                }
            }
            if (index != -1) 
            {
                customers.erase(customers.begin() + index); 
                saveCustomers();
            }
            else 
            {
                cout << "Customer not found." << endl;
            }
        }
 
        void updateCustomer(long int id, Customer c)                                //part of modify a customer
        {
            int index = -1;
            for (int i = 0; i < customers.size(); i++) 
            {
                if (customers[i].getNationalId() == id) 
                {
                    index = i;
                    break;
                }
            }
            if (index != -1) 
            {
                customers[index] = c;
                saveCustomers();
            }
            else 
            {
                cout << "Customer not found." << endl;
            }
        }

        void addAccount(Account a) 
        {
            accounts.push_back(a); 
            saveAccounts();
        }

        void removeAccount(long int num)                                    //part of delete an account
        {
            int index = -1;
            for (int i = 0; i < accounts.size(); i++) 
            { 
                if (accounts[i].getAccountNumber() == num) 
                {
                    index = i; 
                    break;
                }
            }
            if (index != -1) 
            { 
                accounts.erase(accounts.begin() + index);
                saveAccounts();
            }
            else 
            {
                cout << "Account not found." << endl;
            }
        }

        void updateAccount(long int num, Account a)                          //part of modify an account
        {
            int index = -1;
            for (int i = 0; i < accounts.size(); i++) 
            {
                if (accounts[i].getAccountNumber() == num) 
                {
                    index = i;
                    break;
                }
            }
            if (index != -1) 
            {
                accounts[index] = a; 
                saveAccounts();
            }
            else 
            {
                cout << "Account not found." << endl; 
            }
        }


        void addLoan(Loan l) 
        {
            loans.push_back(l); 
            saveLoans();
        }

        
        void removeLoan(long int num)                               //part of delete loan
        {
            int index = -1;
            for (int i = 0; i < loans.size(); i++) 
            { 
                if (loans[i].getLoanNumber() == num) 
                { 
                    index = i; 
                    break; 
                }
            }
            if (index != -1) 
            { 
                loans.erase(loans.begin() + index); 
                saveLoans(); 
            }
            else 
            {
                cout << "Loan not found." << endl;
            }
        }

        void updateLoan(long int num, Loan l)                        //part of modify loan
        {
            int index = -1;
            for (int i = 0; i < loans.size(); i++) 
            {
                if (loans[i].getLoanNumber() == num) 
                {
                    index = i; 
                    break; 
                }
            }
            if (index != -1) 
            { 
                loans[index] = l;
                saveLoans();
            }
            else 
            {
                cout << "Loan not found." << endl;
            }
        }

        
        void addTransaction(Transaction t) 
        {
            transactions.push_back(t);
            saveTransactions();
        }

      
        void removeTransaction(long int num) 
        {
            int index = -1; 
            for (int i = 0; i < transactions.size(); i++) 
            { 
                if (transactions[i].getTransactionNumber() == num) 
                { 
                    index = i; 
                    break;
                }
            }
            if (index != -1) 
            { 
                transactions.erase(transactions.begin() + index); 
                saveTransactions();
            }
            else 
            {
                cout << "Transaction not found." << endl; 
            }
        }

        void updateTransaction(long int num, Transaction t) 
        {
            int index = -1;
            for (int i = 0; i < transactions.size(); i++) 
            {
                if (transactions[i].getTransactionNumber() == num) 
                { 
                    index = i; 
                    break; 
                }
            }
            if (index != -1) 
            {
                transactions[index] = t; 
                saveTransactions();
            }
            else 
            {
                cout << "Transaction not found." << endl; 
            }
        }

        void searchCustomer(string criteria)                                    //search function for customers
        {
            bool found = false; 
            cout << "Enter " << criteria << ": "; 
            if (criteria == "name") 
            { 
                string name; 
                cin >> name; 
                for (Customer c : customers) 
                {
                    if (c.getName() == name) 
                    {
                        c.displayDetails();
                        found = true; 
                    }
                }
            }
            else if (criteria == "national id") 
            {
                long int id; 
                cin >> id; 
                for (Customer c : customers)
                 {
                    if (c.getNationalId() == id) 
                    { 
                        c.displayDetails(); 
                        found = true; 
                    }
                }
            }
            else if (criteria == "account number") 
            {
                long int num; 
                cin >> num; 
                for (Customer c : customers) 
                {
                    if (c.getAccountNumber() == num) 
                    { 
                        c.displayDetails(); 
                        found = true; 
                    }
                }
            }
            else if (criteria == "balance range") 
            { 
                double min, max; 
                cin >> min >> max; 
                for (Customer c : customers) 
                {
                    if (c.getBalance() >= min && c.getBalance() <= max) 
                    {
                        c.displayDetails();
                        found = true; 
                    }
                }
            }
            else 
            {
                cout << "Invalid criteria." << endl; 
            }

            if (!found) 
            {
                cout << "No customer found." << endl; 
            }
        }
        void searchAccount(string criteria)                                     //search function for accounts
        {
            bool found = false; 
            cout << "Enter " << criteria << ": "; 
            if (criteria == "account number") 
            { 
                long int num; 
                cin >> num; 
                for (Account a : accounts) 
                { 
                    if (a.getAccountNumber() == num) 
                    { 
                        a.displayDetails(); 
                        found = true; 
                    }
                }
            }
            else if (criteria == "account type") 
            { 
                char type; 
                cin >> type; 
                for (Account a : accounts) 
                { 
                    if (a.getAccountType() == type) 
                    { 
                        a.displayDetails();
                        found = true; 
                    }
                }
            }
            else if (criteria == "balance range") 
            {
                double min, max; 
                cin >> min >> max; 
                for (Account a : accounts) 
                { 
                    if (a.getBalance() >= min && a.getBalance() <= max) 
                    { 
                        a.displayDetails(); 
                        found = true; 
                    }
                }
            }
            else if (criteria == "interest rate range") 
            {
                double min, max; 
                cin >> min >> max; 
                for (Account a : accounts) 
                { 
                    if (a.getInterestRate() >= min && a.getInterestRate() <= max) 
                    { 
                        a.displayDetails(); 
                        found = true; 
                    }
                }
            }
            else 
            {
                cout << "Invalid criteria." << endl; 
            }

            if (!found) 
            {
                cout << "No account found." << endl;
            }
        }
        void searchLoan(string criteria) 
        {
            bool found = false;
            cout << "Enter " << criteria << ": "; 
            if (criteria == "loan number") 
            {
                long int num; 
                cin >> num; 
                for (Loan l : loans) 
                {
                    if (l.getLoanNumber() == num) 
                    {
                        l.displayDetails();
                        found = true; 
                    }
                }
            }
            else if (criteria == "loan type") 
            {
                char type; 
                cin >> type; 
                for (Loan l : loans) 
                { 
                    if (l.getLoanType() == type) 
                    {
                        l.displayDetails(); 
                        found = true; 
                    }
                }
            }
            else if (criteria == "loan amount range") 
            {
                double min, max; 
                cin >> min >> max; 
                for (Loan l : loans) 
                { 
                    if (l.getLoanAmount() >= min && l.getLoanAmount() <= max) 
                    {
                        l.displayDetails();
                        found = true; 
                    }
                }
            }
            else if (criteria == "interest rate range") 
            {
                double min, max; 
                cin >> min >> max; 
                for (Loan l : loans) 
                { 
                    if (l.getInterestRate() >= min && l.getInterestRate() <= max)
                     { 
                        l.displayDetails(); 
                        found = true; 
                    }
                }
            }
            else 
            {
                cout << "Invalid criteria." << endl; 
            }

            if (!found) 
            {
                cout << "No loan found." << endl; 
            }
        }
        void searchTransaction(string criteria) 
        {
            bool found = false; 
            cout << "Enter " << criteria << ": "; 
            if (criteria == "transaction number")
            { 
                long int num; 
                cin >> num; 
                for (Transaction t : transactions) 
                { 
                    if (t.getTransactionNumber() == num) 
                    { 
                        t.displayDetails(); 
                        found = true; 
                    }
                }
            }
            else if (criteria == "transaction type") 
            { 
                char type; 
                cin >> type; 
                for (Transaction t : transactions) 
                { 
                    if (t.getTransactionType() == type)
                     {
                        t.displayDetails(); 
                    }
                }
            }
            else if (criteria == "transaction amount range") 
            { 
                double min, max; 
                cin >> min >> max; 
                for (Transaction t : transactions)
                 { 
                    if (t.getTransactionAmount() >= min && t.getTransactionAmount() <= max)
                     { 
                        t.displayDetails();
                        found = true; 
                    }
                }
            }
            else if (criteria == "transaction date range") 
            {
                string start, end; 
                cin >> start >> end; 
                for (Transaction t : transactions)
                 { 
                    if (t.getTransactionDate() >= start && t.getTransactionDate() <= end) 
                    {
                        t.displayDetails();
                        found = true; 
                    }
                }
            }
            else 
            {
                cout << "Invalid criteria." << endl; 
            }

            if (!found) 
            {
                cout << "No transaction found." << endl;
            }
        }

        void displayAllCustomers() 
        {
            cout << left << setw(20) << "Name" << setw(15) << "National ID" << setw(15) << "Account Number" << setw(15) << "Balance" << endl;
            cout << "-----------------------------------------------------------------" << endl;
            for (Customer c : customers) 
            {
                cout << left << setw(20) << c.getName() << setw(15) << c.getNationalId() << setw(15) << c.getAccountNumber() << setw(15) << c.getBalance() << endl;
            }
        }

        void displayAllAccounts() 
        {
            cout << left << setw(15) << "Account Number" << setw(15) << "Account Type" << setw(15) << "Balance" << setw(15) << "Interest Rate" << endl;
            cout << "-----------------------------------------------------------------" << endl;
            for (Account a : accounts) 
            {
                cout << left << setw(15) << a.getAccountNumber() << setw(15) << a.getAccountType() << setw(15) << a.getBalance() << setw(15) << a.getInterestRate() << endl;
            }
        }

        void displayAllLoans() 
        {
            cout << left << setw(15) << "Loan Number" << setw(15) << "Loan Type" << setw(15) << "Loan Amount" << setw(15) << "Interest Rate" << endl;
            cout << "-----------------------------------------------------------------" << endl;
            for (Loan l : loans) 
            {
                cout << left << setw(15) << l.getLoanNumber() << setw(15) << l.getLoanType() << setw(15) << l.getLoanAmount() << setw(15) << l.getInterestRate() << endl;
            }
        }

        void displayAllTransactions() 
        {
            cout << left << setw(20) << "Transaction Number" << setw(20) << "Transaction Type" << setw(20) << "Transaction Amount" << setw(20) << "Transaction Date" << endl;
            cout << "-----------------------------------------------------------------" << endl;
            for (Transaction t : transactions) 
            {
                cout << left << setw(20) << t.getTransactionNumber() << setw(20) << t.getTransactionType() << setw(20) << t.getTransactionAmount() << setw(20) << t.getTransactionDate() << endl;
            }
        }

        string getName()                                                //getter and setter functions
        {
            return name;
        }
        long int getNationalId() 
        {
            return national_id;
        }

        string getPassword() 
        {
            return password;
        }

        void setName(string n) 
        {
            name = n;
        }

        void setNationalId(long int id) 
        {
            national_id = id;
        }
        void setPassword(string pass) 
        {
            password = pass;
        }
        void displayDetails() 
        {
            cout << "Name: " << name << endl;
            cout << "National ID: " << national_id << endl;
            cout << "Password: " << password << endl;
        }
};
class Employee: public BankManager                                           //employee class
{
 private:
        string name;
        long int national_id; 
        double salary; 
        string position;
        string password;

    public:
        Employee() 
        {
            name = "Unknown";
            national_id = 0;
            salary = 0;
            position = "No position";
        }
        Employee(string n, long int id, double s, string p, string pass) 
        {
            name = n;
            national_id = id;
            salary = s;
            position = p;
            password = pass;
        }
        string getName()                                //getter and setter functions
        {
            return name;
        }
        long int getNationalId() 
        {
            return national_id;
        }
        double getSalary() 
        {
            return salary;
        }
        string getPosition() 
        {
            return position;
        }
        string getPassword() 
        {
            return password;
        }
        void setName(string n) 
        {
            name = n;
        }
        void setNationalId(long int id) 
        {
            national_id = id;
        }
        void setSalary(double s) 
        {
            salary = s;
        }
        void setPosition(string p) 
        {
            position = p;
        }
        void setPassword(string pass) 
        {
            password = pass;
        }
        void displayDetails() 
        {
            cout << "Name: " << name << endl;
            cout << "National ID: " << national_id << endl;
            cout << "Salary: " << salary << endl;
            cout << "Position: " << position << endl;
        }
        friend ostream& operator<<(ostream& out, const Employee& e) 
        {
            out << e.name << " " << e.national_id << " " << e.salary << " " << e.position;
            return out;
        }
        friend istream& operator>>(istream& in, Employee& e) 
        {
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


class Transaction 
{
  private:
    string number;                                              // private members
    string type;
    string account; 
    double amount; 
    string date; 
    
  public:
    Transaction();                                                //constructor
    Transaction(string n, string t, string a, double m, string d);
    Transaction(const Transaction& t); 
    
    // destructor
    ~Transaction();                                              //destructor
    
  
    string getTransactionNumber()                               // Getter and setter functions
    void setTransactionNumber(string n); 
    string getTransactionType() const; 
    void setTransactionType(string t); 
    string get_account() 
    void set_account(string a);
    double getTransactionAmount() 
    void setTransactionAmount(double m); 
    string getTransactionDate() 
    void setTransactionDate(string d);
    
};

void time()                                                      //Display time and date
{
  time_t now = time(0);
   char* dt = ctime(&now);
   cout << "           " <<dt;
}
void display_main_menu()                                         //Display main menu in console
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
void display_manager_panel() {                                    //Display manager panel actions list
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
void display_employee_panel()                                          //Display employee panel actions list 
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
void display_costumer_panel()                                          //Display customer panel actions list
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
void about_us_panel()                                                  //about our team + name + student id
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
void select_panel()                                                    //select choices main function
{
  while(true)
  {
    display_main_menu();
    int select_choice;
    cin>>select_choice;
    if(select_choice==1)
    {
      display_manager_panel();                                         //part of manager panel
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
        display_employee_panel();                                           //part of employee panel
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
      display_costumer_panel();                                             //part of customer panel
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
      about_us_panel();                                             //part of introduction our team
      cin>>select_choice;
      if(select_choice==1)
      {
        display_main_menu();
      }
    }
    else if(select_choice==5)                                       //part of exit from exe file
    {
      exit(0);
    }
  } 
}
int main()
{
  select_panel();
}