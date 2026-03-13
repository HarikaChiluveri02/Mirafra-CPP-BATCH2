#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

class GraphBFS
{
	vector<vector<int>>adj;

	public:
	GraphBFS(int vertices) : adj(vertices) {}
	void AddEdge(int u,int v)
	{
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	void BFS_Level(int start)
	{
		int V=adj.size();
		vector<bool>visited(V,false);
		queue<int>q;
		visited[start]=true;
		q.push(start);

		while(!q.empty())
		{
			int node=q.front();
			q.pop();
			cout<<node<<" ";
			for(auto& neighbour:adj[node])
			{
				if(!visited[neighbour])
				{
					visited[neighbour]=true;
					q.push(neighbour);
				}
			}
		}
	}

	void BFS_ShortestPath(int start,int end)
	{
		int v=adj.size();
		vector<bool>visited(v,false);
		vector<int>parent(v,-1);
		queue<int>q;
		visited[start]=true;
		q.push(start);

		while(!q.empty())
		{
			int node=q.front();
			q.pop();

			for(auto& neighbour:adj[node])
			{
				if(!visited[neighbour])
				{
					visited[neighbour]=true;
					parent[neighbour]=node;
					q.push(neighbour);
				}
			}
		}

		vector<int>path;
		for(int i=end;i!=-1;i=parent[i])
			path.push_back(i);

		reverse(path.begin(),path.end());
		cout<<"Shortest Path:";
		for(auto i:path)
			cout<<i<<" ";


		cout<<"\nThe Path distance:"<<path.size()-1<<endl;
	}
        
void print()
{
int node=0;
for(const auto& row:adj)
{
cout<<node<<": { ";
for(int val:row)
{
cout<<val<<" ";
}
node++;
cout<<"}"<<endl;
}
}

};
int main() {
	GraphBFS g(5);
	g.AddEdge(0,1);
	g.AddEdge(0,2);
	g.AddEdge(1,2);
	g.AddEdge(1,3);
	g.AddEdge(2,4);
	g.AddEdge(3,4);
	g.BFS_Level(0);
	g.BFS_ShortestPath(1,4);
        g.print();
	return 0;
}



