#include<iostream>
#include<vector>
#include<queue>
using namespace std;
void BFS(vector <int>adj[],int vertices,int start){
    //visited array
    vector<bool>visited(vertices,false);
    //Queue for bfs

    queue<int>q;

    visited[start]=true;
    q.push(start);
    cout<<"BFS Traversal: ";

    //BFS loop
    while(!q.empty()){
        int current=q.front();
        q.pop();
        cout<<current<<" ";
        //Visit of neighbours
        for(int neighbor:adj[current]){
            if(!visited[neighbor]){
                visited[neighbor]=true;
                q.push(neighbor);
            }
        }
    }}
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

    int startVertex = 0;

    BFS(adj, vertices, startVertex);

    return 0;
}