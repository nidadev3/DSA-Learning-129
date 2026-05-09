#include<iostream>
#include<vector>
using namespace std;


void displayNeighbors(int node, vector<int> adj[]) {
cout << "Neighbors of vertex "
         << node << " are: ";

    for(int i = 0; i < adj[node].size(); i++) {
        cout << adj[node][i] << " ";
    }

    cout << endl;



}

int main() {

    int n, m;

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> m;

    int type;

    cout << "Enter graph type (0 = Undirected, 1 = Directed): ";
    cin >> type;

    vector<int> adj[n];

    cout << "Enter edges (u v):\n";

    for(int i = 0; i < m; i++) {

        int u, v;
        cin >> u >> v;

        if(type == 0) {
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        else {
            adj[u].push_back(v);
        }
    }

    // Print adjacency list
    cout << "\nAdjacency List:\n";

    for(int i = 0; i < n; i++) {

        cout << i << " -> ";

        for(int j = 0; j < adj[i].size(); j++) {
            cout << adj[i][j] << " ";
        }

        cout << endl;
    }

    int node;

    cout << "\nEnter vertex to find neighbors: ";
    cin >> node;

    displayNeighbors(node, adj);

    return 0;
}