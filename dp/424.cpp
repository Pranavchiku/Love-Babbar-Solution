#include <bits/stdc++.h>
using namespace std;
#define ll long long int


int LongestRepeatingSubsequence(string str){
    int x=str.length();
    int y=str.length();
  int dp[x+1][y+1];
    for(int i=0;i<=x;i++){
        for(int j=0;j<=y;j++) dp[i][j]=0;
    }

    // for(int i=0;i<=x;i++){
    //     for(int j=0;j<=y;j++) cout<<dp[i][j]<<' ';
    //     cout<<'\n';
    // }

    int i=x-1;
    int j=y-1;

    for(i=x-1;i>=0;i--){
        
        for(j=y-1;j>=0;j--){
            // cout<<s1[i]<<' '<<s2[j]<<'\n';
            if(i!=j and str[i]==str[j]){
                dp[i][j]=1+dp[i+1][j+1];
            }
            else{
                dp[i][j]=max(dp[i+1][j+1],max(dp[i+1][j],dp[i][j+1]));
            }
            // cout<<dp[i][j]<<'\n';
        }
    }

    // for(int i=0;i<=x;i++){
    //     for(int j=0;j<=y;j++) cout<<dp[i][j]<<' ';
    //     cout<<'\n';
    // }
    return dp[0][0];
}
int main(){
    return 0;
}