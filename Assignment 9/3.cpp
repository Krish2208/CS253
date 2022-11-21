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
int findDepth(Node *root, int x)
{
    if (root == NULL)
        return -1;
    int dist = -1;
    if ((root->data == x) || (dist = findDepth(root->left, x)) >= 0 || (dist = findDepth(root->right, x)) >= 0)
        return dist + 1;
    return dist;
}
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
int findDiameter(Node *root, int n1, int n2)
{
    int lca = findLCA(root, n1, n2);
    int d1 = findDepth(root, n1);
    int d2 = findDepth(root, n2);
    int d3 = findDepth(root, lca);
    return d1 + d2 - (2 * d3);
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
    cout << findDiameter(root,12,18);
    return 0;
}