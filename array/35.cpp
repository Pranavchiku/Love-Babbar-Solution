#include <bits/stdc++.h>
using namespace std;
#define ll long long int

long long findMinDiff(vector<long long> a, long long n, long long m){
    sort(a.begin(),a.end());
    long long out=a[m-1]-a[0];
    long long i=m;
    while(i<n){
        out=min(out,a[i]-a[i-m+1]);
        i++;
    }
    return out;
}

int main(){
    long long n=7;long long m=3;
    vector<long long> a={7,3,2,4,9,12,56};
    cout<<findMinDiff(a,n,m)<<'\n';
    return 0;
}