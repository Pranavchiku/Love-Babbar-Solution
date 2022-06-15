#include <bits/stdc++.h>
using namespace std;
#define ll long long int


int maxSquare(int n, int m, vector<vector<int>> mat){
    int dp[n][m];
    for(int j=0;j<m;j++){
        dp[n-1][j]=mat[n-1][j];
    }
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++) cout<<dp[i][j]<<' ';
    //     cout<<'\n';
    // }
    // cout<<'\n';
    for(int i=0;i<n;i++){
        dp[i][m-1]=mat[i][m-1];
    }
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++) cout<<dp[i][j]<<' ';
    //     cout<<'\n';
    // }
    // cout<<'\n';
    for(int i=n-2;i>=0;i--){
        for(int j=m-2;j>=0;j--){
            if(mat[i][j]==0) dp[i][j]=0;
            else dp[i][j]=1+min(dp[i+1][j+1],min(dp[i][j+1],dp[i+1][j]));
        }
    }

    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++) cout<<dp[i][j]<<' ';
    //     cout<<'\n';
    // }
    int temp=-INT_MAX;
    for(int i=0;i<n;i++) temp=max(temp,*max_element(dp[i],dp[i]+m));

    return temp;
}
int main(){
    int n=5;int m=6;
    vector<vector<int>> mat={{0,1,0,1,0,1},{1,0,1,0,1,0},{0,1,1,1,1,0},{0,0,1,1,1,0},{1,1,1,1,1,1}};
    cout<<maxSquare(n,m,mat)<<'\n';
    return 0;
}