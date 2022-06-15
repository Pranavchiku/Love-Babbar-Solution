#include <bits/stdc++.h>
using namespace std;
#define ll long long int


int editDistance(string s, string t) {
    int n=s.length();
    int m=t.length();

    int dp[n+1][m+1];

    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            dp[i][j]=0;
        }
    }

    int j=m;
    for(int i=0;i<=n;i++){
        dp[i][j]=n-i;
    }

    int i=n;
    for(j=0;j<=m;j++){
        dp[i][j]=m-j;
    }

    // for(int i=0;i<=n;i++){
    //     for(int j=0;j<=m;j++){
    //         cout<<dp[i][j]<<' ';
    //     }
    //     cout<<'\n';
    // }

    i=n-1;j=m-1;
    while(i>=0){
        int tempi=i;
        int tempj=j;
        while(tempj>=0){
            // cout<<s[tempi]<<t[tempj]<<'\n';
            if(s[tempi]==t[tempj]) {
                // cout<<"here"<<'\n';
                dp[tempi][tempj]=dp[tempi+1][tempj+1];
            }
            else {
                dp[tempi][tempj]=min(dp[tempi+1][tempj+1],min(dp[tempi+1][tempj],dp[tempi][tempj+1]))+1;
            }
            tempj--;
        }
        j=m-1;i--;
    }

    // for(int i=0;i<=n;i++){
    //     for(int j=0;j<=m;j++){
    //         cout<<dp[i][j]<<' ';
    //     }
    //     cout<<'\n';
    // }

    return dp[0][0];
}


int main(){
    cout<<editDistance("dbb","fdfaccddfac")<<'\n';
    // cout<<editDistance("abd","acd")<<'\n';

    return 0;
}