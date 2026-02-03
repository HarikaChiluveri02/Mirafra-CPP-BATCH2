#include<iostream>
using namespace std;

int a;
int c=10;

void fun()
{
int v;
cout<<"LOcal var in fun:"<<&v<<endl;
}
int main()
{
int b=40;
static int i;
int *p=new int(10);
cout<<"local variable(Stack):"<<&b<<endl;
cout<<"local static varaible(DATA):"<<&i<<endl;
cout<<"global variable un_int(BSS):"<<&a<<endl;
cout<<"Global Varibale Int(DATA):"<<&c<<endl;
cout<<"dynmically Allocated variable(HEAP):"<<&p<<endl;
fun();
}
