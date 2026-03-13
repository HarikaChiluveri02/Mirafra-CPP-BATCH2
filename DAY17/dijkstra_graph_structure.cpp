#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
#include <climits>
using namespace std;

struct Edge
{
    string city;
    int distance;
};

struct Compare
{
    bool operator()(const Edge& a, const Edge& b) const
    {
        return a.distance > b.distance;   // min-heap
    }
};

class DGraph
{
    unordered_map<string, vector<Edge>> adj;

public:

    void AddEdge(string u, string v, int dist)
    {
        adj[u].push_back({v, dist});
        adj[v].push_back({u, dist});
    }

    void Dij_shortest(string src)
    {
        priority_queue<Edge, vector<Edge>, Compare> pq;
        unordered_map<string, int> dist;
        unordered_map<string, bool> visited;

        // initialize
        for(auto &it : adj)
        {
            dist[it.first] = INT_MAX;
            visited[it.first] = false;
        }

        dist[src] = 0;
        pq.push({src, 0});

        while(!pq.empty())
        {
            Edge current = pq.top();
            pq.pop();

            string node = current.city;
            int d = current.distance;

            if(visited[node])
                continue;

            visited[node] = true;

            for(auto edge : adj[node])
            {
                string neighbour = edge.city;
                int weight = edge.distance;

                if(dist[neighbour] > d + weight)
                {
                    dist[neighbour] = d + weight;
                    pq.push({neighbour, dist[neighbour]});
                }
            }
        }

        cout << "From Source : " << src << endl;

        for(auto &it : dist)
        {
            cout << src << " -> "
                 << it.first << " = "
                 << it.second << endl;
        }
    }
};

int main()
{
    DGraph g;

    g.AddEdge("Hyderabad","Chennai",10);
    g.AddEdge("Hyderabad","Bangalore",5);
    g.AddEdge("Chennai","Mumbai",3);
    g.AddEdge("Bangalore","Delhi",8);
    g.AddEdge("Mumbai","Delhi",2);
    g.AddEdge("Bangalore","Mumbai",6);

    g.Dij_shortest("Hyderabad");
}
