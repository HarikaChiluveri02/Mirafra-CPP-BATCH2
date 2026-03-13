#include<iostream>
#include<stack>

using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

Node* Insert(Node* root,int val)
{

if(root==nullptr)
return new Node(val);

if(val < root->data)
root->left=Insert(root->left,val);

else if(val > root->data)
root->right=Insert(root->right,val);

return root;
}

void Inorder(Node* root)
{
if(root==nullptr)
return;

Node* current=root;
stack<Node*>st;

while(current!=nullptr || !st.empty())
{
while(current!=nullptr)
{
st.push(current);
current=current->left;
}
current=st.top();
st.pop();
cout<<current->data<<" ";
current=current->right;
}

}

void Preorder(Node* root)
{
if(root==nullptr)
return;

stack<Node*>st;
st.push(root);

while(!st.empty())
{
Node* current=st.top();
st.pop();
cout<<current->data<<" ";

if(current->right)
st.push(current->right);

if(current->left)
st.push(current->left);
}
}

void Postorder(Node* root)
{
if (!root) 
return;

    stack<Node*> st1, st2;
    st1.push(root);

    while (!st1.empty())
    {
        Node* current = st1.top();
        st1.pop();
        st2.push(current);

        if (current->left)
            st1.push(current->left);

        if (current->right)
            st1.push(current->right);
    }

    while (!st2.empty())
    {
        cout << st2.top()->data << " ";
        st2.pop();
    }
}

int main()
{
    // Creating the tree
    Node* root = new Node(50);
    root->left = new Node(30);
    root->right = new Node(70);
    root->left->left = new Node(20);
    root->left->right = new Node(40);

    cout << "Inorder Traversal: ";
    Inorder(root);
    cout<<"\n Preorder Traversal: ";
    Preorder(root);
    cout<<"\nPostorder Traversal: ";
    Postorder(root);

    return 0;
}














