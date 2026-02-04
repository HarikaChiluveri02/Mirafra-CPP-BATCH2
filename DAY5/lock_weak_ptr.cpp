#include<iostream>
#include<memory>
using namespace std;

class Resource
{
public:
Resource()
{
cout<<"Resource is created"<<endl;
}

void use()
{
cout<<"Using Resource"<<endl;
}

~Resource()
{
cout<<"Resouce Destroyed"<<endl;
}
};

int main()
{
weak_ptr<Resource>wp;

{
auto sp=make_shared<Resource>(); //Resouce is created
wp=sp;
} //Resource is destroyed

if(auto locked = wp.lock()) // weak_ptr resouce is destroyed pointing to NULL
locked->use();
else
cout<<"Resource is already destroyed"<<endl;
}

