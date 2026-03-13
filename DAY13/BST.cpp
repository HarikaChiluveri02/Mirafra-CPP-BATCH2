#include <iostream>
using namespace std;

struct BST
{
int data;
struct BST *left;
struct BST *right;

BST(int val):data(val),left(nullptr),right(nullptr)
{}
};

BST* insert(BST* head,int val)
{
BST* newnode=new BST(val);
if(head==nullptr)
{
head=newnode;
return head;
}

if(val < head->data)
head->left=insert(head->left,val);
else if(val > head->data)
head->right=insert(head->right,val);

return head;
}

void deleteTree(BST* node)
{
if(node==nullptr)
return;

deleteTree(node->left);
deleteTree(node->right);
cout<<"Deleted : "<<node->data<<" Address: "<<node<<endl;
delete node;
}
void preorder(BST* node)
{

if(node==nullptr)
return;

cout << "Node Data: " << node->data
              << " | Address: " << node
              << " | Left: " << node->left
              << " | Right: " << node->right
              << std::endl;
preorder(node->left);
preorder(node->right);
}

void postorder(BST* root)
{
if(root==nullptr)
return;

postorder(root->left);
postorder(root->right);
cout << "Node Data: " << root->data
              << " | Address: " << root
              << " | Left: " << root->left
              << " | Right: " << root->right
              << std::endl;
}

void inorder(BST* node)
{
if(node==nullptr)
return;

inorder(node->left);
//cout<<"data:"<<node->data<<endl;
cout << "Node Data: " << node->data
              << " | Address: " << node
              << " | Left: " << node->left
              << " | Right: " << node->right
              << std::endl;
inorder(node->right);
}
int main() {
    BST* root=nullptr;
    root=insert(root,10);
    root=insert(root,20);
    root=insert(root,5);
    root=insert(root,12);
    root=insert(root,15);
    root=insert(root,8);
    cout<<"Preorder:"<<endl;
    preorder(root);
    cout<<"Inorder:"<<endl;
    inorder(root);
    cout<<"PostOrder:"<<endl;
    postorder(root);
    deleteTree(root);
    return 0;
}



