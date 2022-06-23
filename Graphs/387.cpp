#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void dfs(vector<vector<int>> adj[], int s, vector<bool> &visited,stack<int> &st){
    visited[s]=true;
    for(auto v:adj[s]){
        if(!visited[v[0]]){
            dfs(adj,v[0],visited,st);
        }
    }
    st.push(s);
}

stack<int> topoSort(vector<vector<int>> adj[], int v){
    vector<bool> visited(v,false);
    stack<int> s;
    for(int i=0;i<v;i++){
        if(!visited[i]){
            dfs(adj,i,visited,s);
        }
    }
    return s;
}

void longestPath(vector<vector<int>> adj[], int v, int src){
    stack<int> st=topoSort(adj,v);
    vector<int> dist(v);
    for(int i=0;i<v;i++){
        dist[i]=INT_MIN;
    }

    dist[src]=0;
    while(!st.empty()){
        int u=st.top();
        st.pop();

        //iterate over adj list of u
        //update the distance of all vertices

        for(auto it: adj[u]){
            if(dist[it[0]]!=INT_MIN)
                dist[it[0]]=max(dist[it[0]],dist[u]+it[1]);
        }
    }

    //print the longest distances
    cout<<"Source \tVertex \tDistance"<<endl;
    for(int i=0;i<v;i++){
        if(dist[i]!=INT_MIN)
            cout<<src<<"\t"<<i<<"\t"<<dist[i]<<endl;
        else 
            cout<<src<<"\t"<<i<<"\t"<<"INF"<<endl;
    }


}

int main(){
    int V,e;
    cin>>V>>e;
    vector<vector<int>> adj[V];
    for(int i=0;i<e;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
    }
    longestPath(adj,V,0);
}