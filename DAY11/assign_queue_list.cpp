#include <iostream>
#include<list>
using namespace std;

class Queue
{
list<int>l1;
public:

void push(int value)
{
l1.push_back(value);
}

void pop()
{
l1.pop_front();
}

int& back()
{
return l1.back();
}

int& front()
{
return l1.front();
}

int size()
{
return l1.size();
}

bool empty()
{
return l1.empty();
}


};

int main() {
    Queue q;
q.push(10);
q.push(20);
q.push(30);
q.push(40);
while(!q.empty())
{
cout<<"Poping Element is:"<<q.front()<<endl;
q.pop();
}
if(q.empty())
cout<<"Queue is Empty"<<endl;
else
cout<<"Queue is not Empty"<<endl;
    return 0;
}



