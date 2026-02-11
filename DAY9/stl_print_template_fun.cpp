#include <iostream>
#include <iostream>
#include<vector>
#include<array>
#include<list>
using namespace std;

template<typename Iterator>
void print_all(Iterator first,Iterator last)
{
while(first!=last)
{
cout<<*first<<" ";
++first;
}
cout<<endl;
}
int main() {
vector<int>vec={1,2,3,4,5};
list<int>l={10,20,30};
array<int,3>arr={100,200,300};

int raw[]={6,7,8};

cout<<"Printing vector elemnts"<<endl;
print_all(vec.begin(),vec.end());
cout<<"Printing list elements"<<endl;
print_all(l.begin(),l.end());
cout<<"Printing array elements"<<endl;
print_all(arr.begin(),arr.end());
cout<<"Printing raw pointer elements:"<<endl;
print_all(raw,raw+3);
    return 0;
}



