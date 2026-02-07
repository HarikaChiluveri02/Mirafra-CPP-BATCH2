#include<iostream>
#include<functional>
using namespace std;

class Functor
{
int value;
public:
Functor():value(0){}
Functor(int val)
{
value=val;
}
int operator()(int data)const
{
return data+value;
}
};


int main()
{
int var=10;

//std::function<returntype(list of arguments)>functioname

function<int(int,int)>f = [=](auto a,auto b){ //storing lambda in function
return a+b+var;
};

Functor fun{10};
function<int(int)>myfunc=fun;  //storing functors in function


cout<<"Lambda Sum from std::function : "<<f(5,7)<<endl;
cout<<"Functor Sum from std::function : "<<myfunc(10)<<endl;
}
