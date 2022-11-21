#include <iostream>
using namespace std;

int main(){
    int arr[7] = {1,2,5,8,6,9,7};
    int largest, second_largest;
    largest = arr[0];
    second_largest = arr[0];
    for(int i=0; i<sizeof(arr)/sizeof(arr[0]); i++){
        if (arr[i]> largest){
            largest = arr[i];
        }
    }
    for(int i=0; i<sizeof(arr)/sizeof(arr[0]); i++){
        if ((arr[i]> second_largest) && (arr[i]<largest)){
            second_largest = arr[i];
        }
    }
    cout << second_largest;
    return 0;
}