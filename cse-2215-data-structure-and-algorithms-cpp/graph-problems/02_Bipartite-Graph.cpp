/*
PROBLEM 02. Bipartite Graph Verification (Graph Coloring)

Determine if an unweighted graph can be colored using exactly two colors such that no 
two adjacent nodes share the same color.

Sample input
4 4
0 1
1 2
2 3
3 0

Sample output
1
*/

#include <bits/stdc++.h>
using namespace std;

bool check_bipartite_bfs(int start, const vector<vector<int>>& adj, vector<int>& color) {
    queue<int> q;
    q.push(start);
    color[start] = 0;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int neighbor : adj[node]) {
            if (color[neighbor] == -1) {
                color[neighbor] = 1 - color[node];
                q.push(neighbor);
            } else if (color[neighbor] == color[node]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int vertices, edges;
    if (!(cin >> vertices >> edges)) return 0;

    vector<vector<int>> adj(vertices);
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> color(vertices, -1);
    bool is_bipartite = true;

    for (int i = 0; i < vertices; i++) {
        if (color[i] == -1) {
            if (!check_bipartite_bfs(i, adj, color)) {
                is_bipartite = false;
                break;
            }
        }
    }

    cout << is_bipartite << "\n";
    return 0;
}