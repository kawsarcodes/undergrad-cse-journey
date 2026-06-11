/*
PROBLEM 01: Kruskal's Algorithm for Minimum Spanning Tree
Given a connected, undirected, and weighted graph with n vertices, find the Minimum Spanning Tree (MST)
weight using Kruskal's algorithm. The algorithm sorts all the edges from lowest weight to highest weight
and uses a Disjoint Set Union (DSU) data structure with path compression and union by rank to detect
and prevent cycles while forming the tree.

Write a program that inputs the number of vertices and the complete list of edge connections with 
their respective weights, then calculates the minimum overall cost to span the entire graph.

Sample Input
4 5
0 1 10
0 2 6
0 3 5
1 3 15
2 3 4

Sample Output
Minimum Spanning Tree cost: 15
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class DisjointSet {
    vector<int> parent, rank;

public:
    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for(int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unionSet(int a, int b) {
        int rootA = find(a);
        int rootB = find(b);

        if (rootA == rootB)
            return;

        if (rank[rootA] < rank[rootB]){
            parent[rootA] = rootB;
        } else if(rank[rootA] > rank[rootB]){
            parent[rootB] = rootA;
        } else {
            parent[rootB] = rootA;
            rank[rootA]++;
        }
    }
};

struct Edge {
    int u, v, weight;
};

bool compare(Edge a, Edge b) {
    return a.weight < b.weight;
}

int kruskal(int n, vector<Edge>& edges) {
    sort(edges.begin(), edges.end(), compare);
    DisjointSet ds(n);
    int totalCost = 0;

    for (Edge e : edges) {
        int u = e.u;
        int v = e.v;

        if (ds.find(u) != ds.find(v)){
            ds.unionSet(u, v);
            totalCost += e.weight;
        }
    }
    return totalCost;
}

int main() {
    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<Edge> edges(m);
    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
    }

    cout << "Minimum Spanning Tree cost: "
         << kruskal(n, edges) << endl;

    return 0;
}