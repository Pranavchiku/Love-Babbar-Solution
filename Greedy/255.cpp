#include <bits/stdc++.h>
using namespace std;
#define ll long long int

long long int maximizeSum(long long int arr[], int n, int k)
{
    sort(arr,arr+n);
    long long int countN=0;
    long long int sum=0;
    for(int i=0;i<n;i++){
        if(arr[i]<0) countN++;
    }
    if(k>countN){
        for(int i=0;i<countN;i++){
            arr[i]*=-1;
        }
        sort(arr,arr+n);
        int remain=k-countN;
        if(remain%2!=0){
            sum=sum-arr[0];
            for(int i=1;i<n;i++){
                sum+=arr[i];
            }
            return sum;
        }
        else{
            for(int i=0;i<n;i++) sum+=arr[i];
            return sum;
        }
    }
    else{
        for(int i=0;i<k;i++){
            arr[i]*=-1;
        }
        for(int i=0;i<n;i++){
            sum+=arr[i];
        }
        return sum;
    }
    
}