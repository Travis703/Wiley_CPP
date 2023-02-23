#include <iostream>
using namespace std;

class SwitchCaseTest
{
public:
    char var = 'a';
    void main()
    {

        switch (var)
        {
        case 'A':
        case 'a':
        case 'E':
        case 'e':
        case 'I':
        case 'i':
        case 'o':
        case 'O':
        case 'u':
        case 'U':
            cout << "The letter is a vowel";
            break;

        default:
            cout << "The letter is a consonant";
            break;
        }
    }
};
class ForLoopTest
{
public:
    int num = 5, total = 1;
    void main()
    {
        for (int i = num; i > 0; i--)
        {
            total *= i;
        }
        cout << total;
    }
};

class WhileLoop
{
public:
    int num = 1552551, i = 1, len = 1;
    bool ispal = 1;
    void main()
    {
        int temp = num;
        while (temp > 10)
        {
            temp /= 10;
            len *= 10;
        }

        while (ispal)
        {
            if ((num % (i * 10) / i) != (num / (len / i) % 10))
            {
                ispal = 0;
            }
            i *= 10;
            if (len / i == 0)
            {
                break;
            }
        }

        cout << ((ispal) ? "number is a palindrome" : "number is not a palindrome");
    }
};

class DoWhileLoop
{
public:
    void main()
    {
        int a = 1, b = 1;

        do
        {
            cout << a << " " << b << " ";
            a += b;
            b += a;
        } while (a <= 34);
    }
};

class BreakTest
{
public:
    bool isprime = 1;
    int count = 0;
    void main()
    {
        for (int i = 2; i <= 100; i++)
        {
            for (int k = 2; k < i; k++)
            {
                if (i % k == 0)
                {
                    isprime = 0;
                    break;
                }
            }
            if (isprime)
            {
                cout << i << endl;
                count++;
            }
            isprime = 1;
        }
        cout << "There are " << count << " prime numbers between 1 and 100";
    }
};

class ContinueTest
{
public:
    void main()
    {
        for (int i = 1; i <= 100; i++)
        {
            if (i % 2 != 0)
            {
                continue;
            }
            cout << i << endl;
        }
    }
};
int main()
{
    SwitchCaseTest t;
    ForLoopTest f;
    WhileLoop l;
    DoWhileLoop d;
    ContinueTest c;
    BreakTest b;
    l.main();
    d.main();
    f.main();
    t.main();
    c.main();
    b.main();

    return 0;
}