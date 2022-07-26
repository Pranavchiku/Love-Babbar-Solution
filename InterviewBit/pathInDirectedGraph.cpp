#include<bits/stdc++.h>
using namespace std;
#define ll long long int


void dfs(vector<vector<int>> &adj, int source, int dest, vector<int> &visited, int &flag){
    if(source ==dest) flag = 1;

    visited[source]=1;
    for(auto it: adj[source]){
        if(!visited[it]){
            dfs(adj, it, dest, visited, flag);
        }
    }
}
int solve(int A, vector<vector<int>> &edges){
    vector<vector<int>> adj(A);
    for(auto it: edges){
        adj[it[0]-1].push_back(it[1]-1);
    }

    vector<int> visited(A,0);

    int flag = 0;
    dfs(adj, 0, A-1, visited, flag);
    return flag;
}