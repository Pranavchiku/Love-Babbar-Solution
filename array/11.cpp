#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int doUnion(int a[], int n, int b[], int m)  {
    vector<int> uni;
    vector<int> inte;

    for(int i=0;i<n;i++){
        uni.push_back(a[i]);
    }
    for(int i=0;i<m;i++){
        if(!binary_search(uni.begin(),uni.end(),b[i])){
            uni.push_back(b[i]);
        }
    }
    return uni.size();
}

int main(){
    int n = 5;
    int a[n]={4,5,7,9};
    int m = 3;
    int b[m]={2,3,4};
    cout<<doUnion(a,n,b,m)<<'\n';
    return 0;
}