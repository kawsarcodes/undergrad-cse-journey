/*-----------DFS-------------
Problem 7: Topological Sort
Given a directed acyclic graph (DAG), return a topological ordering of its vertices.
Topological sort is possible only for directed acyclic graphs.

Sample Input:
Nodes: 4, Edges: 4
0 1
0 2
1 3
2 3

Sample Output:
Topological sort: 0 2 1 3 (অথবা 0 1 2 3)
*/

#include <iostream>
#include <stack>
#include <vector>

using namespace std;
void dfsTopo(int current, vector<vector<int>> &graph, vector<bool> &visited, stack<int> &st)
{
    visited[current] = true;
    for (int neighbour : graph[current])
    {
        if (!visited[neighbour])
        {
            dfsTopo(neighbour, graph, visited, st);
        }
    }
    st.push(current);
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
    stack<int> st;
    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            dfsTopo(i, graph, visited, st);
        }
    }
    cout << "Topological sort: ";
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
    return 0;
}