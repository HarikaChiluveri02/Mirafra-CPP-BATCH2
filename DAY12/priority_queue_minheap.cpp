#include <iostream>
#include<vector>
#include<queue>
#include<functional>
using namespace std;

int main() {

priority_queue<int,vector<int>,greater<int>> q;
q.push(40);
q.push(5);
q.push(10);
q.push(60);
q.push(20);

while(!q.empty())
{
cout<<"Popped element is : "<<q.top()<<endl;
q.pop();
}
}



