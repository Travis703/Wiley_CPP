#include <iostream>
#include <vector>

#include "FileStorageDao.h"

using namespace std;

int Menu();

template <typename t1, class t2, typename t3>
void selectionSort(t1 (t2::*memberfunc)(), vector<t3> &data);

char charCheck(char var, char expected[]);

template <typename t6>
t6 numCheck(t6 var);

void displayCustomers(vector<Customer *> customers);
string formatCheck(string var, string format);
int checkID(int id, int n);

int main()
{
    FileStorageDao storeagefile;

    vector<Customer *> customers = storeagefile.retrieveAllCustomers();
    int choice = Menu();
    while (choice != 8)
    {
        switch (choice)
        {
        case 1:
        {
            int age, mobile;
            string name, passport, DOB;

            cout << "Please enter your name: ";
            cin.ignore();
            getline(cin, name);

            cout << "Enter your age: ";

            age = numCheck(age);

            cout << "Enter your mobile number: ";
            mobile = numCheck(mobile);

            cout << "Enter your passport number: ";
            cin >> passport;

            cout << "Enter your Date of Birth(dd/mm/yyyy): ";
            DOB = formatCheck(DOB, "dd/mm/yyyy");

            Customer *customer = new Customer(name, age, DOB, mobile, passport);
            customers.push_back(customer);
            cout << "Customer successfully created." << endl;
            cout << "Your id is: " << Customer::customer_counter << endl;
        }
        break;
        case 2:
        {
            int id = -1;

            cout << "Please enter your ID: " << endl;
            try
            {
                id = checkID(id, customers.size());
            }
            catch (runtime_error e)
            {
                cout << e.what() << endl;
            }
            if (id != -1)
            {

                cout << "What type of account is your bank account?";
                cout << "Enter s for Savings and f for Fixed: ";

                char choice;
                char arr[] = {'s', 'f'};
                choice = charCheck(choice, arr);

                long account_number, BSB;
                string bankname, date;

                cout << "Enter your account number: ";
                account_number = numCheck(account_number);

                cout << "Enter BSB code: ";
                BSB = numCheck(BSB);

                cout << "Enter the name of the Bank: ";
                cin.ignore();
                getline(cin, bankname);

                cout << "Enter todays date(dd/mm/yyyy): ";
                date = formatCheck(date, "dd/mm/yyyy");

                selectionSort(Customer::getID, customers);
                if (choice == 'f')
                {
                    double balance;
                    cout << "Enter your starting balance: ";
                    balance = numCheck(balance);

                    double deposit;
                    cout << "Please specify your initial deposit: $";
                    deposit = numCheck(deposit);

                    while (deposit < 1000)
                    {
                        cout << "Your initial deposit must be a minimum of $1000." << endl;
                        cout << "Please specify your initial deposit: $";
                        deposit = numCheck(deposit);
                    }

                    int tenure;
                    cout << "Tenure options are from a minimum of 1 years to a maximum of 7 years." << endl;
                    cout << "Enter your tenure: ";
                    tenure = numCheck(tenure);
                    while (tenure < 0 || tenure > 7)
                    {
                        cout << "Please Enter a minimum of 1 year and a maximum of 7 years: ";
                        tenure = numCheck(tenure);
                    }

                    Fixed *account = new Fixed(0, account_number, BSB, bankname, date, balance, deposit, tenure);
                    customers.at(id - 100)->addAccount(account);
                }
                else
                {
                    cout << "Is the account a salary account(y,n)? ";
                    char c[] = {'y', 'n'};
                    char s;
                    bool salary;
                    s = charCheck(s, c);

                    if (s == 'y')
                    {
                        salary = 1;
                    }
                    else
                    {
                        cout << "You will have to deposit a minimum of $5000 initially." << endl;
                        salary = 0;
                    }

                    double balance;
                    cout << "Please specify your initial deposit: $";
                    balance = numCheck(balance);
                    while (!salary && balance < 5000)
                    {
                        cout << "Your initial deposit must be a minimum of $5000." << endl;
                        cout << "Please specify your initial deposit: $";
                        balance = numCheck(balance);
                    }

                    Savings *account = new Savings(1, account_number, BSB, bankname, date, balance, salary, (salary) ? 0 : 5000);
                    customers.at(id - 100)->addAccount(account);
                }
            }
        }

        break;
        case 3:
        {
            int id = -1;
            cout << "Enter the customer ID to check: ";
            try
            {
                id = checkID(id, customers.size());
            }
            catch (runtime_error e)
            {
                cout << e.what() << endl;
            }

            if (id != -1)
            {
                cout << "Would you like to display balance or interest." << endl;
                cout << "Please enter b or i: ";
                char in;
                char data[] = {'b', 'i'};
                in = charCheck(in, data);

                selectionSort(Customer::getID, customers);
                if (in == 'b')
                {
                    cout << "Customer: " << customers.at(id - 100)->getName() << " Balance is: ";
                    cout << customers.at(id - 100)->getAccount()->getBalance();
                }
                else
                {
                    cout << "Customer: " << customers.at(id - 100)->getName() << " Interest earned is: ";
                    cout << customers.at(id - 100)->getAccount()->getInterestEarned();
                }
            }
        }
        break;
        case 4:
        {

            cout << "Would you like sorting to be done on customer names or bank balances?" << endl;
            cout << "Please enter a choice either c or b: ";
            char c;
            char arr[] = {'b', 'c'};
            c = charCheck(c, arr);

            if (c == 'c')
            {
                selectionSort(&Customer::getName, customers);
            }
            else
            {
                vector<Account *> accounts;
                for (Customer *i : customers)
                {
                    if (i->getAccount())
                    {
                        accounts.push_back(i->getAccount());
                    }
                }
                selectionSort(&Account::getBalance, accounts);
            }
            cout << "Sorting completed." << endl;
            cout << "Would you like to display all Customers?";
            cout << "Please enter y or n: ";

            arr[0] = 'y';
            arr[1] = 'n';
            c = charCheck(c, arr);
            if (c == 'y')
            {
                displayCustomers(customers);
            }
        }
        break;
        case 5:
        {

            cout << "Would you like to save customers to a database or a text file?" << endl;
            cout << "Please enter t or d: ";
            char arr[] = {'t', 'd'};
            char c;
            c = charCheck(c, arr);

            if (c == 't')
            {
                cout << "saving customers to \"customers.txt\"..." << endl;
                selectionSort(Customer::getID, customers);
                storeagefile.saveAllCustomers(customers);
                cout << "Saving complete!" << endl;
            }
            else
            {
                // todo, save to a db
            }
        }
        break;
        case 6:
        {
            displayCustomers(customers);
        }
        break;
        case 7:
        {
            bool found = 0;
            string in;
            cout << "Enter the name of the customer to find: ";
            getline(cin, in);

            for (Customer *i : customers)
            {
                if (i->getName() == in)
                {
                    found = 1;
                    i->printDetails();
                    cout << endl;
                    break;
                }
            }
            if (!found)
            {
                cout << "Customer not found in the database, please try again with a new name." << endl;
            }
        }
        break;
        default:
            cout << "Please choose a valid option." << endl;
            break;
        }
        cout << endl;
        choice = Menu();
    }
    return 0;
}
void displayCustomers(vector<Customer *> customers)
{
    cout << "Our current customers are:" << endl;
    for (Customer *i : customers)
    {
        i->printDetails();
        cout << endl;
    }
}
int Menu()
{

    int choice;
    cout << "1. Create New Customer Data" << endl;
    cout << "2. Assign a Bank Account to a Customer" << endl;
    cout << "3. Display balance or interest earned of a Customer" << endl;
    cout << "4. Sort Customer Data" << endl;
    cout << "5. Persist Customer Data" << endl;
    cout << "6. Show All Customers" << endl;
    cout << "7. Search Customers by Name" << endl;
    cout << "8. Exit" << endl;
    choice = numCheck(choice);

    return choice;
}

template <typename t6>
t6 numCheck(t6 var)
{
    cin >> var;

    while (cin.fail())
    {
        cout << "Please enter a valid number: ";
        cin.clear();
        cin.ignore();
        cin >> var;
    }
    return var;
}
string formatCheck(string var, string format)
{
    cin >> var;
    vector<string> data = FileStorageDao::split(var, '/');
    try
    {

        if (data.size() == 3)
        {
            int day = stoi(data.at(0)), month = stoi(data.at(1)), year = stoi(data.at(2));
            if (day > 0 && day < 32 && month < 13 && month > 0 && year > 1960 && year < 2024)
            {

                return var;
            }
            else
            {
                throw runtime_error("Please enter valid dates");
            }
        }
        else
        {
            throw invalid_argument("i");
        }
    }
    catch (invalid_argument e)
    {
        cout << "Please enter date in the correct format(dd/mm/yyyy)" << endl;
        cout << "Enter integers separated by a / character: ";
    }
    catch (runtime_error e)
    {
        cout << "Please enter date in the correct format(dd/mm/yyyy)" << endl;
        cout << e.what() << ": ";
    }
    return formatCheck(var, format);
}

int checkID(int id, int n)
{
    cin >> id;
    while (cin.fail())
    {
        cin.clear();
        cin.ignore();
        cout << "Please enter your ID as an Integer: ";
        cin >> id;
    }

    if ((id - 100) >= n || id - 100 < 0)
    {

        throw runtime_error("An incorrect id was passed.");
    }
    return id;
}
char charCheck(char var, char expected[])
{

    cin >> var;
    while (cin.fail())
    {
        cout << "Please enter the correct input " << expected[0] << " or " << expected[1] << ": ";
        cin.clear();
        cin.ignore();
        cin >> var;
    }
    var = tolower(var);
    if (var != expected[0] && var != expected[1])
    {
        cout << "Please choose a valid input " << expected[0] << " or " << expected[1] << ": ";
        charCheck(var, expected);
    }
    return var;
}

template <typename t1, class t2, typename t3>
void selectionSort(t1 (t2::*memberfunc)(), vector<t3> &data)
{

    for (int i = 0; i < data.size() - 1; i++)
    {
        int small = i;
        for (int k = i + 1; k < data.size(); k++)
        {
            if ((data.at(k)->*memberfunc)() < (data.at(small)->*memberfunc)())
            {
                small = k;
            }
        }

        t3 temp = data.at(i);
        data.at(i) = data.at(small);
        data.at(small) = temp;
    }
}
