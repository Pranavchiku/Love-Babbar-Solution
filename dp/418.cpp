#include <bits/stdc++.h>
using namespace std;
#define ll long long int


int countFriendsPairings(int n) 
{ 
    long long int dp[n];
    dp[n-1]=1;
    dp[n-2]=2;
    int i=n-3;
    while(i>=0){
        dp[i]=((dp[i+1]%1000000007)+(((n-i-1)%1000000007)*(dp[i+2])%1000000007)%1000000007)%1000000007;
        i--;
    }
    return dp[0];
}
int main(){
    cout<<countFriendsPairings(6569)<<'\n';
    return 0;
}