#include <bits/stdc++.h>
using namespace std;
#define ll long long int

vector<int> bfsOfGraph(int v, vector<int> adj[]) {
    vector<bool> visited(v,false);
    vector<int> bfs;

    for(int i=0;i<v;i++){
        if(!visited[i]){
            visited[i]=true;
            queue<int> q;
            q.push(i);
            while(!q.empty()){
                int curr=q.front();
                bfs.push_back(curr);
                q.pop();
                for(auto& it: adj[curr]){
                    if(!visited[it]){
                        visited[it]=true;
                        q.push(it);
                    }
                }
            }

        }
    }
    return bfs;
}