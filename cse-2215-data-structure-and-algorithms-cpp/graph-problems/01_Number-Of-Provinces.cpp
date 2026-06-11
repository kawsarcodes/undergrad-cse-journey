/*
PROBLEM 01. Number of Provinces (Connected Components)

Given an undirected graph represented as an adjacency matrix where is_connected[i][j] = 1 
indicates a direct connection between node i and node j, find the total number of connected components.

Sample input
3
1 1 0
1 1 0
0 0 1

Sample output
2
*/

#include <bits/stdc++.h>
using namespace std;

void dfs(int node, const vector<vector<int>>& adj_matrix, vector<bool>& visited, int n) {
    visited[node] = true;
    for (int i = 0; i < n; i++) {
        if (adj_matrix[node][i] == 1 && !visited[i]) {
            dfs(i, adj_matrix, visited, n);
        }
    }
}

int main() {
    int n;
    if (!(cin >> n)) return 0;

    vector<vector<int>> adj_matrix(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> adj_matrix[i][j];
        }
    }

    vector<bool> visited(n, false);
    int provinces = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            provinces++;
            dfs(i, adj_matrix, visited, n);
        }
    }

    cout << provinces << "\n";
    return 0;
}