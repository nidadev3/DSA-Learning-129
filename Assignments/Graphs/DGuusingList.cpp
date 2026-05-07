#include<iostream>
#include<vector>
using namespace std;

int main(){

    int n, m;

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> m;

    // Adjacency List
    vector<int> adj[n + 1];

    cout << "Enter edges (u v):\n";

    for(int i = 0; i < m; i++){

        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
    }

    cout << "\nDirected Graph Adjacency List:\n";

    for(int i = 1; i <= n; i++){

        cout << i << " -> ";

        for(int j = 0; j < adj[i].size(); j++){

            cout << adj[i][j] << " ";
        }

       cout << "\n";
    }

    return 0;
}