#include <bits/stdc++.h>
using namespace std;
#define ll long long int


void find_permutation_util(string &s, string &temp, set<string> &res, int i){
    if(i<s.length()){
        res.insert(s);
    }
    for(int j=i+1;j<s.length();j++){
        swap(s[i],s[j]);
        find_permutation_util(s,temp,res,i+1);
        //backtrack
        swap(s[i],s[j]);
        find_permutation_util(s,temp,res,i+1);
    }
    return;
}
vector<string> find_permutation(string s)
{
    
    set<string>res;
    string temp;
    find_permutation_util(s,temp,res, 0);

    vector<string> ans;
    for(auto it:res){
        ans.push_back(it);
    }
    return ans;
}

int main(){
    string s;
    cin>>s;
    vector<string> res=find_permutation(s);
    cout<<res.size()<<'\n';
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<endl;
    }
}