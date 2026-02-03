#include<iostream>
#include<utility>
using namespace std;

class Demo
{
public:
Demo()
{
cout<<"Default Cons"<<endl;
}

Demo(const Demo& obj)
{
cout<<"Copy cons"<<endl;
}

Demo(Demo&& obj)
{
cout<<"Move cons"<<endl;
}

~Demo()
{
cout<<"Destructor called"<<endl;
}
};

Demo create() //Separate function to create an object
{
Demo d;
return d;
}

int main()
{
Demo c=create();
return 0;
}

