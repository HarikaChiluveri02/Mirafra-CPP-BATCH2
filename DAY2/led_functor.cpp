#include<iostream>
using namespace std;

class LED
{
bool state;
public:LED(int val)
{
state=val;
}
void operator()(bool l_state)
{
if(l_state==true)
{
if(state==true)
cout<<"Invalid Action"<<endl;
else
{
state=true;
cout<<"Led is ON"<<endl;
}
}
else
{
state=false;
cout<<"Led is OFF"<<endl;
}
}
};

int main()
{
LED l1(0);
l1(true);
l1(true);
l1(false);
}
