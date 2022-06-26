#include <bits/stdc++.h>
using namespace std;
#define ll long long int

//to find if bridge exists or not
//just need one condition
// if(low[v]>disc[u]) then this edge is a bridge

//simply perform Tarjan's algorithm
//i.e. to find all articulation points and check the condition

int merge(int* parent, int x)
{
    if (parent[x] == x)
        return x;
    return merge(parent, parent[x]);
}

vector<ll> connectedcomponents(int n, vector<vector<int> >& edges)
{
    int parent[n];
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }
    for (auto x : edges) {
        parent[merge(parent, x[0])] = merge(parent, x[1]);
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += (parent[i] == i);
    }
    for (int i = 0; i < n; i++) {
        parent[i] = merge(parent, parent[i]);
    }
    map<int, list<int> > m;
    for (int i = 0; i < n; i++) {
        m[parent[i]].push_back(i);
    }
    vector<ll> dp(n,0);


    for (auto it = m.begin(); it != m.end(); it++) {
        list<int> l = it->second;
        ll c=0;
        for (auto x : l) {
            c++;
            cout<<x<<' ';
        }
        cout<<'\n';
        for(auto x:l){
            dp[x]=c;
        }
    }
    return dp;
}

void bridgeUtil(vector<int> adj[], int u, vector<bool> &visited,vector<int> &disc, vector<int> &low,vector<int>& parent, set<pair<int,int>> &speEdge){

    static int time=0;
    visited[u]=true;

    disc[u]=low[u]=++time;

    for(auto v: adj[u]){
        if(!visited[v]){
            parent[v]=u;
            bridgeUtil(adj,v,visited,disc,low,parent,speEdge);

            low[u]=min(low[u],low[v]);
            if(low[v]>disc[u]){
                speEdge.insert({u,v});
            }
        }
        else if(v!=parent[u]){
            low[u]=min(low[u],disc[v]);
        }
    }
}

void dfs(vector<int> adj[], int src, int &count, vector<bool> &visited){
    visited[src]=true;
    count++;
    for(auto v: adj[src]){
        if(!visited[v]){
            dfs(adj,v,count,visited);
        }
    }
}

void bridge(vector<int> adj[], int v,int m,vector<vector<int>> &edges){
    vector<bool> visited(v,false);
    vector<int> disc(v,0);
    vector<int> low(v);
    vector<int> parent(v);
    set<pair<int,int>> speEdge;

    // int count=0;
    for(int i=0;i<v;i++){
        parent[i]=-1;
    }
    //iterate over all vertices
    for(int i=0;i<v;i++){
        if(!visited[i]){
            bridgeUtil(adj,i,visited,disc,low,parent,speEdge);
        }
    }

    //print all special edges
    for(auto it: speEdge){
        cout<<it.first+1<<" "<<it.second+1<<endl;
    }

    cout<<'\n';

    //remove all special edges from the graph
    for(auto it: speEdge){
        adj[it.first].erase(find(adj[it.first].begin(),adj[it.first].end(),it.second));
        adj[it.second].erase(find(adj[it.second].begin(),adj[it.second].end(),it.first));
    }

    //now perform DFS traversal and find count of elements in it
    int total=0;
    if(speEdge.size()==0){
        cout<<0<<'\n';
        return;
    }

    for(auto it: edges){
        if(speEdge.find({it[0],it[1]})!=speEdge.end() or speEdge.find({it[1],it[0]})!=speEdge.end()){
            edges.erase(find(edges.begin(),edges.end(),it));
        }
    
    }
    vector<ll> dp=connectedcomponents(v,edges);
    for(int i=0;i<v;i++){
        cout<<i<<' '<<dp[i]<<'\n';
    }

    // for(auto it: speEdge){
    //     int count1=0;
    //     int count2=0;
    //     visited.assign(v,false);
    //     dfs(adj,it.first,count1,visited);
    //     // visited.assign(v,false);
    //     dfs(adj,it.second,count2,visited);
    //     total+=(count1*count2);
    // }
    // cout<<total<<endl;
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
    vector<vector<int>> edges;
    for(int i=0;i<e;i++){
        int u,x;
        cin>>u>>x;
        edges.push_back({u-1,x-1});
        addEdge(adj,u-1,x-1);
    }
    cout<<"\n";
    bridge(adj,v, e,edges);
}


