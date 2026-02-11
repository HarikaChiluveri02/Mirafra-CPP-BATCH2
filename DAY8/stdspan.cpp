#include<iostream>
#include<span>
#include<vector>
using namespace std;

void print(span<int> s)//It is available from c++20 
{
for(int v : s)
{
cout<<v<<" ";
}
cout<<endl;
}

int main()
{
vector<int>v={1,2,3,4,5};
print(v);

int arr[]={10,20,30};
print(arr);
}
