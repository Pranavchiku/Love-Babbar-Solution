#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int numOfSubsets(int arr[], int n, int k) {
    vector<int> v={};

    int i=n-1;
    while(i>=0){
        for(auto&it :v){
            if(it*arr[i]<=k) v.push_back(it*arr[i]);
        }
        if(arr[i]<=k) v.push_back(arr[i]);
        i--;
    }

    // for(auto&it :v) cout<<it<<' ';
    // cout<<'\n';
    return v.size();
}

int main(){
    int n=8;
    int arr[n]={2,3,6,2,3,7,1,4};
    int k=6260;
    cout<<numOfSubsets(arr,n,k)<<'\n';
    return 0;
}