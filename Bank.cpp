#include <iostream>
#include <string> 
#include <fstream>
#include <ctime>
#include <iomanip>
using namespace std;
class BankManager
{
    private:
    string Username={"AliAhmadi"};
    string Password={"Aliahmadi1357"};
    string Name={"Ali"};
    string Family={"Ahmadi"};
    string Gender={"Male"};
    string Born_date={" 13 January 1978"};
    double National_ID=22445566;
    double Salary=35000000;
    public:
    string U,P;
    BankManager(){Username=U , Password=P;}
};
class Employee {
    private:
    string Name;
    string Family;
    string Gender;
    double National_ID;
    double Salary;
    double Born_date;
    public:
};
class Customer {
    private:
    public:
};
class Transaction {
    private:
    public:
};
class Loan {
    private:
    public:
};
void time()
{
  time_t now = time(0);
  char* dt = ctime(&now);
  cout <<"           "<<dt;
}
void display_main_menu() 
{
  system("cls");
  cout<<"---------------------------------------------------\n";
  cout<<"           Welcome To The UT Bank            \n";
  cout<<"---------------------------------------------------\n";
  time();
  cout<<"---------------------------------------------------\n";
  cout << "1: Manager \n\n";
  cout << "2: Employee\n\n";
  cout << "3: Customer\n\n";
  cout << "4: About us\n\n";
  cout << "5: Exit\n\n";
  cout<<"---------------------------------------------------\n";
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
  cout<<"4: View customers\n";
  cout<<"5: Search customers\n";
  cout<<"6: Request for loan\n";
  cout<<"7: View detail of accounts\n";
  cout<<"8: View detail of loans\n";
  cout<<"9: Request for transactions\n";
  cout<<"10: Back to main menu\n\n";
  cout <<"---------------------------------------------------\n";
  cout <<" Select your choice : ";
}
void display_customer_panel()
{
  system("cls");
  cout<<"---------------------------------------------------\n";
  cout<<"                 Customer Panel                           \n";
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
void system_login()
{
  system("cls");
  cout<<"---------------------------------------------------\n";
  cout<<"                 System Login                           \n";
  cout<<"---------------------------------------------------\n\n";
  string username;
  string password;
  cout<<"Username = ";
  cin>>username;
  cout<<endl;
  cout<<"Password = ";
  cin>>password;
}
void select_panel()
{
  while(true)
  {
    display_main_menu();
    int select_choice;
    cin>>select_choice;
    if(select_choice>=1 && select_choice<=5)
    {
    if(select_choice==1)
    {
      system_login();
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
      else if(select_choice<1 && select_choice>22)
      {
        display_manager_panel();
      }      
    }
    else if(select_choice==2)
    {
        display_employee_panel();
        cin>>select_choice;
        if(select_choice>=1 && select_choice<=10)
        {
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
        else
        {
          display_employee_panel();
        }
    }
    else if(select_choice==3)
    {
      display_customer_panel();
      cin>>select_choice;
      if(select_choice>=1 && select_choice<=7)
      {
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
      else
      {
        display_customer_panel();
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
      else
      {
        about_us_panel();
      }
    }
    else if(select_choice==5)
    {
      exit(0);
    }
    }
  } 
}
int main()
{
    select_panel();
}