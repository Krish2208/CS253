#include <iostream>
using namespace std;

int main(){
    int arr[8] = {2,1,5,8,6,9,7,10};
    int temp;
    for(int i=0; i<(sizeof(arr)/sizeof(arr[0]))/2; i++){
        temp = arr[i];
        arr[i]=arr[(sizeof(arr)/sizeof(arr[0]))-i-1];
        arr[(sizeof(arr)/sizeof(arr[0]))-i-1] = temp;
    }
    for(int i=0; i<(sizeof(arr)/sizeof(arr[0])); i++){
        cout << arr[i] << " ";
    }
    return 0;
}