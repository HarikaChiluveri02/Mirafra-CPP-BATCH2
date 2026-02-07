#include<iostream>
#include<vector>
using namespace std;

int main()
{
vector<int>v;

cout<<"intial size = "<<v.size()<<endl;
cout<<"Intial Capacity = "<<v.capacity()<<endl;
v.reserve(5); //pre allocate memory
cout<<"\nAfter reserve size: "<<v.size()<<endl;
cout<<"After reserve capacity: "<<v.capacity()<<endl;

for(int i=1;i<=5;i++)
{
v.push_back(i*2);
cout<<"After push_back : size = "<<v.size()<<" ,Capacity = "<<v.capacity()<<endl;
}
}
