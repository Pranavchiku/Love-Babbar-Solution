#include <bits/stdc++.h>
using namespace std;
#define ll long long int


int longestSubsequence(int n, int a[])
{
    int dp[n];
    dp[n-1]=1;
    for(int i=0;i<n;i++) dp[i]=1;
    int i=n-2;
    while(i>=0){
        int j=i+1;
        int flag=0;
        while(j<n){
            if(a[j]>a[i]) {
                flag=1;
                dp[i]=max(dp[i],1+dp[j]);
            }
            j++;
        }
        i--;
    }

    return *max_element(dp,dp+n);
}
int main(){
    int n=7;
    int arr[n]={2,5,1,4,10,10,7};
    cout<<longestSubsequence(n,arr)<<'\n';
    return 0;
}