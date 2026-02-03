#include<iostream>
#include<memory>
using namespace std;

class Sensor
{
public:
int read()const
{
return 25;
}
};


void controller(shared_ptr<Sensor>ptr)
{
cout<<"Controller: "<<ptr->read()<<endl;
}

void Logger(shared_ptr<Sensor>ptr)
{
cout<<"Logger: "<<ptr->read()<<endl;
}

void Display(shared_ptr<Sensor>ptr)
{
cout<<"Display: "<<ptr->read()<<endl;
}

int main()
{
shared_ptr<Sensor>s=make_shared<Sensor>();
Logger(s);
controller(s);
Display(s);
}
