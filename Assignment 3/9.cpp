#include<iostream>
using namespace std;

struct Node
{
    int data;
    struct Node* link;
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

int main()
{   
    int n;
    cin>>n;
    Node* HEAD = create(n);
    Node* temp = HEAD;
    while(temp!=NULL){
        Node* temp2 = temp;
        while(temp2->link!=NULL){
            if(temp->data==temp2->link->data){
                Node* dup = temp2->link;
                temp2->link=temp2->link->link;
                free(dup);
            }
            else{
                temp2=temp2->link;
            }
        }
        temp=temp->link;
    }
    traverse(HEAD);
    return 0;
}
