#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve(string str, int n,int k, string& ans, int index){
    if(k==0) return;
    char maxChar=str[index];
    for(int i=index+1;i<n;i++){
        if(str[i]>maxChar){
            maxChar=str[i];
        }
    }

    if(maxChar!=str[index]){
        k--;
    }

    for(int i=n-1;i>=index;i--){
        if(str[i]==maxChar){
            swap(str[index],str[i]);
            if(ans<str) ans=str;
            solve(str,n,k,ans,index+1);
            //backtrack
            swap(str[index],str[i]);
        }
    }
    
}
string findMaximumNum(string str, int k)
{
    string ans=str;
    int n=str.length();
    solve(str,n,k,ans,0);
    return ans;
}