/*
PROBLEM 02: Prim's Algorithm for Minimum Spanning Tree
Given a connected, undirected graph represented as an adjacency matrix, construct its Minimum
Spanning Tree (MST). The algorithm starts from an arbitrary root vertex and grows the spanning
tree greedily by choosing the smallest possible edge connecting a vertex in the tree to a vertex outside.

Write a program that reads a V x V adjacency matrix representing the graph's connections and edge
weights, tracks vertex components using key metrics, and lists out each selected structural edge with
its weight sequentially.

Sample Input
5
0 2 0 6 0
2 0 3 8 5
0 3 0 0 7
6 8 0 0 9
0 5 7 9 0

Sample Output
Edge 	Weight
0 - 1 	2 
1 - 2 	3 
0 - 3 	6 
1 - 4 	5 
*/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int minKey(vector<int> &key, vector<bool> &mstSet) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < mstSet.size(); v++)
        if (mstSet[v] == false && key[v] < min){
            min = key[v];
            min_index = v;
        }
    return min_index;
}

void printMST(vector<int> &parent, vector<vector<int>> &graph) {
    cout << "Edge \tWeight\n";
    for (int i = 1; i < graph.size(); i++)
        cout << parent[i] << " - " << i << " \t"
             << graph[parent[i]][i] << " \n";
}

void primMST(vector<vector<int>> &graph) {
    int V = graph.size();
    vector<int> parent(V);
    vector<int> key(V);
    vector<bool> mstSet(V);

    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, mstSet);
        mstSet[u] = true;

        for (int v = 0; v < V; v++)
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v]){
                parent[v] = u;
                key[v] = graph[u][v];
            }
    }
    printMST(parent, graph);
}

int main() {
    int v;
    if (!(cin >> v)) return 0;

    vector<vector<int>> graph(v, vector<int>(v));
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            cin >> graph[i][j];
        }
    }

    primMST(graph);
    return 0;
}