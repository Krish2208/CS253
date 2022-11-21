#include <iostream>
using namespace std;
class node
{
public:
    float data;
    float num;
    float deno;
    node *next;
    node(float n, float d)
    {
        data = n / d;
        num = n;
        deno = d;
        next = NULL;
    }
};
node *insert_in_list(node *head, float n, float d)
{
    if (head == NULL)
    {
        return (new node(n, d));
    }
    node *node1 = new node(n, d);
    node1->next = head;
    head = node1;
    return head;
}
void heap(float arr[], int size, int root)
{
    int max = root;
    int left = 2 * root + 1;
    int right = 2 * root + 2;
    if (left < size && arr[max] < arr[left])
    {
        max = left;
    }
    if (right < size && arr[max] < arr[right])
    {
        max = right;
    }
    if (max != root)
    {
        float temp = arr[root];
        arr[root] = arr[max];
        arr[max] = temp;
        heap(arr, size, root);
    }
}
void build_heap(float arr[], int size)
{
    for (int i = (size / 2) - 1; i >= 0; i--)
    {
        heap(arr, size, i);
    }
}
float get_priority_element(float arr[], int size)
{
    float ans = arr[0];
    arr[0] = arr[size - 1];
    arr[size - 1] = 0;
    size = size - 1;
    build_heap(arr, size);
    return ans;
}
int main()
{
    int size;
    cin >> size;
    float prime[size];
    for (int i = 0; i < size; i++)
    {
        int data;
        cin >> data;
        prime[i] = data;
    }
    int k;
    cin >> k;
    node *head = NULL;
    int num_of_frac = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            head = insert_in_list(head, prime[i], prime[j]);
            num_of_frac = num_of_frac + 1;
        }
    }
    float max_heap[num_of_frac];
    node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        max_heap[count] = temp->data;
        count = count + 1;
        temp = temp->next;
    }
    build_heap(max_heap, num_of_frac);
    float ans;
    for (int i = 0; i <= (num_of_frac - k); i++)
    {
        ans = get_priority_element(max_heap, num_of_frac);
    }
    // cout<<ans;
    temp = head;
    while (temp->data != ans)
    {
        temp = temp->next;
    }
    int ans_matrix[2];
    ans_matrix[0] = temp->num;
    ans_matrix[1] = temp->deno;
    cout << "[" << ans_matrix[0] << "," << ans_matrix[1] << "]" << endl;
    return 0;
}