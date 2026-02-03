#include<iostream>
using namespace std;

class GPIO
{
int pin;
public:
/*GPIO()
{
cout<<"Default cons"<<endl;
cout<<pin<<endl;
}*/

void print()
{
cout<<pin<<endl;
}
~GPIO()
{
cout<<"Destructor"<<endl;
}
};

int main()
{
cout<<"Pin using normal declaration(garbage) "<<endl;
GPIO v;
v.print();

cout<<"Pin using value Initialization(0)"<<endl;
GPIO a{};
a.print();

}

