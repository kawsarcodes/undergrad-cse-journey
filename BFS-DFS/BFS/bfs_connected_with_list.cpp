#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void bfs(int source, int v, vector<vector<int>> &graph)
{
    queue<int> q;
    vector<bool> visited(v, false);
    vector<int> parent(v, -1);
    vector<int> distance(v, 0);

    q.push(source);
    visited[source] = true;
    parent[source] = -1;
    distance[source] = 0;

    cout << "BFS Output: ";

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
                parent[neighbour] = current;
                distance[neighbour] = distance[current] + 1;
            }
        }
    }
    cout << endl;
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
        cout << "Enter edge" << i << " (u v): ";
        cin >> x >> y;

        if (x >= 0 && x < v && y >= 0 && y < v)
        {
            graph[x].push_back(y);
            graph[y].push_back(x);
        }
    }

    int src;
    cout << "Enter the source: ";
    cin >> src;

    bfs(src, v, graph);

    return 0;
}