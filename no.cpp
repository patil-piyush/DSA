#include<iostream>
using namespace std;
static int x = 123456000;
class bankAccount
{
    string name;
    int acc_no;
    string type;
    float bal;

public:
    bankAccount();
    bankAccount(string a, int b, string c, float d);\
    void display();
    void deposit(float amt);
    void withdraw(float amt);
    friend class bankManager;
};

class bankManager
{
public:
    void display(bankAccount z);
    void deleteAccount(bankAccount &z);
    int ac_no(bankAccount z);
};

bankAccount::bankAccount()
{
    name = "NULL";
    acc_no = 0;
    type = "NULL";
    bal = 0;
}

bankAccount::bankAccount(string a, int b, string c, float d)
{
    name = a;
    acc_no = x+b;
    type = c;
    bal = d;
}
int bankManager::ac_no(bankAccount z)
{
    return z.acc_no;
}
void bankManager::display(bankAccount z)
{
    cout << "Name of Customer : " << z.name << endl
         << "Account Number : " << z.acc_no << endl
         << "Type of Account : " << z.type << endl
         << "Balance : " << z.bal << " Rs." << endl;
}
void bankAccount::display()
{
    cout << "Name of Customer : " << name << endl
         << "Account Number : " << acc_no << endl
         << "Type of Account : " << type << endl
         << "Balance : " << bal << " Rs." << endl;
}
void bankManager::deleteAccount(bankAccount &z)
{
    z.name = "NULL";
    z.acc_no = 0;
    z.type = "NULL";
    z.bal = 0;
    cout << "Account Deletion Successful" << endl;
}

void bankAccount::deposit(float amt)
{
    cout << "Added amount " << amt << " Rs to the account" << endl;
    bal = bal + amt;
    cout << "Total Account Balance is " << bal << " Rs." << endl;
}

void bankAccount::withdraw(float amt)
{
    if (bal < amt)
    {
        cout << "Insufficient balance. Cannot withdraw." << endl;
    }
    else
    {
        cout << "Withdrawn amount " << amt << " Rs from the account" << endl;
        bal = bal - amt;
        cout << "Total Account Balance is " << bal << " Rs." << endl;
    }
}



int main()
{
    bool eloop;
    bankAccount customer[100];
    bankManager x;
    int i = 0;
    int choice, pos;
    string a;
    int m;
    int b;
    string c;
    float d;
    while (1)
    {
        cout << "Login as a customer (0) or Manager (1) else (2) to exit ?" << endl;
        cout << "Enter Choice : ";
        cin >> pos;
        switch (pos)
        {
        case 0:
            eloop = true; // Set eloop to true to enter the loop
            while (eloop) // Continue looping as long as eloop is true
            {
                cout << "1. Deposit money\n2. Withdraw money\n3. Exit\n";
                cout << "Enter Choice  :";
                cin >> choice;

                switch (choice)
                {
                case 1:
                    cout << "Enter customer account number to deposit money: ";
                    cin >> m;
                    b = m%123456;
                    if (b >= 0 && b < i)
                    {
                        cout<<"Your Account Details : ";
                        customer[b].display();
                        cout << "Enter amount to deposit: ";
                        cin >> d;
                        customer[b].deposit(d);
                    }
                    else
                    {
                        cout << "Invalid Account Number." << endl;
                    }
                    break;

                case 2:
                    cout << "Enter customer Account number to withdraw money: ";
                    cin >> m;
                    b = m%123456;
                    if (b >= 0 && b < i)
                    {
                        cout<<"Your Account Details : ";
                        customer[b].display();
                        cout << "Enter amount to withdraw: ";
                        cin >> d;
                        customer[b].withdraw(d);
                    }
                    else
                    {
                        cout << "Invalid Account Number." << endl;
                    }
                    break;

                case 3:
                    cout << "Exiting as customer." << endl;
                    eloop = false; // Set eloop to false to exit the loop
                    break;

                default:
                    cout << "Invalid choice. Please try again." << endl;
                    break;
                }
            }
            break;

        case 1:
            eloop = true; // Set eloop to true to enter the loop
            while (eloop) // Continue looping as long as eloop is true
            {
                cout << "1. Register a customer\n2. Display Data of Customer\n3. Delete Data\n4. Exit\n";
                cout << "Enter Choice : ";
                cin >> choice;

                switch (choice)
                {
                case 1:
                    cout << "Enter Name : ";
                    cin >> a;
                    cout << "Enter type of account : ";
                    cin >> c;
                    cout << "Enter Initial Deposit : ";
                    cin >> d;
                    customer[i] = bankAccount(a, i, c, d);
                    cout << "Account number assigned to customer is : " << x.ac_no(customer[i]) << endl;
                    i++;
                    break;

                case 2:
                    cout << "Enter customer account number to display: ";
                    cin >> m;
                    b = m%123456;
                    if (b >= 0 && b < i)
                    {
                        x.display(customer[b]);
                    }
                    else
                    {
                        cout << "Invalid Account Number." << endl;
                    }
                    break;
                case 3:
                    cout << "Enter customer account number to delete: ";
                    cin >> m;
                    b = m%123456;
                    if (b >= 0 && b < i)
                    {
                        x.deleteAccount(customer[b]);
                    }
                    else
                    {
                        cout << "Invalid Account Number." << endl;
                    }
                    break;
                case 4:
                    cout << "Exiting as customer." << endl;
                    eloop = false; // Set eloop to false to exit the loop
                    break;

                default:
                    cout << "Invalid choice. Please try again." << endl;
                    break;
                }
            }
            break;
        case 2:
            return 0;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    }
    return 0;
}
