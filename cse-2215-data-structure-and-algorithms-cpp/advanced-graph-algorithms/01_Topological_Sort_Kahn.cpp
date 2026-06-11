/*
Problem(1): Return topological sort order of a DAG using Kahn's algorithm.
Input 
Directed Graph Edges (6 vertices): 5->0, 5->2, 4->0, 4->1, 2->3, 3->1
Output
4 5 0 2 3 1
*/

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> topoSort(int V, vector<int> adj[]){
    vector<int> indegree(V, 0);
    for(int i = 0; i < V; i++){
        for(auto it : adj[i]){
            indegree[it]++;
        }
    }
    queue<int> q;
    for(int i = 0; i < V; i++){
        if(indegree[i] == 0) q.push(i);
    }
    vector<int> topo;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        topo.push_back(node);
        for(auto it : adj[node]){
            indegree[it]--;
            if(indegree[it] == 0) q.push(it);
        }
    }
    return topo;
}

int main(){
    int V = 6;
    vector<int> adj[6];
    adj[5].push_back(0); adj[5].push_back(2);
    adj[4].push_back(0); adj[4].push_back(1);
    adj[2].push_back(3); adj[3].push_back(1);

    vector<int> result = topoSort(V, adj);
    for(int x : result) cout << x << " ";
}