#include<iostream>
#include<vector>
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
vector<int> nodes;
void inorder(node *root){
    node* temp= root;
    if(temp==NULL){
     return;
    }
    inorder(temp->left);
    nodes.push_back(temp->key);
    inorder(temp->right);

}
node* insert_in_BST(node *root, int key){
    node *temp= root;
    if(root==NULL){
        return (new node(key));
    }
    else if(key< temp->key){
        temp->left= insert_in_BST(temp->left, key);
    }
    else if(key>temp->key){
        temp->right= insert_in_BST(temp->right, key);
    }
    return temp;
}
void writeNodeInGVFile(node* root) {
if (root == NULL)
return;
if(root->left != NULL)
cout<<root->key << " -- " << root->left->key << "\n";
if(root->right != NULL)
cout<<root->key << " -- " <<  root->right->key << "\n";
writeNodeInGVFile(root->left);
writeNodeInGVFile(root->right);
}
int main(){
    node *root1= new node(10);
    root1->left= new node(8);
    root1->left->left= new node(5);
    root1->left->right= new node(9);
    root1->right= new node(16);
    root1->right->left= new node(14);
    root1->right->left->left= new node(12);
    root1->right->right= new node(18);
    node *root2= new node(20);
    root2->left= new node(1);
    root2->left->right= new node(3);
    root2->right= new node(22);
    root2->right->left= new node(21);
    root2->right->right= new node(69);
    writeNodeInGVFile(root1);
    cout<<endl;
    writeNodeInGVFile(root2);
    cout<<endl;
    inorder(root1);
    inorder(root2);
    node *root3= NULL;
    for (int i = 0; i < nodes.size(); i++)
    {
        root3= insert_in_BST(root3, nodes[i]);
    }
    writeNodeInGVFile(root3);
    cout<<endl;
    return 0;
}