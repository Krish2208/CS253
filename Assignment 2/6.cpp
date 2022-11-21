#include<iostream>
using namespace std;

int factorial(int* a){
    int c = 1;
    for(int i = *a; i>1; i--){
        c*=i;
    }
    return c;
};

int main() {
    int a;
    cin>>a;
    cout << factorial(&a);
}