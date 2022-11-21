#include <iostream>
#include <vector>
#include <climits>
using namespace std;
class node
{
public:
    int weight;
    int parent;
    int index;
    node()
    {
        weight = INT_MAX;
        parent = -1;
        index = 0;
    }
};
void heap(node *arr[], int size, int root)
{
    int min = root;
    int left = 2 * root + 1;
    int right = 2 * root + 2;
    if (left < size && (arr[min]->weight) > (arr[left]->weight))
    {
        min = left;
    }
    if (right < size && (arr[min]->weight) > (arr[right]->weight))
    {
        min = right;
    }
    if (min != root)
    {
        node *temp = arr[root];
        arr[root] = arr[min];
        arr[min] = temp;
        heap(arr, size, root);
    }
}
void build_heap(node *arr[], int size)
{
    for (int i = (size / 2) - 1; i >= 0; i--)
    {
        heap(arr, size, i);
    }
}
node *get_priority_element(node *arr[], int size)
{
    node *n = arr[0];
    node *temp = arr[size - 1];
    arr[0] = temp;
    arr[size - 1] = NULL;
    size = size - 1;
    build_heap(arr, size);
    return n;
}
int nodes;
void dij_path(vector<vector<int>> matrix, int start)
{
    node *arr[nodes];
    for (int i = 0; i < nodes; i++)
    {
        arr[i] = new node();
    }
    arr[start]->weight = 0;
    arr[start]->index = start;
    arr[start]->parent = -1;
    for (int i = 0; i < nodes; i++)
    {
        if (i != start)
        {
            arr[i]->parent = -1;
            arr[i]->weight = matrix[start][i];
            arr[i]->index = i;
        }
    }
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<node *> a_iter(arr, arr + n);
    build_heap(arr, nodes);
    node *k1 = get_priority_element(arr, nodes);
    int count = 0;
    while (arr[0] != NULL)
    {
        count = count + 1;
        node *temp = get_priority_element(arr, nodes - count);
        printf("%d\t%d\n", temp->index, temp->weight);
        for (int k = 0; k < nodes - count - 1; k++)
        {
            for (int i = 0; i < nodes; i++)
            {
                if (arr[k]->index == i)
                {
                    if (matrix[temp->index][i] != INT_MAX && temp->weight!=INT_MAX  && ((matrix[temp->index][i] + temp->weight) <= (arr[k]->weight) && (i != temp->index)))
                    {
                        arr[k]->weight = ((matrix[temp->index][i]) + (temp->weight));
                        arr[k]->parent = temp->index;
                    }
                }
            }
        }
    }
}
int main()
{
    vector<vector<int>> matrix;
    vector<int> r1({0, 3, 8, INT_MAX, 4});
    vector<int> r2({INT_MAX, 0, INT_MAX, 1, 7});
    vector<int> r3({INT_MAX, 4, 0, 0, INT_MAX});
    vector<int> r4({INT_MAX, INT_MAX, 5, 0, INT_MAX});
    vector<int> r5({INT_MAX, INT_MAX, INT_MAX, 6, 0});
    matrix.push_back(r1); matrix.push_back(r2); matrix.push_back(r3); matrix.push_back(r4); matrix.push_back(r5);
    cin>>nodes;
    int start;
    cin>>start;
    dij_path(matrix, start);
    return 0;
}