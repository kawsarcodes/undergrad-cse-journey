/*
Problem 5: Find the Connected Components
Sample Input (Converted to Edges for List):
Nodes: 3, Edges: 2
0 1
1 2

Sample Output:
Component 1: 0 1 2
*/

#include <iostream>
#include <queue>
#include <vector>
using namespace std;
void bfs(int source, int v, vector<vector<int>> &graph, vector<bool> &visited)
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
    vector<bool> visited(v, false);
    int componentCount = 0;
    cout << "Connected components: " << endl;
    for (int i = 0; i < v; i++)
    {
        if (visited[i] == false)
        {
            componentCount++;
            cout << "Component " << componentCount << ": ";
            bfs(i, v, graph, visited);
            cout << endl;
        }
    }
    return 0;
}