#include<iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n];
    int in;
    for(int i = 0; i<n; i++){
        cin >> in;
        *(arr+i)=in;
    }
    int sum = 0;
    for(int i = 0; i<n; i++){
        sum+= *(arr+i);
    }
    cout << sum;
}