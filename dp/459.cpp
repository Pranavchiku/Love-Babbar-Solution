#include <bits/stdc++.h>
using namespace std;
#define ll long long int


long long maximumAmount(int arr[], int n){
    int sum[n][n];
    int dp[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            sum[i][j]=0;
            dp[i][j]=0;
        }
    }

    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if(i==j) sum[i][j]=arr[j];
            else{
                sum[i][j]=sum[i][j-1]+arr[j];
            }
        }
    }

    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         cout<<sum[i][j]<<' ';
    //     }
    //     cout<<'\n';
    // }

    int i=0;int j=0; int len=1;
    while(j<n){
        int tempi=i;
        int tempj=j;
        while(tempi+len-1<n){
            if(len==1) dp[tempi][tempj]=arr[tempj];
            else if(len==2) dp[tempi][tempj]=max(dp[tempi][tempj-1],dp[tempi+1][tempj]);
            else{
                dp[tempi][tempj]=max(arr[tempi]+sum[tempi+1][tempj]-dp[tempi+1][tempj],arr[tempj]+sum[tempi][tempj-1]-dp[tempi][tempj-1]);
            }
            tempi++;tempj++;
        }
        i=0;j++;len++;
    }
    return dp[0][n-1];
}
int main(){
    int n=4;
    int arr[n]={8,15,3,7};
    cout<<maximumAmount(arr,n)<<'\n';
    return 0;
}