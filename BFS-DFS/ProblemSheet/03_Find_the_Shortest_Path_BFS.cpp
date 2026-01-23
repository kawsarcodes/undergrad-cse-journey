/*
Sample Input Sample Output
graph = [[0, 1, 0, 0],
         [1, 0, 1, 1],
         [0, 1, 0, 1],
         [0, 1, 1, 0]], start = 0
Shortest path from 0: [0, 1, 2, 3]
*/

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void bfsShortestPath(int source, int v, vector<vector<int>> &graph)
{
    queue<int> q;
    vector<bool> visited(v, false);
    vector<int> distance(v, 0);
    q.push(source);
    visited[source] = true;
    distance[source] = 0;
    while (!q.empty())
    {
        int current = q.front();
        q.pop();
        for (int neighbour : graph[current])
        {
            if (!visited[neighbour])
            {
                visited[neighbour] = true;
                q.push(neighbour);
                distance[neighbour] = distance[current] + 1;
            }
        }
    }
    cout << "Shortest path from " << source << ": [ ";
    for (int i = 0; i < v; i++)
    {
        cout << distance[i];
        if (i < v - 1)
            cout << ", ";
    }
    cout << " ]" << endl;
}
int main()
{
    int v, e;
    cout << "Enter Nodes and Edges: ";
    cin >> v >> e;
    vector<vector<int>> graph(v);
    for (int i = 0; i < e; i++)
    {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    int src;
    cout << "Enter start node: ";
    cin >> src;
    bfsShortestPath(src, v, graph);
    return 0;
}