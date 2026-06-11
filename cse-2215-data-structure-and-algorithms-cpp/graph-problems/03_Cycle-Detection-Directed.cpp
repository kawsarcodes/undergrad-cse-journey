/*
PROBLEM 03. Cycle Detection in a Directed Graph

Detect if a directed graph contains at least one cycle using tracking arrays to identify 
nodes currently living on the active DFS path recursion stack.

Sample input
4 4
0 1
1 2
2 3
3 1

Sample output
1
*/

#include <bits/stdc++.h>
using namespace std;

bool check_cycle_dfs(int node, const vector<vector<int>>& adj, vector<bool>& visited, vector<bool>& path_visited) {
    visited[node] = true;
    path_visited[node] = true;

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            if (check_cycle_dfs(neighbor, adj, visited, path_visited)) return true;
        } else if (path_visited[neighbor]) {
            return true;
        }
    }

    path_visited[node] = false;
    return false;
}

int main() {
    int vertices, edges;
    if (!(cin >> vertices >> edges)) return 0;

    vector<vector<int>> adj(vertices);
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    vector<bool> visited(vertices, false);
    vector<bool> path_visited(vertices, false);
    bool has_cycle = false;

    for (int i = 0; i < vertices; i++) {
        if (!visited[i]) {
            if (check_cycle_dfs(i, adj, visited, path_visited)) {
                has_cycle = true;
                break;
            }
        }
    }

    cout << has_cycle << "\n";
    return 0;
}