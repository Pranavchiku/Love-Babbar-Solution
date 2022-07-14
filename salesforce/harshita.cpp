#include<bits/stdc++.h>
using namespace std;
#define ll int

int countWays(vector<vector<ll>> &adj, int source, int dest, vector<bool> &visited){
    if(source==dest) return 1;
    ll count=0;
    for(int i=1;i<=adj[source].size();i++){
        if(adj[source][i]==1 and !visited[i]){
            visited[i]=true;
            count=((count%1000000007)+(countWays(adj, i, dest, visited)%1000000007))%1000000007;
            visited[i]=false;
        }
    }

    return count%1000000007;
}
int main(){
    ll t;cin>>t;
    while(t--){
        ll n;cin>>n;
        // if(n==1) cout<<1<<'\n';
        vector<vector<ll>> adj;
        for(int i=0;i<=n;i++){
            vector<ll> temp;
            for(int j=0;j<=n;j++){
                temp.push_back(0);
            }
            adj.push_back(temp);
        }

        for(ll i=1;i<=n;i++){
            for(ll j=1;j<=n;j++){
                if(i>j and i%j==0){
                    adj[j][i]=1;
                }
            }
        }

        vector<bool> visited;
        for(int i=0;i<=n;i++){
            visited.push_back(false);
        }
        visited[1]=true;
        cout<<countWays(adj,1,n,visited)<<'\n';

    }
}