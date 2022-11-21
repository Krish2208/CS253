#include <iostream>
using namespace std;

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

class MinHeap
{
    int *arr;
    int capacity;
    int c_size;

public:
    MinHeap(int cap)
    {
        c_size = 0;
        capacity = cap;
        arr = new int[cap];
    }
    int left(int key)
    {
        return key * 2;
    }
    int right(int key)
    {
        return 1 + key * 2;
    }
    int parent(int key)
    {
        return key / 2;
    }
    void Balance(int i)
    {
        int l = left(i);
        int r = right(i);
        int smallest = i;
        if (l < c_size && arr[l] < arr[i])
            smallest = l;
        if (r < c_size && arr[r] < arr[smallest])
            smallest = r;
        if (smallest != i)
        {
            swap(&arr[i], &arr[smallest]);
            Balance(smallest);
        }
    }
    int insert(int k)
    {
        if (c_size == capacity)
        {
            cout << "Heap Full Cannot Insert More!";
            return -1;
        }
        arr[c_size] = k;
        c_size++;
        int i = c_size - 1;
        while (i != 0 && arr[parent(i)] > arr[i])
        {
            swap(&arr[i], &arr[parent(i)]);
            i = parent(i);
        }
    }
    int del(int i)
    {
        int root = arr[0];
        arr[0] = arr[c_size - 1];
        c_size--;
        Balance(0);
        return root;
    }
    void display()
    {
        for (int i = 0; i < c_size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    int n, x;
    cout << "Enter the Number of Elements: ";
    cin >> n;
    MinHeap h(n);
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        h.insert(x);
    }
    for (int i = 0; i < n; i++)
    {
        cout << h.del(0) << " ";
    }
    return 0;
}