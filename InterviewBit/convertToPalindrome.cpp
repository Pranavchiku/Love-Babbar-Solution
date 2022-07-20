#include<bits/stdc++.h>
using namespace std;


bool isPalindrome(string A){
    int l=0;
    int r=A.size()-1;
    while(l<=r){
        if(A[l]!=A[r]) return false;
        l++;
        r--;
    }
    return true;
}
int solve(string A) {
    int n=A.size();
    if(n%2!=0 and isPalindrome(A)) return true;
    else if(n%2==0 and isPalindrome(A)) return false;
    else{
        int l=0;
        int r=A.size()-1;
        int flag=1;
        while(l<=r){
            if(A[l]!=A[r]){
                if(flag){
                    flag=0;
                }
                else return false;
            }
            l++;
            r--;
        }
        return true;
    }
}

int main(){
    string A="phmjjmap";
    cout<<solve(A)<<endl;
    return 0;
}
