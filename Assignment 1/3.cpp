#include <iostream>
using namespace std;

int binary_search(int ele, int* arr, int low, int high){
    while(low!=high){
        int mid = (low+high)/2;
        if(arr[mid]==ele){
            return mid;
        }
        else{
            if(ele<arr[mid]){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
    }
    return -1;
};

int main(){
    int arr[6] = {1,2,5,7,8,6};
    int ele = 5;
    cout << binary_search(ele, arr, 0, sizeof(arr)/sizeof(arr[0])-1);
    return 0;
}