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

//more intutive
int maxProduct(const vector<int> &arr) {
    int n=arr.size();
    int mini=1;
    int maxi=1;
    int ans=arr[0];
    for(int i=0;i<n;i++){
        int temp=mini;
        //take minimum from every possible case
        mini=min({arr[i],arr[i]*mini, arr[i]*maxi});
        //take maximum from every possible case
        maxi=max({arr[i],arr[i]*maxi,arr[i]*temp});
        //take maximum of all possible cases
        ans=max(ans,maxi);
    }
    return ans;
    
}


int main(){
    int n=7;
    vector<int> arr={9,0,8,-1,-2,-2,6};
    cout<<maxProduct(arr,n)<<'\n';
    return 0;
}