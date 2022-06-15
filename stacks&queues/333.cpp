#include <bits/stdc++.h>
using namespace std;
#define ll long long int


int minValue(string s, int k){
    if(k>s.length()) return 0;
    vector<int> v;
    for(int i=0;i<26;i++) v.push_back(0);

    for(int i=0;i<s.size();i++){
        v[s[i]-'a']++;
    }  
    // for(auto &it:v){
    //     cout<<it<<' ';  
    // }
    // cout<<'\n';

    sort(v.begin(),v.end());
    // for(auto &it:v){
    //     cout<<it<<' ';  
    // }
    // cout<<'\n';
    int maxi=v[24];
    while(k--){
        v[25]--;
        if(v[25]<maxi) {
            sort(v.begin(),v.end());
            maxi=v[24];
        }
    }
    int ans=0;
    for(auto &it:v){
        // cout<<it<<' ';
        ans+=(it*it);
    }
    // cout<<'\n';
    return ans;

}
int main(){
    cout<<minValue("abccc",1)<<'\n';
    return 0;
}