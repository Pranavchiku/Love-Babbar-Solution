#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int maxProfit(vector<int>& prices) {
    int n=prices.size();
    int p=0;
    int b=prices[0];
    int s=prices[0];
    int i=1;
    while(i<n){
        if(prices[i]>s and p<prices[i]-b){
            s=prices[i];
            p=s-b;
        }
        else if(prices[i]<b){
            b=prices[i];
            s=prices[i];
            if(s-b>p) p=s-b;
        }
        i++;
        
    }
    return p;
}

int main(){
    vector<int> prices={3,2,6,5,0,3};
    cout<<maxProfit(prices)<<'\n';
    return 0;
}