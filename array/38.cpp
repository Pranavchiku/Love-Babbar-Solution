#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int minSwap(int arr[], int n, int k) {
    int count=0;
    for(int i=0;i<n;i++){
        if(arr[i]<=k) count++;
    }
    if(count==0) return count;
    else if(count==1) return 0;
    else{
        int i=0;
        int j=count-1;
        int output=INT_MAX;
        
        int bad=0;
        int temp=i;
        while(temp<=j){
            if(arr[temp]>k) {
                bad++;
            }
            temp++;
        }

        output=min(output,bad);
        i++;j++;
        while(bad>=0 and j<=n-1){
            if(arr[j]>k) output=min(output,++bad);
            if(arr[i-1]>k){
                output=min(output,--bad);
                if(output<=0) return 0;
            }
            j++;i++;
        }
        return min(bad,output);
    }
}

int main(){
    int n=7;int k=6;
    int arr[n]={2,7,9,5,8,7,4};
    cout<<minSwap(arr,n,k)<<'\n';
    return 0;
}