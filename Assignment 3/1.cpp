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
    Node* HEAD = NULL;
    Node* temp = NULL;
    for(int i = 0; i<n; i++){
        cin >> x;
        if(i==0){
            Node* new_node = (struct Node*)malloc(sizeof(struct Node));
            new_node->data = x;
            temp = new_node;
            HEAD = new_node;
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
    return HEAD;
};

int main(){
    int n;
    cin >> n;
    Node* HEAD = create(n);
    traverse(HEAD);
    return 0;
}