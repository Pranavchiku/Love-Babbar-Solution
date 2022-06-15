#include <bits/stdc++.h>
using namespace std;
#define ll long long int

/*
This is o(n2) time and o(n) memory will lead to tle 
use two pointers to optimise
int AlternatingaMaxLength(vector<int>&nums){
    int n=nums.size();
    int dp[n][2];
    int out=-INT_MAX;
    for(int i=0;i<n;i++){
        dp[i][0]=1;dp[i][1]=1;
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(nums[i]>nums[j]){
                dp[i][0]=max(dp[i][0],dp[j][1]+1);
            }
            if(nums[i]<nums[j]){
                dp[i][1]=max(dp[i][1],dp[j][0]+1);
            }
        }
        out=max(out,max(dp[i][0],dp[i][1]));
    }
    return out;
}
*/

int AlternatingaMaxLength(vector<int>&nums){
    int inc=1;
    int dec=1;
    int n=nums.size();
    for(int i=1;i<n;i++){
        if(nums[i]>nums[i-1]) inc=dec+1;
        else if(nums[i]<nums[i-1]) dec=inc+1;
    }
    return max(dec,inc);
}
int main(){
    vector<int> nums={1,17,5,10,13,15,10,5,16,8};
    cout<<AlternatingaMaxLength(nums)<<'\n';
    return 0;
}