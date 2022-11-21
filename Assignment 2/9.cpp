#include<iostream>
#include<string.h>
using namespace std;

int main() {
    string c = "abcd";
    char * p = &c[c.length()-1];
    for(int i = 0; i<c.length(); i++){
        cout << *p;
        p--;
    }
}