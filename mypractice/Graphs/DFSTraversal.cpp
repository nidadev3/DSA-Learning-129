#include<iostream>
#include<vector>
using namespace std;
void DFS(vector<int>adj[],vector<bool>&visited,int current){
     visited[current] = true;

    // Print node
    cout << current << " ";

    // Visit all neighbors
    for(int neighbor : adj[current])
    {
        if(!visited[neighbor])
        {
            DFS(adj, visited, neighbor);
        }
    }
}
int main()
{
    int vertices = 5;

    // Adjacency List
    vector<int> adj[5];

    // Adding edges
    adj[0].push_back(1);
    adj[0].push_back(2);

    adj[1].push_back(0);
    adj[1].push_back(3);
    adj[1].push_back(4);

    adj[2].push_back(0);

    adj[3].push_back(1);

    adj[4].push_back(1);

    // Visited array
    vector<bool> visited(vertices, false);

    cout << "DFS Traversal: ";

    DFS(adj, visited, 0);

    return 0;
}