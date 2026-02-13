#include <iostream>
using namespace std;

class List
{
struct Node
{
int data;
Node* prev;
Node* next;
Node(int val):data(val),prev(NULL),next(NULL){}
};
Node* head;
Node* tail;
int sz;
public:
List():head(NULL),tail(NULL),sz(0){}

~List()
{
Node* temp=head;
while(head)
pop_front();
}

void push_front(int val)
{
Node* newnode=new Node(val);

if(head==NULL)
head=tail=newnode;
else
{
newnode->next=head;
head->prev=newnode;
head=newnode;
}
sz++;
}

void push_back(int val)
{
Node* newnode=new Node(val);

if(tail==NULL)
head=tail=newnode;
else
{
newnode->prev=tail;
tail->next=newnode;
tail=newnode;
}
sz++;
}

void pop_front()
{
if(head==NULL)
return;
else
{
Node* temp=head;
head=temp->next;
if(head!=NULL)
head->prev=NULL;
else
tail=NULL;
delete temp;
}
sz--;
}

void pop_back()
{
if(tail==NULL)
return;
else
{
Node* temp=tail;
tail=tail->prev;
if(tail!=NULL)
tail->next=NULL;
else
head=NULL;
delete temp;
}
sz--;
}

int size()const
{
return sz;
}

void print()
{
Node* temp=head;
while(temp)
{
cout<<temp->data<<" ";
temp=temp->next;
}
}

Node* begin()
{
return head;
}

Node* end()
{
return tail;
}


Node* insert(Node* pos,int val)
{
Node* newnode=new Node(val);
if(pos==head||head==NULL)
{
push_front(val);
return head;
}

if(pos==tail)
{
push_back(val);
return tail;
}
pos->next->prev=newnode;
newnode->prev=pos;
newnode->next=pos->next;
pos->next=newnode;
return newnode;
}

};
int main()
{
List l1;
l1.push_back(10);
l1.push_back(20);
l1.push_front(30);
l1.push_front(40);
l1.pop_front();
l1.pop_back();
l1.print();

auto it=l1.begin();
cout<<"\nbegin():"<<it->data<<endl;


}





