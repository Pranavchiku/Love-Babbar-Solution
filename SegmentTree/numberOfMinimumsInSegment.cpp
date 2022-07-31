#include<bits/stdc++.h>
using namespace std;

const int N=1e5+2, MOD=1e9+7;

//stores frequency of each element in array
pair<int,int> tree[4*N];
int a[N];

/*
Q) Find the minimum element in the given segment and 
return the number of minimum elements in the segment.
*/
void build(int node, int start, int end){
    if(start==end){
        tree[node].first=a[start];
        tree[node].second=1;
        return;
    }
    int mid=(start+end)/2;
    build(node*2,start,mid);
    build(node*2+1,mid+1,end);

    if(tree[2*node].first<tree[2*node+1].first){
        tree[node].first=tree[2*node].first;
        tree[node].second=tree[2*node].second;
    }
    else if(tree[2*node].first>tree[2*node+1].first){
        tree[node].first=tree[2*node+1].first;
        tree[node].second=tree[2*node+1].second;
    }
    else{
        tree[node].first=tree[2*node].first;
        //add both frequencies
        tree[node].second=tree[2*node].second+tree[2*node+1].second;
    }
    
}

pair<int,int> query(int node, int start, int end, int l, int r){
    if(start>r or end<l) return {MOD,-1};
    if(start>=l and end<=r) return tree[node];

    int mid=(start+end)/2;
    pair<int,int> q1=query(node*2,start,mid,l,r);
    pair<int,int> q2=query(node*2+1,mid+1,end,l,r);

    if(q1.first<q2.first){
        return q1;

    }
    else if(q1.first>q2.first){
        return q2;
    }
    else{
        return {q1.first,q1.second+q2.second};
    }
    
}

void update(int node, int start, int end, int pos, int val){
    if(start==end){
        a[start]=val;
        tree[node].first=val;
        tree[node].second=1;
        return;
    }
    int mid=(start+end)/2;
    if(pos<=mid) update(node*2,start,mid,pos,val);
    else update(node*2+1,mid+1,end,pos,val);

    //backtrack to update parent node
    if(tree[2*node].first<tree[2*node+1].first){
        tree[node].first=tree[2*node].first;
        tree[node].second=tree[2*node].second;
    }
    else if(tree[2*node].first>tree[2*node+1].first){
        tree[node].first=tree[2*node+1].first;
        tree[node].second=tree[2*node+1].second;
    }
    else{
        tree[node].first=tree[2*node].first;
        //add both frequencies
        tree[node].second=tree[2*node].second+tree[2*node+1].second;
    }
}

int main(){
    int n,m;cin>>n>>m;
    for(int i=0;i<n;i++) cin>>a[i];
    build(1,0,n-1);
    while(m--){
        int type;cin>>type;
        if(type==1){
            int pos,val;cin>>pos>>val;
            update(1,0,n-1,pos,val);
        }
        else{
            int l,r;cin>>l>>r;
            pair<int,int> ans=query(1,0,n-1,l,r-1);
            cout<<ans.first<<" "<<ans.second<<endl;
        }
    }
}