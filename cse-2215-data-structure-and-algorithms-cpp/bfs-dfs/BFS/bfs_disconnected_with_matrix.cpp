#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void bfsComponent(int source, int v, vector<vector<int>> &graph, vector<bool> &visited)
{
    queue<int> q;

    q.push(source);
    visited[source] = true;

    while (!q.empty())
    {
        int current = q.front();
        q.pop();
        cout << current << " ";

        for (int i = 0; i < v; i++)
        {
            if (graph[current][i] == 1)
            {
                int neighbour = i;

                if (!visited[neighbour])
                {
                    visited[neighbour] = true;
                    q.push(neighbour);
                }
            }
        }
    }
}

void bfsDisconnected(int v, vector<vector<int>> &graph)
{
    vector<bool> visited(v, false);
    int componentCount = 0;

    cout << "\nBFS Traversal (Disconnected aware):" << endl;

    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            componentCount++;
            cout << "Component " << componentCount << ": ";
            bfsComponent(i, v, graph, visited);
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

    vector<vector<int>> graph(v, vector<int>(v, 0));

    for (int i = 0; i < e; i++)
    {
        int x, y;
        cout << "Enter edge " << i + 1 << " (u v): ";
        cin >> x >> y;

        if (x >= 0 && x < v && y >= 0 && y < v)
        {
            graph[x][y] = 1;
            graph[y][x] = 1;
        }
    }

    // We do not ask for a single source, we traverse the whole graph
    bfsDisconnected(v, graph);

    return 0;
}