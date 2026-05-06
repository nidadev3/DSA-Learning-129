#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int main() {

    int n, m;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> m;

    vector<pair<int,int>> adj[n+1];

    cout << "Enter edges (u v w):\n";
    for(int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // undirected graph
    }}