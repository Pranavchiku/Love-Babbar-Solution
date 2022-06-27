#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ll t;cin>>t;
    while(t--){
ll n,c;cin>>n>>c;
    ll arr[n];
    for(ll i=0;i<n;i++){
        cin>>arr[i];
    }
    ll lb=1;
    ll ub=1e9;
    ll ans=0;
    sort(arr,arr+n);
    while(lb<=ub){
        ll mid=(lb+ub)/2;
        ll cow=1;
        ll prev=arr[0];
        for(ll i=1;i<n;i++){
            if(arr[i]>=prev+mid){
                cow++;
                prev=arr[i];
                if(c==cow) break;
            }
        }
        if(cow==c){
            ans=mid;
            lb=mid+1;
        }
        else ub=mid-1;
    }
    cout<<ans<<'\n';
    }
    
}