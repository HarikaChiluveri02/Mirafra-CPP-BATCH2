#include <iostream>
#include <vector>
using namespace std;

enum Feature
{
    ENGINE_CONTROL,
    FUEL_SYSTEM,
    IGNITION,
    SENSOR_MODULE,
    LOGGING_SYSTEM,
    TOTAL_FEATURES
};

string featureName[TOTAL_FEATURES] = {"Engine Control","Fuel System","Ignition","Sensor Module","Logging System"};

void DFS(int node, vector<vector<int>>& adj, vector<bool>& visited)
{
    visited[node] = true;
    cout << featureName[node] << "  ";

    for(int neighbor : adj[node])
    {
        if(!visited[neighbor])
            DFS(neighbor, adj, visited);
    }
}

int main()
{
    vector<vector<int>> adj(TOTAL_FEATURES);

    adj[ENGINE_CONTROL].push_back(FUEL_SYSTEM);
    adj[ENGINE_CONTROL].push_back(IGNITION);
    adj[FUEL_SYSTEM].push_back(SENSOR_MODULE);
    adj[IGNITION].push_back(SENSOR_MODULE);
    adj[SENSOR_MODULE].push_back(LOGGING_SYSTEM);

    vector<bool> visited(TOTAL_FEATURES, false);

    DFS(ENGINE_CONTROL, adj, visited);
    cout<<endl;
    return 0;
}
