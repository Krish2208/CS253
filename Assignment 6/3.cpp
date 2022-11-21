#include <bits/stdc++.h>
using namespace std;
 
struct Node
{
    int key;
    Node *left;
    Node *right;
    int height;
    Node(){
        left = NULL;
        right = NULL;
        height = 1;
    }
};

int height(Node *currnode)
{
    if (currnode == NULL)
        return 0;
    return currnode->height;
}

Node* newNode(int key)
{
    Node* node = new Node();
    node->key = key;
    return(node);
}
 
Node *rightRotate(Node *y)
{
    Node *x = y->left;
    Node *T2 = x->right;
 
    x->right = y;
    y->left = T2;
 
    y->height = max(height(y->left),height(y->right)) + 1;
    x->height = max(height(x->left),height(x->right)) + 1;
 
    return x;
}
 
Node *leftRotate(Node *x)
{
    Node *y = x->right;
    Node *T2 = y->left;
 
    y->left = x;
    x->right = T2;

    x->height = max(height(x->left),height(x->right)) + 1;
    y->height = max(height(y->left),height(y->right)) + 1;
     return y;
}
 
int getBalance(Node *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}
 
Node* insert(Node* node, int key)
{
    if (node == NULL)
        return(newNode(key));
 
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node;
 
    node->height = 1 + max(height(node->left),height(node->right));
 
    int balance = getBalance(node);
    if(balance > 1 && key < node->left->key)
        return rightRotate(node);
 
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);
 
    if (balance > 1 && key > node->left->key)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
 
    if (balance < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}
void preOrder(Node *root)
{
    if(root != NULL)
    {
        cout << root->key << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}
void inorder(struct Node *node)
{
    if (node == NULL)
    {
        return;
    }
    else
    {
        inorder(node->left);
        cout << node->key << " ";
        inorder(node->right);
    }
};
int main()
{
    Node *root = NULL;
    int n,x;
    cout << "Enter the number of elements you want to insert in AVL tree\n";
    cin >> n;
    cout << "Enter the elements : ";
    for(int i = 0; i < n; i++){
        cin >> x;
        root = insert(root, x);
    }
    cout << "Preorder traversal of the constructed AVL tree is \n";
    preOrder(root);
    cout << endl;
    inorder(root);
    return 0;
}