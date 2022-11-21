#include<iostream>
using namespace std;
class Stacks{
    public:
    int *a;
    int size;
    int front;
    int rear;
    Stacks(int n){
        size= n;
        a= new int[n];
        front=-1;
        rear=-1;
    }
    void enqueue(int data){
        if(front==-1 && rear==-1){
            front=0;
            rear=0;
            a[rear]= data;
            
        }
        else if(rear==(size-1)){
            cout<<rear<<endl;
            cout<<"Stack Overflow"<<endl;
        }
        else{
            rear= rear+1;
            a[rear]= data;
        }
    }
    int dequeue(){
    if(rear==-1 && front==-1){
        cout<<"Stack Underflow"<<endl;
        return 0;
    }
    else if(front==0 && rear==0){
        int k;
        k=a[front];
        front = -1;
        rear= -1;
        return k;
    }
    else{
        int k;
        k=a[front];
        front= front+1;
        return k;
    }
   }
   void display(){
    if(front==-1){
        cout<<"Empty"<<endl;
    }
    else if(front<=rear){
        for (int i = front; i <= rear; i++)
        {
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }
   }
   void push_in_stack(){
    int b[size];
    int i=0;
    int temp= front;
    while(temp!= rear+1 && rear!=-1){
        b[i]= dequeue();
        i=i+1;
        temp= temp+1;
    }
    cout<<i<<endl;

    for (int j = 0; j < i/2; j++)
    {
        int k= b[j];
        b[j]=b[i-j-1];
        b[i-j-1]= k;
    }
    front= 0;
    rear= i-1;
    for (int l = 0; l < i; l++)
    {
        a[l]= b[l];
    }
    
   }
   void pop_from_stack(){
    cout<<dequeue()<<endl;
   } 
};
int main(){
    int size;
    cin>>size;
    Stacks s(size);
    char k;
    do{
        int data;
        cin>>data;
        s.enqueue(data);
        cin>>k;
    }while(k=='y');
    s.display();
    s.push_in_stack();
    s.display();
    s.pop_from_stack();
    s.display();
    return 0;
}