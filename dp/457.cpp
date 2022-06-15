#include <bits/stdc++.h>
using namespace std;
#define ll long long int


int countDer(int n){
    int dp[n+1];
    dp[0]=0;
    dp[1]=0;
    dp[2]=1;
    int i=3;
    while(i<=n){
        dp[i]=(i-1)*(dp[i-1]+dp[i-2]);
        i++;
    }
    return dp[n];
}
int main(){
    cout<<countDer(4)<<'\n';
    return 0;
}