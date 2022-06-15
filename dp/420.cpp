#include <bits/stdc++.h>
using namespace std;
#define ll long long int


int carAssembly(vector<vector<int>>& a, vector<vector<int>>& t, vector<int>& e, vector<int>& x){
    int a1=e[0]+a[0][0];
    int b1=e[1]+a[1][0];
    int i=1;
    int n=a[0].size();
    while(i<n){
        int tempa1=a1;
        int tempb1=b1;
        a1=min(tempa1+a[0][i]+0,tempb1+a[0][i]+t[1][i]);
        b1=min(tempb1+a[1][i]+0,tempa1+a[1][i]+t[0][i]);
        i++;
        // cout<<a1<<" "<<b1<<'\n';
    }

    return min(a1+x[0],b1+x[1]);
}
int main(){
    vector<vector<int>> a={{4,5,3,2},{2,10,1,4}};
    vector<vector<int>> t={{0,7,4,5},{0,9,2,8}};
    vector<int> e={10,12};
    vector<int> x={18,7};
    cout<<carAssembly(a,t,e,x)<<'\n';
    return 0;
}