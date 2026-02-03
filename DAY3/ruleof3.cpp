#include<iostream>
using namespace std;

class Car
{
int fuel;
int* vehicleNumber;

public:Car(int f=0,int vNum=0):fuel(f),vehicleNumber(new int(vNum)) { }

//Copy Constructor(Deep Copy)

Car(const Car& other):fuel(other.fuel)
{
cout<<"Copy Constructor (Deep Copy)"<<endl;
vehicleNumber=new int(*other.vehicleNumber);
}

Car& operator=(const Car& other)
{
if(this!=&other)
{
cout<<"Objects are diffreent"<<endl;
this->fuel=other.fuel;
delete(this->vehicleNumber);
(this->vehicleNumber)=new int(*other.vehicleNumber);
}
return *this;
}

void Display(const Car& obj)const
{
cout<<"Fuel:"<<obj.fuel<<endl;
cout<<"VehicleNumber:"<<*obj.vehicleNumber<<endl;
}
~Car()
{
delete vehicleNumber;
}
};

int main()
{
Car obj1(50,1234);
Car obj2(70,5678);
Car obj3(obj2);
obj2=obj1;
obj1.Display(obj1);
obj2.Display(obj2);
obj3.Display(obj3);

}
