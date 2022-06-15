#include <bits/stdc++.h>
using namespace std;
#define ll long long int


int nCr(int n, int r){
    int dp[r+1];
    dp[0]=1;
    dp[1]=n;
    for(int i=2;i<=r;i++){
        dp[i]=(dp[i-1]*(n-i+1))/(i);
    }
    return dp[r];
}

int main(){
    cout<<nCr(2,4)<<'\n';
    return 0;
}