#include <iostream>
using namespace std;

class car
{
struct BST
{
int rating;
string car_name;
int car_no;
struct BST* left;
struct BST* right;

BST(int val,string name,int num):rating(val),car_name(name),car_no(num),left(nullptr),right(nullptr)
{}
};

BST* root=nullptr;

public:
void insert(int rat,string nm,int n)
{
root=insertImp(root,rat,nm,n);
}

void search(int rat)
{
BST* result = searchImp(root, rat);
if (result)
cout << "Car Found: " << result->car_name << endl;
else
cout << "Car not found\n";
}
void display()
{
Inorder(root);
}

private:

BST* insertImp(BST* node,int r,string nm,int no)
{
if(node==nullptr)
return new BST(r,nm,no);

if(r < node->rating)
node->left=insertImp(node->left,r,nm,no);

else if(r > node->rating)
node->right = insertImp(node->right,r,nm,no);

return node;
}

BST* searchImp(BST* node,int r)
{
if(node==nullptr || node->rating==r)
return node;

if(r < node->rating)
return searchImp(node->left,r);

else
return searchImp(node->right,r); 
}

void Inorder(BST* node)
{
if(node==nullptr)
return;
Inorder(node->left);
cout << "Rating: " << node->rating<< ", Name: " << node->car_name<< ", Car No: " << node->car_no << endl;
Inorder(node->right);
}
};
int main() {
    
car c;
c.insert(5, "BMW", 101);
c.insert(3, "Audi", 102);
c.insert(7, "Tesla", 103);
c.insert(2, "Hyundai", 104);
c.insert(4, "Kia", 105);
cout << "\nInorder Traversal:\n";
c.display();
cout << "\nSearch Result:\n";
c.search(7);

}



