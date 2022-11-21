#include<iostream>
using namespace std;
class node{
    public:
    int key;
    node *left;
    node *right;
    node(int n){
        key= n;
        left=NULL;
        right=NULL;
    }
};
int max(int a, int b){
    if(a>=b){
        return a;
    }
    else{
        return b;
    }
}
void inorder(node *root){
        if(root==NULL){
         return;
        }
        inorder(root->left);
        cout<<(root->key)<<" ";
        inorder(root->right);

}
int height(node* root){
    int h= 0;
    node *temp= root;
    if(temp==NULL){
        return h;
    }
    if(temp->left==NULL && temp->right==NULL){
        return h;
    }
    else if(temp->left==NULL){
        h= height(temp->right)+1;
    }
    else if(temp->right==NULL){
        h= height(temp->left)+1;
    }
    else{
        h= max(height(temp->left),height(temp->right))+1;
    }
    return h;
}
int balance(node *root){
    node *temp= root;
    if(temp==NULL){
        return 0;
    }
    return (height(temp->left)- height(temp->right));
}
bool check_bst(node* root){
    node* temp= root;
    if(temp==NULL){
        return true;
    }
    if(temp->left!=NULL && temp->left->key> temp->key){
        return false;
    }
    if(temp->right!=NULL && temp->right->key< temp->key){
        return false;
    }
    if(check_bst(temp->left)!= true || check_bst(temp->right)!=true){
        return false;
    }
    return true;   
}
node* ans= NULL;
int l= 0;
void find_largest_AVL(node* root){
    node* temp= root;
    if(temp==NULL){
        return;
    }
    if(balance(temp)== -1 || balance(temp)== 0 || balance(temp)== 1){
        int x= height(temp);
        if(x> l && check_bst(temp)==true){
            l= x;
            ans= temp;
        }
    }
    find_largest_AVL(temp->left);
    find_largest_AVL(temp->right);
}
int main(){
    node* root= new node(30);
    root->left= new node(20);
    root->right= new node(7);
    root->left->left= new node(10);
    root->left->right= new node(28);
    root->right->left= new node(6);
    root->right->right= new node(8);
    root->left->left->left= new node(3);
    root->left->left->right= new node(11);
    find_largest_AVL(root);
    cout<<l<<endl;
    return 0;
}