#include<bits/stdc++.h>
using namespace std;
#define ll long long int


int solve(vector<int> &A) {
    int n=A.size();
    vector<vector<int>> adj(n+1,vector<int>(n+1,0));
    for(int i=0;i<n;i++){
        adj[i+1][A[i]]=1;
    }   
    // for(auto it: adj){
    //     for(auto it2: it){
    //         cout<<it2<<" ";
    //     }
    //     cout<<'\n';
    // }
    
    vector<int> visited(n+1,0);
    queue<pair<int,bool>> q;
    q.push({1,true});
    
    // for(int i=1;i<=n;i++){
    //     if(adj[i][1]==1){
    //         goodNodes[i]=true;
    //     }
    // }

    int count=0;

    while(!q.empty()){
        int curr=q.front().first;
        bool isGood=q.front().second;
        visited[curr]=1;
        q.pop();

        if(isGood){
            
            for(int i=1;i<=n;i++){
                if(adj[i][curr]==1 and !visited[i]){
                    q.push({i,true});
                }
            }
        }
    }
    
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            adj[i][1]=1;
            count++;
            q.push({i,true});
            while(!q.empty()){
                int curr=q.front().first;
                bool isGood=q.front().second;
                visited[curr]=1;
                q.pop();

                if(isGood){
                    
                    for(int i=1;i<=n;i++){
                        if(adj[i][curr]==1 and !visited[i]){
                            q.push({i,true});
                        }
                    }
                }
            }
        }
    }
    // for(int i=1;i<=n;i++){
    //     if(goodNodes[i]){
    //         cout<<i<<"i"<<'\n';
    //         for(int j=1;j<=n;j++){
    //             if(adj[j][i]==1){
    //                 cout<<j<<'\n';
    //                 goodNodes[j]=true;
    //             }
    //         }
    //     }
    // }
    
    
    return count;
    
}

int dfs(int node, vector<int>& A, vector<int>& vis){
    if(A[node] == 1){
        return 0;
    }
    if(vis[node] == 1){
        A[node] = 1;
        return 1;
    }
   
    vis[node] = 1;
    int res = dfs(A[node] - 1, A, vis);
    A[node] = 1;
    return res;
   
}
int solve2(vector<int> &A) {
    int n = A.size();
    vector<int> vis(n, 0);
    int cnt = 0;
    for(int i = 0; i < n; i++){
        if(vis[i] == 0){
            if(dfs(i, A, vis)){
                cnt++;
            }
        }
    }
    return cnt;
}

int main(){
    int n;
    cin>>n;
    vector<int> A(n);
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
    cout<<solve(A)<<'\n';
    return 0;
}
