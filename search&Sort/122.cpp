#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ll t;cin>>t;
    while(t--){
        ll n,q;cin>>n>>q;
        vector<pair<ll,ll>> v;
        while(n--){
            ll a,b;cin>>a>>b;
            v.push_back({a,b});
        }
        sort(v.begin(),v.end());
        ll idx=0;
        for(ll i=1;i<v.size();i++){
            if(v[idx].second>=v[i].first){
                v[idx].second=max(v[idx].second,v[i].second);
            }
            else{
                idx++;
                v[idx]=v[i];
            }
        }
        while(q--){
            ll k;cin>>k;
            ll ans=-1;
            for(ll i=0;i<=idx;i++){
                if(v[i].second-v[i].first+1>=k){
                    ans=v[i].first+k-1;
                    break;
                }
                else{
                    k-=v[i].second-v[i].first+1;
                }
            }
            cout<<ans<<'\n';

        }
    }
    return 0;
}