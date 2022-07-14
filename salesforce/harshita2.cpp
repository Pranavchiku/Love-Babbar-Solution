#include<bits/stdc++.h>
using namespace std;
#define ll int

void printDivisors(int n, set<int> &div)
{
    for (int i=1; i<=sqrt(n); i++)
    {
        if (n%i == 0)
        {
            if (n/i == i)
                div.insert(i);
 
            else{
                div.insert(i);
                div.insert(n/i);
            }
        }
    }
}

int helper(int n, vector<int> &dp){
    if(n==1) return 1;
    if(dp[n]!=-1) return dp[n];
    int ans=0;
    for (int i=1; i<=sqrt(n); i++)
    {
        if (n%i == 0)
        {
            if (n/i == i){
                ans=((ans%1000000007)+(helper(i,dp)%1000000007))%1000000007;
            }
            else 
            {
                ans=((ans%1000000007)+(helper(i,dp)%1000000007))%1000000007;
                if(i!=1)
                    ans=((ans%1000000007)+(helper(n/i,dp)%1000000007))%1000000007;
            }
        }
    }
    dp[n]=ans%1000000007;
    return ans%1000000007;
}

int main(){
    ll t;cin>>t;
    while(t--){
        ll n;cin>>n;
        vector<int> dp;
        for(int i=0;i<=n;i++){
            dp.push_back(-1);
        }
        dp[1]=1;
        int ans=helper(n,dp);
        cout<<ans<<'\n';
    }
}