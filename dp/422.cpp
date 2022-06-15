#include <bits/stdc++.h>
using namespace std;
#define ll long long int


int maximizeTheCuts(int n, int p, int q, int r)
{
    vector<int>dp(n+1,-1);
    
    dp[0] = 0;
    423
    for(int i = 1; i<=n ;i++){
        if(i>=p && dp[i-p]!=-1){
            dp[i] = max(dp[i],1+dp[i-p]);
        }
        if(i>=q && dp[i-q]!=-1){
            dp[i] = max(dp[i],1+dp[i-q]);
        }
        if(i>=r && dp[i-r]!=-1){
            dp[i] = max(dp[i],1+dp[i-r]);
        }
    }
    return dp[n]==-1 ? 0 : dp[n];
}

int main(){
    return 0;
}