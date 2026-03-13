#include <iostream>
#include<vector>
#include<limits>
#include<iomanip>
using namespace std;
template<typename T>
class GraphDW
{

int v;
T INF;
vector<vector<T>>adjmatrix;

public:
GraphDW(int vertex):v(vertex),INF(numeric_limits<T>::max()),adjmatrix(v,vector<T>(v,INF))
{
}

void AddEdge(int src,int dest,T weight)
{
if(src>=0 && src<v && dest>=0 && dest<v)
{
adjmatrix[src][dest]=weight;
}
}

void print()const
{
for(const auto& row :adjmatrix)
{
for(const auto& val : row)
{
if(val==INF)
cout<<setw(6)<<"INF";
else
cout<<setw(6)<<val;
}
cout<<endl;
}
}

};
int main()
{
GraphDW<int>g(4);
g.AddEdge(1,2,10);
g.AddEdge(0,3,20);
g.AddEdge(2,3,30);
g.AddEdge(3,1,40);
g.print();
    return 0;
}



