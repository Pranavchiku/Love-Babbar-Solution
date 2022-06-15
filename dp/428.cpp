#include <bits/stdc++.h>
using namespace std;
#define ll long long int


int maxSumIS(int arr[], int n)  
{  
    int dp[n];
    for(int i=0;i<n;i++) dp[i]=arr[i];
    int i=n-2;
    while(i>=0){
        int j=i+1;
        int flag=0;
        while(j<n){
            if(arr[j]>arr[i]) {
                flag=1;
                dp[i]=max(dp[i],arr[i]+dp[j]);
            }
            j++;
        }
        i--;
    }

    return *max_element(dp,dp+n);
} 
int main(){
    int n=5;
    int arr[n]={1,101,2,3,100};
    cout<<maxSumIS(arr,n)<<'\n';
    return 0;
}