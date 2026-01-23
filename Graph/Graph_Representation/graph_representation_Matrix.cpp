#include <iostream>
using namespace std;
int main()
{
    int V, E;
    cout << "Enter total vertex (Nodes): ";
    cin >> V;
    cout << "Enter total edges (Connections): ";
    cin >> E;
    int matrix[100][100];
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            matrix[i][j] = 0;
        }
    }
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cout << "Enter edge " << i + 1 << " (u v): ";
        cin >> u >> v;
        matrix[u][v] = 1;
        matrix[v][u] = 1;
    }
    cout << "\n----- Graph Representation (Adjacency Matrix) -----\n";
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}