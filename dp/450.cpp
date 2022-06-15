#include <bits/stdc++.h>
using namespace std;
#define ll long long int


int lcs(int x, int y, string s1, string s2)
{
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
            if(s1[i]==s2[j]){
                dp[i][j]=1+dp[i+1][j+1];
            }
            else{
                dp[i][j]=max(dp[i+1][j+1],max(dp[i+1][j],dp[i][j+1]));
            }
            // cout<<dp[i][j]<<'\n';
        }
    }

    // cout<<'\n';
    // for(int i=0;i<=x;i++){
    //     for(int j=0;j<=y;j++) cout<<dp[i][j]<<' ';
    //     cout<<'\n';
    // }
    return dp[0][0];
}

int longestPalinSubseq(string a) {
    int n=a.size();
    string b=string(a.rbegin(),a.rend());
    return lcs(n,n,a,b);
}

int main(){
    cout<<longestPalinSubseq("bbabcbcab")<<'\n';
    return 0;
}