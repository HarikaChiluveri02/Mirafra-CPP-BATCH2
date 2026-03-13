#include <iostream>
#include <memory>
#include <optional>
using namespace std;

class BST
{
private:
    struct SBST
    {
        uint16_t error_id;
        unique_ptr<SBST> left;
        unique_ptr<SBST> right;

        SBST(uint16_t val) : error_id(val) {}
    };

    unique_ptr<SBST> root;

public:
    void insert(uint16_t value)
    {
        insertimply(root, value);
    }

    void print()
    {
        inorder(root.get());
    }

    bool search(uint16_t val) const
    {
        return searchimply(root.get(), val);
    }
    
    void Delete(uint16_t val)
    {
        Deleteimply(root,val);
    }
private:
    void insertimply(unique_ptr<SBST>& root, uint16_t value)
    {
        if (!root)
        {
            root = make_unique<SBST>(value);
            return;
        }

        if (value < root->error_id)
            insertimply(root->left, value);
        else if (value > root->error_id)
            insertimply(root->right, value);
    }

    bool searchimply(const SBST* node, uint16_t value) const
    {
        if (!node)
            return false;

        if (value == node->error_id)
            return true;

        if (value < node->error_id)
            return searchimply(node->left.get(), value);
        else
            return searchimply(node->right.get(), value);
    }

    void inorder(const SBST* root) const
    {
        if (!root)
            return;

        inorder(root->left.get());
        cout << "Data: " << root->error_id << endl;
        inorder(root->right.get());
    }
public:
    optional<uint16_t> Findmin()
    {
     SBST* node=root.get();
     if(!node)
     return nullopt;
     
     while(node->left)
     node=node->left.get();
     
     return node->error_id;
    }

    optional<uint16_t> Findmax()
    {
     SBST* node=root.get();
     if(!node)
     return nullopt;
   
     while(node->right)
     node=node->right.get();
     return node->error_id;
    }
private:
    void Deleteimply(unique_ptr<SBST>& root,uint16_t value)
    {
        if(!root)
        return;
 
        if(value < root->error_id)              
        Deleteimply(root->left,value);
        
        else if(value > root->error_id)
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
        
          root->error_id=maxnode->error_id;
          Deleteimply(root->left,maxnode->error_id);
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

    cout << "The element 20: "
         << (obj.search(20) ? "Found" : "Not Found") << endl;

   /*cout<<"Deleting 15 :"<<endl;
   obj.Delete(15);
   obj.print();
   cout<<"Deleting 5 :"<<endl;
  obj.Delete(5);
  obj.print();
*/

 cout<<"Deleting error_id : 20"<<endl;
 obj.Delete(20);
 obj.print();

 optional<uint16_t>res=obj.Findmax();
 if(*res)
 cout<<"Max:"<<*res<<endl;
 else
 cout<<"Max not found:"<<endl;
}

