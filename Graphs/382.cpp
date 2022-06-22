#include <bits/stdc++.h>
using namespace std;
#define ll long long int


int minThrow(int n, int arr[]){
    vector<int> adj(31,-1);
    for(int i=0;i<(2*n-1);i+=2){
        adj[arr[i]]=arr[i+1];
    }
    queue<pair<int,int>> q;
    q.push({1,0});
    
    vector<bool> visited(31,false);
    
    while(!q.empty()){
        auto it=q.front();
        q.pop();
        
        int curr_sq=it.first;
        int moves=it.second;
        if(curr_sq==30){
            return moves;
        }
        for(int i=1;i<=6;i++){
            int next_sq=curr_sq+i;
            if(next_sq>30) break;
            if(adj[next_sq]!=-1){
                next_sq=adj[next_sq];
            }
            if(visited[next_sq]==false){
                q.push({next_sq,moves+1});
                visited[next_sq]=true;
            }
        }
    }
}