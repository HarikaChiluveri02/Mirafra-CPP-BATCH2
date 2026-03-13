#include <iostream>
#include<queue>
#include<vector>
#include<bits/stdc++.h>
#include<climits>
using namespace std;

class DGraph
{
int V;
vector<vector<pair<int,int>>>adj;
public:
DGraph(int v)
{
V=v;
adj.resize(V);
}

void AddEdge(int u,int v,int weight)
{
adj[u].push_back({v, weight});
adj[v].push_back({u, weight});
}

void Dij_shortest(int src)
{
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
vector<int>dist(V,INT_MAX);
vector<bool>visited(V,false);

dist[src]=0;
pq.push({0,src});

while(!pq.empty())
{
int d=pq.top().first;
int node=pq.top().second;
pq.pop();
/*
if(visited[node])
continue;
visited[node]=true;
*/
for(auto edge:adj[node])
{
int neighbour=edge.first;
int weight=edge.second; 
if(dist[neighbour]>d+weight)
//if(!visited[neighbour] && dist[neighbour]>d+weight)
{
dist[neighbour]=d+weight;
pq.push({dist[neighbour],neighbour});
}
}
}
cout<<"From Source :"<<src<<endl;
for(int i=0;i<V;i++)
{
cout<<src<<"->"<<i<<"="<<dist[i]<<endl;
}
}

};

int main() {
DGraph g(5);
g.AddEdge(0,1,4);
g.AddEdge(0,2,1);
g.AddEdge(3,4,1);
g.AddEdge(1,3,2);
g.AddEdge(2,4,3);
g.Dij_shortest(0);
}



