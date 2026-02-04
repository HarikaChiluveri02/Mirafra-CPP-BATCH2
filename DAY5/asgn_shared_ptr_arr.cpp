#include<iostream>
#include<memory>
using namespace std;

class TempArray
{
double *temp;
int s;

public:
TempArray(double* init,int size):s(size)
{
temp=new double[size];
for(int i=0;i<size;i++)
temp[i]=init[i];
}

~TempArray()
{
cout<<"Destructor of Temperatures"<<endl;
delete[] temp;
}

double get(int index)const
{
return (index>=0 && index<s)?temp[index]:0.0;
}
int getSize()const
{
return s;
}
};


class TempDeleter
{
public:
void operator()(TempArray *ptr)const
{
cout<<"Deleting Temperature data:"<<endl;
delete ptr;
}
};


double ComputeAverage(shared_ptr<TempArray>&arr)
{
if(!arr || arr->getSize() == 0)
return 0.0;
double sum=0.0;
for(int i=0;i<arr->getSize();i++)
{
sum+=arr->get(i);
}
return sum;
}

int main()
{
double rawTemps[]={25.0,26.5,24.8,27.1,24.0};
int size=(sizeof(rawTemps)/sizeof(rawTemps[0]));
shared_ptr<TempArray>temps(new TempArray(rawTemps,size),TempDeleter{});

double avg=ComputeAverage(temps);
cout<<"Average Temperature:"<<avg<<endl;
}

