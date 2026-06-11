/*
Problem(4): Find the edge that forms a cycle in a tree so it can be removed.
Input 
edges = [[1,2],[1,3],[2,3]]
Output
2 3
*/

#include<iostream>
#include<vector>
using namespace std;

class DisjointSet{
        vector<int> parent, size;
    public:
        DisjointSet(int n){
            parent.resize(n + 1);
            size.resize(n + 1, 1);
            for(int i = 0; i <= n; i++) parent[i] = i;
        }
        int findUPar(int node){
            if(node == parent[node]) return node;
            return parent[node] = findUPar(parent[node]);
        }
        bool unionBySize(int u, int v){
            int ulp_u = findUPar(u);
            int ulp_v = findUPar(v);
            if(ulp_u == ulp_v) return false;
            if(size[ulp_u] < size[ulp_v]){
                parent[ulp_u] = ulp_v;
                size[ulp_v] += size[ulp_u];
            } else {
                parent[ulp_v] = ulp_u;
                size[ulp_u] += size[ulp_v];
            }
            return true;
        }
};

vector<int> findRedundantConnection(vector<vector<int>>& edges){
    int n = edges.size();
    DisjointSet ds(n);
    for(auto edge : edges){
        if(!ds.unionBySize(edge[0], edge[1])){
            return edge;
        }
    }
    return {};
}

int main(){
    vector<vector<int>> edges = {{1, 2}, {1, 3}, {2, 3}};
    vector<int> redundant = findRedundantConnection(edges);
    cout << "Redundant edge: " << redundant[0] << " " << redundant[1];
}