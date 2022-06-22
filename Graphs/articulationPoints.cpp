#include <bits/stdc++.h>
using namespace std;
#define ll long long int


//recursive function to find articulation points
//similar to DFS
//we have 2 cases
//1st if the node is root node and has children>1 
//then is AP
//Else, if there doesnot exist any backEdge from the children of u to
//the ancestors of u or u
//then is AP

void APUtil(vector<int> adj[], int u, vector<bool> &visited,vector<int> &disc, vector<int> &low, int &time, vector<bool> &ap, int parent){
    //count children in DFS tree
    int children=0;

    //mark the current vertex visite
    visited[u]=true;

    //initialise discovery and low value
    disc[u]=low[u]=++time;

    //iterate through all the adjacent vertices
    for(auto v:adj[u]){
        //if the vertex is not visited
        if(!visited[v]){
            children++;
            //recursive call to find articulation points
            //with parent as u
            APUtil(adj,v,visited,disc,low,time,ap,u);

            //check if subtree rooted with current vertex
            //has any backedge to ancestors of u or u
            //if no then u is articulation point
            low[u]=min(low[u],low[v]);

            //if u is root and low value of one of its child
            //is more than discovery value of u

            if(parent!=-1 and low[v]>=disc[u]){
                ap[u]=true;
            }
        }
        //if the vertex is visited and not the parent of u
        else if(v!=parent){
            //update low value of u
            low[u]=min(low[u],disc[v]);
        }
    }
    //if u is root and has more than 1 child
    //then u is articulation point
    if(parent==-1 and children>1){
        ap[u]=true;
    }
}


//function to find articulation points in a graph
//graph is adjacency list

void AP(vector<int> adj[], int v){
    //create a discovery array to store discovery time of each vertex
    //initialise all discovery time as 0
    vector<int> disc(v,0);

    //create a low array to store low value of each vertex
    vector<int> low(v);

    //create a visited array to store visited status of each vertex
    vector<bool> visited(v,false);

    //create an array to keep track of which vertex is AP
    vector<bool> isAP(v,false);

    //time of visiting a vertex;
    int time=0;

    //parent of a vertex
    int par=-1;
    
    //iterate through all vertices
    //i.e. 0,1,2,3,....,v-1
    //so if the graph is disconnected then also it works
    for(int u=0;u<v;u++){
        //if vertex u is not visited
        if(!visited[u]){
            //call dfs function to find articulation points
            APUtil(adj,u,visited,disc,low,time,isAP,par);
        }
    }

    //print all the articulation points
    cout<<"Articulation points in graph is"<<'\n';
    for(int i=0;i<v;i++){
        if(isAP[i]){
            cout<<i<<" ";
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
    AP(adj,v);
    return 0;
}
