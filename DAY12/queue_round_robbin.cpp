#include <iostream>
#include<queue>
#include<vector>
using namespace std;

struct process
{
int id;
int process_time;
int remaining_time;
};
int main() {
queue<process>q;
q.push({1,5,5});
q.push({2,3,3});
q.push({3,6,6});

int current_time=0;
int time_quanta=2;
while(!q.empty())
{
process &p1=q.front();
q.pop();
cout<<"Excueting process"<<p1.id<<"at time "<<current_time;
if(p1.remaining_time >time_quanta)
{
current_time+=time_quanta;
p1.remaining_time-=time_quanta;
cout << " for " << time_quanta<< " units\n";
q.push(p1);
}
else
{
current_time += p1.remaining_time;
cout << " for " << p1.remaining_time << " units (Finished)\n";
p1.remaining_time = 0;
}
}

    return 0;
}



