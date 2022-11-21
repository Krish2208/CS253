#include <iostream>
using namespace std;

struct Node{
    int data;
    Node * link;
};

void traverse(struct Node* ptr){
    printf("%d\n", ptr->data);
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
    Node* HEAD = NULL;
    HEAD = create(n);
    cout << "Delete\n1: First\n2: Mid\n 3: Last" << endl;
    int op;
    cin >> op;
    int ind;
    if(op==1){
        Node * temp = HEAD;
        HEAD = HEAD->link;
        free(temp);
    }
    else if(op==2){
        cin >> ind;
        Node * temp = HEAD;
        Node * prev = NULL;
        for(int i=0; i<ind; i++){
            prev = temp;
            temp = temp->link;
        }
        prev->link = temp->link;
        free(temp);
    }
    else{
        Node * temp = HEAD;
        Node * prev = NULL;
        while(temp->link!=NULL){
            prev = temp;
            temp = temp->link;
        }
        prev->link = NULL;
        free(temp);
    }
    traverse(HEAD);
    return 0;
}