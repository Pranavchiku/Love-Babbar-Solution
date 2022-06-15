#include <bits/stdc++.h>
using namespace std;
#define ll long long int


int findMaxSum(int *arr, int n) {
    int dp[n];
    dp[0]=arr[0];
    dp[1]=arr[0]+arr[1];
    dp[2]=max(dp[1],max(arr[0]+arr[2],arr[1]+arr[2]));

    int i=3;
    while(i<n){
        dp[i]=max(dp[i-1],max(dp[i-2]+arr[2],dp[i-3]+arr[i]+arr[i-1]));
        i++;
    }

    return dp[n-1];
}
int main(){
    int n=6;
    int arr[n]={5,5,10,100,10,5};
    cout<<findMaxSum(arr,n)<<'\n';
    return 0;
}