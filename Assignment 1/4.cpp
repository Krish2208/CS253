#include <iostream>
using namespace std;

bool search(int *arr, int ele, int length){
    for(int i = 0; i<length; i++){
        if(arr[i]==ele){
            return 1;
        }
    }
    return 0;
};

int main(){
    int arr[9] = {2,1,5,6,7,2,1,7,8};
    int new_arr[9];
    int j = 0;
    int length = sizeof(arr)/sizeof(arr[0]);
    for(int i = 0; i<length; i++){
        if(!search(new_arr, arr[i], length)){
            new_arr[j] = arr[i];
            j++;
        }
    }
    for(int i=0; i<length; i++){
        cout << new_arr[i] << " ";
    }
    return 0;
}