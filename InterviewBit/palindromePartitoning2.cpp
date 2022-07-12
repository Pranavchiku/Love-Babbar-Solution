#include<bits/stdc++.h>
using namespace std;
#define ll long long int


bool isPalindrome(string s, int start, int end){
    int l=start;
    int h=end;
    while(l<h){
        if(s[l]!=s[h]) return false;
        l++;
        h--;
    }
    return true;
}

// int helper(string s, vector<string> curr, int i, int n, int& cut, vector<int> &dp){
//     if(i==n){
//         int temp=curr.size();
//         for(auto x:curr){
//             cout<<x<<" ";
//         }

//         cout<<endl;
//         cout<<temp<<'\n';
//         cut=min(cut,temp-1);
//         return cut;
//     }
//     if(dp[i]!=-1){
//         for(auto x:curr){
//             cout<<x<<" ";
//         }

//         cout<<endl;
//         int temp=curr.size()-1;
//         cut=min(cut, temp+dp[i]);
//         return cut;
//     }
//     for(int j=i;j<n;j++){
//         if(isPalindrome(s,i,j)){
//             curr.push_back(s.substr(i,j-i+1));
//             dp[j]=helper(s,curr,j+1,n,cut,dp);
//             for(auto it: dp) cout<<it<<' ';
//             cout<<'\n';
//             curr.pop_back();
//         }
//     }
//     return cut;
// }

int helper(){
    
}
int minCut(string A) {
    if(isPalindrome(A,0,A.size()-1)) return 0;
    vector<string> curr;
    vector<int> dp(A.size());
    for(int i=0;i<A.size();i++) dp[i]=-1;
    // int cut=INT_MAX;
    // helper(A,curr,0,A.size(),cut,dp);
    // int ans=INT_MAX;
    // for(auto it: dp){
    //     if(it!=-1) ans=min(ans,it);
    // }
    // return ans;
}

int main(){
    string s="ababb";
    cout<<minCut(s)<<endl;
    return 0;
}
