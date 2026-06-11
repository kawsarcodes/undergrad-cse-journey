/*
PROBLEM 02: Shortest path passing through a mandatory node

You are given a connected weighted directed graph with n vertices (numbered 0 to n-1) and m edges. Each 
edge connects two vertices u and v with a weight w. You are also given three special vertices: s (source node), 
t (destination node), and k (mandatory node). You must find the shortest path from s to t that passes through 
the node k at least once. If there is no valid path, print "No valid path".

Input: The first line contains two integers: n (number of vertices) and m (number of edges). The next m 
lines each contain three integers: u v w (two endpoints of the edge and its weight). The last line contains 
three integers: s (source node), t (destination node), and k (mandatory node).

Output: If there is no valid path, print “No valid path”. Otherwise, first print the shortest distance and 
then print the path in the proper format given.

Sample Input
6 7  
0 1 4  
0 2 2  
1 2 5  
1 3 10  
2 4 3  
4 3 4  
3 5 11  
0 5 2 

Sample Output
Shortest distance from 0 to 5 passing through 2: 20  
Path: 0 -> 2 -> 4 -> 3 -> 5
*/

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
using namespace std;

const int INF = INT_MAX;

pair<vector<int>, vector<int>> dijkstra(int n, const vector<vector<pair<int, int>>>& adj, int src) {
    vector<int> dist(n, INF);
    vector<int> parent(n, -1);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if (d > dist[u]) continue;

        for (auto edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;

            if (dist[u] != INF && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }
    return {dist, parent};
}

int main() {
    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    int s, t, k;
    cin >> s >> t >> k;

    auto result1 = dijkstra(n, adj, s);
    vector<int> distFromS = result1.first;
    vector<int> parentFromS = result1.second;

    auto result2 = dijkstra(n, adj, k);
    vector<int> distFromK = result2.first;
    vector<int> parentFromK = result2.second;

    if (distFromS[k] == INF || distFromK[t] == INF) {
        cout << "No valid path\n";
        return 0;
    }

    int totalDistance = distFromS[k] + distFromK[t];

    vector<int> path;
    
    int curr = t;
    while (curr != k && curr != -1) {
        path.push_back(curr);
        curr = parentFromK[curr];
    }
    
    curr = k;
    while (curr != s && curr != -1) {
        path.push_back(curr);
        curr = parentFromS[curr];
    }
    path.push_back(s);

    reverse(path.begin(), path.end());

    cout << "Shortest distance from " << s << " to " << t << " passing through " << k << ": " << totalDistance << "\n";
    cout << "Path: ";
    for (size_t i = 0; i < path.size(); i++) {
        cout << path[i];
        if (i < path.size() - 1) {
            cout << " -> ";
        }
    }
    cout << "\n";

    return 0;
}