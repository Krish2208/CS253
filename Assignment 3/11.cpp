#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *link;
};

void traverse(struct Node *ptr)
{
    cout << ptr->data << " ";
    if (ptr->link != NULL)
    {
        traverse(ptr->link);
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
            temp = new_node;
            HEAD = new_node;
        }
        else if (i == n - 1)
        {
            Node *new_node = (struct Node *)malloc(sizeof(struct Node));
            new_node->data = x;
            temp->link = new_node;
            new_node->link = NULL;
        }
        else
        {
            Node *new_node = (struct Node *)malloc(sizeof(struct Node));
            new_node->data = x;
            temp->link = new_node;
            temp = new_node;
        }
    }
    return HEAD;
};

void u(Node *Head1, Node *Head2)
{
    Node *temp1 = Head1;
    Node *temp2 = Head2;
    while(temp1!=NULL){
        cout << temp1->data << " ";
        temp1=temp1->link;
    }
    while(temp2!=NULL){
        temp1=Head1;
        int c = 0;
        while(temp1!=NULL){
            if(temp2->data==temp1->data) c++;
            temp1 = temp1->link;
        }
        if(c==0) cout << temp2->data << " ";
        temp2 = temp2->link;
    }
};

void i(Node *Head1, Node *Head2)
{
    Node *temp1 = Head1;
    Node *temp2 = Head2;
    while(temp2!=NULL){
        temp1=Head1;
        int c = 0;
        while(temp1!=NULL){
            if(temp2->data==temp1->data) c++;
            temp1 = temp1->link;
        }
        if(c!=0) cout << temp2->data << " ";
        temp2 = temp2->link;
    }
};

int main()
{
    int n, m;
    cout<<"Length of List 1: ";
    cin >> n;
    Node *HEAD = NULL;
    HEAD = create(n);
    cout << "Length of List 2: ";
    cin >> m;
    Node *HEAD2 = create(m);
    cout<<"List 1: ";
    traverse(HEAD);
    cout<<"\nList 2: ";
    traverse(HEAD2);
    cout << "\nUnion: ";
    u(HEAD, HEAD2);
    cout << "\nIntersection: ";
    i(HEAD,HEAD2);
}