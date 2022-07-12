#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int dfs(string s, string p, int i, int j, vector<vector<int>>&dp){
    if(dp[i][j]==1) return 1;
    if(i>=s.length() and j>=p.length()) return 1;
    if(j>=p.length()) return false;

    bool match = (i<s.length() and (s[i]==p[j] or p[j]=='.'));
    if(j+1<p.length() and p[j+1]=='*'){
        dp[i][j]=(dfs(s,p,i,j+2,dp) or (match and dfs(s,p,i+1,j,dp)));
        return dp[i][j];
    }
    if(match){
        dp[i][j]=dfs(s,p,i+1,j+1,dp);
        return dp[i][j];
    }
    dp[i][j]=false;
    return false;
}
int isMatch(const string s, const string t) {
    int n=s.length();
    int m=t.length();

    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    return dfs(s,t,0,0,dp);
}
