#include<bits/stdc++.h>
using namespace std;
#define ll long long int

bool isValid(string s, int m){
    int start=s[0]-'0';
    int end=s[s.length()-1]-'0';
    int length=s.length();
    if(length>=m and start%2==0 and end%2!=0) return true;
    return false;
}
void helper(int n, int m, int k, string s, int start, long long &count){
    if(k==0){
        count=(count+1)%1000000007;
        // cout<<count<<'\n';

        return;
    }
    if(k==1){
        if(isValid(s.substr(start,s.length()-start),m)){
            count=(count+1)%1000000007;
            // cout<<count<<'\n';

            return;
        }
    }
    if(start>=n){
        return;
    }
    for(int i=start;i<n;i++){
        if(isValid(s.substr(start,i-start+1),m)){
            // cout<<s.substr(start,i-start+1)<<endl;
            helper(n,m,k-1,s,i+1,count);
        }
    }
    return;
}

long long solve(int n, int m, int k, string s){
    long long count=0;
    long long dp[n]={0};
    helper(n,m,k,s,0,count);
    return count;
}

int main(){
    int n,m,k;
    cin>>n>>m>>k;
    string s;
    cin>>s;
    cout<<solve(n,m,k,s)<<endl;
    return 0;
}