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

int main()
{
    struct Node* HEAD;
    struct Node* first;
    struct Node* second;
    struct Node* third;
    
    HEAD = (struct Node*)malloc(sizeof(struct Node));
    first = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));

    HEAD = first;
    first->data = 5;
    first->link = second;
    second->data = 10;
    second->link = third;
    third->data = 15;
    third->link = NULL;

    Node* temp = HEAD;
    while(temp!=NULL){
        Node* temp2 = temp->link;
        while(temp2!=NULL){
            if(temp2->link==temp){
                cout<< "Loop";
                return 0;
            }
            temp2=temp2->link;
        }
        temp=temp->link;
    }

    return 0;
}
