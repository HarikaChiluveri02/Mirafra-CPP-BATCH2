#include<iostream>
#include<algorithm>
#include<array>
using namespace std;

int main()
{

//Declaration of stl array
array<int,5> my_arr;

//array<int,5>my_arr{{1,2,3}};  //double curly required 
//array<int,5>my_arr={1,2,3};   //using = so single curly required

cout<<"Enter the "<<my_arr.size()<<" elements in array"<<endl;
for(int i=0;i<my_arr.size();i++)
{
cin>>my_arr[i];
}

cout<<"\nPrinting Array elements"<<endl;
for(int i: my_arr)
{
cout<<i<<" ";
}
cout<<endl;
cout<<"\nAccessing element using my_arr[3] :"<<my_arr[3]<<endl;
cout<<"Accessing element using my_arr.at(2) :"<<my_arr.at(2)<<endl;
//cout<<"Accessing element using my_arr.at(6) :"<<my_arr.at(6)<<endl;
//cout<<"Accessing element using my_arr[6] :"<<my_arr[6]<<endl;

cout<<"\nSorting array:"<<endl;
sort(my_arr.begin(),my_arr.end());
cout<<"Printing array after Sorting"<<endl;
for(auto c : my_arr)
cout<<c<<" ";
cout<<endl;

cout<<"\nReversing array"<<endl;
reverse(my_arr.begin(),my_arr.end());
cout<<"Printing after reversing:"<<endl;
for(int x : my_arr)
{
cout<<x<<" ";
}
cout<<endl;
cout<<"\nAccesing front element using front() : "<<my_arr.front()<<endl;
cout<<"Accessing back element using back() : "<<my_arr.back()<<endl;

//cout<<"\nCapacity of my_arr: "<<my_arr.capacity()<<endl;
}
