#include <iostream>
#include <unordered_map>
#include<map>
#include<list>
using namespace std;


class GraphAdjList
{

unordered_map<int,list<int>>adjmat;

public:

void AddEdge(int u,int v,bool directed=false)
{
adjmat[u].push_back(v);
if(!directed)
adjmat[v].push_back(u);
}

void print()
{
for(const auto& pair : adjmat)
{
cout<<pair.first<<"->";
for(const auto&val : pair.second)
{
cout<<val<<" ";
}

cout<<endl;
}
}

};
int main() {

GraphAdjList g;
g.AddEdge(1,2);
g.AddEdge(0,1);
g.AddEdge(2,3);
g.AddEdge(3,0);
g.print();
    return 0;
}



