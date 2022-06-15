#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int longestSubsequence(int n, int a[])
{
    int dp[n];
    for(int i=0;i<n;i++) dp[i]=1;

    int i=n-2;
    while(i>=0){
        int j=i+1;
        while(j<n){
            if(a[j]==a[i]+1 or a[j]==a[i]-1) dp[i]=max(dp[i],dp[j]+1);
            j++;
        }
        i--;
    }

    return *max_element(dp,dp+n);
}

int main(){
    int n=7;
    int a[n]={10,9,4,5,4,8,6};
    cout<<longestSubsequence(n,a)<<'\n';
    return 0;
}