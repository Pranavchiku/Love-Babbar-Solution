#include <bits/stdc++.h>
using namespace std;
#define ll long long int


string isSubset(int a1[], int a2[], int n, int m) {
    int m1=*max_element(a1,a1+n);
    int m2=*max_element(a2,a2+m);
    int x = max(m1,m2);
    if(n>m){
        int freq[x+1]={0};
        for(int i=0;i<n;i++) freq[a1[i]]++;

        for(int i=0;i<m;i++){
            if(freq[a2[i]]==0) return "No";
        }
        return "Yes";
    }
    else{
        int freq[x+1]={0};
        for(int i=0;i<m;i++) freq[a2[i]]++;

        for(int i=0;i<n;i++){
            if(freq[a1[i]]==0) return "No";
        }
        return "Yes";
    }
}

int main(){
    int n=5;int a1[n]={10, 5, 2, 23, 19};
    int m=3;int a2[m]={19,5,3};
    cout<<isSubset(a1,a2,n,m)<<'\n';
    return 0;
}