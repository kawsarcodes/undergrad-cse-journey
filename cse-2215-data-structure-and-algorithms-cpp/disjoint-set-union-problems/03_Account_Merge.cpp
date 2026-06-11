/*
Problem(3): Merge accounts with the same email lists into a unified profile.
Input 
accounts = [["John","johnsmith@mail.com","john_newyork@mail.com"],["John","johnsmith@mail.com","john00@mail.com"],["Mary","mary@mail.com"]]
Output
John: john00@mail.com, john_newyork@mail.com, johnsmith@mail.com
Mary: mary@mail.com
*/

#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<algorithm>
using namespace std;

class DisjointSet{
    public:
        vector<int> parent, size;
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

vector<vector<string>> accountsMerge(vector<vector<string>>& accounts){
    int n = accounts.size();
    DisjointSet ds(n);
    unordered_map<string, int> mapMailNode;
    for(int i = 0; i < n; i++){
        for(int j = 1; j < accounts[i].size(); j++){
            string mail = accounts[i][j];
            if(mapMailNode.find(mail) == mapMailNode.end()){
                mapMailNode[mail] = i;
            } else {
                ds.unionBySize(i, mapMailNode[mail]);
            }
        }
    }
    vector<string> mergedMail[n];
    for(auto it : mapMailNode){
        string mail = it.first;
        int node = ds.findUPar(it.second);
        mergedMail[node].push_back(mail);
    }
    vector<vector<string>> ans;
    for(int i = 0; i < n; i++){
        if(mergedMail[i].size() == 0) continue;
        sort(mergedMail[i].begin(), mergedMail[i].end());
        vector<string> temp;
        temp.push_back(accounts[i][0]);
        for(auto it : mergedMail[i]){
            temp.push_back(it);
        }
        ans.push_back(temp);
    }
    return ans;
}

int main(){
    vector<vector<string>> accounts = {
        {"John", "johnsmith@mail.com", "john_newyork@mail.com"},
        {"John", "johnsmith@mail.com", "john00@mail.com"},
        {"Mary", "mary@mail.com"}
    };
    vector<vector<string>> ans = accountsMerge(accounts);
    for(auto acc : ans){
        cout << acc[0] << ": ";
        for(int i = 1; i < acc.size(); i++) cout << acc[i] << " ";
        cout << endl;
    }
}