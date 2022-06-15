#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int findCatalan(int n) 
{
    int dp[n+1];
    dp[0]=1;
    dp[1]=1;
    for(int i=2;i<=n;i++){
        int j=0;
        int c=0;
        while(j<i){
            c+=(dp[j]*dp[i-j-1]);
            j++;
        }
        dp[i]=c;
    }
    return dp[n];
}
int main(){
    cout<<findCatalan(23)<<'\n';
    return 0;
}