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
        adj[v].push_back({u, w});
    }

    int source, dest;
    cout << "Enter source node: ";
    cin >> source;

    cout << "Enter destination node: ";
    cin >> dest;

    vector<int> dist(n+1, INT_MAX);
    vector<int> parent(n+1);  

    for(int i = 1; i <= n; i++){
        parent[i] = i;
    }

    dist[source] = 0;

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, source});

    while(!pq.empty()){

        int node = pq.top().second;
        pq.pop();

        for(auto x : adj[node]){

            int v = x.first;
            int w = x.second;

            if(dist[node] + w < dist[v]){

                dist[v] = dist[node] + w;
                pq.push({dist[v], v});

                parent[v] = node; 
            }
        }
    }

    
     
    cout << "\nShortest distance = " << dist[dest] << endl;

    cout << "Path: ";

    vector<int> path;
    int node = dest;

    while(parent[node] != node){
        path.push_back(node);
        node = parent[node];
    }

    path.push_back(source);

    for(int i = path.size() - 1; i >= 0; i--){
        cout << path[i] << " ";
    }

    return 0;
}