#include <iostream>
using namespace std;

struct Node{
    int data;
    Node * link;
};

void traverse(struct Node* ptr){
    cout << ptr->data << " ";
    if(ptr->link!=NULL){
        traverse(ptr->link);
    }
};

Node* create(int n){
    int x;
    Node* TOP = NULL;
    Node* temp = NULL;
    for(int i = 0; i<n; i++){
        cin >> x;
        if(i==0){
            Node* new_node = (struct Node*)malloc(sizeof(struct Node));
            new_node->data = x;
            temp = new_node;
            TOP = new_node;
        }
        else if(i==n-1){
            Node* new_node = (struct Node*)malloc(sizeof(struct Node));
            new_node->data = x;
            temp->link = new_node;
            new_node->link = NULL;
        }
        else{
            Node* new_node = (struct Node*)malloc(sizeof(struct Node));
            new_node->data = x;
            temp->link = new_node;
            temp = new_node;
        }
    }
    return TOP;
};

Node* push(Node* TOP){
    int new_data;
    cin>> new_data;
    Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data=new_data;
    new_node->link=TOP;
    return new_node;
}

Node* pop(Node* TOP){
    Node * temp = TOP;
    TOP = TOP->link;
    free(temp);
    return TOP;
}

int main(){
    int n;
    cin >> n;
    Node* TOP = NULL;
    TOP = create(n);
    traverse(TOP);
    cout << endl;
    TOP = push(TOP);
    traverse(TOP);
    TOP = pop(TOP);
    cout << endl;
    traverse(TOP);
    return 0;
}