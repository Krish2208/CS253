#include<iostream>
#include<string.h>
using namespace std;

int main() {
    string c = "abcd";
    int i = 0;
    char* a = &c[0];
    while (*a!='\0'){
        a++;
        i++;
    }
    cout << i;
}