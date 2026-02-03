#include<iostream>
using namespace std;

class Add
{
int num;
public:Add(int value)
{
num=value;
}
Add operator+(Add &obj)
{
return num+obj.num;
}
void display()
{
cout<<"Addition of numbers:"<<num<<endl;
}
};

int main()
{
Add obj1(10),obj2(20);
Add obj3=obj1+obj2;
obj3.display();
}
