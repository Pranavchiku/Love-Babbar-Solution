#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int sum(vector<int> C, int from, int to){
    int res=0;
    for(int i=from;i<=to;i++){
        res+=C[i];
    }
    return res;
}
int paint(int k, int B, vector<int> &C) {
    int n=C.size();
    int dp[k+1][n+1]={0};
    for(int i=1;i<=n;i++){
        dp[1][i]=sum(C,0,i-1);
    }
    for(int i=1;i<=k;i++){
        dp[i][1]=C[0];
    }
    for(int i=2;i<=k;i++){
        for(int j=2;j<=n;j++){
            int best=INT_MAX;
            for(int p=1;p<=j;p++){
                best=min(best,max(dp[i-1][p],sum(C,p,j-1)));
            }
            dp[i][j]=best;
        }
        
    }

    return dp[k][n];
}

int main(){
    return 0;
}