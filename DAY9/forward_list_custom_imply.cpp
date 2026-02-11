#include <iostream>

using namespace std;

template<typename T>
class Forwardlist
{
struct Node
{
T data;
Node* next;
Node(T val):data(val),next(NULL){}
};
Node *head;
public:
Forwardlist(): head(NULL){}

~Forwardlist()
{
while(head!=NULL)
{
Node* temp=head;
head=head->next;
delete temp;
}
}

void push_front(T value)
{
Node* newnode=new Node{value,head};
head=newnode;
}

void pop_front()
{
if(head==NULL)
return;
Node* temp=head;
head=head->next;
delete temp;
}

void insert_after(Node* prev)


};

int main() {

    return 0;
}



