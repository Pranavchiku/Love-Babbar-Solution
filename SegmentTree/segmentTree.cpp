#include<bits/stdc++.h>
using namespace std;

//size of segment tree
const int N=1e5+2;

int a[N],tree[4*N];

void build(int node, int start, int end){
    //if leaf node
    if(start==end){
        tree[node]=a[start];
        return;
    }
    //if not leaf node
    int mid=(start+end)/2;
    //left child
    build(node*2,start,mid);
    //right child
    build(node*2+1,mid+1,end);

    //merge
    //as we needed sum we took sum of left and right child 
    //and added it to parent node
    tree[node]=tree[node*2]+tree[node*2+1];

    /*
    //if we need min we can take min of left and right child 
    //and add it to parent node
    tree[node]=min(tree[node*2],tree[node*2+1]);
    */

   /*
   //if we need max we can take max of left and right child
   //and add it to parent node
    tree[node]=max(tree[node*2],tree[node*2+1]);
    */

    return;
}

//returns sum from l to r
int query(int node, int start, int end, int l, int r){
    //if range is not overlapping with query range
    if(start>r or end<l) return 0;
    //if range is completely overlapping with query range
    if(start>=l and end<=r) return tree[node];
    //if range is partially overlapping with query range

    //call for both the child nodes
    int mid=(start+end)/2;
    int q1=query(node*2,start,mid,l,r);
    int q2=query(node*2+1,mid+1,end,l,r);

    //merge
    //as we needed sum we took sum of left and right child
    //and added it to parent node
    return q1+q2;

    /*
    //if we need min we can take min of left and right child
    //and add it to parent node
    return min(q1,q2);
    */
}

int main(){
    int n;cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];

    build(1,0,n-1);
    // for(int i=0;i<15;i++){
    //     cout<<tree[i]<<" ";
    // }
    // cout<<'\n';

    int q;cin>>q;
    while(q--){
        int l,r;cin>>l>>r;
        int ans = query(1,0,n-1,l,r);
        cout<<ans<<endl;
    }

    return 0;
}