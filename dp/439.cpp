#include <bits/stdc++.h>
using namespace std;
#define ll long long int


int minimumCost(int cost[], int n, int w) 
{ 
    int dp[w+1];
    dp[0]=0;
    int sum=0;
    for(int i=0;i<n;i++) sum+=cost[i];
    int i=1;
    while(i<=w){
        int temp=INT_MAX;
        for(int j=0;j<i;j++){
            if(j<n and cost[j]!=-1){
                temp=min(temp,cost[j]+dp[i-(j+1)]);
            }
        }
        dp[i]=temp;
        i++;
    }

    // for(int i=0;i<=w;i++) cout<<dp[i]<<' ';
    // cout<<'\n';
    return dp[w];
}
int main(){
    int n=5;int w=6;
    int arr[n]={20,10,4,50,100};
    cout<<minimumCost(arr,n,w)<<'\n';
    return 0;
}