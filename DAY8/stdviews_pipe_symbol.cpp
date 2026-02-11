#include<iostream>
#include<vector>
#include<ranges>
using namespace std;

int main()
{
vector<int>v={1,2,3,4,5,6,7,8,9,10};

auto result = v | views::filter([](int x){ return x%2==0;}) | views::transform([](int x) {return x*10;});
cout<<"After v|views::filter() | views::transform()"<<endl;

for(auto it : result)
cout<<it<<" ";
cout<<endl;

cout<<"Original Vector"<<endl;
for(auto it : v)
cout<<it<<" ";
cout<<endl;
}
