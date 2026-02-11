#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
};

struct ForwardIterator {
    Node* ptr;
    int& operator*() 
    { 
    return ptr->data; 
    }
    ForwardIterator& operator++() 
    {
    ptr = ptr->next;
    return *this; 
    }
    bool operator!=(const ForwardIterator& other) const 
    {
 return ptr != other.ptr;
 }
};

class SimpleForwardList {
    Node* dummynode;

public:
    SimpleForwardList() {
        dummynode = new Node{0, nullptr};
    }

    ForwardIterator before_begin() 
    { 
     return {dummynode}; 
     }

     ForwardIterator begin() 
      { 
       return {dummynode->next}; 
         }
    
    ForwardIterator end() 
    { 
          return {nullptr}; 
     }

    ForwardIterator insert_after(ForwardIterator pos, int val) {
        Node* newNode = new Node{val, pos.ptr->next};
        pos.ptr->next = newNode;
        return {newNode};
    }
    ForwardIterator erase_after(ForwardIterator pos){
 Node* prevnode=pos.ptr;
if(prevnode==NULL || prevnode->next==NULL)
return end();
Node* nextnode=prevnode->next;
prevnode->next=nextnode->next;
delete nextnode;
return{prevnode->next};   
}
    ~SimpleForwardList() {
        Node* curr = dummynode;
        while (curr) {
            Node* next = curr->next;
            delete curr;
            curr = next;
        }
    }
};

int main() {
    SimpleForwardList list;

    auto it = list.before_begin();
    it = list.insert_after(it, 10); // List: 10
    it = list.insert_after(it, 20); // List: 10 -> 20 (it now points to 20)

    
    list.insert_after(list.before_begin(), 5); // List: 5 -> 10 -> 20

     for (int val : list) std::cout << val << " ";
     cout<<endl;

    std::cout << "After erasing first element: ";
    list.erase_after(list.before_begin());

/*    for (int val : list) std::cout << val << " "; 
    cout<<endl;*/

    for (int val : list) std::cout << val << " "; // Output: 5 10 20
    return 0;
}

