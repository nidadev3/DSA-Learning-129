#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int main() {

    int n, m;
    cin >> n >> m;

    vector<pair<int,int>> adj[n+1];

    // input graph
    for(int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
    
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    // heuristic array calculation of h(n)
      vector<int> h(n+1);
      cout << "Enter heuristic values for each node:\n";
    for(int i = 1; i <= n; i++){
        cin >> h[i];
    }
    int start, goal;
cout << "Enter start (source): ";
cin >> start;
cout << "Enter goal (destination): ";
cin>>goal;

//calculation of g(n)
vector<int> dist(n+1, INT_MAX);
dist[start] = 0; 

//priority queue
 priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    pq.push({h[start], start});

    while(!pq.empty()){

        int node = pq.top().second;
        pq.pop();
         if(node == goal){
            cout << "Reached goal. Cost = " << dist[node];
            return 0;}
             for(auto x : adj[node]){

            int v = x.first;
            int w = x.second;

            if(dist[node] + w < dist[v]){

                dist[v] = dist[node] + w;

                int f = dist[v] + h[v];

                pq.push({f, v});
            }
        }
    }

    cout << "No path found";
}
