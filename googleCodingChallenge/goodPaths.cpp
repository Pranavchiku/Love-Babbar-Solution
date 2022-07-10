#include<bits/stdc++.h>
using namespace std;
#define ll long long int

bool isGoodPath(map<int,int> count, int pathLength){
    for(auto it: count){
        if(it.second/2>=pathLength) return true;

    }
    return false;
}

void dfs(vector<int> c, vector<vector<int>> &adj, int source, map<int,int> &count, int pathLength, vector<int>& visited, int &goodPaths){
    visited[source]=1;
    count[c[source-1]]++;
    if(isGoodPath(count,pathLength)){
        goodPaths++;
    }
    for(auto it: adj[source]){
        if(visited[it]==0){
            dfs(c,adj,it,count,pathLength,visited,goodPaths);
        }
    }
    
}
int solve(int n, vector<int> c, vector<vector<int>> edges){
    vector<vector<int>> adj;
    for(auto it: edges){
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }

    map<int,int> count;
    int source=c[0];
    count[source]++;
    vector<int> visited(n,0);
    int goodPaths=0;
    dfs(c,adj,source,count,c[1],visited,goodPaths);
    return goodPaths;

    
}
int main(){
    int n;
    cin>>n;
    vector<int> c(n);
    for(int i=0;i<n;i++){
        cin>>c[i];
    }
    
    vector<vector<int>> edges(n-1);
    for(int i=0;i<n-1;i++){
        int x,y;
        cin>>x>>y;
        edges[i].push_back(x);
        edges[i].push_back(y);
    }
    cout<<solve(n,c,edges);

    return 0;
}