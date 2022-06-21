#include <bits/stdc++.h>
using namespace std;
#define ll long long int


int spanningTree(int v, vector<vector<int>> adj[])
{
    //given is adjaceny list 
    //element of adjacency list is {vertex,weight}
    vector<int> key(v,INT_MAX);
    vector<bool> mstSet(v,false);
    
    key[0]=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0,0}); //weight-vertex
    
    while(!pq.empty()){
        int u=pq.top().second;
        pq.pop();
        mstSet[u]=true;
        
        for(auto &it: adj[u]){
            int x=it[0]; //vertex
            int weight=it[1]; //weight
            
            if(mstSet[x]==false and weight<key[x]){
                key[x]=weight;
                pq.push({weight,x});
            }
        }
    }
    return accumulate(key.begin(),key.end(),0);
}