#include<bits/stdc++.h>
using namespace std;
#define ll long long int


int solve(vector<int> &A, int B) {
    int n=A.size();
    int l=0;
    int r=0;
    int len=0;
    int count=0;
    while(l<n and r<n){
        len=max(len,r-l+1);
        if(A[r]==1){
            r++;
        }
        else{
            if(count<B){
                r++;
                count++;
            }
            else{
                // cout<<l<<' '<<r<<'\n';
                while(l<r and A[l]==1) l++;
                // cout<<l<<' '<<r<<'\n';
                while(l<r and A[l]==0) l++;
                cout<<l<<' '<<r<<'\n';

                r++;
            }
        }
    }
    len=max(len,r-l);
    return len;
}

int main(){
    int n; cin>>n;
    vector<int> A(n);
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
    int B; cin>>B;
    cout<<solve(A,B)<<endl;

    return 0;
}
