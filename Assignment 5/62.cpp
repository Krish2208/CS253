#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *link;
};
struct Queue
{
    Node *front;
    Node *rear;
};
void enqueue(Queue *q, int k)
{
    Node *node1 = new Node();
    node1->data = k;
    if (q->front == NULL)
    {
        q->front = node1;
    }
    else
    {
        q->rear->link = node1;
    }
    q->rear = node1;
    q->rear->link = q->front;
}
void dequeue(Queue *q)
{
    if (q->front == NULL)
    {
        cout << "Queue is empty" << endl;
    }
    else if (q->front == q->rear)
    {
        cout << q->front->data << endl;
        free(q->front);
        q->front = NULL;
        q->rear = NULL;
    }
    else
    {
        Node *temp = q->front;
        cout << q->front->data << endl;
        q->front = q->front->link;
        q->rear->link = q->front;
        free(temp);
        temp = NULL;
    }
}
void display(Queue *q)
{
    Node *temp = q->front;
    do
    {
        cout << temp->data << " ";
        temp = temp->link;
    } while (temp != q->front);
    cout << endl;
}

int main()
{
    Queue *q = new Queue();
    q->front = NULL;
    q->rear = NULL;
    char k;
    do
    {
        int data;
        cin >> data;
        enqueue(q, data);
        cin >> k;
    } while (k == 'y');
    display(q);
    dequeue(q);
    display(q);
    return 0;
}