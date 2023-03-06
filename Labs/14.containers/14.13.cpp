#include <iostream>
#include <deque>

using namespace std;

int main()
{
    string line;
    bool result = 1;

    deque<char> q;
    getline(cin, line);
    for (int i = 0; i < line.length(); i++)
    {
        if (isalpha(line.at(i)))
        {
            q.push_back(line.at(i));
        }
    }
    while (result && q.size() > 1)
    {
        if (q.back() != q.front())
        {
            result = 0;
        }
        q.pop_back();
        q.pop_front();
    }
    if (result)
    {
        cout << "Yes, \"" << line << "\" is a palindrome." << endl;
    }
    else
    {
        cout << "No, \"" << line << "\" is not a palindrome." << endl;
    }

    return 0;
}
