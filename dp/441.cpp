#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int longestCommonSubstr (string s1, string s2, int x, int y)
{
    int dp[x+1][y+1];
    for(int i=0;i<=x;i++){
        for(int j=0;j<=y;j++) dp[i][j]=0;
    }

    // for(int i=0;i<=x;i++){
    //     for(int j=0;j<=y;j++) cout<<dp[i][j]<<' ';
    //     cout<<'\n';
    // }

    int i=1;
    int j=1;
    for(i=1;i<=x;i++){
        for(j=1;j<=y;j++){
            if(s1[i-1]==s2[j-1]) dp[i][j]=1+dp[i-1][j-1];
            else dp[i][j]=0;
        }
    }


    int temp=-INT_MAX;
    for(i=0;i<=x;i++){
        temp=max(temp,*max_element(dp[i],dp[i]+y+1));
    }



    

    // cout<<'\n';
    // for(int i=0;i<=x;i++){
    //     for(int j=0;j<=y;j++) cout<<dp[i][j]<<' ';
    //     cout<<'\n';
    // }
    return temp;
}
int main(){
    cout<<longestCommonSubstr("babacdgh","abaacdgp",8,8)<<'\n';
    return 0;
}