#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int findMaxLen(string s) {
    int len=0;
    int left=0;
    int right=0;
    int n=s.length();
    for(int i=0;i<n;i++){
        if(s[i]=='(') left++;
        else right++;

        if(left==right) len=max(len,2*right);

        else if(right>left) left=right=0;
    }

    left=right=0;

    for(int i=n-1;i>=0;i--){
        if(s[i]=='(') left++;
        else right++;

        if(left==right) len=max(len,2*left);
        else if(left>right) left=right=0;
    }

    return len;

    
}


int main(){
    return 0;
}