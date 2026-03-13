#include <iostream>
#include<vector>
using namespace std;

class GraphMatrix
{

int v;
vector<vector<int>>matrix;

public:

GraphMatrix(int vertices)
{
v=vertices;
matrix.resize(v,vector<int>(v,0));
}

//undirected->Symmetric (too and fro)
//Directed->No symmetric
void addEdge(int u,int v)
{
matrix[u][v]=1;
matrix[v][u]=1;//remove for directed
}

void print()
{
for(int i=0;i<v;i++)
{
for(int j=0;j<v;j++)
{
cout<<matrix[i][j]<<" ";
}
cout<<endl;
}
}
};
int main() {

GraphMatrix g(4);
g.addEdge(2,1);
g.addEdge(3,1);
g.addEdge(1,0);
g.print();
}



