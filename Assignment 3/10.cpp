#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *link;
};

void traverse(struct Node *ptr)
{
    printf("%d\n", ptr->data);
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

bool check(int n, int x, Node* HEAD){
    int a, b;
    Node* temp = HEAD;
    for(int i = 0; i<n-x; i++){
        if(i==x){
            a = temp->data;
        }
        if(i==n-x-1){
            b=temp->data;
        }
        temp=temp->link;
    }
    return a==b;
};

int main()
{
    int n;
    cin >> n;
    Node *HEAD = NULL;
    HEAD = create(n);
    int c = 0;
    for(int i =0; i<n/2; i++){
        if(!check(n,i,HEAD)) c++;
    }
    if(c==0){
        cout << "Palindrome" << endl;
    }
    else{
        cout << "Not a Palindrome" << endl;
    }
}