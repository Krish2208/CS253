#include <iostream>
using namespace std;
struct Node{
    int data;
    struct Node* left;
    struct Node* right;    
    Node(int val){
    data=val;
    left=right=NULL;}
};
void preorder(struct Node* node){
    if(node==NULL)
    {
        return;
    }
    else{
        cout<<node->data<<" ";
        preorder(node->left);
        preorder(node->right);
    }    
};
void inorder(struct Node* node){
    if(node==NULL){return;}
    else{
        inorder(node->left);
        cout<<node->data<<" ";
        inorder(node->right);
    }
};
void postorder(struct Node* node){
    if(node==NULL){return;}
    else{
        postorder(node->left);
        postorder(node->right);
        cout<<node->data<<" ";
    }
};
int main(){
    struct Node* root=new Node(10);
    root->left= new Node(8);
    root->right= new Node(16);
    root->left->left=new Node(5);
    root->left->right=new Node(9);
    root->right->right=new Node(18);
    root->right->left=new Node(14);
    root->right->left->left=new Node(12);
    cout<<"Pre Order Traversal: ";
    preorder(root);
    cout<<endl;
    cout<<"In Order Traversal: ";
    inorder(root);
    cout<<endl;
    cout<<"Post Order Traversal: ";
    postorder(root);
    return 0;
}