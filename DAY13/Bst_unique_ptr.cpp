#include <iostream>
#include <memory>
using namespace std;
class BST
{
private:
struct SBST
{
int data;
unique_ptr<SBST> left;
unique_ptr<SBST> right;

SBST(int val):data(val)
{}

};
unique_ptr<SBST>root;

public:
void insert(int value)
{
insertimply(root,value);
}

void print()
{
inorder(root.get());
}

bool search(int val)const
{
return searchimply(root.get(),val);
}
private:

void insertimply(unique_ptr<SBST>& root,int value)
{

if(!root)
root=make_unique<SBST>(value);

if(value < root->data)
insertimply(root->left,value);

else if(value > root->data)
insertimply(root->right,value);

}

bool searchimply(const SBST* node ,int value)const
{
if(!node) 
return false;

if (value == node->data)
return true;
        
if (value < node->data)
return searchimply(node->left.get(), value);

else
return searchimply(node->right.get(), value);

}
void inorder(const SBST* root)const
{

if(!root)
return;

inorder(root->left.get());
cout<<"Data: "<<root->data<<endl;
inorder(root->right.get());
}
};
int main() {
 /*   auto root=make_unique<SBST>(10);
   root->left=make_unique<SBST>(5);
   root->left->right=make_unique<SBST>(8);
   root->right=make_unique<SBST>(20);
   root->right->left=make_unique<SBST>(12);
   root->right->left->right=make_unique<SBST>(15);
  inorder(root.get());
*/
  BST obj;
  cout<<"Insert function :"<<endl;
   obj.insert(10);
   obj.insert(20);
   obj.insert(5);
   obj.insert(12);
   obj.insert(15);
   obj.insert(8);
   obj.print();
   cout<<"the element : "<< (obj.search(20)?"Found":"Not Found")<<endl;
}



