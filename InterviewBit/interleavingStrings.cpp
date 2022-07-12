#include<bits/stdc++.h>
using namespace std;
#define ll long long int

bool dfs(string a, string b, string c, int i, int j, vector<vector<int>> &dp){
    if(i==a.length() and j==b.length()) return true;
    if(dp[i][j]==1) return true;
    if(i<a.length() and a[i]==c[i+j] and dfs(a,b,c,i+1,j,dp)) return true;
    if(j<b.length() and b[j]==c[i+j] and dfs(a,b,c,i,j+1,dp)) return true;
    dp[i][j]=false;
    return false;
}
int isInterleave(string A, string B, string C) {
    if(A.length()+B.length()!=C.length()) return 0;
    vector<vector<int>> dp(A.length()+1, vector<int>(B.length()+1,0));

    dp[A.length()][B.length()]=1;

    for(int i=A.length();i>=0;i--){
        for(int j=B.length();j>=0;j--){
            if(i<A.length() and A[i]==C[i+j] and dp[i+1][j]){
                dp[i][j]=1;
            }
            else if(j<B.length() and B[j]==C[i+j] and dp[i][j+1]){
                dp[i][j]=1;
            }
        }
    }

    return dp[0][0];
}

int main(){
    string a="b";
    string b="e";
    string c="be";
    cout<<isInterleave(a,b,c)<<endl;
    return 0;
}