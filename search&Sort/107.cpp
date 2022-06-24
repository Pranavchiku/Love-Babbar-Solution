#include <bits/stdc++.h>
using namespace std;
#define ll long long int


int *findTwoElement(int *arr, int n) {
    int freq[n+1]={0};
    for(int i=0;i<n;i++){
        freq[arr[i]]++;
    }
    int *ans = new int[2];
    for(int i=1;i<=n;i++){
        if(freq[i]>1){
            ans[0]=i;
        }
        if(freq[i]==0){
            ans[1]=i;
        }
    }
    return ans;
}

int main(){
    int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int *ans=findTwoElement(arr,n);
    cout<<ans[0]<<" "<<ans[1]<<endl;
    return 0;
}