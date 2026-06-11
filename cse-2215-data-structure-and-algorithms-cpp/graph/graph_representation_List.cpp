#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int V, E;
    cout << "Enter total vertex (Nodes): ";
    cin >> V;
    cout << "Enter total edges (Connections): ";
    cin >> E;
    vector<vector<int>> graph(V);
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cout << "Enter edge " << i + 1 << " (u v): ";
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    cout << "\n----- Graph Representation (Adjacency List) -----\n";
    for (int i = 0; i < V; i++)
    {
        cout << "Node " << i << " is connected to: ";
        for (int j = 0; j < graph[i].size(); j++)
        {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}