#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int dfs(int i, int j, string s, string t, vector<vector<int>>&dp){
    if(j==t.length()) return 1;
    if(i==s.length()) return 0;

    if(dp[i][j]!=-1) return dp[i][j];


    if(s[i]==t[j]){
        dp[i][j]=dfs(i+1,j+1,s,t,dp)+dfs(i+1,j,s,t,dp);
    }
    else{
        dp[i][j]=dfs(i+1,j,s,t,dp);
    }
    return dp[i][j];

}
int numDistinct(string A, string B) {
    vector<vector<int>> dp(A.length()+1,vector<int>(B.length()+1,-1));
    int temp=dfs(0,0,A,B,dp);
    return dp[0][0];
}