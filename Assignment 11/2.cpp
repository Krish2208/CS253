#include <bits/stdc++.h>
using namespace std;
char c = 65;
int nc = 0;
struct Node
{
    int h, w;
    char label;
    Node *parent;
    Node *left;
    Node *right;
    int nam;
};

Node *initial(char label, int h, int w)
{
    Node *n = new Node();
    n->label = c;
    c++;
    n->w = w;
    n->h = h;
    n->left = NULL;
    n->right = NULL;
    n->parent = NULL;
    n->nam = nc;
    nc++;
    return n;
}
Node *inOrder(struct Node *root, char label)
{
    stack<Node *> s;
    Node *curr = root;
    while (curr != NULL || s.empty() == false)
    {
        while (curr != NULL)
        {
            s.push(curr);
            curr = curr->left;
        }
        curr = s.top();
        s.pop();
        if (curr->label == label)
        {
            return curr;
        }
        curr = curr->right;
    }
}
void addHorizontal(char rect, int x, Node *&HEAD)
{
    Node *curr = inOrder(HEAD, rect);
    if (curr->h > x)
    {
        Node *ln = new Node();
        Node *rn = new Node();
        ln->h = x;
        rn->h = curr->h - x;
        ln->w = curr->w;
        rn->w = curr->w;
        ln->left = NULL;
        ln->right = NULL;
        rn->left = NULL;
        rn->right = NULL;
        ln->parent = curr;
        rn->parent = curr;
        ln->label = curr->label;
        rn->label = c;
        ln->nam = nc;
        rn->nam = nc + 1;
        nc += 2;
        curr->label = '-';
        curr->left = ln;
        curr->right = rn;
        c++;
        Node *temp = curr;
        while (temp != NULL)
        {
            if (temp->label == '|')
            {
                temp->h = max(temp->left->h, temp->right->h);
                temp->w = temp->left->w + temp->right->w;
                temp = temp->parent;
            }
            else if (temp->label == '-')
            {
                temp->w = max(temp->left->w, temp->right->w);
                temp->h = temp->left->h + temp->right->h;
                temp = temp->parent;
            }
        }
    }
    else
        cout << "Invalid Cut\n";
}
void addVertical(char rect, int x, Node *&HEAD)
{
    Node *curr = inOrder(HEAD, rect);
    if (curr->w > x)
    {
        Node *ln = new Node();
        Node *rn = new Node();
        ln->w = x;
        rn->w = curr->w - x;
        ln->h = curr->h;
        rn->h = curr->h;
        ln->left = NULL;
        ln->right = NULL;
        rn->left = NULL;
        rn->right = NULL;
        ln->parent = curr;
        rn->parent = curr;
        ln->label = curr->label;
        rn->label = c;
        curr->label = '|';
        ln->nam = nc;
        rn->nam = nc + 1;
        nc += 2;
        curr->left = ln;
        curr->right = rn;
        c++;
        Node *temp = curr;
        while (temp != NULL)
        {
            if (temp->label == '|')
            {
                temp->h = max(temp->left->h, temp->right->h);
                temp->w = temp->left->w + temp->right->w;
                temp = temp->parent;
            }
            else if (temp->label == '-')
            {
                temp->w = max(temp->left->w, temp->right->w);
                temp->h = temp->left->h + temp->right->h;
                temp = temp->parent;
            }
        }
    }
    else
        cout << "Invalid Cut\n";
}
void printInOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    printInOrder(root->left);
    printf("Label: %c, Height: %d, Width: %d\n", root->label, root->h, root->w);
    printInOrder(root->right);
};
void printPreOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    printf("Label: %c, Height: %d, Width: %d\n", root->label, root->h, root->w);
    printPreOrder(root->left);
    printPreOrder(root->right);
};
void makeGV(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%d [label=<<B><FONT POINT-SIZE='15'>%c</FONT></B><BR/><FONT POINT-SIZE='10'>Width: %d, Height: %d</FONT>>]\n", root->nam, root->label, root->w, root->h);
    if (root->parent != NULL)
    {
        printf("%d -> %d\n", root->parent->nam, root->nam);
    }
    makeGV(root->left);
    makeGV(root->right);
};
int main()
{
    int w, h;
    cout << "Enter Basic Rectangle Width and Height: ";
    cin >> w >> h;
    Node *HEAD = initial('A', w, h);
    int x;
    char k, rect;
    do
    {
        cin >> k >> rect >> x;
        if (k == 'v')
        {
            addVertical(rect, x, HEAD);
        }
        else if (k == 'h')
        {
            addHorizontal(rect, x, HEAD);
        }
        else
            cout << "Operation should be Vertival(v) or Horizontal(h) only." << endl;
        cout << "Do you wish to continue [y/n] ";
        cin >> k;
    } while (k == 'y');
    // cout << "Inorder\n";
    // printInOrder(HEAD);
    // cout << "\n\nPreorder\n";
    // printPreOrder(HEAD);
    makeGV(HEAD);
    return 0;
}