#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

enum control_stations { Traffic_Contol,Power_Grid,Water_Supply,Hospital_Network,Police_Control,Data_Center,LENGTH};
string station[LENGTH] = {"Traffic Contol","Power Grid","Water Supply","Hospital Network","Police Control","Data Center"};
struct Edge
{
int u;
int v;
int cost;

public:

bool operator<(const Edge& other) const {
        return cost < other.cost;
    }
};

void print(vector<int>& parent,vector<int>& rank)
{
cout<<"Parent :";
for(auto p:parent)
cout<<p<<"  ";
cout<<endl;

cout<<"Rank   :";
for(auto r:rank)
cout<<r<<"  ";
cout<<endl;
cout<<"--------------------------------------------------------------"<<endl;
}
void makeset(int n,vector<int>& parent,vector<int>& rank)
{
for(int i=0;i<n;i++)
{
parent[i]=i;
rank[i]=0;
}
}

int FindParent(vector<int>& parent,int node)
{
if(parent[node]==node)
return node;
return parent[node]=FindParent(parent,parent[node]);
}

void unionset(int u,int v,vector<int>& parent,vector<int>& rank)
{
u=FindParent(parent,u);
v=FindParent(parent,v);

if(u==v)
return;

if(rank[u]<rank[v])
parent[u]=v;

else if(rank[v]<rank[u])
parent[v]=u;

else
{
parent[v]=u;
rank[u]++;
}
}

int Kruskal_MST(vector<Edge>& e,int n)
{
sort(e.begin(),e.end());

vector<int>parent(n);
vector<int>rank(n);
makeset(n,parent,rank);
int minweight=0;
int Edgecount=0;
cout<<"Intial state:"<<endl;
print(parent,rank);
for(auto& ed:e)
{
int u=ed.u;
int v=ed.v;
int cost=ed.cost;

if(FindParent(parent,u)!=FindParent(parent,v))
{
unionset(u,v,parent,rank);
print(parent,rank);
cout<<station[u]<<"->"<<station[v]<<":"<<cost<<endl;
minweight+=cost;
Edgecount++;

if(Edgecount==n-1)
break;
}
}
print(parent,rank);
return minweight;
}

/*

0 → Traffic Control
1 → Power Grid
2 → Water Supply
3 → Hospital Network
4 → Police Control
5 → Data Cente
-------------------
From     To    Cost
--------------------
0        1      4
0        2      4
1        2      2
2        3      3
2        5      2
2        4      4
3        4      3
5        4      3
-------------------
*/
int main() {

int Vertices=6;
vector<Edge>e={{0,1,4},{0,2,4},{1,2,2},{2,3,3},{2,5,2},{2,4,4},{3,4,3},{5,4,3}};
int mst=Kruskal_MST(e,Vertices); 
cout<<"Total Cost:"<<mst<<endl;

}



