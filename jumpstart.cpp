#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    //00
    //01
    //10
    //end with 0 - 2
    //end with 1 - 1

    //00 - 000 and 001
    //10 - 100 and 101
    //01 - 010

    //n=3 -> n=2 -> count(0)*2 +count(1)*1 = 2*2 + 1*1

    //new0=ans[n-1];
    //new1=prev0

    int n;cin>>n;
    //{count0,coun1};
    vector<pair<long long int,long long int>> dp(n+1);

    dp[0]={0,0};
    dp[1]={1,1};

    if(n==1) cout<<2<<'\n';
    else{
        for(long long int i=2;i<=n;i++){
            int new0=((dp[i-1].first)%1000000007 + (dp[i-1].second)%1000000007)%1000000007;
            int new1=dp[i-1].first;

            dp[i]={new0,new1};
        }

        long long int ans = ((dp[n].first)%1000000007 + (dp[n].second)%1000000007)%1000000007;
        cout<<ans<<'\n';
    }
    
    return 0;
}