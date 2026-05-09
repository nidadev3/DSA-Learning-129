#include<iostream>
usingg namespace std;

int countVertices(int n){
return n;

}
int countEdges(){


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

    cout << "\nTotal Vertices = "
         << countVertices(n) << endl;

    cout << "Total Edges = "
         << countEdges(adj, n, type) << endl;

    return 0;
}