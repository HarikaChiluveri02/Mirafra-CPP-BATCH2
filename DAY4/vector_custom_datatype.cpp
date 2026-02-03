#include<iostream>
#include<utility>
#include<vector>

using namespace std;

class GPIO
{
int pin;

public:GPIO(int p):pin(p)
{
cout<<"GPIO "<<pin<<" is intialized"<<endl;
}

GPIO(const GPIO& other):pin(other.pin)
{
cout<<"GPIO "<<pin<<" is copied"<<endl;
}

GPIO(GPIO&& other):pin(other.pin) //because of no  noexcept copy is called move called
{
other.pin=-1;
cout<<"GPIO moved(NOT noexcept)"<<endl;
}

/*GPIO(GPIO&& other) noexcept:pin(other.pin) //because of noexcept copy is called move called
 {
other.pin=-1;
cout<<"GPIO moved(with noexcept)"<<endl;
 }*/

~GPIO()
{
cout<<"GPIO "<<pin<<" is released"<<endl;
}

};

int main()
{
vector<GPIO>v; //vector with custom data type
 // vector<int>vec_int; std::move will take care
v.push_back(GPIO(1));
v.push_back(GPIO(2)); //for 2 push_backs 2 moves definetly called and another one copy/move happens for reallocation
return 0;
}
