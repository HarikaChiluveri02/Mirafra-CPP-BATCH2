#include<iostream>
#include<atomic>
#include<thread>

using namespace std;

/*Using atomic the syncroniztion is perfectly happening

std::atomic template defines an atomic type. If one thread writes to an atomic object while another thread reads from it, the behavior is well-defined (see memory model for details on data races).*/

//Different threads of execution are always allowed to access (read and modify) different memory locations concurrently, with no interference and no synchronization requirements.

atomic<int>counter{0};

/* Using normal integer some are neglected*/
//int counter=0;
void increment()
{
for(int i=0;i<25000;++i)
{
counter++;
}
}

void decrement()
{
for(int i=0;i<25000;++i)
{
counter--;
}
}
int main()
{
thread t1(increment);
thread t2(decrement);

t1.join();
t2.join();
cout<<"Final Counter value:"<<counter<<endl;
}
