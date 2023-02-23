#include <iostream>
#include <string>
using namespace std;

void Q1(string in)
{
    cout << in.at(in.length() - 1);
    for (int i = in.length() - 2; i >= 0; i--)
    {
        cout << "-" << in.at(i);
    }
    cout << endl;
}

void Q2(string in)
{
    int i = 0;
    int len = in.length();

    while (i < len)
    {
        if (in.at(i) == 'x')
        {
            in.replace(i, in.length() - i, in.substr(i + 1, in.length()));
            in.append("x");

            i--;
            len--;
        }
        i++;
    }
    cout << in << endl;
}
void Q3(string in){
    char temp=in.at(in.length()-1);
    in.at(in.length()-1)=in.at(0);
    in.at(0)=temp;
    cout<<in<<endl;

}
void Q4(string in)
{
    int max, start, i = 0;
    string sub;

    max = in.find(" ");
    start = 0;
    i = in.find(" ", i) + 1;

    while (in.find(" ", i) != string::npos)
    {

        if (in.find(" ", i) - i > max)
        {
            max = in.find(" ", i) - i;
            start = i;
        }
        i = in.find(" ", i) + 1;
    }

    if (in.length() - i > max)
    {
        start = i;
        max = in.length() - i;
    }

    cout << in.substr(start, max) << endl;
}

void Q5(string in){
    int i=0;
    string temp="";
    temp+=in.at(0);
    while (in.find(" ", i) != string::npos)
    {
        temp+=in.at(in.find(" ",i)+1);
        i = in.find(" ", i) + 1;
    }
    cout<<temp<<endl;
}

void Q6(string in){

    int i=0;
    string temp="";
    temp+=in.at(0);
    while (in.find(" ", i) != string::npos)
    {
        temp+=toupper(in.at(in.find(" ",i)+1+temp.length()));
        i = in.find(" ", i) + 1;
    }
    cout<<temp<<endl;

}

void Q7(string in){
    for(int i=0;i<in.length();i++){
        if(in.at(i)==' '){
            continue;
        }else{
            in.at(i)=in.at(i)+1;
        }
    }
    cout<<in<<endl;

}

int main()
{
    Q1("computer");

    Q2("abcxXXcxerxxXXwer");

    Q3("Hello World");

    Q4("This is java String program");
    Q4("Hi How are you");

    Q5("Softra Services Limited");

    Q6("Softra Services Limited");

    Q7("hello java");

    return 0;
}