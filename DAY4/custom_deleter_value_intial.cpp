#include<iostream>
#include<memory>
using namespace std;

class GPIO
{
int pin;
public:GPIO()
{
cout<<"GPIO Default cons is called:"<<endl;
pin=-1;
}

void write(int value)
{
pin=value;
}
 
int getpin()
{
return pin;
}

~GPIO()
{
cout<<"GPIO Destructor is called"<<endl;
}
};

class GPIODeleter
{
bool clockon;
public:
GPIODeleter()
{
cout<<"DEfault cons"<<endl;
clockon=false;
}
explicit GPIODeleter(bool c):clockon(c){}
void operator()(GPIO *g)const
{
cout<<"GPIO pin "<<g->getpin()<<clockon<<endl;
delete g;
}
};


int main()
{
GPIODeleter d{};
unique_ptr<GPIO,GPIODeleter>g(new GPIO(12),d);
g->write(10);
}








