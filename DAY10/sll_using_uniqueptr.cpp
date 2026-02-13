#include <iostream>
#include <memory>
using namespace std;

class LinkedList
{
private:
    struct Node
    {
        int data;
        std::unique_ptr<Node> next;

        Node(int value) : data(value), next(nullptr) {}
    };

    std::unique_ptr<Node> head;

public:
    LinkedList() : head(nullptr) {}

    void push_front(int value)
    {
        auto newNode = std::make_unique<Node>(value);

        newNode->next = std::move(head);
        head = std::move(newNode);
    }

    void print() const
    {
        Node* temp = head.get();

        while (temp)
        {
            std::cout << temp->data << " ";
            temp = temp->next.get();
        }
        std::cout << "\n";
    }
    
    void push_back(int value)
    {
    auto newNode = make_unique<Node>(value);
    Node* temp=head.get();
     
    if(temp==NULL)
    head=move(newNode);
    
    while(temp->next!=NULL)
    temp=temp->next.get();
    
    temp->next=move(newNode);
    }
   
/*  void pop_front()
    {
      Node* temp=head.get();
      head=head->next.get();
      delete temp;
    }*/
};
int main()
{
    LinkedList list;

    list.push_front(10);
    list.push_front(20);
    list.push_front(30);
    list.push_back(40);
    //list.pop_front();
    list.print();

    return 0;
}

