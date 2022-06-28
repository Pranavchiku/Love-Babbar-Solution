#include <bits/stdc++.h>
using namespace std;
#define ll long long int

bool isValid(vector<int> sum, int n, int k){
    for(auto it:sum){
        cout<<it<<" ";
    }
    cout<<'\n';
    for(int i=1;i<n;i++){
        if(sum[i]!=sum[i-1]){
            return false;
        }
    }
    return true;
}
bool solve(int a[], int n, int k, vector<int> &sum, int i){
    if(i==n){
        if(isValid(sum,n,k)){
            for(auto it:sum){
                cout<<it<<" ";
            }
            cout<<'\n';
            return true;
        }
        return false;
    }
    for(int j=0;j<k;j++){
        sum[j]+=a[i];
        if(solve(a,n,k,sum,i+1)){
            return true;
        }
        sum[j]-=a[i];
    }
    
}
bool isKPartitionPossible(int a[], int n, int k)
{
    vector<int> sum(k,0);
    return solve(a, n, k, sum, 0);
}

int main(){
    int n;cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int k;cin>>k;
    if(isKPartitionPossible(a,n,k)){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
}
