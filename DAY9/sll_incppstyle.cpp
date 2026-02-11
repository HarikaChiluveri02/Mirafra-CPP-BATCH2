#include <iostream>
#include <iostream>

using namespace std;

struct Node
{
int data;
struct Node* next;
};

void insert_back(Node*& head,int value)
{
Node* newNode=new Node{value,NULL};
if(head==NULL)
{
head=newNode;
return;
}
Node* temp=head;
while(temp->next!=NULL)
temp=temp->next;
temp->next=newNode;
}

void insert_front(Node*& head,int value)
{
Node* newNode=new Node{value,head};
head=newNode;
}

void delete_front(Node*& head)
{
Node* temp=head;
head=head->next;
delete temp;
}

void delete_list(Node*& head)
{
while(head!=NULL)
{
Node* temp=head;
head=head->next;
delete temp;
}
}

void print(Node*& head)
{
Node* temp=head;
while(temp!=NULL)
{
cout<<"Data : "<<temp->data<<endl;
temp=temp->next;
}
}
int main() {
Node* head=NULL;
insert_back(head,10);
insert_back(head,20);
insert_back(head,30);
cout<<"Printing data:"<<endl;
print(head);
insert_front(head,40);
insert_front(head,100);
cout<<"Printing after 2 front operartions"<<endl;
print(head);
cout<<"Delete front:"<<endl;
delete_front(head);
print(head);







    return 0;
}



