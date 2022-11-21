#include <bits/stdc++.h>
using namespace std;
 
struct Node
{
    int key;
    Node *left, *right, *parent;
    Node(){
        left = NULL;
        right = NULL;
        parent = NULL;
    }
};

Node* newNode(int key)
{
    Node* node = new Node();
    node->key = key;
    return(node);
}

Node* insert(Node* node, int key)
{
    if (node == NULL) return(newNode(key));
 
    if (key < node->key){
        node->left = insert(node->left, key);
        node->left->parent = node;
    }
    else if (key > node->key){
        node->right = insert(node->right, key);
        node->right->parent = node;
    }

    return node;
}

Node* minValueNode(Node* node)
{
    Node* current = node;
    while (current && current->left != NULL) current = current->left;
    return current;
}
  
Node* deleteNode(Node* root, int key)
{
    if (root == NULL) return root;
    if (key < root->key) root->left = deleteNode(root->left, key);
    else if (key > root->key) root->right = deleteNode(root->right, key);
    else {
        if (root->left==NULL && root->right==NULL) return NULL;
        else if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        Node* temp = minValueNode(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
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
void inOrder(Node *root)
{
    if(root != NULL)
    {
        inOrder(root->left);
        cout << root->key << " ";
        inOrder(root->right);
    }
}
void postOrder(Node *root)
{
    if(root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->key << " ";
    }
}
int main()
{
    Node *root = NULL;
    int n,x;
    cout << "Enter the number of elements you want to insert in BST\n";
    cin >> n;
    cout << "Enter the elements : ";
    for(int i = 0; i < n; i++){
        cin >> x;
        root = insert(root, x);
    }
    cout << "Preorder traversal of the constructed BST is \n";
    preOrder(root);
    cout << "\nInorder traversal of the constructed BST is \n";
    inOrder(root);
    cout << "\nPostorder traversal of the constructed BST is \n";
    postOrder(root);
    cout<<"\nEnter the element you want to delete"<<endl;
    int g;
    cin>>g;
    deleteNode(root,g);
    postOrder(root);
    return 0;
}