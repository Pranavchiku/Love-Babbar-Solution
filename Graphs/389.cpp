#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    //{vertex, weight}
    vector<vector<pair<int,int>>> adj(n);

    for(auto t: flights){
        adj[t[0]].push_back({t[1],t[2]});
    }

    priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> pq;
    //priority_queue of {cost, vertex, stops}
    pq.push({0,src,0});

    while(!pq.empty()){
        auto x=pq.top();
        pq.pop();
        int stops=get<2>(x);
        int u=get<1>(x);
        int cost=get<0>(x);
        if(u==dst) return cost;
        if(stops>k) continue;
        for(auto it: adj[u]){
            pq.push({cost+it.second,it.first,stops+1});
        } 
    }
    return -1;
}