#include<iostream>
#include<vector>
using namespace std;
bool edgeExists(int u, int v, vector<int> adj[]) {
  for(int i = 0; i < adj[u].size(); i++) {
        if(adj[u][i] == v) {
            return true;
        }
    }

    return false;

}

int main() {

    int n, m;
    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> m;

    int type;
    cout << "Enter graph type (0 = undirected, 1 = directed): ";
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

    int u, v;
    cout << "\nEnter two nodes to check edge (u v): ";
    cin >> u >> v;

    if(type == 0) {
        
        if(edgeExists(u, v, adj) || edgeExists(v, u, adj)) {
            cout << "Edge EXISTS between " << u << " and " << v << endl;
        } else {
            cout << "NO edge between " << u << " and " << v << endl;
        }
    }
    else {
       
        if(edgeExists(u, v, adj)) {
            cout << "Edge EXISTS from " << u << " to " << v << endl;
        } else {
            cout << "NO edge from " << u << " to " << v << endl;
        }
    }

    return 0;
}