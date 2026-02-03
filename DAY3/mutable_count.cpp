#include<iostream>
using namespace std;

class Sensor
{
int value;
mutable int read_count;//allowed to change in const function and const object also

public:

Sensor(int v):value(v),read_count(0){}

int read()const
{
read_count++; //Allowed because of mutable
return value;
}

void write(int v)
{
value=v;
cout<<"Sensor Data: "<<value<<endl;
}
int getReadcount()const
{
return read_count;
}
};

int main()
{
const Sensor s(100);// Constant object can access only constant member functions

cout<<s.read()<<endl;
cout<<s.read()<<endl;
cout<<s.read()<<endl;

cout<<"Read count ="<<s.getReadcount()<<endl;

Sensor s1(100);
s1.write(50);
return 0;
}
