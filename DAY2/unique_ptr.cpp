//unique_ptr is a smart pointer that owns (is responsible for) and manages another object via a pointer
// and subsequently disposes of that object when the unique_ptr goes out of scope.

//C++14 onwards it is available

#include<iostream>
#include<memory>
using namespace std;
class Myclass
{
int data;
public:Myclass()
{
cout<<"MY class created"<<endl;
}

void sayHello() const
{
cout<<"Hello from class"<<endl;
}

~Myclass()
{
cout<<"My class is destroyed"<<endl;
}
};

int main()
{
unique_ptr<Myclass>p1=make_unique<Myclass>();
p1->sayHello();

unique_ptr<Myclass>p2=move(p1);
if(!p1)
cout<<"P1 is now Empty"<<endl;
p2->sayHello();

Myclass *rawptr=p2.release();
if(!p2)
cout<<"Released"<<endl;
delete rawptr;

unique_ptr<Myclass>p3=make_unique<Myclass>();
Myclass *raw=p3.get();

p3.reset(new Myclass());

Myclass *rawptr1=p3.get();
cout<<"Got raw data"<<endl;
unique_ptr<Myclass>p4=make_unique<Myclass>();
p3.swap(p4);
}
