/*
PROBLEM 04. Topological Sort (Kahn's Algorithm)

Given a Directed Acyclic Graph (DAG), return a valid topological ordering of its vertices 
using an in-degree calculation map array and a BFS processing queue layout.

Sample input
6 6
5 0
5 2
2 3
3 1
4 1
4 0

Sample output
4 5 0 2 3 1
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int vertices, edges;
    if (!(cin >> vertices >> edges)) return 0;

    vector<vector<int>> adj(vertices);
    vector<int> in_degree(vertices, 0);

    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        in_degree[v]++;
    }

    queue<int> q;
    for (int i = 0; i < vertices; i++) {
        if (in_degree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> topo_order;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        topo_order.push_back(node);

        for (int neighbor : adj[node]) {
            in_degree[neighbor]--;
            if (in_degree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    for (int i = 0; i < topo_order.size(); i++) {
        cout << topo_order[i] << (i == topo_order.size() - 1 ? "" : " ");
    }
    cout << "\n";
    return 0;
}