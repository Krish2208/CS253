#include <iostream>
using namespace std;

struct Node
{
    int shares;
    int value;
    Node *link;
};
struct Queue
{
    Node *front;
    Node *rear;
};
void enqueue(Queue *q, int s, int v)
{
    Node *trade = new Node();
    trade->shares = s;
    trade->value = v;
    if (q->front == NULL)
    {
        q->front = trade;
    }
    else
    {
        q->rear->link = trade;
    }
    q->rear = trade;
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
        free(q->front);
        q->front = NULL;
        q->rear = NULL;
    }
    else
    {
        Node *temp = q->front;
        q->front = q->front->link;
        q->rear->link = q->front;
        free(temp);
        temp = NULL;
    }
}
void buy(Queue *q, int s, int v)
{
    enqueue(q, s, v);
}
void sell(Queue *q, int s, int v)
{
    if (q->front == NULL)
    {
        cout << "Busted! You cannot sell, before buying" << endl;
    }
    else
    {
        int total = 0;
        Node *temp = q->front;
        do
        {
            total += temp->shares;
            temp = temp->link;
        } while (temp != q->front);
        if (total >= s)
        {
            int capital = 0;
            while (s)
            {
                if (q->front->shares < s)
                {
                    s -= q->front->shares;
                    capital += q->front->shares * (v - q->front->value);
                    dequeue(q);
                }
                else
                {
                    q->front->shares -= s;
                    capital += q->front->shares * (v - q->front->value);
                    s = 0;
                }
            }
            if(capital>=0) cout << "Capital Gain : " << capital << endl;
            else cout << "Capital Loss : " << capital << endl;
        }
        else{
            cout << "Busted! You cannot sell more shares than you hold!" << endl;
        }
    }
}

int main()
{
    Queue *q = new Queue();
    q->front = NULL;
    q->rear = NULL;
    char k;
    // OPERATION NUMBER_OF_SHARES VALUE
    // 0 -> BUY, 1->SELL
    int op, n, v;
    do
    {
        cin >> op >> n >> v;
        if(op==0){
            buy(q, n, v);
        }
        else if(op==1){
            sell(q, n, v);
        }
        else cout << "Operation should be Buy(0) or Sell(1) only." << endl;
        cin >> k;
    } while (k == 'y');
    return 0;
}