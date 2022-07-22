#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int maxProfit(const vector<int> &A) {
    if(A.size()==0) return 0;
    int buy=A[0]; //minimise
    int sell=A[0]; //maximise
    int profit=max(0,sell-buy);
    
    for(int i=1;i<A.size();i++){
        // cout<<A[i]<<'\n';
        if(sell<A[i]){
            // cout<<"here"<<'\n';
            sell=A[i];
        }
        else{
            // cout<<"here2"<<'\n';
            if(buy>A[i]){
                // cout<<"here3"<<'\n';
                profit=max(profit,abs(sell-buy));
                buy=A[i];
                sell=A[i];
            }
        }
    }
    return max(profit,abs(sell-buy));
}

int main(){
    int n;cin>>n;
    vector<int> A(n);
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
    cout<<maxProfit(A)<<endl;
    return 0;
}