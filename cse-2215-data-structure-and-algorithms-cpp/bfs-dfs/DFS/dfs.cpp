#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void dfs(int src, int v, vector<vector<int>> &graph)
{
    stack<int> st;
    vector<bool> visited(v, false);
    vector<int> parent(v, -1);
    vector<int> distance(v, 0);

    st.push(src);
    visited[src] = true;
    parent[src] = -1;
    distance[src] = 0;

    while (!st.empty())
    {
        int current = st.top();
        st.pop();
        cout << current << " ";
        for (int neighbour : graph[current])
        {
            if (!visited[neighbour])
            {
                visited[neighbour] = true;
                st.push(neighbour);
                parent[neighbour] = current;
                distance[neighbour] = distance[current] + 1;
            }
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
        cout << "Enter edge " << i << " (u v): ";
        cin >> x >> y;
        if (x >= 0 && x < v && y >= 0 && y < v)
        {
            graph[x].push_back(y);
            graph[y].push_back(x);
        }
    }

    int source;
    cout << "Enter the source: ";
    cin >> source;
    dfs(source, v, graph);

    return 0;
}