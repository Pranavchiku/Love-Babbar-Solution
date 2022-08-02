#include<bits/stdc++.h>
using namespace std;

//not correct - remaining
int solution(int n, vector<int> &seq){
    if(n<=2) return n;
    vector<unordered_map<int,int>> dp(n);

    int max_len=2;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int diff=seq[j]-seq[i];
            // int diff2=seq[i]-seq[j];
            if(dp[i].find(-1*diff)!=dp[i].end()){
                dp[j][diff]=dp[i][diff]+1;
            }
            else{
                dp[j][diff]=1;
            }
            max_len=max(max_len,dp[j][diff]);
        }
    }

    return max_len;

}

int main(){
    int n;
    cin >> n;
    vector<int> seq(n);
    for(int i=0;i<n;i++){
        cin >> seq[i];
    }
    cout << solution(n,seq)<<'\n';
    return 0;
}