#include <bits/stdc++.h>
using namespace std;
#define ll long long int


bool pathMoreThanKUtil(int src, int k, int v, vector<vector<int>> adj[],  vector<bool> &visited ){
    if(k<=0) return true;

    //iterate over adj list of src
    for(auto it: adj[src]){
        int vertex=it[0];
        int weight=it[1];

        if(visited[vertex]) continue;

        if(weight>=k) return true;

        visited[vertex]=true;
        if(pathMoreThanKUtil(vertex, k-weight, v, adj, visited)) return true;

        //backtrack
        visited[vertex]=false;
    }
    //if no adjacent can produce path of length >= k
    return false;
}
bool pathMoreThanK(int src, int k, int v, vector<vector<int>> adj[]){
    vector<bool> visited(v,false);
    visited[v]=true;
    return pathMoreThanKUtil(src, k, v, adj, visited);
}