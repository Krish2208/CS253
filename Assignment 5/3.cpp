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
            return 1;
        }
    }
    int peek()
    {
        return arr[t1-1];
    }
    int isEmpty()
    {
        return t1 == 0;
    }
};

int check(string &ex, stack &a)
{
    for (int i = 0; i < ex.length(); i++)
    {
        if (ex[i] == '(')
            a.push('(');
        else if (ex[i] == '[')
            a.push('[');
        else if (ex[i] == '{')
            a.push('{');
        else if (ex[i] == ')')
        {
            if (a.peek() == '(')
            {
                if (a.pop() == 0)
                {
                    return 0;
                }
            }
            else
            {
                return 0;
            }
        }
        else if (ex[i] == ']')
        {
            if (a.peek() == '[')
            {
                if (a.pop() == 0)
                {
                    return 0;
                }
            }
            else
            {
                return 0;
            }
        }
        else if (ex[i] == '}')
        {
            if (a.peek() == '{')
            {
                if (a.pop() == 0)
                {
                    return 0;
                }
            }
            else
            {
                return 0;
            }
        }
    }
    if (a.isEmpty())
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    string ex;
    cin >> ex;
    stack a(ex.length());
    if (check(ex, a)) cout << "Balanced";
    else cout << "Unbalanced";
    return 0;
}