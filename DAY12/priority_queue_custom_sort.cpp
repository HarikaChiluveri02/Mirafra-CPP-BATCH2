#include <iostream>
#include<queue>
using namespace std;

class Task
{
public:int priority;
string name;
int burst_time;



Task(int p,string nm,int bt):priority(p),name(nm),burst_time(bt) {}

/*bool operator<(const Task& o)const
{
return priority > o.priority;
}*/

/*bool operator < (const Task& obj) const
{
return burst_time < obj.burst_time;
}*/

friend ostream& operator<<(ostream& out,const Task& obj)
{
out<<obj.priority<<","<<obj.name<<","<<obj.burst_time;
return out;
}

};

struct CompareTask
{
bool operator()(const Task& t1, const Task& t2)const
{
return t1.priority < t2.priority ;
}
};
int main() {

//priority_queue<Task>pq;

priority_queue<Task,vector<Task>,CompareTask>pq;
pq.push(Task(1,"Task1",5));
pq.push(Task(2,"Task2",3));
pq.push(Task(3,"Task3",4));
pq.push(Task(4,"Task4",2));

while(!pq.empty())
{
//auto p=pq.top();
//cout<<p.priority<<","<<p.name<<","<<p.burst_time<<endl;
cout<<"Poped element is :"<<pq.top()<<endl;
pq.pop();
}
}



