#include<iostream>
#include<functional>

using namespace std;

void fun()
{
int y=10;
}
int main()
{
function<int()>f;

{
//Block
int x=10; //Local variable inside the block
f=[&x](){
return x;
};
}//varaible x is destroyed

cout<<f()<<endl; //Ideally considering calling out of scope var(x) so Error

auto f1=[&y](){
return y;
};

cout<<f1()<<endl;
}


