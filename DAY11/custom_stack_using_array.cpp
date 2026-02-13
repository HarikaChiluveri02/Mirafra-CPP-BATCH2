#include <iostream>
using namespace std;
#define SIZE 5

template<typename T>
class Mystack
{
T arr[SIZE];
int index;

public:
Mystack()
{
index=-1;
}

void push(T value)
{
if(index>=SIZE-1)
{
cout<<"Stack Overflow"<<endl;
return;
}
arr[++index]=value;
}

void pop()
{
if(index<0)
{
cout<<"Stack Underflow"<<endl;
return;
}
index--;
}

T top()
{
return arr[index];
}

int size()
{
return index+1;
}

bool empty()
{
if(index==-1)
return 1;
return 0;
}
};

int main() {
Mystack<int>s;
s.push(10);
s.push(20);
s.push(30);
s.push(40);
s.push(50);
s.push(60);
s.push(70);
while(!s.empty())
{
cout<<"Popped element is : "<<s.top()<<endl;
s.pop();
}
s.pop();
}



