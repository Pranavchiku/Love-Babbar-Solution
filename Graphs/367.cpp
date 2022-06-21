#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void dfs(int s, vector<int>& vis, vector<int> g[]){
    vis[s]=true;
    for(auto &it: g[s]){
        if(!vis[it]){
            dfs(it,vis,g);
        }
    }
}
int makeConnected(int n, vector<vector<int>>& edges) {
    vector<int> g[n];
    int m=edges.size();
    if(m<n-1){
        return -1;
    }
    else{
        for(int i=0;i<edges.size();i++){
            g[edges[i][0]].push_back(edges[i][1]);
            g[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> vis(n,0);
        int c=0; //number of disconnected components
        for(int i=0;i<n;i++){
            if(!vis[i]){
                c++; //if disconnected component exist increment it
                dfs(i,vis,g);
            }
        }
        return c-1;

    }
}