#include <bits/stdc++.h>
using namespace std;
#define ll long long int


long long maxSubarraySum(int arr[], int n){
    long long out = -INT_MAX;
    long long sum = 0;
    int i=0;
    while(i<n){
        if(i==0){
            if(arr[i]<0){
                int temp=arr[i];
                while(i<n and arr[i]<=0) {
                    sum=arr[i];
                    if(out<sum){
                        out=sum;
                    }
                    i++;
                }
                if(i==n) return out;
                else sum=0;
            }
            else{
                sum+=arr[i++];
            }
        }
        else if(arr[i]>0){
            sum+=arr[i];
            i++;
        }
        else{
            if(sum>out){
                out = sum;
            }
            sum+=arr[i];
            if(sum<=0) sum=0;
            i++;
        }
    }
    
    return max(out,sum);
        
}


int main(){
    int n =9;
    int arr[n]={-2,1,-3,4,-1,2,1,-5,4};
    cout<<maxSubarraySum(arr,n)<<'\n';
    return 0;
}