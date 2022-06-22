#include <bits/stdc++.h>
using namespace std;
#define ll long long int

//to find if bridge exists or not
//just need one condition
// if(low[v]>disc[u]) then this edge is a bridge

//simply perform Tarjan's algorithm
//i.e. to find all articulation points and check the condition

void bridgeUtil(vector<int> adj[], int u, vector<bool> &visited,vector<int> &disc, vector<int> &low, int &time, vector<int>& parent){

    visited[u]=true;

    disc[u]=low[u]=++time;

    for(auto v: adj[u]){
        if(!visited[v]){
            parent[v]=u;
            bridgeUtil(adj,v,visited,disc,low,time,parent);

            low[u]=min(low[u],low[v]);
            if(low[v]>disc[u]){
                cout<<u<<" "<<v<<endl;
            }
        }
        else if(v!=parent[u]){
            low[u]=min(low[u],disc[v]);
        }
    }
}
void bridge(vector<int> adj[], int v){
    int time=0;
    vector<bool> visited(v,false);
    vector<int> disc(v,0);
    vector<int> low(v);
    vector<int> parent(v);

    for(int i=0;i<v;i++){
        parent[i]=-1;
    }
    //iterate over all vertices
    for(int i=0;i<v;i++){
        if(!visited[i]){
            bridgeUtil(adj,i,visited,disc,low,time,parent);
        }
    }


}
// Utility function to add an edge
void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main(){
    int v; int e;
    cin>>v>>e;
    vector<int> adj[v];
    for(int i=0;i<e;i++){
        int u,x;
        cin>>u>>x;
        addEdge(adj,u,x);
    }
    cout<<"\n";
    bridge(adj,v);
    return 0;
}
