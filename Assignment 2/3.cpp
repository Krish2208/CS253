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
    for(int i = 0; i<n; i++){
        cout << *(arr+i)<< endl;
    }
}