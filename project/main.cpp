#include <iostream>
#include <vector>
#include <map>

#include "FileStorageDao.h"

using namespace std;
static int ids = FileStorageDao::lastID();

int Menu();

template <typename t1, class t2, typename t3>
void selectionSort(t1 (t2::*memberfunc)(), vector<t3> &data);

char charCheck(char var, char expected[]);

template <typename t6>
t6 numCheck(t6 var);

string formatCheck(string var, string format);

ostream &operator<<(ostream &out, Bank &bank);
ostream &operator<<(ostream &out, Customer *&customer);

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

            cout << "Please enter the your name: ";
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
            Customer customer(ids, name, age, DOB, mobile, passport);
            customers.push_back(&customer);
        }
        break;
        case 2:
        {
            int id;

            cout << "Please enter your ID: " << endl;
            cin >> id;
            while (cin.fail())
            {
                cin.clear();
                cin.ignore();
                cout << "Please enter your ID as an Integer: ";
                cin >> id;
            }

            if ((id - 100) >= customers.size() || id - 100 < 0)
            {
                cout << "An incorrect id was passed." << endl;
            }

            else
            {
                char choice;
                cout << "What type of account is your bank account?";
                cout << "Enter s for Savings and f for Fixed: ";
                char arr[] = {'s', 'f'};
                choice = charCheck(choice, arr);

                long account_number, BSB;
                string bankname, date;

                cout << "Enter BSB code: ";
                cin >> BSB;
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

                    Fixed bank(0, account_number, BSB, bankname, date, balance, deposit, tenure);

                    customers.at(id - 100)->addBank(&bank);
                }
                else
                {
                    char s;
                    bool salary;
                    cout << "Is the account a salary account(y,n)? ";
                    char c[] = {'y', 'n'};
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

                    Savings bank(1, account_number, BSB, bankname, date, balance, salary, (salary) ? 0 : 5000);
                    customers.at(id - 100)->addBank(&bank);
                }
            }
        }

        break;
        case 3:
        {
            int id;
            cout << "Enter the customer ID to check: ";
            cin >> id;
            while (cin.fail())
            {
                cin.clear();
                cin.ignore();
                cout << "Please enter the ID as an Integer: ";
                cin >> id;
            }
            if (id - 100 >= customers.size() || id - 100 < 0)
            {
                cout << "An incorrect id was passed." << endl;
            }
            else
            {
                char in;
                selectionSort(Customer::getID, customers);
                cout << "Would you like to display balance or interest." << endl;
                cout << "Please enter b or i: ";
                char data[] = {'b', 'i'};
                in = charCheck(in, data);
                if (in == 'b')
                {
                    cout << "Customer: " << customers.at(id - 100)->getName() << " Balance is: ";
                    cout << customers.at(id - 100)->getBank()->getBalance();
                }
                else
                {
                    cout << "Customer: " << customers.at(id - 100)->getName() << " Interest earned is: ";
                    cout << customers.at(id - 100)->getBank()->getInterestEarned();
                }
            }
        }
        break;
        case 4:
        {
            char c;
            cout << "Would you like sorting to be done on customer names or bank balances?" << endl;
            cout << "Please enter a choice either c or b: ";
            char arr[] = {'b', 'c'};
            c = charCheck(c, arr);
            if (c == 'c')
            {

                selectionSort(&Customer::getName, customers);
            }
            else
            {

                vector<Bank *> banks;
                for (Customer *i : customers)
                {
                    banks.push_back(i->getBank());
                }
                selectionSort(&Bank::getBalance, banks);
            }
            cout << "Sorting completed." << endl;
        }
        break;
        case 5:
        {
            char c;
            cout << "Would you like to save customers to a database or a text file?" << endl;
            cout << "Please enter t or d";
            char arr[] = {'t', 'd'};
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
            cout << "The saved customers are:" << endl;
            for (Customer *i : customers)
            {

                cout << i;
            }
        }
        break;
        case 7:
        {
            string in;
            cout << "Enter the name of the customer to find: ";
            cin >> in;
            bool found = 0;
            for (Customer *i : customers)
            {
                if (i->getName() == in)
                {
                    found = 1;
                    cout << i << endl;
                    break;
                }
            }
            if (!found)
            {
                cout << "Customer not found in the database, please try again" << endl;
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
    cin >> choice;

    return choice;
}

ostream &operator<<(ostream &out, Bank &bank)
{
    out << "Your bank details are: ";
    out << bank.getAccountNumber() << "," << bank.getBSB() << ",";
    out << bank.getBankName() << "," << bank.getBalance() << ",";
    out << bank.getDateOpened() << "," << bank.getInterestEarned() << ",";
    pair<int, int> others = bank.getOther();
    out << others.first << "," << others.second << endl;
    return out;
}

ostream &operator<<(ostream &out, Customer *&customer)
{
    out << customer->getID() << "," << customer->getName() << ",";
    out << customer->getAge() << "," << customer->getDOB() << ",";
    out << customer->getMobile() << "," << customer->getPassport() << ",";
    out << *(customer->getBank()) << endl;
    return out;
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
        int day=stoi(data.at(0)),month=stoi(data.at(1)),year=stoi(data.at(2));

        if (data.size() == 3&&day>0&&day<32&&month<13&&month>0&&year>0)
        {

            return var;
        }
        else{
            cout<<"Please enter date in the correct format(dd/mm/yyyy)"<<endl;
        }
    }
    catch (invalid_argument e)
    {
        cout<<"Please enter integers separated by /"<<endl;
        
    }
    formatCheck(var, format);
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