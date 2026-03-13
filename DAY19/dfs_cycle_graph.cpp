#include <iostream>
#include <vector>
using namespace std;

/*
 0-1
 | |
 3-2
*/
bool dfs(int node,int parent,vector<vector<int>>&adj,vector<bool>&visited)
{
visited[node]=true;

for(int neighbour:adj[node])
{
if(!visited[neighbour])
{
if(dfs(neighbour,node,adj,visited))
return true;
}
else if(neighbour!=parent)
return true;
}
return false;
}


int main() {
 int V=4;
vector<vector<int>>adj;
 adj.resize(V);
adj[0].push_back(1);
adj[1].push_back(0);

adj[1].push_back(2);
adj[2].push_back(1);

adj[2].push_back(3);
adj[3].push_back(2);

adj[3].push_back(0);
adj[0].push_back(3);

vector<bool>visited(V,false);
bool cycleExist=false;
for(int i=0;i<V;i++)
{
if(!visited[i])
{
if(dfs(i,-1,adj,visited))
{
cycleExist=true;
break;
}
}
}  
if(cycleExist)
cout<<"Cycle is Found"<<endl;
else
cout<<"Cycle is not found"<<endl;
    return 0;
}



