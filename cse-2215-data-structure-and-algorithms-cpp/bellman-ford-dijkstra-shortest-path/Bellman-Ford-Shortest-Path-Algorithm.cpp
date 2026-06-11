/*
PROBLEM 01: Bellman-Ford Shortest Path Algorithm

Given a directed, weighted graph represented as an adjacency matrix and a source vertex, find the 
shortest path distance from the source to all other vertices. The Bellman-Ford algorithm repeatedly 
relaxes all edges n-1 times and is capable of handling graphs containing negative edge weights. It also 
runs a final verification pass to detect the presence of any negative weight cycles.

Write a program that takes the number of vertices, a complete V x V adjacency matrix representation 
of the graph, and the source vertex id, then outputs the shortest distance values or flags a negative cycle.

Sample Input
5
0 6 0 7 0
0 0 5 8 -4
0 -2 0 0 0
0 0 -3 0 9
2 0 7 0 0
0

Sample Output
Vertex	Distance from Source
Distance from Source to node 0: 0
Distance from Source to node 1: 2
Distance from Source to node 2: 4
Distance from Source to node 3: 7
Distance from Source to node 4: -2
*/

#include <iostream>
#include <vector>
using namespace std;

const int INF = 99999;

void printSolution(vector<int>& dist) {
    cout << "\nVertex\tDistance from Source\n";
    int n = dist.size();
    for (int i = 0; i < n; i++) {
        cout << "Distance from Source to node " << i << ": " << dist[i] << "\n";
    }
}

void bellmanFord(vector<vector<int>>& graph, int src) {
    int n = graph.size();
    vector<int> dist(n, INF);
    dist[src] = 0;

    for (int count = 0; count < n - 1; count++) {
        for (int u = 0; u < n; u++) {
            for (int v = 0; v < n; v++) {
                if (graph[u][v] != 0 && dist[u] != INF && dist[u] + graph[u][v] < dist[v]) {
                    dist[v] = dist[u] + graph[u][v];
                }
            }
        }
    }

    for (int u = 0; u < n; u++) {
        for (int v = 0; v < n; v++) {
            if (graph[u][v] != 0 && dist[u] != INF && dist[u] + graph[u][v] < dist[v]) {
                cout << "Negative Weight Cycle Found\n";
                return;
            }
        }
    }

    printSolution(dist);
}

int main() {
    int n;
    if (!(cin >> n)) return 0;

    vector<vector<int>> graph(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    int src;
    cin >> src;

    bellmanFord(graph, src);
    return 0;
}