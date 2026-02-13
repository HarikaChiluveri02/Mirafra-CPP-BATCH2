#include <iostream>
#include<queue>
using namespace std;

int main() {

priority_queue<int>q;
q.push(10);
q.push(30);
q.push(5);
q.push(15);

while(!q.empty())
{
cout<<"Pooped element :"<<q.top()<<endl;
q.pop();
}
}



