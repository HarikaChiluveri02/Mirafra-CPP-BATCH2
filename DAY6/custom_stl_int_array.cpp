#include<iostream>
#include<stdexcept>
#include<cstddef>
using namespace std;

class int_Array
{
int data[5]; //Fixed size storage
public:

int size()const noexcept
{
return 5;
}

int& operator[](int index)
{
return data[index];
}

int& at(int index)
{
if(index >= 5)
throw out_of_range("int_Array at:");
return data[index];
}

int* begin()noexcept
{
return data;
}

int* end()noexcept
{
return data+5;
}

int& front()
{
return data[0];
}

int& back()
{
return data[4];
}
};

int main()
{
int_Array arr;
for(int i=0;i<arr.size();i++)
arr[i]=(i+1)*10;

for(auto x : arr)
cout<<x<<" ";
cout<<endl;

cout<<"\nArr front:"<<arr.front()<<endl;
cout<<"Array End:"<<arr.back()<<endl;
cout<<"\nsize : "<<arr.size()<<endl;
}
