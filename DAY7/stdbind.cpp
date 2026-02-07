#include<iostream>
#include<functional>

using namespace std;

int sum(int a,int b,int c)
{
return a+b+c;
}

auto lambda=[](int x,int y)
{
return x+y;
};
int main()
{
auto boundsum=bind(sum,10,placeholders::_1,placeholders::_2);
auto bsum=bind(lambda,10,placeholders::_1);
cout<<"BoundSum from function: "<<boundsum(5,15)<<endl;

}
