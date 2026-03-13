#include <iostream>
#include <vector>
using namespace std;

void makeset(int size,vector<int>& parent,vector<int>& rank)
{
for(int node=0;node<size;node++)
{
parent[node]=node;
rank[node]=0;
}
}
void printDSU(vector<int>& parent,vector<int>& rank)
{
cout<<"Parent : ";
for(auto i:parent)
cout<<i<<" ";
cout<<endl;

cout<<"Rank   : ";
for(auto p:rank)
cout<<p<<" ";
cout<<endl;

cout<<"--------------------------------------------------------------"<<endl;
}
int FindParent(int node,vector<int>& parent)
{
if(parent[node]==node)
return node;

return parent[node]=FindParent(parent[node],parent);
}

void unionset(int u,int v,vector<int>& parent,vector<int>& rank)
{
u=FindParent(u,parent);
v=FindParent(v,parent);

if(u==v)
{
cout<<"Both are already Present in same set"<<endl;
return;
}

if(rank[u]<rank[v])
{
parent[u]=v;
}
else if(rank[v]<rank[u])
{
parent[v]=u;
}
else
{
parent[v]=u;
rank[u]++;
}
cout<<"union done between "<<u<<" and "<<v<<endl;
printDSU(parent,rank);
}

int main() {
int V=7;
vector<int>parent(V);
vector<int>rank(V);
makeset(V,parent,rank);

cout<<"Intial State:"<<endl;
printDSU(parent,rank);
unionset(0,1,parent,rank);
unionset(1,2,parent,rank);
unionset(3,4,parent,rank);
unionset(5,6,parent,rank);
unionset(0,6,parent,rank);

if(FindParent(0,parent)==FindParent(3,parent))
cout<<"0 and 3 are Connected"<<endl;
else
cout<<"0 and 3 are not connected"<<endl;

if(FindParent(0,parent)==FindParent(6,parent))
cout<<"0 and 6 are connected"<<endl;
else
cout<<"0 and 6 are not connected"<<endl;
printDSU(parent,rank);
}



