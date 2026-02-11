#include<iostream>
using namespace std;
struct SparseMatrix
{
int index;
int data;
};

int main()
{
int arr[10]={0,0,5,6,0,0,4,0,0,0};
SparseMatrix sparse[10];
int count=0;
for(int i=0;i<10;i++)
{
if(arr[i]!=0)
{
sparse[count].index=i;
sparse[count].data=arr[i];
count++;
}
}

cout<<"Printing Sparse dta:"<<endl;
for(int i=0;i<count;i++)
cout<<"Sparse at index : "<<sparse[i].index<<" Sparse value : "<<sparse[i].data<<endl;
}
