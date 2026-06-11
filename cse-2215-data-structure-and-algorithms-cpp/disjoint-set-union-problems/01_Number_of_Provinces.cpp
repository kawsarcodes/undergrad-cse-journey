/*
Problem(1): Find the total number of connected provinces using DSU.
Input 
Connected matrix (Graph):
1 1 0
1 1 0
0 0 1
Output
2
*/

#include<iostream>
#include<vector>
using namespace std;

class DisjointSet{
        vector<int> parent, size;
    public:
        DisjointSet(int n){
            parent.resize(n);
            size.resize(n, 1);
            for(int i = 0; i < n; i++) parent[i] = i;
        }
        int findUPar(int node){
            if(node == parent[node]) return node;
            return parent[node] = findUPar(parent[node]);
        }
        void unionBySize(int u, int v){
            int ulp_u = findUPar(u);
            int ulp_v = findUPar(v);
            if(ulp_u == ulp_v) return;
            if(size[ulp_u] < size[ulp_v]){
                parent[ulp_u] = ulp_v;
                size[ulp_v] += size[ulp_u];
            } else {
                parent[ulp_v] = ulp_u;
                size[ulp_u] += size[ulp_v];
            }
        }
};

int numProvinces(vector<vector<int>>& adj, int V){
    DisjointSet ds(V);
    for(int i = 0; i < V; i++){
        for(int j = 0; j < V; j++){
            if(adj[i][j] == 1){
                ds.unionBySize(i, j);
            }
        }
    }
    int provinces = 0;
    for(int i = 0; i < V; i++){
        if(ds.findUPar(i) == i) provinces++;
    }
    return provinces;
}

int main(){
    vector<vector<int>> adj = {
        {1, 1, 0},
        {1, 1, 0},
        {0, 0, 1}
    };
    cout << "Provinces: " << numProvinces(adj, 3);
}