/*
Problem 1: Check Graph Connectivity
Sample Input: graph = [[0, 1, 0, 0], [1, 0, 1, 0], [0, 1, 0, 1], [0, 0, 1, 0]]
Sample Output: The graph is connected
*/

#include <iostream>
#include <queue>
#include <vector>
using namespace std;
void checkConnected(int source, int v, vector<vector<int>> &graph)
{
    queue<int> q;
    vector<bool> visited(v, false);
    q.push(source);
    visited[source] = true;
    int count = 0;
    while (!q.empty())
    {
        int current = q.front();
        q.pop();
        count++;
        for (int neighbour : graph[current])
        {
            if (!visited[neighbour])
            {
                visited[neighbour] = true;
                q.push(neighbour);
            }
        }
    }
    if (count == v)
        cout << "The graph is connected" << endl;
    else
        cout << "The graph is NOT connected" << endl;
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
    checkConnected(0, v, graph);
    return 0;
}