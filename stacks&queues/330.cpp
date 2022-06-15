#include <bits/stdc++.h>
using namespace std;
#define ll long long int


vector<long long> printFirstNegativeInteger(long long int a[],long long int n, long long int k) {
    vector<long long> out;
    queue<long long> q;

    int i=0;
    int count=0;
    while(i<k-1){
        if(a[i]<0) q.push(a[i]);

        i++;
    }
    while(i<n){
        if(a[i]<0) q.push(a[i]);
        if(!q.empty()){
            out.push_back(q.front());
            if(q.front()==a[i-k+1]) q.pop();
        }
        else out.push_back(0);

        i++;
    }
    return out;


                                                 
}
int main(){
    return 0;
}