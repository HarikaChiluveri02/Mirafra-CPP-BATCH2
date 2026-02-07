#include<iostream>
using namespace std;

void ledon(int pin)
{
cout<<"Making led on at pin :"<<pin<<endl;
}

void motoron(int pin)
{
cout<<"Making motor on at pin : "<<pin<<endl;
}

int main()
{
int temp,pin=10;
cout<<"Enter the temperartue:"<<endl;
cin>>temp;
void (*fp)(int);
if(temp >25)
fp=&ledon;
else
fp=&motoron;
fp(pin);
return 0;
}
