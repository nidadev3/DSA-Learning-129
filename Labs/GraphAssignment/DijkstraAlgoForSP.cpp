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
    }
      int source;
    cout << "Enter source node: ";
    cin >> source;

    vector<int> dist(n+1, INT_MAX);
    dist[source] = 0;

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, source}); // (distance, node)

    while(!pq.empty()){

        int node = pq.top().second;
        pq.pop();

        for(auto x : adj[node]){

            int v = x.first;
            int w = x.second;

            if(dist[node] + w < dist[v]){

                dist[v] = dist[node] + w;
                pq.push({dist[v], v});
            }
        }
    }
      cout << "\nShortest distances from source:\n";

    for(int i = 1; i <= n; i++){
        cout << i << " -> " << dist[i] << endl;
    }

    return 0;
}