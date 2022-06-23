#include <bits/stdc++.h>
using namespace std;
#define ll long long int

//a bipartite graph is a graph whose vertices
//can be divided among a set of two vertices
//such that vertices in same set doesnot have any edge

bool bfs(vector<int> adj[], int src, vector<int> &colored){
    colored[src]=1;

    queue<int> q;
    q.push(src);

    while(!q.empty()){
        int u=q.front();
        q.pop();

        for(auto it: adj[u]){
            if(colored[it]==colored[u]){
                return false;
            }
            if(colored[it]==-1){
                colored[it]=1-colored[u];
                q.push(it);
            }
        }
    }
    return true;
}

bool isBipartite(int v, vector<int>adj[]){
    //create a colored array
    //0 means white - set U
    //1 means black - set V
    vector<int> colored(v);
    for(int i=0;i<v;i++){
        colored[i]=-1;
    }

    //perform a bfs traversal from vertex 0 - with 0 as color 1
    //and color all its adjacent vertices as 0

    //iterate over all vertices
    for(int i=0;i<v;i++){
        if(colored[i]==-1){
            if(!bfs(adj,i,colored)){
                return false;
            }
        }
    }
    return true;
}