#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void subsets(string s){
    //(i<<n) is 2^n
    int n=s.size();
    for(int i=0;i<(1<<n);i++){
        for(int j=0;j<n;j++){
            if(i&(1<<j)){
                cout<<s[j]<<" ";
            }
        }
        cout<<endl;
    }
}

vector<string> AllPossibleStrings(string s){
    vector<string> ans;
    int n=s.length();
    for(int i=0;i<(1<<n);i++){
        string str="";
        for(int j=0;j<n;j++){
            if(i&(1<<j)){
                str+=s[j];
            }
        }
        ans.push_back(str);
    }
    return ans;
}

int main(){
    string s="abc";
    subsets(s);
    return 0;
}