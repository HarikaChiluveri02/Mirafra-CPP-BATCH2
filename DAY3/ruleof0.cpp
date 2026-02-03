#include<iostream>
#include<vector>
using namespace std;

class Car
{
vector<int>vehiclenumbers;
public:

//Constructor
explicit Car(int count):vehiclenumbers(count,0){}

//Set Vehicle Number
void setVehicle(int index,int number)
{
if(index<vehiclenumbers.size())
vehiclenumbers[index]=number;
}

//Print all Cars
void print()const
{
cout<<"Total Cars:"<<vehiclenumbers.size()<<endl;
for(int i=0;i<vehiclenumbers.size();i++)
{
cout<<"Car"<<" "<<(i+1)<<" "<<"Number"<<" "<<vehiclenumbers[i]<<endl;
}
}

};


int main()
{
Car garage(2);
garage.setVehicle(0,1111);
garage.setVehicle(1,2222);

Car garage2(3);
garage2.setVehicle(0,1009);
garage2.setVehicle(1,2002);
garage2.setVehicle(2,3003);

cout<<"Garage 1 cars"<<endl;
garage.print();
cout<<endl;
cout<<"Garage 2 cars"<<endl;
garage2.print();

cout<<"\nCopy Assignment (garage1=garage2)\n";
garage=garage2;  // SAFE, deep copy handled by std::vector
garage.print();

cout<<"\ncopy constructor"<<endl;
Car garage3=garage;
garage3.setVehicle(1,999);
garage3.print();
return 0;
}
