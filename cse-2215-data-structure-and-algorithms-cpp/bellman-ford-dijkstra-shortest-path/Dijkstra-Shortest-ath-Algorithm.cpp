/*
PROBLEM 02: Dijkstra's Shortest Path Algorithm

Given a connected, undirected graph represented as an adjacency matrix and a starting source vertex,
compute the single-source shortest path distances using a greedy tracking method. The algorithm keeps 
track of visited elements and repeatedly picks the unvisited vertex with the minimum absolute key distance 
to expand its path optimizations until all intersections are resolved.

Write a program that takes the number of vertices, reads the structural V x V matrix entries representing 
the system layout, takes a chosen source point index, and calculates the completed minimum paths.

Sample Input
9
0 4 0 0 0 0 0 8 0
4 0 8 0 0 0 0 11 0
0 8 0 7 0 4 0 0 2
0 0 7 0 9 14 0 0 0
0 0 0 9 0 10 0 0 0
0 0 4 14 10 0 2 0 0
0 0 0 0 0 2 0 1 6
8 11 0 0 0 0 1 0 7
0 0 2 0 0 0 6 7 0
0

Sample Output
Vertex	Distance from Source
Distance from Source to node 0: 0
Distance from Source to node 1: 4
Distance from Source to node 2: 12
Distance from Source to node 3: 19
Distance from Source to node 4: 21
Distance from Source to node 5: 11
Distance from Source to node 6: 9
Distance from Source to node 7: 8
Distance from Source to node 8: 14
*/

#include <iostream>
#include <vector>
using namespace std;

const int INF = 99999;

int minDistance(vector<int>& dist, vector<bool>& visited) {
    int min = INF;
    int minIndex = -1;
    int n = dist.size();

    for (int i = 0; i < n; i++) {
        if (dist[i] < min && !visited[i]) {
            min = dist[i];
            minIndex = i;
        }
    }
    return minIndex;
}

void printSolution(vector<int>& dist) {
    cout << "\nVertex\tDistance from Source\n";
    int n = dist.size();
    for (int i = 0; i < n; i++) {
        cout << "Distance from Source to node " << i << ": " << dist[i] << "\n";
    }
}

void dijkstra(vector<vector<int>>& graph, int src) {
    int n = graph.size();
    vector<int> dist(n, INF);
    vector<bool> visited(n, false);

    dist[src] = 0;

    for (int i = 0; i < n - 1; i++) {
        int u = minDistance(dist, visited);
        if (u == -1) break;
        visited[u] = true;

        for (int v = 0; v < n; v++) {
            if (graph[u][v] != 0 && !visited[v] && dist[u] != INF && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
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

    dijkstra(graph, src);
    return 0;
}