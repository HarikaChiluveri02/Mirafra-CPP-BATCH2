#include<iostream>
using namspace std;

class Sensor
{
int* value;
public:

//Default Constructor
Sensor(int v=0):value(v){}

//Parameterized Constructor
Sensor(int v)
{
cout<<"Parametrized Constructor"<<endl;
value=v;
}

//copy Constructor
Sensor(Sensor& obj)
{
value=new int(*obj.value);
}

//Copy Assignment operator
Sensor& operator=(const Sensor& obj)
{
if(this!=*obj)
{
cout<<"Objects are different:"<<endl;
delete(this->value);
(this->value)=new int(*obj.value);
return *this; 
}
}

//Move Constructor
Sensor(Sensor&& obj)noexcept
{
value=obj.value
delete obj.value;
}

//Move Assignment operator
Sensor& operator=(const Sensor& obj)
{

}
};
