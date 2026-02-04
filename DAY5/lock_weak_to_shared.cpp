// For weak_ptr allocation use make_shared or new but there is no make_weak

#include<iostream>
#include<memory>
using namespace std;

int main()
{
weak_ptr<int>wp;
auto sp=make_shared<int>(42);
wp=sp; // weak_ptr observes

/*
{
auto sp=make_shared<int>(10)
wp=sp; // only block scope weak_ptr observes on using lock it returns NULL
}
*/

if(auto locked = wp.lock()) // with the help of lock weak_ptr(no-ownership) converted to shared_ptr(ownership acquired).
{
cout<<"weak_ptr convert to shared with data = "<<*locked<<endl;
cout<<"Use count:"<<locked.use_count()<<endl;
}
else
cout<<"Object Destroyed"<<endl;

weak_ptr<int>w1;
cout<<"w1(just Declared) count = "<<w1.use_count()<<endl;
weak_ptr<int>w=make_shared<int>(1);
cout<<"w(Allocated using make_shared) count = "<<w.use_count()<<endl;
}
