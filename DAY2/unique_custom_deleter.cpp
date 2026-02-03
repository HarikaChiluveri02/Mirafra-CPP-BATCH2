#include<iostream>
#include<memory>
#include<cstdlib>
using namespace std;

struct FreeDeleter
{
template<typename T>
void operator()(T* p)const
{
free(p);
cout<<"Memory freed using free"<<endl;
}
};

//Custom_deleter using function pointers
void customDeleter(float *ptr)
{
cout<<"Custom deleter is called to free memory"<<endl;
free(ptr);
}

//Deletion of whole array
struct deleteArray
{
template<typename T>
void operator()(T* p)const
{
cout<<"array Deleted"<<endl;
delete[] p;
}
};


int main()
{
unique_ptr<float,FreeDeleter>p{(float*)malloc(sizeof(float))}; //using functor
unique_ptr<float,void(*)(float*)>ptr{(float*)malloc(sizeof(float)),customDeleter};//using Function pointer
unique_ptr<int[],deleteArray>arrPtr(new int[10]);

if(!p)
{
cout<<"Memory allocation faile"<<endl;
return 1;
}

*p=100;
cout<<*p<<endl;
}
