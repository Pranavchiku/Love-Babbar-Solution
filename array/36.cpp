#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int smallestSubWithSum(int arr[], int n, int x)
{
    int p=0;
    int q=p+1;
    int m=*max_element(arr,arr+n);
    if(m>x){
        return 1;
    }
    else{
        int sum=arr[p]+arr[q];
        q++;
        int out=INT_MAX;
        while(p<n and q<n){
            while(q<n and sum<=x){
                sum+=arr[q++];
            }
            while(p<n and sum>x){
                sum-=arr[p++];
            }
    
            out=min(out,q-p+1);
            sum+=arr[++q];
        }
        return out;
    }
}

int main(){
    int n=8;int x=16;
    int arr[n]={6,3,4,5,4,3,7,9};
    cout<<smallestSubWithSum(arr,n,x)<<'\n';
    return 0;
}