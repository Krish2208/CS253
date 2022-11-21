#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node *parent;
    Node(int val)
    {
        data = val;
        left = right = parent = NULL;
    }
};
void inorder(struct Node *node)
{
    if (node == NULL)
    {
        return;
    }
    else
    {
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }
};
void insertNode(Node *&root, int key)
{
    Node *nn = new Node(key);
    Node *prev = root;
    while (1)
    {
        if (key < prev->data && prev->left != NULL)
            prev = prev->left;
        else if (key > prev->data && prev->right != NULL)
            prev = prev->right;
        else if (key < prev->data)
        {
            prev->left = nn;
            nn->parent = prev;
            break;
        }
        else if (key > prev->data)
        {
            prev->right = nn;
            nn->parent = prev;
            break;
        }
    }
}
struct Node* minValueNode(struct Node* Node)
{
    struct Node* current = Node;
    while (current && current->left != NULL)
        current = current->left; 
    return current;
}
struct Node* deleteNode(struct Node* root, int key)
{
    if (root == NULL)
        return root;
    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        if (root->left==NULL && root->right==NULL)
            return NULL;
        else if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        struct Node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}
int main()
{
    int n, x;
    cin >> n;
    Node *root = NULL;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        Node *nn = new Node(x);
        Node *prev = root;
        if (i == 0)
        {
            root = nn;
        }
        else
        {
            while (1)
            {
                if (x < prev->data && prev->left != NULL)
                    prev = prev->left;
                else if (x > prev->data && prev->right != NULL)
                    prev = prev->right;
                else if (x < prev->data)
                {
                    prev->left = nn;
                    nn->parent = prev;
                    break;
                }
                else if (x > prev->data)
                {
                    prev->right = nn;
                    nn->parent = prev;
                    break;
                }
            }
        }
    }
    inorder(root);
    int y;
    cin >> y;
    root = deleteNode(root, y);
    inorder(root);
    return 0;
}