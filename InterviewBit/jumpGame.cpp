#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int dfs(vector<int> &dp, vector<int> &A, int i, int n){
    if(i>=n) {
        // cout<<"here2"<<'\n';
        return 1;
    }
    if(dp[i]!=-1) {
        // cout<<"here5"<<'\n';
        return dp[i];
    }
    // cout<<"here"<<'\n';
    int steps=A[i];
    int j=i+1;
    dp[i]=0;
    while(j<n and steps--){
        // cout<<j<<'\n';
        if(dfs(dp,A,j,n)==1) {
            return dp[i]=1;
        }
        j++;
    }
    return dp[i]=0;
}

int canJump(vector<int> &A) {
    if(A.size()==1 and A[0]==0) {
        // cout<<"fads"<<'\n';
        return 1;
    }
    // if(A.size()>1 and A[0]==0) return 0;
    // cout<<"here3"<<'\n';
    int n=A.size();
    vector<int> dp(n,-1);
    // cout<<"here4"<<'\n';
    int temp= dfs(dp,A,0,A.size());
    return dp[0];
}

int main(){
    int n;cin>>n;
    vector<int> A(n);
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
    cout<<canJump(A)<<endl;
    return 0;
}
