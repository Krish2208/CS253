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

Node *reverse(Node *HEAD)
{
    Node *temp = HEAD;
    while (temp != NULL)
    {
        Node *temp2 = temp->next;
        temp->next = temp->prev;
        temp->prev = temp2;
        HEAD = temp;
        temp = temp->prev;
    }
    return HEAD;
}

int main()
{
    int n;
    cin >> n;
    Node *HEAD = create(n);
    traverse(HEAD);
    cout << endl;
    HEAD = reverse(HEAD);
    traverse(HEAD);
    return 0;
}