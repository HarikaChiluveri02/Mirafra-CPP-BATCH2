#include<iostream>
using namespace std;

class int_vec
{
int *data,sz,cap;
public:
int_vec():data(NULL),sz(0),cap(0)
{
}

~int_vec()
{
cout<<"Descructor called"<<endl;
delete[] data;
}

void push_back(int val)
{
if(sz==cap)
grow();
data[sz++]=val;
}

void pop_back()
{
int* ptr=new int[sz-1];
for(int i=0;i<sz-1;i++)
ptr[i]=data[i];
delete[] data;
data=ptr;
sz--;
}
int& front()
{
return data[0];
}

int& back()
{
return data[sz-1];
}
bool empty()
{
return sz==0;
}
int& operator[](int index)
{
if(index<sz)
throw out_of_range("Vector AT:");
return data[index];
}

int size()const
{
return sz;
}

int capacity()const
{
return cap;
}

int* begin()
{
return data;
}

int* end()
{
return data+sz;
}

void shrink_to_fit()
{
if(sz==cap)
return;

int* p=new int[sz];
for(int i=0;i<sz;i++)
p[i]=data[i];
delete[] data;
data=p;
cap=sz;
}

private:

void grow()
{
int newCap=(cap==0)?1:(cap*2);
int* newData=new int(newCap);

//copying data to new memory location
for(int i=0;i<sz;i++)
{
newData[i]=data[i];
}
delete[] data;
data=newData;
cap=newCap;
}

};


int main()
{
int_vec v;
cout<<"Intial size = "<<v.size()<<", Capacity = "<<v.capacity()<<endl;
cout<<"1 push_back"<<endl; 
v.push_back(10);
cout<<"Size: "<<v.size()<<", Capacity= "<<v.capacity()<<endl;
cout<<"2 push_back"<<endl;
v.push_back(20);
cout<<"3 push_back"<<endl;
v.push_back(30);
cout<<"Size: "<<v.size()<<", Capacity= "<<v.capacity()<<endl;
for(auto i : v)
{
cout<<i<<" ";
}
cout<<"\nPOP BACK():"<<endl;
v.pop_back();
for(auto i : v)
{
cout<<i<<" ";
}
v.push_back(30);
v.push_back(40);
v.push_back(50);
v.push_back(60);
cout<<"\nSize : "<<v.size()<<" , Capacity = "<<v.capacity()<<endl;
v.shrink_to_fit();
cout<<"shrink_to_fit():"<<"Size : "<<v.size()<<", Capacity : "<<v.capacity()<<endl;
}












