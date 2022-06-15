#include <bits/stdc++.h>
using namespace std;
#define ll long long int


int findDuplicate(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    int i=1;
    while(i<nums.size()-1 and nums[i]!=nums[i-1]){
        i++;
    }
    return nums[i];
}

int main(){
    vector<int>nums={2,2,2,2,2,2};
    cout<<findDuplicate(nums)<<'\n';
    return 0;
}