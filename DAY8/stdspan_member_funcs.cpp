#include<iostream>
#include<span>
#include<vector>

using namespace std;

void print(span<int> s,const string& name)
{
cout<<name<<" : ";
for(int i: s)
cout<<i<<" ";
cout<<endl;
}
int main()
{
vector<int> v={10,20,30,40,50};
span<int>s(v); //create span view

auto first_half=s.first(2); //Take first 2 Elements
auto last_half=s.last(2) ; //Take Last 2 Elements
auto middle=s.subspan(1,3); //Takes  2 Elemnts staring from index 1

print(s,"Original");
print(first_half,"First Half");
print(last_half,"Last Half");
print(middle,"Middle");

cout<<v.at(1);
}
