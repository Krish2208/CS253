#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
    Node *prev;
};

void traverse(struct Node *ptr)
{
    cout << ptr->data << " ";
    if (ptr->next != NULL)
    {
        traverse(ptr->next);
    }
};

Node *create(int n)
{
    int x;
    Node *HEAD = NULL;
    Node *temp = NULL;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        if (i == 0)
        {
            Node *new_node = (struct Node *)malloc(sizeof(struct Node));
            new_node->data = x;
            new_node->prev = NULL;
            temp = new_node;
            HEAD = new_node;
        }
        else if (i == n - 1)
        {
            Node *new_node = (struct Node *)malloc(sizeof(struct Node));
            new_node->data = x;
            new_node->prev = temp;
            temp->next = new_node;
            new_node->next = NULL;
        }
        else
        {
            Node *new_node = (struct Node *)malloc(sizeof(struct Node));
            new_node->data = x;
            new_node->prev = temp;
            temp->next = new_node;
            temp = new_node;
        }
    }
    return HEAD;
};

Node *insertFirst(Node *HEAD)
{
    int new_data;
    cin >> new_data;
    Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = HEAD;
    HEAD->prev = new_node;
    new_node->prev = NULL;
    HEAD = new_node;
    return HEAD;
}

Node *insertLast(Node *HEAD)
{
    int new_data;
    cin >> new_data;
    Node* temp = HEAD;
    Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = new_data;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=new_node;
    new_node->prev=temp;
    new_node->next=NULL;
    return HEAD;
}

Node *insertMiddle(Node *HEAD)
{
    int new_data, position;
    cin >> position >> new_data;
    Node* temp = HEAD;
    Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = new_data;
    for(int i = 0; i<position-1; i++){
        temp=temp->next;
    }
    new_node->next = temp->next;
    new_node->next->prev = new_node;
    temp->next=new_node;
    new_node->prev=temp;
    return HEAD;
}

Node *deleteFirst(Node *HEAD)
{
    Node* temp = HEAD;
    HEAD->next->prev = NULL;
    HEAD = HEAD->next;
    free(temp);
    return HEAD;
}

Node *deleteLast(Node *HEAD)
{
    Node* temp = HEAD;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->prev->next=NULL;
    free(temp);
    return HEAD;
}

Node *deleteMiddle(Node *HEAD)
{
    int position;
    cin >> position;
    Node* temp = HEAD;
    for(int i = 0; i<position-1; i++){
        temp=temp->next;
    }
    temp->prev->next=temp->next;
    temp->next->prev=temp->prev;
    free(temp);
    return HEAD;
}

int main()
{
    int n;
    cin >> n;
    Node *HEAD = create(n);
    traverse(HEAD);
    cout << endl;
    HEAD = insertFirst(HEAD);
    traverse(HEAD);
    cout << endl;
    HEAD = insertLast(HEAD);
    traverse(HEAD);
    cout << endl;
    HEAD = insertMiddle(HEAD);
    traverse(HEAD);
    cout << endl;
    HEAD = deleteFirst(HEAD);
    traverse(HEAD);
    cout << endl;
    HEAD = deleteLast(HEAD);
    traverse(HEAD);
    cout << endl;
    HEAD = deleteMiddle(HEAD);
    traverse(HEAD);
    return 0;
}