#include <iostream>
using namespace std;

int main(){
    int arr[9] = {2,1,5,6,7,2,1,7,8};
    int count = 0;
    for(int i = 0; i<sizeof(arr)/sizeof(arr[0]); i++){
        int k = 0;
        for(int j = 0; j<i; j++){
            if (arr[j]==arr[i]){
                k++;
            }
        }
        if(k==0){
            count++;
        }
    }
    cout << count;
    return 0;
}