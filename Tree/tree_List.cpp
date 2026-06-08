#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int nodes;
    cout << "Enter total nodes: ";
    cin >> nodes;
    int edges = nodes - 1;
    vector<vector<int>> tree(nodes + 1);
    cout << "Enter " << edges << " edges (Parent Child):\n";
    for (int i = 0; i < edges; i++)
    {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    cout << "\n----- Tree Structure (Adjacency List) -----\n";
    for (int i = 1; i <= nodes; i++)
    {
        cout << "Node " << i << " is connected with: ";
        for (int child : tree[i])
        {
            cout << child << " ";
        }
        cout << endl;
    }
    return 0;
}