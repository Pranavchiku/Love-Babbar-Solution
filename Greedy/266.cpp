#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ll n;cin>>n;
    while(true){
        ll arr[n];
        for(ll i=0;i<n;i++){
            cin>>arr[i];
        }
        
        vector<pair<int,int>> buy;
        vector<pair<int,int>> sell;

        for(int i=0;i<n;i++){
            if(arr[i]>0) buy.push_back({arr[i],i});
            else sell.push_back({arr[i],i});
        }

        ll ans=0;
        int i=0;int j=0;
        while(i<buy.size() and j<sell.size()){
            int x=min(buy[i].first,-sell[j].first);
            buy[i].first-=x;
            sell[j].first+=x;

            int diff=abs(buy[i].second-sell[j].second);
            ans+=(x*diff);
            if(buy[i].first==0) i++;
            if(sell[j].first==0) j++;
        }
        cout<<ans<<'\n';
        cin>>n;
        if(n==0) break;
    }

    return 0;

}