#include <iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;

class GraphDFS
{
	vector<vector<int>>adj;

	public:
	GraphDFS(int vertices) : adj(vertices) {}
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

	void DFS_Traverse(int start,vector<bool> &visited)
	{
		visited[start]=true;
		cout<<start<<" ";
		for(auto& neighbour:adj[start])
		{
			if(!visited[neighbour])
				DFS_Traverse(neighbour,visited);
		}
	}
        void DFS_Iterative(int start,vector<bool>&visited)
        {
            stack<int>st;
            st.push(start);

            while(!st.empty())
            {
              int node=st.top();
              st.pop();
              if(!visited[node])
              {
               visited[node]=true;
               cout<<node<<" ";
               for(int i=adj[node].size()-1;i>=0;i--)
               {
                int neighbor = adj[node][i];
                if (!visited[neighbor])
                {
                    st.push(neighbor);
                }
               }
              }
            }
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
	GraphDFS g(5);
	vector<bool>visited(5,false);
	g.AddEdge(0,1);
	g.AddEdge(0,2);
	g.AddEdge(1,2);
	g.AddEdge(1,3);
	g.AddEdge(2,4);
	g.AddEdge(3,4);
        cout<<"BFS Traversal:"<<endl;
	g.BFS_Level(0);
	cout<<"\nDFS Traversal:"<<endl;
	g.DFS_Traverse(1,visited);
	cout<<endl;
        vector<bool>visit(5,false);
        cout<<"DFS Iterative :"<<endl;
        g.DFS_Iterative(1,visit);
        cout<<endl;
	g.print();
	return 0;
}



