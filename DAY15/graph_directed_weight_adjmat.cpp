#include <iostream>
#include<vector>
using namespace std;

class GraphDW
{

int v;
vector<vector<int>>adjmatrix;

public:
GraphDW(int vertex)
{
v=vertex;
adjmatrix.resize(v,vector<int>(v,0));
}

void AddEdge(int src,int dest,int weight)
{
if(src>=0 && src<v && dest>=0 && dest<v)
{
adjmatrix[src][dest]=weight;
}
}

void print()const
{
for(int i=0;i<v;i++)
{
for(int j=0;j<v;j++)
{
cout<<adjmatrix[i][j]<<" ";
}
cout<<endl;
}
}
};
int main() {
 
GraphDW g(4);
g.AddEdge(1,2,10);
g.AddEdge(0,3,20);
g.AddEdge(2,3,30);
g.AddEdge(3,1,40);
g.print();
    return 0;
}



