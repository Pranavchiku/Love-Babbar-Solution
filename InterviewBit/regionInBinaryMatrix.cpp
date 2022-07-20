#include<bits/stdc++.h>
using namespace std;
#define ll long long int

bool isValid(vector<vector<int>> &A, vector<vector<int>>& visited, int x, int y, int n, int m){
    if(x<0 or x>=n or y<0 or y>=m or A[x][y]==0 or visited[x][y]==1) return false;
    else return true;
}
void dfs(vector<vector<int>> &A,vector<vector<int>> &visited, int x, int y, int n, int m, int &count){
    visited[x][y]=1;
    count=count+1;
    cout<<x<<" "<<y<<endl;
    cout<<"count: "<<count<<endl;
    vector<pair<int,int>> adj={{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1},{1,0},{1,1}};
    for(auto it: adj){
        int newx=x+it.first;
        int newy=y+it.second;
        if(isValid(A,visited,newx,newy,n,m)){
            dfs(A,visited,newx,newy,n,m,count);
        }
    }
}
int solve(vector<vector<int> > &A) {
    int n=A.size();
    if(n==0) return 0;
    int m=A[0].size();
    vector<vector<int>> visited(n,vector<int>(m,0));
    
    int ans=INT_MIN;
    int count=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(A[i][j]==1 and !visited[i][j]){
                count=0;
                dfs(A,visited,i,j,n,m,count);
                // cout<<count<<endl;
                ans=max(ans,count);
            }
        }
    }
    return max(ans,count);
}

int main(){
    int n;cin>>n;
    int m;cin>>m;
    vector<vector<int>> A(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>A[i][j];
        }
    }
    cout<<solve(A)<<endl;
    return 0;
}
