#include <bits/stdc++.h>
using namespace std;
#define ll long long int

bool isSafe(int i, int j, int n, int m, vector<vector<int>> &visited,vector<vector<char>> grid){
    if((i>=0 and i<n) and (j>=0 and j<m) and !visited[i][j] and grid[i][j]=='1'){
        return true;
    }
    else return false;
}
void dfsHelper(vector<vector<char>> grid, int i, int j,int n, int m, vector<vector<int>> &visited){
    visited[i][j]=1;

    vector<pair<int,int>> v={{i+1,j},{i-1,j},{i,j+1},{i,j-1},{i+1,j+1},{i-1,j-1},{i-1,j+1},{i+1,j-1}};

    for(auto &it: v){
        if(isSafe(it.first,it.second,n,m,visited,grid)){
            // cout<<it.first<<" "<<it.second<<'\n';
            dfsHelper(grid,it.first,it.second,n,m,visited);

        }
    }
}

void dfs(vector<vector<char>> &grid, int &ans){
    vector<vector<int>> visited(grid.size(),vector<int>(grid[0].size(),0));
    int n=grid.size();
    int m=grid[0].size();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]=='1' and !visited[i][j]){
                ans++;
                dfsHelper(grid,i,j,n,m,visited);
            }
        }
    }

}
int numIslands(vector<vector<char>>& grid) {
    int ans=0;
    dfs(grid,ans);
    return ans;
}

int main(){
    int n; int m;
    cin>>n>>m;
    vector<vector<char>> grid;
    for(int i=0;i<n;i++){
        vector<char> temp;
        char x;
        for(int j=0;j<m;j++){
            cin>>x;
            temp.push_back(x);
        }
        grid.push_back(temp);
    }
    cout<<"\n";
    cout<<numIslands(grid)<<'\n';
    return 0;
}