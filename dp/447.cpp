#include <bits/stdc++.h>
using namespace std;
#define ll long long int


bool isPresent(string word,vector<string> &B){
    for(auto& it: B){
        if(it.compare(word)==0) return true;
    }
    return false;
}
/*

This will lead to TLE - O(n3) time and O(n2) space


int wordBreak(string a, vector<string> &b) {
    int n=a.length();
    bool dp[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) dp[i][j]=0;
    }
    int i=0;int j=0;int len=0;

    
    while(j<n){
        int tempi=i;
        int tempj=j;
        while(tempi+len<n){
            // cout<<a.substr(tempi,len)<<'\n';
            if(isPresent(a.substr(tempi,len+1),b)) dp[tempi][tempj]=true;
            else{
                int k=tempi;
                while(k<j){
                    dp[tempi][tempj]|=(dp[tempi][k]&&dp[k+1][tempj]);
                    k++;
                }
            }
            tempi++;
            tempj++;
        }
        len++;
        j++;i=0;
    }

    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++) cout<<dp[i][j]<<' ';
    //     cout<<'\n';
    // }

    return dp[0][n-1];
}
*/
int wordBreak(string a, vector<string> &b) {
    int n=a.size();
    if(n==0) return true;
    bool dp[n+1];
    memset(dp, 0, sizeof(dp));

    for(int i=1;i<=n;i++){
        if(dp[i]==false and isPresent(a.substr(0,i),b)) dp[i]=true;
        if(dp[i]==true){
            if(i==n) return true;
            for(int j=i+1;j<=n;j++){
                if(dp[j]==false and isPresent(a.substr(i,j-i),b)) dp[j]=true;
                if(j==n and dp[j]==true) return true;
            }
        }
    }

    return false;
}

int main(){
    int n=12;
//     vector<string> b = { "i", "like", "sam",
// "sung", "samsung", "mobile",
// "ice","cream", "icecream",
// "man", "go", "mango" };
vector<string> b={"my","pen"};
    string a="mypenmy";
    cout<<wordBreak(a,b)<<'\n';
    return 0;
}