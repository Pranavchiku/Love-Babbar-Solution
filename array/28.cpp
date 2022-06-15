#include <bits/stdc++.h>
using namespace std;
#define ll long long int

long long maxProduct(vector<int> arr, int n) {
    int mini=1;
    int maxi=1;
    int output=1;
    for(int i=0;i<n;i++){
        if(arr[i]==0){
            output=max(output,maxi);
            maxi=mini=1;
        }
        else{
            if(arr[i]>0){
                maxi*=arr[i];
            }
            else{
                int temp=mini;
                mini=maxi;
                maxi=temp;
                mini*=arr[i];
            }
        }
    }
    return max(output,maxi);
}

int main(){
    int n=7;
    vector<int> arr={9,0,8,-1,-2,-2,6};
    cout<<maxProduct(arr,n)<<'\n';
    return 0;
}