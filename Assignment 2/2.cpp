#include<iostream>
using namespace std;

int maximum(int* a, int* b){
    if(*a > *b) return *a;
    return *b;
};

int main() {
    int a = 5;
    int b = 6;
    cout << maximum(&a, &b);
}