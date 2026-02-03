#include<iostream>
using namespace std;
template<typename T>
class UniquePtr
{
T *ptr;
public:explicit UniquePtr(T *p=NULL):ptr(p){}

~UniquePtr()
{
cout<<"Unique ptr deleted"<<endl;
delete ptr;
}

UniquePtr(const UniquePtr&)=delete;
UniquePtr&operator=(const UniquePtr&)=delete;
T& operator*()const
{
return *ptr;
}

T* operator->()const
{
return ptr;
}

bool isValid()const
{
return ptr!=NULL;
}

T* release()
{
cout<<"Release the ownership of pointer and return the raw pointer"<<endl;
T* temp=ptr;
ptr=NULL;
return temp;
}

void reset(T* newPtr=NULL)
{
cout<<"Reset the managed object (With pr without A New one)"<<endl;
delete ptr;
ptr=newPtr;
}
};

class Test
{
public:Test()
{
cout<<"Test object is created"<<endl;
}
void greet()
{
cout<<"Hello from test object"<<endl;
}

~Test()
{
cout<<"Test object is destroyed"<<endl;
}

};

int main()
{
UniquePtr<Test>p1(new Test());
p1->greet();
UniquePtr<Test>p2(new Test());
cout<<&p2<<endl;
p2.reset(new Test());
cout<<&p2<<endl;

Test* rawptr=p1.release();
if(!p1.isValid())
{
cout<<"P1 is Empty"<<endl;
}

delete rawptr;
}



