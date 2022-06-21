#include <bits/stdc++.h>
using namespace std;
#define ll long long int

bool isCyclicUtil(int s, vector<bool> &visited,int parent, vector<int> adj[]){
    visited[s]=true;
    for(auto &it: adj[s]){
        if(!visited[it]){
            if(isCyclicUtil(it,visited,s,adj))
                return true;
        }
        else if (it!=parent){
            return true;
        }
    }
    return false;
}
bool isCycle(int v, vector<int> adj[]) {
    vector<bool> visited(v,false);
    for(int i=0;i<v;i++){
        if(!visited[i]){
            if(isCyclicUtil(i,visited,-1,adj))
                return true;
        }
    }
    return false;
}