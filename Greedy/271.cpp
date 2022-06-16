#include <bits/stdc++.h>
using namespace std;
#define ll long long int


long long minCost(long long arr[], long long n) {
    // Your code here
    priority_queue <long long, vector<long long>, greater<long long>> q;
    
    for(int i=0;i<n;i++){
        q.push(arr[i]);
    }
    long long out=0;
    while(!q.empty()){
        int temp=q.top();
        q.pop();
        if(!q.empty()){
            // cout<<"here"<<'\n';
            int temp2=q.top();
            // cout<<temp<<' '<<temp2<<'\n';
            q.pop();
            q.push(temp+temp2);
            out+=temp+temp2;
            // cout<<out<<'\n';
        }
        else{
            return out;
        }
    }
    return out;
}
int main(){
    long long n=5;
    long long arr[n]={4,2,7,6,9};
    cout<<minCost(arr,n)<<'\n';
    return 0;
}