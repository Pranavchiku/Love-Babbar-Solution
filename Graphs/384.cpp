#include <bits/stdc++.h>
using namespace std;
#define ll long long int


void dfs(vector<int> adj[], int s, vector<bool> &visited,vector<int> &order){
    visited[s]=true;
    for(auto v:adj[s]){
        if(!visited[v]){
            dfs(adj,v,visited,order);
        }
    }
    order.push_back(s);
}

void reverse(vector<int> adj[],vector<int> rev[], int v){
    for(int i=0;i<v;i++){
        for(auto j: adj[i]){
            rev[j].push_back(i);
        }
    }
}

void rdfs(vector<int> adj[], int s, vector<bool> &visited){
    visited[s]=true;
    for(auto it: adj[s]){
        if(!visited[it]){
            rdfs(adj,it,visited);
        }
    }
}

int kosaraju(int v, vector<int> adj[])
{
    //create a visited array
    vector<bool> visited(v,false);
    vector<int> rev[v];
    //keep track of order vector
    //will be used in reverse graph
    vector<int> order;

    //perform DFS from vertex 0
    for(int i=0;i<v;i++){
        if(!visited[i]){
            dfs(adj,i,visited,order);
        }
    }

    //reverse the graph
    reverse(adj,rev,v);
    visited.assign(v,false);
    int count=0;

    for(int i=v-1;i>=0;i--){
        if(!visited[order[i]]){
            rdfs(rev,order[i],visited);
            count++;
        }
    }

    return count;

}