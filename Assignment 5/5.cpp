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

void check(string &ex, stack &a)
{
    int v1,v2,opera,ans;
    for(int i =0; i<ex.length(); i++){
        if(ex[i] == '+' || ex[i] == '-' || ex[i] =='*' || ex[i] == '/'){
            v1 = a.pop();
            v2 = a.pop();
            if(ex[i]=='+') ans = v2+v1;
            else if(ex[i]=='-') ans = v2-v1;
            else if(ex[i]=='*') ans = v2*v1;
            else if(ex[i]=='/') ans = v2/v1;
            a.push(ans);
        }
        else{
            a.push(ex[i]-'0');
        }
    }
    cout << a.peek();
}

int main()
{
    string ex;
    cin >> ex;
    stack a(ex.length());
    check(ex, a);
    return 0;
}