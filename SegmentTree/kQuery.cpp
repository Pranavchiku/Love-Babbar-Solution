#include<bits/stdc++.h>
using namespace std;
const int N=1e5+2;
vector<int> a(N);
vector<vector<int>> tree(4*N);

vector<int> merge(vector<int> a, vector<int> b){
    vector<int> ans(a.size()+b.size());
    int i=0,j=0,k=0;
    while(i<a.size()&&j<b.size()){
        if(a[i]<b[j]){
            ans[k]=a[i];
            i++;
        }
        else{
            ans[k]=b[j];
            j++;
        }
        k++;
    }
    while(i<a.size()){
        ans[k]=a[i];
        i++;
        k++;
    }
    while(j<b.size()){
        ans[k]=b[j];
        j++;
        k++;
    }
    return ans;
}

int binarySearch(vector<int> a, int x){
    int l=0,r=a.size()-1;
    while(l<=r){
        int mid=(l+r)/2;
        if(a[mid]<=x) l=mid+1;
        else r=mid-1;
    }
    return l;
}
void build(int node, int start, int end){
    if(start==end){
        tree[node]=vector<int>{a[start]};
        return;
    }
    int mid=(start+end)/2;
    build(node*2,start,mid);
    build(node*2+1,mid+1,end);

    tree[node]=merge(tree[node*2],tree[node*2+1]);
}
int query(int node, int start, int end, int l, int r, int k){
    if(start>r or end<l) return 0;
    if(start>=l and end<=r){
        int bi=binarySearch(tree[node],k);
        // cout<<bi<<endl;
        return tree[node].size()-bi;
    } 
    int mid=(start+end)/2;
    int ans=query(node*2,start,mid,l,r,k);
    ans+=query(node*2+1,mid+1,end,l,r,k);
    return ans;
}
int main(){
    int n;cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    build(1,0,n-1);
    int q;cin>>q;
    while(q--){
        int l,r,k;cin>>l>>r>>k;
        cout<<query(1,0,n-1,l-1,r-1,k)<<endl;
    }
}