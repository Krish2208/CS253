#include<iostream>
#include<string.h>
using namespace std;

int main() {
    string c;
    cin >> c;
    for(int i = 0; i<c.length(); i++){
        for(int j=i+1; j<c.length(); j++){
            char temp = c[i];
            c[i] = c[j];
            c[j] = temp;
            cout << c << endl;
            temp = c[i];
            c[i] = c[j];
            c[j] = temp;
        }
    }
}