#include<iostream>
#include<deque>
using namespace std;
int main()
{
deque<int>dq={5,2,1,4};
dq.push_front(1);
dq.push_back(10);
dq.push_front(3);
for(auto it :dq)
{
cout<<it<<" ";
}
cout<<endl;
dq.pop_front();
dq.pop_back();
for(auto it=dq.begin();it!=dq.end();it++)
cout<<*it<<" ";
cout<<endl;
cout<<"Printing in reverse:"<<endl;
for(auto it=dq.rbegin();it!=dq.rend();it++)
cout<<*it<<" ";
cout<<endl;
}
