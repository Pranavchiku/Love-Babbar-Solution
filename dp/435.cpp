#include <bits/stdc++.h>
using namespace std;
#define ll long long int


int maxSumPairWithDifferenceLessThanK(int arr[], int n, int k)
{
    sort(arr,arr+n, greater<int>());

    int i=0;
    int sum=0;
    while(i<n-1){
        int diff=abs(arr[i]-arr[i+1]);
        if(diff<k){
            sum+=arr[i];
            sum+=arr[i+1];
            i+=2;
        }
        else i++;
    }
    return sum;
}
int main(){
    int n=7;
    int arr[n]={3,5,10,15,17,12,9};
    int k=4;
    cout<<maxSumPairWithDifferenceLessThanK(arr,n,k)<<'\n';
    return 0;
}