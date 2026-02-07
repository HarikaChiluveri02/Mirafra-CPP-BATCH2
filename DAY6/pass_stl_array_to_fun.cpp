#include<iostream>
#include<array>
#include<algorithm>
using namespace std;

void Print(array<int,5>&a)
{
for(auto i=a.cbegin();i<a.cend();i++)
cout<<*i<<" ";
cout<<endl;
}

void ReadData(array<int,5>&arr)
{
for(int i=0;i<arr.size();i++)
{
cin>>arr[i];
arr[i]+=10;
}
}

int main()
{
array<int,5>my_arr;

cout<<"Printing array: (stored in stack no intiliazation so garbage values)"<<endl;
Print(my_arr);

cout<<"\nReading data into my_arr:"<<endl;
ReadData(my_arr);

cout<<"\nPrinting data in my_arr:"<<endl;
Print(my_arr);
}
