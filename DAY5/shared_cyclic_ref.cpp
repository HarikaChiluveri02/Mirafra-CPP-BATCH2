// this is memory leak by shared ptr

#include<iostream>
#include<memory>
using namespace std;
class car;

class person
{
public:
shared_ptr<car>cmem;
static int count;

person()
{
++count;
cout<<"person Constructor"<<endl;
}

~person()
{
--count;
cout<<"person Destroyed"<<endl;
}
};

class car
 {
public:
 //shared_ptr<person>pmem;
weak_ptr<person>pmem; //use to overcome cyclic reference(Memory Leakage)
static int count; 

car()
 {
++count;
cout<<"Car Constructor"<<endl;
 } 
 ~car()
 {
 --count;
 cout<<"Car Destroyed"<<endl;
 }
 };

int car ::count=0;
int person :: count=0;
int main()
{
{
shared_ptr<person>p=make_shared<person>();
shared_ptr<car>c=make_shared<car>();

p->cmem=c;
c->pmem=p;

cout<<"\nInside the block"<<endl;
cout<<"Person count = "<<person::count<<endl;
cout<<"Car Count = "<<car::count<<endl;
}
cout<<"\nInside Block ended"<<endl;
cout<<"Person count = "<<person::count<<endl;
cout<<"Car Count = "<<car::count<<endl;

cout<<"Program Exiting"<<endl;
}


