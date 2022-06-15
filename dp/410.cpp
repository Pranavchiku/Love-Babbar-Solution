#include <bits/stdc++.h>
using namespace std;
#define ll long long int

long long int count1(int s[], int m, int n) {
    long long int dp[n+1];
    for(int i=0;i<n+1;i++) dp[i]=0;
    sort(s,s+m);

    dp[0]=1;
    int i=m-1;
    for(int j=1;j<n+1;j++){
        if(j-s[i]>=0) dp[j]+=dp[j-s[i]];
        else dp[j]=0;
    }

    // for(int j=0;j<n+1;j++){
    //     cout<<dp[j]<<' ';
    // }
    // cout<<'\n';
    for(int i=m-2;i>=0;i--){
        for(int j=1;j<n+1;j++){
            if(j-s[i]>=0){
                dp[j]+=dp[j-s[i]];
            }
        }
        // for(int j=0;j<n+1;j++){
        //     cout<<dp[j]<<' ';
        // }
        // cout<<'\n';
    }

    return dp[n];
    
}

int main(){
    int n=10;int m=4;
    int arr[m]={2,5,3,6};
    cout<<count1(arr,m,n)<<'\n';
    return 0;
}