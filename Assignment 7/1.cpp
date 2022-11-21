#include <iostream>
using namespace std;
int main()
{
    int n, x;
    cout << "Enter the Number of Elements";
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        a[i] = x;
    }
    int t = 0;
    for (int j = 0; j < (n / 2 + 1); j++)
    {
        if ((2 * j + 1) < n)
        {
            if (a[j] > a[j * 2] || a[j] > a[j * 2 + 1])
                t = 1;
        }
        else if (2 * j < n)
        {
            if (a[j] > a[j * 2])
                t = 1;
        }
    }
    if (t == 0)
    {
        cout << "Min-Heap";
    }
    else
        cout << "Not a Min-Heap";
    return 0;
}
