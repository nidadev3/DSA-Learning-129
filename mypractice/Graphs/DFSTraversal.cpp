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