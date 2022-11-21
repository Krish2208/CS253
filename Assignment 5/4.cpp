#include <iostream>
#include <string>
using namespace std;

class stack
{
    int *arr;
    int size;
    int t1;

public:
    stack(int n)
    {
        size = n;
        arr = new int[n];
        t1 = 0;
    }
    void push(int a)
    {
        arr[t1] = a;
        t1++;
    }
    int pop()
    {
        if (t1 == 0)
        {
            return 0;
        }
        else
        {
            t1--;
            return arr[t1];
        }
    }
    int peek()
    {
        return arr[t1 - 1];
    }
    int isEmpty()
    {
        return t1 == 0;
    }
};

bool op(char c)
{
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

int pre(char c)
{
    switch (c)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    default:
        return -1;
    }
}

void check(string &ex, stack &a)
{
    for (int i = 0; i < ex.length(); i++)
    {
        if (!op(ex[i]))
        {
            if(ex[i] == '(') a.push(ex[i]);
            else if (ex[i] == ')')
            {
                while (a.peek() != '(')
                {
                    cout << (char)a.pop();
                }
                a.pop();
            }
            else
            {
                while (pre(a.peek()) >= pre(ex[i]) && !a.isEmpty())
                {
                    cout << (char)a.pop();
                }
                a.push(ex[i]);
            }
        }
        else
        {
            cout << ex[i];
        }
    }
    while (!a.isEmpty())
    {
        cout << (char)a.pop();
    }
}

int main()
{
    string ex;
    cin >> ex;
    stack a(ex.length());
    check(ex, a);
    return 0;
}