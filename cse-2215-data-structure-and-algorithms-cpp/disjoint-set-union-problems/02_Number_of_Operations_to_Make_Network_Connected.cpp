/*
Problem(2): Find the minimum number of times you need to extract and connect cables to make all computers connected.
Input 
n = 4, connections = [[0,1],[0,2],[1,2]]
Output
1
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

int makeConnected(int n, vector<vector<int>>& connections){
    if(connections.size() < n - 1) return -1;
    DisjointSet ds(n);
    int extraEdges = 0;
    for(auto it : connections){
        int u = it[0];
        int v = it[1];
        if(ds.findUPar(u) == ds.findUPar(v)){
            extraEdges++;
        } else {
            ds.unionBySize(u, v);
        }
    }
    int components = 0;
    for(int i = 0; i < n; i++){
        if(ds.findUPar(i) == i) components++;
    }
    int ans = components - 1;
    if(extraEdges >= ans) return ans;
    return -1;
}

int main(){
    int n = 4;
    vector<vector<int>> connections = {{0, 1}, {0, 2}, {1, 2}};
    cout << "Operations needed: " << makeConnected(n, connections);
}