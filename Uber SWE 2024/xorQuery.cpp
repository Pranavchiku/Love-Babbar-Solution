#include<bits/stdc++.h>
using namespace std;


const int N=1e5+2;
int tree[4*N], a[N];

void build(int node, int start, int end){
    if(start==end){
        tree[node]=a[start];
        return;
    }
    int mid=(start+end)/2;
    build(node*2,start,mid);
    build(node*2+1,mid+1,end);
    tree[node]=max(tree[node*2],tree[node*2+1]);
}

int query(int node, int start, int end, int l, int r){
    if(start>r or end<l) return INT_MIN;
    if(start>=l and end<=r) return tree[node];

    int mid=(start+end)/2;
    int q1=query(node*2,start,mid,l,r);
    int q2=query(node*2+1,mid+1,end,l,r);

    return max(q1,q2);
    
}

void update(int node, int start, int end, int pos, int val){
    if(start==end){
        a[start]=val;
        tree[node]=val;
        return;
    }
    int mid=(start+end)/2;
    if(pos<=mid) update(node*2,start,mid,pos,val);
    else update(node*2+1,mid+1,end,pos,val);

    //backtrack to update parent node
    tree[node]=max(tree[node*2],tree[node*2+1]);
}