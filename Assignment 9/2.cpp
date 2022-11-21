#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};
bool findPath(Node *root, vector<int> &path, int k)
{
    if (root == NULL)
        return false;
    path.push_back(root->data);
    if (root->data == k)
        return true;
    if ((root->left && findPath(root->left, path, k)) || (root->right && findPath(root->right, path, k)))
        return true;
    path.pop_back();
    return false;
}
int findLCA(Node *root, int n1, int n2)
{
    vector<int> path1, path2;
    if (!findPath(root, path1, n1) || !findPath(root, path2, n2))
        return -1;
    int i;
    for (i = 0; i < path1.size() && i < path2.size(); i++)
        if (path1[i] != path2[i])
            break;
    return path1[i - 1];
}
int main()
{
    struct Node *root = new Node(10);
    root->left = new Node(8);
    root->right = new Node(16);
    root->left->left = new Node(5);
    root->left->right = new Node(9);
    root->right->right = new Node(18);
    root->right->left = new Node(14);
    root->right->left->left = new Node(12);
    cout << findLCA(root, 18, 12);
    return 0;
}