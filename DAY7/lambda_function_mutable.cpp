#include<iostream>
using namespace std;

int main()
{
int var=10;

//Mutable-> can change the copied data but original is not getting effected
// noexcept-> will catch the throwed standard excepetion

auto mutablelambda=[=](int val)mutable 
{
var++;
cout<<"Var inside mutable lambda function :"<<var<<endl;
//if(val>15)
//throw runtime_error("Fatal error"); 

};

mutablelambda(20); //calling lambda function

cout<<"Var outside lambda (original data is not changed) : "<<var<<endl;

auto lambda=[=](int val)
{
if(val>10)
throw "BAD value";
};
try
{
lambda(30);
}
catch (const char* str)
{
cout<<"Catched : "<<*str<<endl;
}
}
