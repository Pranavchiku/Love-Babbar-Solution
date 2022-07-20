#include<bits/stdc++.h>
using namespace std;
#define ll long long int


string solve(string A) {
    int n=A.size();
    cout<<n<<'\n';
    int i=0;
    string ans="";
    string temp="";
    while(i<n and A[i]==' ') i++;
    while(i<n){
        if(A[i]!=' '){
            temp+=A[i];
            i++;
        }
        else{ 
            temp=" "+temp;
            cout<<temp<<'\n';
            ans=temp+ans;
            temp="";
            while(i<n and A[i]==' ') i++;
            cout<<i<<'\n';

        }
    }
    ans=temp+ans;
    i=0;
    while(i<n and ans[i]==' ') i++;
    string fAns="";
    while(i<n){
        fAns+=ans[i];
        i++;
    }
    return fAns;
    
}

int main(){
    string A="fwbpudnbrozzifml osdt ulc jsx kxorifrhubk ouhsuhf sswz qfho dqmy sn myq igjgip iwfcqq";
    cout<<solve(A)<<'\n';
    return 0;
}
