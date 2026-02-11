#include<iostream>
#include<vector>
using namespace std;

class SparseArray
{
vector<pair<int,int>>sparsedata;

public:

void set(int index,int value)
{
if(value!=0)
{
sparsedata.push_back({index,value});
}
}

int get(int ind)
{
for(const auto& [index,value] : sparsedata)
if(ind==index)
return value;
return 0;
}

void print()const
{
for(const auto& [index,value] : sparsedata)
cout<<"Index = "<<index<<", Value = "<<value<<endl;
}
};

int main()
{
SparseArray arr;
arr.set(4,20);
arr.set(1,10);

cout<<"Value at index 4 : "<<arr.get(4)<<endl;
cout<<"Value at index 10: "<<arr.get(10)<<endl;
}
