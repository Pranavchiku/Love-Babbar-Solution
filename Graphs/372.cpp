#include <bits/stdc++.h>
using namespace std;
#define ll long long int


vector<unordered_set<int>> makeAdj(int numTasks,vector<pair<int, int> >& prerequisites){
    vector<unordered_set<int>> adj(numTasks);
    for(auto it: prerequisites){
        adj[it.second].insert(it.first);
    }
    return adj;
}
bool isCyclic(vector<unordered_set<int>> &adj, int node, vector<bool> &onPath, vector<bool> &visited){
    if(visited[node])
        return false;
    
    onPath[node]=visited[node]=true;
    for(auto it: adj[node]){
        if(onPath[it] or isCyclic(adj,it,onPath,visited)) return true;
    }
    return onPath[node]=false;
}
bool isPossible(int N, vector<pair<int, int> >& prerequisites) {
    vector<unordered_set<int>> adj=makeAdj(N,prerequisites);
    vector<bool> onPath(N,false),visited(N,false);
    for(int i=0;i<N;i++){
        if(isCyclic(adj,i,onPath,visited)) return false;
    }
    return true;
}   