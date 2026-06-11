#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void bfsTraversal(int source, vector<vector<int>> &graph, vector<bool> &visited)
{
    queue<int> q;

    q.push(source);
    visited[source] = true;

    while (!q.empty())
    {
        int current = q.front();
        q.pop();
        cout << current << " ";

        for (int neighbour : graph[current])
        {
            if (!visited[neighbour])
            {
                visited[neighbour] = true;
                q.push(neighbour);
            }
        }
    }
}

void bfsDisconnected(int v, vector<vector<int>> &graph)
{
    vector<bool> visited(v, false);
    int componentCount = 0;

    cout << "BFS Output: " << endl;
    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            componentCount++;
            cout << "Component " << componentCount << ": ";
            bfsTraversal(i, graph, visited);
            cout << endl;
        }
    }
}

int main()
{
    int v, e;
    cout << "Enter the number of vertices: ";
    cin >> v;
    cout << "Enter the number of edges: ";
    cin >> e;

    vector<vector<int>> graph(v);

    for (int i = 0; i < e; i++)
    {
        int x, y;
        cout << "Enter edge " << i + 1 << " (u v): ";
        cin >> x >> y;

        if (x >= 0 && x < v && y >= 0 && y < v)
        {
            graph[x].push_back(y);
            graph[y].push_back(x);
        }
    }

    bfsDisconnected(v, graph);

    return 0;
}