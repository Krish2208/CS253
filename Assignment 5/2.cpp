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

void push(Node *&TOP)
{
    int new_data;
    cin >> new_data;
    Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->link = TOP;
    TOP = new_node;
}

void pop(Node *&TOP)
{
    if (TOP == NULL)
    {
        cout << "Stack Underflow" << endl;
    }
    else
    {
        Node *temp = TOP;
        cout << TOP->data << endl;
        TOP = TOP->link;
        free(temp);
    }
}

int main()
{
    Node *TOP = NULL;
    cout << endl;
    int op;
    while (1)
    {
        cout << "Enter 1(Push), 2(Pop), 3(Traverse), 4(Quit) : ";
        cin >> op;
        if (op == 1)
            push(TOP);
        else if (op == 2)
            pop(TOP);
        else if (op == 3)
        {
            traverse(TOP);
            cout << endl;
        }
        else if (op == 4)
            break;
    }
    return 0;
}