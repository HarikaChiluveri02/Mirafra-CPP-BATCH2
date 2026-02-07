#include<iostream>
using namespace std;

int main()
{
int threshold =50;
int offset=10;
bool enableAlaram=true;

auto mycheck=[&](int value) //&->the data is modified(capture by refernce) =->The data is not modified(capture by value).
{
cout<<"Threshold:"<<threshold<<endl;
cout<<"Offset : "<<offset<<endl;
cout<<"EnableAlaram : "<<enableAlaram<<endl;
//cout<<"Altering the values"<<endl;
threshold=100;
offset=5;
enableAlaram=false;
};

mycheck(10);
mycheck(30);

//Generic Lambda can hold any data type

int var=10;
auto genericlambda =[=](auto x,auto y)
{
return x+y+var;
};
cout<<"\nGeneric Lambda : "<<genericlambda(10,20)<<endl;
cout<<"Generic Lambda : "<<genericlambda(10.2,7.5)<<endl;
}
