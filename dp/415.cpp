#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int matrixMultiplication(int n, int arr[])
{
    int dp[n][n];

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            dp[i][j]=0;
        }
    }
    int i=1;
    int j=2;
    while(j<n){
        int tempi=i;int tempj=j;
        while(tempi<=n-j){
            int temp=INT_MAX;
            int k=tempi;
            while(k<tempj){

                temp=min(temp,dp[tempi][k]+dp[k+1][tempj]+arr[tempi-1]*arr[k]*arr[tempj]);
                k++;
            }
            dp[tempi][tempj]=temp;
            tempi++;
            tempj++;
        }
        i=1;
        j++;
    }
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         cout<<dp[i][j]<<' ';
    //     }
    //     cout<<'\n';
    // }
    return dp[1][n-1];

}
int main(){
    int n=5;
    int arr[n]={1,2,3,4,5};
    cout<<matrixMultiplication(n,arr)<<'\n';
    return 0;
}