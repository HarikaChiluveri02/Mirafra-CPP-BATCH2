//simple c++ program to toggling led and displaying with the use of const refrence API


#include<iostream>
using namespace std;

class Led
{
public: bool state;
Led()
{
state=0;
}
void ledon()
{
state=1;
}
void ledoff()
{
state=0;
}
};

void display(const Led &obj)
{
cout<<"Display led state:"<<obj.state<<endl;
}

int main()
{

Led obj;
display(obj);
obj.ledon();
display(obj);
obj.ledoff();
display(obj);
}
