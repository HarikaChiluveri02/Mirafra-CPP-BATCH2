#include<iostream>
#include<span>
using namespace std;


void fun(span<int> s)
{
for(int& v:s)
v=v*2;
for(int a:s)
cout<<a<<" ";
}
int main()
{
int size=5;
int *ptr=new int[size]{1,2,3,4,5};
fun(span<int>(ptr,size)); //if we pass raw pointer size need to be passed

cout<<"\nAfter span"<<endl;
for(int i=0;i<size;i++)
{
cout<<ptr[i]<<" ";
}
cout<<endl;

cout<<"Another span pointing to same raw data"<<endl;
span<int> sp(ptr,size);
for(int& v : sp)
v=v*2;

cout<<"using span printing doubled data"<<endl;
for(int a: sp)
cout<<a<<" ";

delete[] ptr;
return 0;
}
