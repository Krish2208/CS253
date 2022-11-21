#include <iostream>
using namespace std;

int main(){
    int arr[7] = {2,1,5,8,6,9,7};
    int largest, smallest;
    largest = arr[0];
    smallest = arr[0];
    for(int i=0; i<sizeof(arr)/sizeof(arr[0]); i++){
        if (arr[i]> largest){
            largest = arr[i];
        }
        if (arr[i]< smallest){
            smallest = arr[i];
        }
    }
    cout << "Maximum: " << largest << "\nMinimum: " << smallest;
    return 0;
}