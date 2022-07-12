#include<bits/stdc++.h>
using namespace std;
#define ll long long int

bool isValid(int x, int y, vector<vector<bool>> &visited, vector<vector<int>> &m, int n){
    if(x<0 or x>=n or y<0 or y>=n or visited[x][y] or m[x][y]==0) return false;
    return true;
}
void dfs(int x, int y, vector<vector<bool>> &visited, vector<vector<int>> &m, string ans){
    //base condition
    if(x==m.size()-1 and y==m.size()-1){
        cout<<ans<<'\n';
        return;
    }

    //recursive case
    visited[x][y]=true;
    // adjacent cells
    vector<pair<int,int>> adj={{0,1},{0,-1},{1,0},{-1,0}};
    
    for(auto it: adj){
        int newx=x+it.first;
        int newy=y+it.second;
        if(isValid(newx,newy,visited,m,m.size())){
            if(it.first==0 and it.second==1){
                ans+='R';
            }
            else if(it.first==-1 and it.second==0){
                ans+='U';
            }
            else if(it.first==0 and it.second==-1){
                ans+='L';
            }
            else if(it.first==1 and it.second==0){
                ans+='D';
            }
            dfs(newx,newy,visited,m,ans);
            ans.pop_back();
        }
    }
    visited[x][y]=false;
    ans.pop_back();

}
void findPath(vector<vector<int>> &m, int n){
    vector<vector<bool>> visited(n,vector<bool>(n,false));
    dfs(0,0,visited,m,"");
}

int main(){
    int n;
    cin>>n;
    vector<vector<int>> m(n,vector<int>(n,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>m[i][j];
        }
    }
    findPath(m,n);
    return 0;
}
