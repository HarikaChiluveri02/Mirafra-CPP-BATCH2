#include <iostream>
#include<set>
using namespace std;

class Task
{
public:int priority;
string name;
int tid;


Task(int p,string nm,int bt):priority(p),name(nm),tid(bt) {}

/*bool operator<(const Task& o)const
{
return priority > o.priority;
}*/

/*bool operator < (const Task& obj) const
{
return burst_time < obj.burst_time;
}*/

/*friend ostream& operator<<(ostream& out,const Task& obj)
{
out<<obj.priority<<","<<obj.name<<","<<obj.tid;
return out;
}*/

};

struct CompareTask
{
bool operator()(const Task& t1, const Task& t2)const
{
cout<<"Compare called"<<endl;
if(t1.priority==t2.priority)
return t1.tid<t2.tid;

return t1.priority < t2.priority ;
}
};
int main() {

//priority_queue<Task>pq;

set<Task,CompareTask>s;
s.insert(Task(1,"Task1",5));
s.insert(Task(2,"Task2",3));
s.insert(Task(3,"Task3",4));
s.insert(Task(3,"Task4",2));
s.insert(Task(4,"Task5",1));

for(auto const& [p,nm,t]: s)
cout<<p<<" "<<nm<<" "<<t<<endl;
}



