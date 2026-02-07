#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
vector<int>v={1,2,3,4,5,6};

cout<<"Printing vector elements"<<endl;
for_each(v.begin(),v.end(),[](auto val){
cout<<val<<" ";
});
cout<<endl;
cout<<"\nPrinting vector Elememts in reverse order:"<<endl;

for_each(v.rbegin(),v.rend(),[](auto val)
{
cout<<val<<" ";
});
cout<<endl;
}
