#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void maxProf(int arr[], int n){
    int prof1[n]={0};
    int maxp=arr[n-1];
    for(int i=n-2;i>=0;i--){
        maxp=max(maxp,arr[i]);
        prof1[i]=max(prof1[i+1],maxp-arr[i]);
    }
    int minb=arr[0];
    int prof2[n]={0};
    for(int i=1;i<n;i++){
        minb=min(minb,arr[i]);
        prof2[i]=max(prof2[i-1],arr[i]-minb);
    }
    int output=-INT_MAX;
    for(int i=0;i<n-2;i++) output=max(output,prof2[i]+prof1[i+1]);
    cout<<output<<'\n';
    // for(int i=0;i<n;i++) cout<<prof1[i]<<' ';
    // cout<<'\n';
}

int main(){
    int n=7;
    int price[n]={90,80,70,60,50,40,30};
    maxProf(price,n);
    return 0;
}