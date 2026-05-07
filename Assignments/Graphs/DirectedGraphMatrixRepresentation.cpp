#include <iostream>
using namespace std;

int main() {

    int n, m;
    cin >> n >> m;

    int adj[100][100] = {0};

    // Input edges
    for (int i = 0; i < m; i++) {

        int u, v;
        cin >> u >> v;

        // Directed graph
        adj[u][v] = 1;
    }

    // Print adjacency matrix
    for (int i = 0; i < n; i++) {

        for (int j = 0; j < n; j++) {
            cout << adj[i][j] << " ";
        }

        cout << endl;
    }

    return 0;
}