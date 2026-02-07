#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
vector<int>my_vec(5);
int val;
cout<<"Enter "<<my_vec.size()<<" elements in vector"<<endl;
for(int i=0;i<my_vec.size();i++)
{
cin>>my_vec[i];
}

cout<<"\nPrinting vector elements:"<<endl;
for(auto c:my_vec)
{
cout<<c<<" ";
}
cout<<endl;

cout<<"Reversing the vector using reverse():"<<endl;
reverse(my_vec.begin(),my_vec.end());
cout<<"Printing after reversing"<<endl;
for(auto it=my_vec.begin();it!=my_vec.end();it++)
cout<<*it<<" ";
cout<<endl;

cout<<"Size(): "<<my_vec.size()<<endl;
cout<<"Front(): "<<my_vec.front()<<endl;
cout<<"Back(): "<<my_vec.back()<<endl;
}
