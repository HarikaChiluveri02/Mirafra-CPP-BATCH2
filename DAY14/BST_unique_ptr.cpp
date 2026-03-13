#include <iostream>
#include <memory>
#include <optional>
using namespace std;

class BST
{
private:
    struct SBST
    {
        int data;
        unique_ptr<SBST> left;
        unique_ptr<SBST> right;

        SBST(int val) : data(val) {}
    };

    unique_ptr<SBST> root;

public:
    void insert(int value)
    {
        insertimply(root, value);
    }

    void print()
    {
        inorder(root.get());
    }

    bool search(int val) const
    {
        return searchimply(root.get(), val);
    }
    
    void Delete(int val)
    {
        Deleteimply(root,val);
    }
private:
    void insertimply(unique_ptr<SBST>& root, int value)
    {
        if (!root)
        {
            root = make_unique<SBST>(value);
            return;
        }

        if (value < root->data)
            insertimply(root->left, value);
        else if (value > root->data)
            insertimply(root->right, value);
    }

    bool searchimply(const SBST* node, int value) const
    {
        if (!node)
            return false;

        if (value == node->data)
            return true;

        if (value < node->data)
            return searchimply(node->left.get(), value);
        else
            return searchimply(node->right.get(), value);
    }

    void inorder(const SBST* root) const
    {
        if (!root)
            return;

        inorder(root->left.get());
        cout << "Data: " << root->data << endl;
        inorder(root->right.get());
    }
public:
    optional<int> Findmin()
    {
     SBST* node=root.get();
     if(!node)
     return nullopt;
     
     while(node->left)
     node=node->left.get();
     
     return node->data;
    }

    optional<int> Findmax()
    {
     SBST* node=root.get();
     if(!node)
     return nullopt;
   
     while(node->right)
     node=node->right.get();
     return node->data;
    }
private:
    void Deleteimply(unique_ptr<SBST>& root,int value)
    {
        if(!root)
        return;
 
        if(value < root->data)              
        Deleteimply(root->left,value);
        
        else if(value > root->data)
        Deleteimply(root->right,value);

        else
        {
           if(!root->left && !root->right)
           root.reset();
           
           else if(!root->left)
           root=move(root->right);

           else if(!root->right)
           root=move(root->left);

          else
          {
          /* 
          SBST* minode=root->right.get();
          while(minode->left)
          minode=minode->left.get();
          root->data=minode->data;
          Deleteimply(root->right,minode->data);
          */
        
          SBST* maxnode=root->left.get();
          while(maxnode->right)
          maxnode=maxnode->right.get();
        
          root->data=maxnode->data;
          Deleteimply(root->left,maxnode->data);
          }
        }
    }
};

int main()
{
    BST obj;

    cout << "Insert function :" << endl;

    obj.insert(10);
    obj.insert(20);
    obj.insert(5);
    obj.insert(12);
    obj.insert(15);
    obj.insert(8);
    obj.insert(11);
    obj.insert(22);
    obj.insert(30);
    obj.insert(21);
    obj.print();

    cout << "The element: "
         << (obj.search(20) ? "Found" : "Not Found") << endl;

   /*cout<<"Deleting 15 :"<<endl;
   obj.Delete(15);
   obj.print();
   cout<<"Deleting 5 :"<<endl;
  obj.Delete(5);
  obj.print();
*/

 cout<<"Deleting :20"<<endl;
 obj.Delete(20);
 obj.print();

 optional<int>res=obj.Findmax();
 if(*res)
 cout<<"Max:"<<*res<<endl;
 else
 cout<<"Max not found:"<<endl;
}

