#include "FileStorageDao.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
using namespace std;

void FileStorageDao::saveAllCustomers(vector<Customer *> data)
{
    ofstream out;
    out.open("customers.txt");
    for (int i = 0; i < data.size(); i++)
    {
        out << data.at(i);
    }
    out.close();
}
vector<string> FileStorageDao::split(string s, char delim)
{
    int i = 0;
    vector<string> broken_string;
    while (i != string::npos)
    {
        broken_string.push_back(s.substr(i, s.find(delim, i) - i));
        i = s.find(delim, i);
        if (i != string::npos)
        {
            i++;
        }
    }
    return broken_string;
}

vector<Customer *> FileStorageDao::retrieveAllCustomers()
{
    vector<Customer *> customers;
    ifstream in;
    in.open("customers.txt");
    while (!in.eof())
    {
        string customer_data;

        getline(in, customer_data);
        
        vector<string> data = split(customer_data, ',');
        Bank *bank;
        try
        {
            if (stoi(data.at(7)))
            {
                Savings* savings =new Savings(1, stol(data.at(8)), stol(data.at(9)), data.at(9), data.at(11), stod(data.at(12)), stoi(data.at(13)), stoi(data.at(14)));
                bank = savings;
            }
            else
            {
                Fixed* fixed=new Fixed(0,stol(data.at(8)), stol(data.at(9)), data.at(9), data.at(11), stod(data.at(12)), stoi(data.at(13)), stoi(data.at(14)));                bank=fixed;
            }
        }
        catch (out_of_range e)
        {
            Customer *customer = new Customer(stoi(data.at(0)), data.at(1), stoi(data.at(2)), data.at(3),stoi(data.at(4)), data.at(5));
        }
        Customer *customer = new Customer(stoi(data.at(0)), data.at(1), stoi(data.at(2)), data.at(3),stoi(data.at(4)), data.at(5), bank);

        customers.push_back(customer);
    }
    in.close();
    return customers;
}

int FileStorageDao::lastID()
{
    ifstream in;
    in.open("customers.txt");
    string s;
    while (!in.eof())
    {

        getline(in, s);
    }
    in.close();
    return stoi(s.substr(0, s.find(",")));
}