#include <iostream>
#include <iostream>

struct sll
{
int data;
sll* next;
};

using namespace std;

int main() {
sll* head=new sll{10,NULL};
sll* second=new sll{20,NULL};
sll* third=new sll{30,NULL};
head->next=second;
second->next=third;
sll* temp=head;
while(temp!=NULL)
{
cout<<"Data: "<<temp->data<<endl;
temp=temp->next;
}
    return 0;
}



