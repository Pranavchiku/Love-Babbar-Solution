#include <bits/stdc++.h>
using namespace std;
#define ll long long int


long long int  countPS(string str)
{
    int n=str.size();
    long long int dp[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            dp[i][j]=0;
        }
    }
    int i=0;int j=0;int len=1;
    while(j<n){
        int tempi=i;
        int tempj=j;
        while(tempi+len-1<n){
            if(len==1) dp[tempi][tempj]=1;
            else{
                if(str[tempi]==str[tempj]){
                    dp[tempi][tempj]=dp[tempi][tempj-1]+dp[tempi+1][tempj]+1;
                }
                else{
                    dp[tempi][tempj]=dp[tempi][tempj-1]+dp[tempi+1][tempj]-dp[tempi+1][tempj-1];
                }
            }
            tempi++;tempj++;
        }
        i=0;j++;len++;

    }
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         cout<<dp[i][j]<<' ';
    //     }
    //     cout<<'\n';
    // }
    return dp[0][n-1];
}

int main(){
    cout<<countPS("abccbc")<<'\n';
    return 0;
}