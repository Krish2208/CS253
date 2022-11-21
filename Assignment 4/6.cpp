#include <iostream>
using namespace std;

class stacks
{
    int *arr;
    int size;
    int t1;
    int t2;

public:
    stacks(int n)
    {
        size = n;
        arr = new int[n];
        t1 = 0;
        t2 = n;
    }
    void push1(int a)
    {
        if (t1 == t2 )
        {
            cout << "Stack Overflow" << endl;
        }
        else
        {
            arr[t1] = a;
            t1++;
        }
    }
    void push2(int a)
    {
        if (t1 == t2 )
        {
            cout << "Stack Overflow" << endl;
        }
        else
        {
            arr[t2] = a;
            t2--;
        }
    }
    void pop1()
    {
        if (t1 == 0)
        {
            cout << "Stack1 Underflow" << endl;
        }
        else
        {
            t1--;
            cout << arr[t1] << endl;
        }
    }
    void pop2()
    {
        if (t2 == size)
        {
            cout << "Stack2 Underflow" << endl;
        }
        else
        {
            t2++;
            cout << arr[t2] << endl;
        }
    }
};

int main()
{
    stacks a(2);
    a.push1(4);
    a.pop1();
    a.pop1();
    a.pop2();
    a.push2(5);
    a.push2(6);
    a.push2(4);
    return 0;
}