#include <iostream>
#include <climits>
#include <queue>
#include <vector>
#include <unordered_map>
#include <list>
using namespace std;

vector<pair<pair<int,int>,int>> calculatePrims(int n, vector<pair<pair<int,int>,int>>& g) {
    unordered_map<int, list<pair<int,int>>> adj;
    for(int i = 0; i < g.size(); i++) {
        int u = g[i].first.first;
        int v = g[i].first.second;
        int w = g[i].second;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<int> key(n + 1, INT_MAX);
    vector<bool> visited(n + 1, false);
    vector<int> parent(n + 1, -1);

    key[1] = 0;

    for(int i = 1; i <= n; i++) {
        int mini = INT_MAX;
        int u = -1;
        
        // FIX 1: Use 'v' to find the minimum key vertex, not 'i'
        for(int v = 1; v <= n; v++) {
            if(!visited[v] && key[v] < mini) {
                mini = key[v];
                u = v;
            }
        }

        if(u == -1) break; // Optimization: graph might be disconnected
        visited[u] = true;

        for(auto it : adj[u]) {
            int v = it.first;
            int weight = it.second;
            if(!visited[v] && weight < key[v]) {
                key[v] = weight;
                parent[v] = u;
            }
        }
    }

    vector<pair<pair<int,int>,int>> result;
    for(int i = 2; i <= n; i++) {
        // Only add valid edges where a parent was found
        if(parent[i] != -1) {
            result.push_back({{parent[i], i}, key[i]});
        }
    }
    return result;
}

int main() {
    int V = 5;
    vector<pair<pair<int,int>,int>> edges = {
        {{1,2}, 2}, {{1,3}, 3}, {{2,3}, 1}, {{2,4}, 4}, {{3,4}, 5}, {{4,5}, 7}
    };
    
    // FIX 2: Correct capitalization
    auto mst = calculatePrims(V, edges);

    cout << "Edges in MST:\n";
    // FIX 3: Print 'mst' (the result), not 'edges' (the input)
    for (auto edge : mst) {
        cout << edge.first.first << " - "
             << edge.first.second << "  weight: "
             << edge.second << endl;
    }
    return 0;
}

