//Representation using Matrix
#include <iostream>
using namespace std;

int main() {

    int n, m;
    cin >> n >> m;

    int adj[100][100] = {0};

    
    for (int i = 0; i < m; i++) {

        int u, v, w;

        cin >> u >> v >> w;

        
        adj[u][v] = w;
    }

   
    for (int i = 0; i < n; i++) {

        for (int j = 0; j < n; j++) {

            cout << adj[i][j] << " ";
        }

        cout << endl;
    }

    return 0;
}
//Representeation using list
// #include<iostream>
// #include<vector>
// using namespace std;

// int main(){
//     int n, m;

//     cout << "Enter the number of nodes/vertices of the graph: ";
//     cin >> n;

//     cout << "Enter the number of edges of the graph: ";
//     cin >> m;

//     // Adjacency list
//     vector<pair<int, int>> adj[n + 1];

//     cout << "Enter edges (u v w):\n";

//     for(int i = 0; i < m; i++){
//         int u, v, w;
//         cin >> u >> v >> w;

//         adj[u].push_back({v, w});
//         adj[v].push_back({u, w}); 
//     }

//     cout << "\nGraph (Adjacency List with weights):\n";

//     for(int i = 1; i <= n; i++){
//         cout << i << " -> ";

//         for(int j = 0; j < adj[i].size(); j++){
//             cout << "(" << adj[i][j].first << ", " << adj[i][j].second << ") ";
//         }

//         cout << endl;
//     }

//     return 0;
// }