#include<iostream>
#include<ranges>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
vector<int>v={1,5,8,3,4,5};

cout<<"Printing vector"<<endl;
for(int x: v)
cout<<x<<" ";
cout<<endl;

ranges::sort(v);
cout<<"After sort:"<<endl;
for(int a: v)
cout<<a<<" ";
cout<<endl;

auto it=ranges::find(v,4);
if(it!=v.end())
cout<<"Found 4 at index: "<<distance(v.begin(),it)<<endl;

vector<int>destination(v.size());
ranges::copy(v,destination.begin());

cout<<"Using ranges::copy : "<<endl;
for(int i : v)
cout<<i<<" ";
cout<<endl;

cout<<"Using for_each in std::ranges"<<endl;
ranges::for_each(v,[](int&x)
{
x=x*2;
cout<<x<<" ";
}); 
cout<<endl;


 //  std::ranges::count
    int count_of_10 = std::ranges::count(v, 10);
    std::cout << "Count of 10: " << count_of_10 << "\n";


    //  std::ranges::all_of
    bool all_positive = std::ranges::all_of(v, [](int x) {
        return x > 0;
    }); 
    /*std::ranges::all_of
     Checks if all elements satisfy a condition. */

    std::cout << "All elements positive? " <<
           std::boolalpha   << all_positive << "\n";



}
