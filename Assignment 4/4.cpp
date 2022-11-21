#include <iostream>
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
        if (t1 == size)
        {
            cout << "Stack Overflow" << endl;
        }
        else
        {
            arr[t1] = a;
            t1++;
        }
    }
    void pop()
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
};

int main()
{
    stack a(3);
    a.pop();
    a.push(1);
    a.push(1);
    a.push(1);
    a.push(1);
    return 0;
}