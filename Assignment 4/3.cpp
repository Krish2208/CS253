#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
    Node *prev;
};

void traverse(struct Node *ptr, Node* HEAD)
{
    cout << ptr->data << " ";
    if (ptr->next != HEAD)
    {
        traverse(ptr->next, HEAD);
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
            new_node->next = HEAD;
            HEAD->prev = new_node;
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

Node* rotate(Node * HEAD){
	int n;
	cin >> n;
	for(int i = 0; i< n; i++){
		HEAD = HEAD->next;
	}
	return HEAD;
}

int main()
{
    int n;
    cin >> n;
    Node *HEAD = create(n);
    traverse(HEAD, HEAD);
    cout << endl;
    HEAD = rotate(HEAD);
    traverse(HEAD, HEAD);
    return 0;
}