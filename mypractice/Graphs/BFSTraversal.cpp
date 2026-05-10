#include<iostream>
#include<vector>
#inclue<queue>
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
    }