#include<iostream>
using namespace std;

int main() {
    int a[3][3] = {{1,2,3}, {4,5,6}, {7,8,9}};
    int b[3][3] = {{1,2,3}, {4,5,6}, {1,1,1}};

    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            int sum = 0;
            for(int k=0; k<3; k++){
                sum+=(*(*(a+i)+k)) * (*(*(b+k)+j));
            }
            cout << sum << " ";
        }
        cout << endl;
    }
}