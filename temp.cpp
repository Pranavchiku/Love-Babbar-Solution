
#include<bits/stdc++.h>
using namespace std;

struct auxStruct{
    int node,cost;
    
    friend bool operator<(auxStruct a, auxStruct b) {return a.cost<b.cost;}
}

vector<int> solve(int A, vector<int> &B, vector<vector<int> > &C, int D) {
    vector<vector<int>> adj(A);
    for(auto it: C){
        adj[it[0]-1]=vector<int> {it[1]-1,it[2],D};
        adj[it[1]-1]=vector<int> {it[0]-1,it[2],D};
    }
    vector<int> ans;
    ans=B;
    
    priority_queue<vector<int>,vector<vector<int>>, greater<vector<int>>>pq;
    for(int i=0;i<A;i++)
        pq.push({B[i],i});
    
    while(!pq.empty()){
        int curr_cost=pq.top()[0];
        int curr_node=pq.top()[1];
        
        pq.pop();
        
        if(curr_cost!=ans[curr_node]) continue;
        
        for(auto it: adj[curr_node]){
            // if(ans[it[0]]>ans[curr_node]+it[1]+it[1]*it[2]){
            //     ans[it[0]]=min(ans[it[0]],ans[curr_node]+it[1]+it[1]*it[2]);
            //     pq.push({ans[it[0]],it[0]});
            // }
            cout<<it[0]<<" "<<it[1]<<" "<<it[2]<<endl;
        }
    }
    return ans;
    
}


int main(){

}