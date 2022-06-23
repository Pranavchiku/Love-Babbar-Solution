#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void printVertexCover(vector<int> adj[], int v){
    vector<bool> visited(v, false);
    //visit all edges one by one
    for(int i=0;i<v;i++){
        //an edge is only picked when both its vertices are not visited
        if(visited[i]==false){
            //go through all adjacent of i and pick the first
            //unvisiterd vertex
            //and add this vertex to the vertex cover i.e. visited list
            for(auto &it: adj[i]){
                if(visited[it]==false){
                    //add the edge to the vertex cover
                    visited[it]=true;
                    visited[i]=true;
                    break;
                }
            }
        }
    }
    //print the vertex cover
    for(int i=0;i<v;i++){
        if(visited[i]==true)
            cout<<i<<" ";
    }
}

int main(){
    int v,e;
    cin>>v>>e;
    vector<int> adj[v];
    for(int i=0;i<e;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    printVertexCover(adj,v);
}