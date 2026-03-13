#include <iostream>
#include<memory>
#include<queue>
using namespace std;

struct Node
{

	int val;
	unique_ptr<Node>left;
	unique_ptr<Node>right;

	explicit Node(int value):val(value)
	{}

};

void Level_order(const unique_ptr<Node>&root)
{
	if(!root)
		return;

	queue<Node*>q;
	q.push(root.get());

	while(!q.empty())
	{
		Node* current=q.front();
		q.pop();

		cout<<current->val<<" ";

		if(current->left)
			q.push(current->left.get());

		if(current->right)
			q.push(current->right.get());
	}
	cout<<endl;
}


int main() {    
	unique_ptr<Node>root=make_unique<Node>(50);
	root->left=make_unique<Node>(30);
	root->right=make_unique<Node>(70);
	root->left->left=make_unique<Node>(20);
	root->left->right=make_unique<Node>(40);
	root->right->left=make_unique<Node>(60);
	root->right->right=make_unique<Node>(80);
	Level_order(root);
}



