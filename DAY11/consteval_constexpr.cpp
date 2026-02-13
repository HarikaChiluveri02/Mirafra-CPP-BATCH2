#include <iostream>
using namespace std;

consteval int square(int v)
{
return v*v;
}

int main() {
constexpr int a=square(5);
cout<<"a="<<a<<endl; //no Error because value is passed at compile time only

/*
int b=10;
int res=square(b); //Error because passing a variable (it will be assigned at runtime)
*/

int result;
const int var=10; //value is assigned at compile time
result=square(var);
cout<<"result="<<result<<endl;

int res1;
constexpr int val=5; //value is assigned at compile time
res1=square(val);
cout<<"res1="<<res1<<endl;
    
    return 0;
}



