/* ---------- DFS----------
Problem 6: Cycle Detection in Directed Graph
Sample Input:
Nodes: 3, Edges: 3
0 1
1 2
2 0

Sample Output:
The graph contains a cycle
*/

#include <iostream>
#include <vector>
using namespace std;

bool dfsCheckCycle(int current, vector<vector<int>> &graph, vector<bool> &visited, vector<bool> &recStack)
{
    visited[current] = true;
    recStack[current] = true;
    for (int neighbour : graph[current])
    {
        if (!visited[neighbour])
        {
            if (dfsCheckCycle(neighbour, graph, visited, recStack))
            {
                return true;
            }
        }
        else if (recStack[neighbour])
        {
            return true;
        }
    }
    recStack[current] = false;
    return false;
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
    }
    vector<bool> visited(v, false);
    vector<bool> recStack(v, false);
    bool hasCycle = false;
    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            if (dfsCheckCycle(i, graph, visited, recStack))
            {
                hasCycle = true;
                break;
            }
        }
    }
    if (hasCycle)
    {
        cout << "The graph contains a cycle" << endl;
    }
    else
    {
        cout << "No cycle found" << endl;
    }
    return 0;
}