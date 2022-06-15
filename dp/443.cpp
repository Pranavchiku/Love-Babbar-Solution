#include <bits/stdc++.h>
using namespace std;
#define ll long long int


long long int countBT(int h) { 
    int dp[h+1];
    dp[0]=1;
    dp[1]=1;
    for(int i=2;i<=h;i++){
        dp[i]=(((dp[i-2]%1000000007)*(dp[i-1]%1000000007))%1000000007)+((dp[i-2]%1000000007)*(dp[i-1]%1000000007))%1000000007+((dp[i-1]%1000000007)*(dp[i-1]%1000000007))%1000000007;
    }
    return dp[h];
}
int main(){
    return 0;
}