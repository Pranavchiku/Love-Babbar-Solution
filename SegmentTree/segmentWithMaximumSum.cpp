#include<bits/stdc++.h>
using namespace std;
#define ll long long int

const ll N=1e5+2;
ll a[N];
class node{
    public:
    ll pref,suff,sum,ans;

    node()=default;
    node(ll pref, ll suff, ll sum, ll ans){
        this->pref = pref;
        this->suff = suff;
        this->sum = sum;
        this->ans = ans;
    }
};

node tree[4*N];

void build(ll n, ll start, ll end){
    if(start==end){
        if(a[start]<=0){
            node temp(0,0,a[start],0);
            tree[n]=temp;
        }
        else{
            tree[n]=node(a[start],a[start],a[start],a[start]);
        }
        return;
    }

    int mid=(start+end)/2;
    build(n*2,start,mid);
    build(n*2+1,mid+1,end);

    ll sum=tree[2*n].sum+tree[2*n+1].sum;
    ll pref=max(tree[2*n].pref,tree[2*n].sum+tree[2*n+1].pref);
    ll suff=max(tree[2*n+1].suff,tree[2*n+1].sum+tree[2*n].suff);
    ll ans=max({tree[2*n].ans,tree[2*n+1].ans,tree[2*n].suff+tree[2*n+1].pref});

    node temp(pref,suff,sum,ans);
    tree[n]=temp;
}

void update(ll n, ll start, ll end, ll index, ll val){
    if(start==end){
        a[start]=val;
        if(val<0){
            tree[n]=node(0,0,val,0);
        }
        else{
            tree[n]=node(val,val,val,val);
        }
        return;
    }


    int mid=(start+end)/2;
    if(index<=mid) update(n*2,start,mid,index,val);
    else update(n*2+1,mid+1,end,index,val);

    ll sum=tree[2*n].sum+tree[2*n+1].sum;
    ll pref=max(tree[2*n].pref,tree[2*n].sum+tree[2*n+1].pref);
    ll suff=max(tree[2*n+1].suff,tree[2*n+1].sum+tree[2*n].suff);
    ll ans=max({tree[2*n].ans,tree[2*n+1].ans,tree[2*n].suff+tree[2*n+1].pref});

    node temp(pref,suff,sum,ans);
    tree[n]=temp;

}

int main(){
    ll n,m;cin>>n>>m;
    for(ll i=0;i<n;i++) cin>>a[i];

    build(1,0,n-1);

    cout<<tree[1].ans<<endl;
    while(m--){
        ll idx,val;
        cin>>idx>>val;
        update(1,0,n-1,idx,val);
        cout<<tree[1].ans<<endl;
    }
    return 0;
}