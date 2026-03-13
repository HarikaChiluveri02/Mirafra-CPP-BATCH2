#include <iostream>
#include<memory>
#include<queue>
using namespace std;


class BST_Level
{
struct ECU
{
string name;
bool status;
ECU(string n,bool s=false):name(n),status(s)
{}
};

struct Node
{
ECU e;
int priority;
unique_ptr<Node>left;
unique_ptr<Node>right;
Node(int p,string n,bool s=false):priority(p),e(n,s)
{}
};
public:
unique_ptr<Node>root;
void Insert(int p,string name,bool s=false)
{
InsertImply(root,p,name,s);
}

void Traverse()
{
Level_Order(root);
}

private:

void InsertImply(unique_ptr<Node>& root,int p,string n,bool s)
{
if(!root)
{
root=make_unique<Node>(p,n,s);
return;
}
if(p < root->priority)
InsertImply(root->left,p,n,s);
else if(p > root->priority)
InsertImply(root->right,p,n,s);
}

void Level_Order(unique_ptr<Node>&root)
{
if(root==nullptr)
return;
queue<Node*>q;
q.push(root.get());
while(!q.empty())
{
Node* current=q.front();
q.pop();
current->e.status = true;
cout << "Activating Module: "
                  << current->e.name
                  << " | Status: "
                  << (current->e.status ? "ON" : "OFF")
                  << endl;
if(current->left)
q.push(current->left.get());
if(current->right)
q.push(current->right.get());
}
}

};
int main() {
BST_Level b;
b.Insert(5,"ECU");
b.Insert(7,"Dashboard");
b.Insert(4,"Safety",true);
b.Insert(6,"speed");
b.Insert(10,"Fuel");
b.Insert(3,"AirBag",true);
b.Traverse();
}



