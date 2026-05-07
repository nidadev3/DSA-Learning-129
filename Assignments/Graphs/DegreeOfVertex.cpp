#include<iostream>
using namespace std;
int outDegree(int node,vector<int>adj[]){


}

int inDegree(int node,vector<int>adj[],int n){

    
}
int main (){
    int n,m;
    cout <<"Enter the number of vertex of graph:";
    cin>>n;
    cout<<"Enter the number of edges of the graph:";
    cin>>m;
    int type;
    cout<<"Enter the type of graph(0 for undirected and 1 for directed ):";
    cin>>type;
    vector<int>adj[n];
    cout<<"Enter the edges(u v):\n";
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        if(type==0){
adj[u].push_back(v);
adj[v].push_back(u);
    }
    else{
        adj[u].push_back(v);
    }
    }
    cout<<"\nAdjacency list:\n";
    for (int i=0; i<n;i++){
        cout<<i<<"->";
        for(int j=0;j<adj[i].size();j++){
            cout<<adj[i][j]<<" ";

        }
        cout<<endl;
    }
     int node;
    cout << "\nEnter node to calculate degree: ";
    cin >> node;
    
}