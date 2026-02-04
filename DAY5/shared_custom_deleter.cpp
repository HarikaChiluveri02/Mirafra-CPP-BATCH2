#include<iostream>
#include<memory>
using namespace std;

class GPIO
{
int pin;
public:
GPIO(int val)
{
pin=val;
cout<<"GPIO pin "<<pin<<" intialized"<<endl;
}
int getpin()const
{
return pin;
}
~GPIO()
{
cout<<"GPIO Destructor is called"<<endl;
}
};

struct GPIODeleter
{
void operator()(GPIO* gpio)const
{
cout<<"Custom Deleter : GPIO pin "<<gpio->getpin()<<" released"<<endl;
delete gpio;
}
};

void fun1(shared_ptr<GPIO>ptr)
{
cout<<"Fun1 with pin "<<ptr->getpin()<<endl;
cout<<"Fun1 with use_count "<<ptr.use_count()<<endl;
}

void fun2(shared_ptr<GPIO>ptr)
{
cout<<"Fun2 with pin "<<ptr->getpin()<<endl;
cout<<"Fun2 with use_count "<<ptr.use_count()<<endl;
}


int main()
{
shared_ptr<GPIO>gpio(new GPIO(13),GPIODeleter{});
fun1(gpio);
fun2(gpio);
cout<<"Main:use_count : "<<gpio.use_count()<<endl;
}











