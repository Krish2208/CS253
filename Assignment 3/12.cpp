#include <iostream>
using namespace std;

struct Node{
    int data;
    Node * link;
};

void traverse(Node* ptr, Node* HEAD){
    printf("%d\n", ptr->data);
    if(ptr->link!=HEAD){
        traverse(ptr->link, HEAD);
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
            new_node->link = HEAD;
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
    Node* HEAD = NULL;
    HEAD = create(n);
    cout << "\n";
    Node * temp4 = HEAD;
    Node * prev = NULL;
    Node * next = HEAD->link;
    do {
        next = temp4->link;
        temp4->link = prev;
        prev = temp4;
        temp4 = next;
    }
    while(temp4!=HEAD);
    HEAD->link=prev;
    HEAD = prev;
    traverse(HEAD, HEAD);
    return 0;
}