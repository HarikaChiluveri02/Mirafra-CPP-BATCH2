#include<iostream>
using namespace std;

//return l-value
int& Transform(int& x)
{
x*=x;
return x;
}

void print(int& x)//L value
{
cout<<"Print(int&)"<<endl;
}

void print(const int& val)
{
cout<<"Print(Const int&)"<<endl;
}

void print(int&& x)
{
cout<<"Print(int&&)"<<&x<<endl;
}

//returns r-value
int Add(int a,int b)
{
return a+b;
}

int main()
{
int x=10;//x is l-value;

int& ref=x; // ref is an l-value

const int& ref3=100; //constant refernece(l value)can be equtaed to r value

//Transform returns an l-value
int& ref2=Transform(x);
print(x); //Binds to function that Accepts l-value refrence

int&& rv=8;
int&& rv2=Add(2,3);
cout<<"Size(rv2)"<<sizeof(rv2)<<endl;

print(3);
print(500);
return 0; 
}
