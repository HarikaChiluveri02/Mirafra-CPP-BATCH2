#include<iostream>
#include<memory>

using namespace std;

class MyClass
{
public:
MyClass()
{
cout<<"Myclass Constructor called"<<endl;
}
~MyClass()
{
cout<<"MyClass Destructor Called"<<endl;
}
void Display()
{
cout<<"Hello from my class"<<endl;
}
};

void UseSharedptr(shared_ptr<MyClass>ptr)
{
ptr->Display();
cout<<"Shared ptr use Count = "<<ptr.use_count()<<endl;
}

int main()
{
shared_ptr<MyClass>sptr1=make_shared<MyClass>();
cout<<"Shared ptr use count = "<<sptr1.use_count()<<endl; // sptr1 count=1
{
shared_ptr<MyClass>sptr2=sptr1; //sptr1 and sptr2 having shared ownership count=2;       
cout<<"Shared ptr use count for sptr2 = "<<sptr2.use_count()<<endl;
//shared_ptr<MyClass>sptr3; //just Declaration
shared_ptr<MyClass>sptr3=make_shared<MyClass>();
cout<<"Shared ptr use count for sptr3 = "<<sptr3.use_count()<<endl;

sptr3=sptr2;
cout<<"Sptr3 xount:"<<sptr3.use_count()<<endl;
UseSharedptr(sptr3);
}
shared_ptr<MyClass>sptr4=make_shared<MyClass>();
sptr4=sptr1;
cout<<"Shared ptr count after sptr1 goes out of scope "<<sptr4.use_count()<<endl;
}
