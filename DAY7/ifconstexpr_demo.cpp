#include<iostream>
using namespace std;

template<typename T>
void process(T value)
{
if constexpr (sizeof(T)==4)
{
cout<<"32-bit Type:"<<endl;
}
else
cout<<"Non 32-bit Type"<<endl;
}

int main()
{
process(4);
process(3.2);
process('A');
return 0;
}
