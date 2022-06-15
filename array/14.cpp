#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int getMinDiff(int arr[], int n, int k) {
    sort(arr,arr+n);
    int mini = arr[0];
    int diff = arr[n-1]-arr[0];
    int maxi = arr[n-1];
    int i=0;
    while(i<n){
        if(arr[i]-k>=mini){
            arr[i]=arr[i]-k;
            mini=*min_element(arr, arr + n);
            maxi=*max_element(arr,arr+n);
            diff=min(diff,maxi-mini);
            i++;
        }
        else{
            arr[i]=arr[i]+k;
            mini=*min_element(arr, arr + n);
            maxi=*max_element(arr,arr+n);
            diff=min(diff,maxi-mini);
            i++;
        }
    }
    return min(diff,maxi-mini);
}
int main(){
    int k=2;int n=4;
    int arr[n]={1,5,8,10};
    cout<<getMinDiff(arr,n,k)<<'\n';
    return 0;
}