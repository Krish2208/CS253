#include <iostream>
using namespace std;

struct Node
{
    int data;
    int pow;
    struct Node *link;
};

void traverse(struct Node *ptr)
{
    printf("%dx**%d\n", ptr->data, ptr->pow);
    if (ptr->link != NULL)
    {
        traverse(ptr->link);
    }
};

Node *create(int n)
{
    int x, p;
    Node *HEAD = NULL;
    Node *temp = NULL;
    for (int i = 0; i < n; i++)
    {
        cin >> x >> p;
        if (i == 0)
        {
            Node *new_node = (struct Node *)malloc(sizeof(struct Node));
            new_node->data = x;
            new_node->pow = p;
            temp = new_node;
            HEAD = new_node;
        }
        else if (i == n - 1)
        {
            Node *new_node = (struct Node *)malloc(sizeof(struct Node));
            new_node->data = x;
            new_node->pow = p;
            temp->link = new_node;
            new_node->link = NULL;
        }
        else
        {
            Node *new_node = (struct Node *)malloc(sizeof(struct Node));
            new_node->data = x;
            new_node->pow = p;
            temp->link = new_node;
            temp = new_node;
        }
    }
    return HEAD;
};

int main()
{
    int n1;
    cin >> n1;
    Node *HEAD = create(n1);
    int n2;
    cin >> n2;
    Node *HEAD2 = create(n2);
    Node *HEAD3 = (struct Node *)malloc(sizeof(struct Node));
    Node *temp3 = HEAD3;
    Node *temp1 = HEAD;
    Node *temp2 = HEAD2;
    while (temp1 && temp2)
    {
        if (temp1->pow < temp2->pow)
        {
            temp3->data = temp2->data;
            temp3->pow = temp2->pow;
            temp2 = temp2->link;
        }
        else if (temp1->pow > temp2->pow)
        {
            temp3->data = temp1->data;
            temp3->pow = temp1->pow;
            temp1 = temp1->link;
        }
        else
        {
            temp3->data = temp1->data + temp2->data;
            temp3->pow = temp1->pow;
            temp1 = temp1->link;
            temp2 = temp2->link;
        }
        temp3->link = (struct Node *)malloc(sizeof(struct Node));
        temp3 = temp3->link;
        temp3->link = NULL;
    }
    traverse(HEAD3);
    return 0;
}
