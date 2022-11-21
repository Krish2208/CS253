#include<iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n];
    int temp;
    int in;
    for(int i = 0; i<n; i++){
        cin >> in;
        *(arr+i)=in;
    }
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(arr[i]>arr[j]){
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    for(int i = 0; i<n; i++){
        cout << *(arr+i)<< endl;
    }
}