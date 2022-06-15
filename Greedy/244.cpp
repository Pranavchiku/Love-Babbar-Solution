#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int minCoins(int coins[], int m, int v) 
{ 
    int count[v+1];
    count[0]=0;
    for(int i=1;i<=v;i++) {
        count[i]=INT_MAX;
    }

    sort(coins, coins + m, greater<int>());

    for(int i=1;i<=v;i++){
        for(int j=0;j<m;j++){
            if(coins[j]<=i){
                int remain=count[i-coins[j]];
                if(remain!=INT_MAX and remain+1<count[i]){
                    count[i]=remain+1;
                }
            }
        }
    }
    
    if(count[v]==INT_MAX) return -1;
    else return count[v];
}

int main(){
    int v;cin>>v;
    int m;cin>>m;
    int arr[m];
    for(int i=0;i<m;i++) cin>>arr[i];

    cout<<minCoins(arr,m,v)<<'\n';
    return 0;
}