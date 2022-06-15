#include <bits/stdc++.h>
using namespace std;
#define ll long long int
long long countWays1(int n, int k){
    int M=1e9+7;
    long long diff=k, same=0, total=(diff+same)%M;
    for(int i=1; i<n; i++) {
        same=diff;
        diff=(total*(k-1))%M;
        total=(same+diff)%M;
    }
    return total;
}

int main(){
    cout<<countWays1(3,2)<<'\n';
    return 0;
}