#include <iostream>
#include<stack>
using namespace std;
class Stack
{
public:
int pid;
string process_name;
string running_state;
friend ostream& operator <<(ostream& os,Stack& obj)
{
os<<"Pid:"<<obj.pid<<",Name:"<<obj.process_name<<" ,State:"<<obj.running_state<<endl;
return os;
}
};
int main() {
stack<Stack>s;
s.push({1,"Process1","Ready"});
s.push({2,"process2","Running"});
s.push({3,"process3","Exceution"});

while(!s.empty())
{
cout<<s.top();
//cout<<"PID:"<<s.top().pid<<" Processname:"<<s.top().process_name<<" Running_state:"<<s.top().running_state<<endl;
s.pop();
}
    return 0;
}



