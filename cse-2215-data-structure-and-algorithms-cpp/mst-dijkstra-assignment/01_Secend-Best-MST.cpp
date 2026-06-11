/*
PROBLEM 01: Second Best Minimum Spanning Tree

You are given an undirected connected weighted graph with n vertices and m edges. Each edge has a weight 
representing its cost. Find the Second Best Minimum Spanning Tree (MST).

Input: The first line contains two integers: n (number of vertices) and m (number of edges). The next m 
lines each contain three integers: u v w (two endpoints of the edge and its weight). Here m > n and the 
graph is connected, also there are multiple spanning trees in the given inputs.

Output: Print the second best MST weight. Then in the next lines, print the edges for the second best MST.

Sample Input
4 5  
0 1 1  
1 2 2  
0 2 3  
2 3 1  
1 3 4 

Sample Output
Second Best MST Weight: 5  
Edges in Second Best MST:  
0 - 1 (1)  
0 - 2 (3)  
2 - 3 (1) 
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class DisjointSet {
    vector<int> parent, rank;
public:
    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) parent[i] = i;
    }
    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }
    bool unionSet(int a, int b) {
        int rootA = find(a);
        int rootB = find(b);
        if (rootA == rootB) return false;
        if (rank[rootA] < rank[rootB]) {
            parent[rootA] = rootB;
        } else if (rank[rootA] > rank[rootB]) {
            parent[rootB] = rootA;
        } else {
            parent[rootB] = rootA;
            rank[rootA]++;
        }
        return true;
    }
};

struct Edge {
    int u, v, weight, id;
};

bool compare(Edge a, Edge b) {
    return a.weight < b.weight;
}

int main() {
    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<Edge> edges(m);
    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
        edges[i].id = i;
    }

    sort(edges.begin(), edges.end(), compare);

    DisjointSet ds(n);
    int originalMstWeight = 0;
    vector<Edge> originalMstEdges;

    for (int i = 0; i < m; i++) {
        if (ds.unionSet(edges[i].u, edges[i].v)) {
            originalMstWeight += edges[i].weight;
            originalMstEdges.push_back(edges[i]);
        }
    }

    int secondBestMstWeight = INT_MAX;
    vector<Edge> secondBestMstEdges;

    for (Edge skipEdge : originalMstEdges) {
        DisjointSet currentDs(n);
        int currentWeight = 0;
        int edgesCount = 0;
        vector<Edge> currentEdges;

        for (int i = 0; i < m; i++) {
            if (edges[i].id == skipEdge.id) continue;

            if (currentDs.unionSet(edges[i].u, edges[i].v)) {
                currentWeight += edges[i].weight;
                edgesCount++;
                currentEdges.push_back(edges[i]);
            }
        }

        if (edgesCount == n - 1 && currentWeight < secondBestMstWeight) {
            secondBestMstWeight = currentWeight;
            secondBestMstEdges = currentEdges;
        }
    }

    cout << "Second Best MST Weight: " << secondBestMstWeight << "\n";
    cout << "Edges in Second Best MST:\n";
    for (Edge e : secondBestMstEdges) {
        cout << e.u << " - " << e.v << " (" << e.weight << ")\n";
    }

    return 0;
}