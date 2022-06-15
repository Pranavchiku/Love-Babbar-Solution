#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int eggDrop(int n, int k) 
{
    int dp[n+1][k+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=k;j++) dp[i][j]=0;
    }

    for(int j=1;j<=k;j++) dp[1][j]=j;

    for(int i=1;i<=n;i++) dp[i][1]=1;

    

    for(int i=2;i<=n;i++){
        for(int j=2;j<=k;j++){
            int temp=INT_MAX;
            for(int a=1;a<=j;a++){
                temp=min(temp,max(dp[i-1][a-1],dp[i][j-a]));
            }
            dp[i][j]=1+temp;
        }
    }
    
    // for(int i=0;i<=n;i++){
    //     for(int j=0;j<=k;j++) cout<<dp[i][j]<<' ';
    //     cout<<'\n';
    // }
    return dp[n][k];
}
int main(){
    cout<<eggDrop(2,10)<<'\n';
    return 0;
}