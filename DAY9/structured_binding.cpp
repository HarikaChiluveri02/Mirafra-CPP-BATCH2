#include <iostream>
#include <iostream>

using namespace std;

struct S
{
mutable int x : 2;
volatile double y;
};

S f()
{
return S{1,2.3};
}
int main() {
const auto [x,y] = f();//object creation from function and intializing them as const with returned values 
cout<<x<<" "<<y<<endl;
x=-2; //mutable so can modify
//y=-2; //Error : y is const-qualified
cout<<x<<" "<<y<<endl;
S s_var;
auto[x2,y2]=f();
x2=2;
y2=0.8;
cout<<x2<<" "<<y2<<endl;
    return 0;
}



