#include <iostream>
#include <climits>
#include <vector>
#include <list>
#include <unordered_map>
#include <queue>
#include <utility>
using namespace std;

vector<pair<pair<string,string>,int>> CalculatePrims(string startNode, vector<pair<pair<string,string>,int>> &g)
{
    // Adjacency list: node -> list of (neighbour, weight)
    unordered_map<string, list<pair<string,int>>> adj;

    unordered_map<string,bool> visited;
    unordered_map<string,int> key;
    unordered_map<string,string> parent;

    // Build graph
    for(int i=0;i<g.size();i++)
    {
        string u = g[i].first.first;
        string v = g[i].first.second;
        int w = g[i].second;

        adj[u].push_back({v,w});
        adj[v].push_back({u,w});

        key[u] = INT_MAX;
        key[v] = INT_MAX;
        visited[u] = false;
        visited[v] = false;
    }

    // Min heap: {weight, node}
    priority_queue<pair<int,string>, vector<pair<int,string>>, greater<pair<int,string>>> pq;

    key[startNode] = 0;
    pq.push({0,startNode});

    while(!pq.empty())
    {
        string u = pq.top().second;
        pq.pop();

        if(visited[u])
            continue;

        visited[u] = true;

        for(auto neighbour : adj[u])
        {
            string v = neighbour.first;
            int weight = neighbour.second;

            if(!visited[v] && weight < key[v])
            {
                key[v] = weight;
                parent[v] = u;
                pq.push({key[v], v});
            }
        }
    }

    vector<pair<pair<string,string>, int>> result;
    for(auto &p : parent)
    {
        result.push_back({{p.second, p.first}, key[p.first]});
    }
    return result;
}

int main()
{
    vector<pair<pair<string,string>,int>> edge = 
    {
        {{"Engine Control","Battery Management"},3},
        {{"Engine Control","Dashboard"},4},
        {{"Battery Management","Dashboard"},2},
        {{"Battery Management","ADAS Camera"},6},
        {{"Dashboard","ADAS Camera"},5},
        {{"Dashboard","Rear Parking Sensor"},7},
        {{"ADAS Camera","Infotainment"},4},
        {{"Rear Parking Sensor","Infotainment"},3}
    };

    vector<pair<pair<string,string>,int>> mst;

    mst = CalculatePrims("Engine Control", edge);

    cout << "Minimum Spanning Tree:\n";
    for(auto e : mst)
    {
        cout << e.first.first << " - " 
             << e.first.second << " : " 
             << e.second << endl;
    }

    return 0;
}
