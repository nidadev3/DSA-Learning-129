#include <iostream>
#include <vector>
using namespace std;

int main() {

    int vertices, edgesCount;

    cout << "Enter number of vertices: ";
    cin >> vertices;

    cout << "Enter number of edges: ";
    cin >> edgesCount;

    // Edge list
    vector<pair<int, int>> edges;

    // Taking edges input
    for (int i = 0; i < edgesCount; i++) {

        int u, v;

        cout << "Enter edge " << i + 1 << " (u v): ";
        cin >> u >> v;

        edges.push_back({u, v});
    }

    // Display edge list
    cout << "\nEdge List:\n";

    for (auto edge : edges) {
        cout << "(" << edge.first << "," << edge.second << ")" << endl;
    }

    return 0;
}