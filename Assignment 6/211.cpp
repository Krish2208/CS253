#include<iostream>
using namespace std;
int main(){
    int size;
    cin>>size;
    int a[size];
    for (int i = 0; i < size; i++)
    {
        cin>>a[i];
    }
    int bst[size];
    bst[0]= a[0];
    for (int i = 1; i < size; i++)
    {
        int j=0;
        // cout<<i<<endl;
        // cout<<a[i]<<endl;
        while(j<i)
        {
            if(a[i]<bst[j]){
                // cout<<bst[j]<<endl;
                j=j*2+1;
            }
            else if (a[i]>bst[j]){
                // cout<<bst[j]<<endl;
                j=j*2+2;
            }
        }
        // cout<<j<<endl;
        bst[j]=a[i];
    }
    for (int i = 0; i < size; i++)
    {
        cout<<bst[i]<<" ";
    }
    int key;
    cin>>key;
    for (int i = 0; i < size; i++)
    {
        if(bst[i]==key){
            if((2*i+1)>size && (2*i+2)>size){
                bst[i]=0;
            }
            else{
                int j=2*i+2;
                while((2*j+1)<size){
                    j= 2*j+1;
                }
                bst[i]=bst[j];
                bst[j]=0;
            }
        }
    }
    for (int i = 0; i < size; i++)
    {
        cout<<bst[i]<<" ";
    }
    cout<<endl;
    return 0;
}