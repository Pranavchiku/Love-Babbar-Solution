#include <bits/stdc++.h>
using namespace std;
#define ll long long int

//kosaraju's algorithm is used to find is the graph
//strongly connected or not

//To find number of Strongly Connected Components
//we use Tarjan's algorithm or refer 384.cpp



//a graph is strongly connected if
//Every vertex can be reached from v and
//v can be reached from every vertex

// simple idea is 
//perform a DFS traversal at vertex v
//check if all vertex visited, if no return false;

//Above step ensures every vertex can be reached from v

//if yes, reverse the graph
//perform a DFS traversal at vertex v again
//check if all vertex visited, if no return false; else return true

//Above step ensures v can be reached from every vertex

void dfs(vector<int> adj[], int s, vector<bool> &visited){
    visited[s]=true;
    for(auto v:adj[s]){
        if(!visited[v]){
            dfs(adj,v,visited);
        }
    }
}

//function that reverse the graph
void reverse(vector<int> adj[], int v){
    for(int i=0;i<v;i++){
        for(auto j: adj[i]){
            adj[j].push_back(i);
        }
    }
}

//function to check if graph is strongly connected or not
bool isSC(vector<int> adj[], int v){

    //create a visited array
    vector<bool> visited(v,false);

    //perform DFS from vertex 0
    dfs(adj,0,visited);

    //check if all vertex visited or not
    for(int i=0;i<v;i++){
        if(!visited[i]){
            //if not visited return false;
            return false;
        }
    }

    //if all vertex visited, reverse the graph
    reverse(adj,v);

    //perform DFS from vertex 0
    visited.assign(v,false);
    dfs(adj,0,visited);

    //check if all vertex visited or not
    for(int i=0;i<v;i++){
        if(!visited[i]){
            //if not visited return false;
            return false;
        }
    }
    return true;
}

void addEdge(vector<int> adj[],int v, int w){
    adj[v].push_back(w);
}

int main(){
    int v; int e;
    cin>>v>>e;
    vector<int> adj[v];
    for(int i=0;i<e;i++){
        int u,w;
        cin>>u>>w;
        addEdge(adj,u,w);
    }
    if(isSC(adj,v)){
        cout<<"Graph is strongly connected"<<'\n';
    }
    else{
        cout<<"Graph is not strongly connected"<<'\n';
    }
}

