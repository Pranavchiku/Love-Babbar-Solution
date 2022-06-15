#include <bits/stdc++.h>
using namespace std;
#define ll long long int

vector<vector<int>> nearest(vector<vector<int>>grid)
{
    vector<vector<int>> out;
    int n=grid.size();
    int m=grid[0].size();
    for(int i=0;i<n;i++){
        vector<int> v;
        for(int j=0;j<m;j++) {
            v.push_back(INT_MAX);
        }
        out.push_back(v);
    }

    queue<pair<int,int>> q;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==1) {
                q.push(pair<int,int>(i,j));
                out[i][j]=0;
            }
        }
    }

    // cout<<"here"<<'\n';
    while(!q.empty()){
        pair<int,int> temp=q.front();
        q.pop();
        int i=temp.first;
        int j=temp.second;  
        // cout<<i<<' '<<j<<'\n';
         if( (i - 1) >= 0  and out[i][j] + 1 < out[i-1][j])
        {
            out[i-1][j] = out[i][j] + 1 ;
            q.push({i-1,j});
        }
        
        if((j - 1) >= 0  and out[i][j] + 1 < out[i][j-1])
        {
            out[i][j-1] = out[i][j] + 1 ;
            q.push({i,j-1});
        }
        
        if((i + 1) < n  and out[i][j] + 1 < out[i+1][j])
        {
            out[i+1][j] = out[i][j] + 1 ;
            q.push({i+1,j});
        }
        
        if((j + 1) < m  and out[i][j] + 1 < out[i][j+1])
        {
             out[i][j+1] = out[i][j] + 1 ;
             q.push({i,j+1});
        }
    }

    // for(auto &it: out){
    //     for(auto &it2: it){
    //         cout<<it2<<' ';
    //     }
    //     cout<<'\n';
    // }
    return out;
}

int main(){
    vector<vector<int>> v={{1,0,1},{1,1,0},{1,0,0}};

    vector<vector<int>> out=nearest(v);
    return 0;
}