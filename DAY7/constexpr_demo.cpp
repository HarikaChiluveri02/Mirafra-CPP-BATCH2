#include<iostream>
using namespace std;

constexpr int fact(int n)
{
int res=1;
for(int i=1;i<=n;i++)
res*=i;
return res;
}

int main()
{
constexpr int res=fact(5); //compile time evaluation
constexpr int n=6;
int res2=fact(n);  //Runtime Evaluation
cout<<"Factorial(5) : "<<res<<endl;
cout<<"Factorial(6) : "<<res2<<endl;
}
