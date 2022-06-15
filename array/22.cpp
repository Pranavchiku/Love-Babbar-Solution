#include <bits/stdc++.h>
using namespace std;
#define ll long long int


int getPairsCount(int arr[], int n, int k) {
    int maxElem=*max_element(arr,arr+n);
    int freq[maxElem+1]={0};
    for(int i=0;i<n;i++) freq[arr[i]]++;
    int l=0;
    int r=maxElem;
    int count=0;
    if(k%2==0){
        while(l<maxElem+1){
            if(k/2==l){
                count+=(freq[l]*(freq[l]-1))/2;
                l++;
            }
            l++;
        }
    }
    l=0;
    while(l<r){
        if(freq[l]!=0 and freq[r]!=0){
            if(l+r>k) r--;
            else if(l+r<k) l++;
            else{
                count+=(freq[l]*freq[r]);
                r--;l++;
            }
        }
        else if(freq[l]==0) l++;
        else if(freq[r]==0) r--;
        else{
            l++;r--;
        }
    }
    return count;
}

int main(){
    int n=7;int k=5;
    int arr[n]={1,1,2,3,4,4,7};
    cout<<getPairsCount(arr,n,k)<<'\n';
    return 0;
}