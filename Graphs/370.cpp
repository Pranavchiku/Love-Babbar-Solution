#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void helper(int s, map<int,bool> &visited, stack<int>&st, vector<int> adj[]){
    visited[s]=true;
    
    for(auto& it: adj[s]){
        if(!visited[it]){
            helper(it,visited,st,adj);
        }
    }
    st.push(s);
}
vector<int> topoSort(int v, vector<int> adj[]) 
{
    vector<int> ans;
    map<int,bool> visited;
    stack<int> st;
    for(int i=0;i<v;i++){
        if(!visited[i]){
            helper(i,visited,st,adj);
        }
    }
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}