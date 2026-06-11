/*
Problem(2): Count Strongly Connected Components (Kosaraju's Algorithm).
Input 
5 vertices Directed Graph Edges: 1->0, 0->2, 2->1, 0->3, 3->4
Output
3
*/

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

void dfs(int node, vector<int>& vis, vector<int> adj[], stack<int>& st){
    vis[node] = 1;
    for(auto it : adj[node]){
        if(!vis[it]) dfs(it, vis, adj, st);
    }
    st.push(node);
}

void dfsRev(int node, vector<int>& vis, vector<int> adjRev[]){
    vis[node] = 1;
    for(auto it : adjRev[node]){
        if(!vis[it]) dfsRev(it, vis, adjRev);
    }
}

int kosaraju(int V, vector<int> adj[]){
    vector<int> vis(V, 0);
    stack<int> st;
    for(int i = 0; i < V; i++){
        if(!vis[i]) dfs(i, vis, adj, st);
    }
    vector<int> adjRev[V];
    for(int i = 0; i < V; i++){
        vis[i] = 0;
        for(auto it : adj[i]){
            adjRev[it].push_back(i);
        }
    }
    int scc = 0;
    while(!st.empty()){
        int node = st.top();
        st.pop();
        if(!vis[node]){
            scc++;
            dfsRev(node, vis, adjRev);
        }
    }
    return scc;
}

int main(){
    int V = 5;
    vector<int> adj[5];
    adj[1].push_back(0); adj[0].push_back(2);
    adj[2].push_back(1); adj[0].push_back(3);
    adj[3].push_back(4);

    cout << "Total SCCs: " << kosaraju(V, adj);
}