#include<iostream>
using namespace std;

void fun(int &n)
{
n=n*2;
}

int& caliber(int &n)//API
{
n=n*2;
static int l=100;
int &r=l;
return r;
}

void display(const int &n)
{
cout<<"Display(NOT Changable):"<<n<<endl;
}

int main()
{
int *ptr;
int a=10;
ptr=&a;
int &ref=a;

int b=100;
ref=b;

const int v=10;
const int &p=v;

//cout<<"Num:"<<fun(a)<<endl;
cout<<&ref<<endl;
cout<<&a<<endl;
cout<<&b<<endl;
cout<<a<<endl;

cout<<p<<endl;


int num=5;
display(num);
int l_ref=caliber(num);
cout<<"After Caliberation:"<<endl;
cout<<"num:"<<num<<endl;
cout<<"l_ref:"<<l_ref<<endl;

return 0;
}
