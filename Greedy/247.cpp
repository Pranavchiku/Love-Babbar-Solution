#include <bits/stdc++.h>
using namespace std;
#define ll long long int


int findPlatform(int arr[], int dep[], int n)
{
    vector<pair<int,int>> v(n);

    for(int i=0;i<n;i++){
        v[i]={arr[i],dep[i]};
    }

    sort(v.begin(),v.end());

    priority_queue<int, vector<int>,greater<int>> p; //min priority queue

    int c=1;
    p.push(v[0].second);

    for(int i=1;i<n;i++){
        if(p.top()>=v[i].first){
            c++;
        }
        else p.pop();
        p.push(v[i].second);
    }
    return c;
}


int main(){

    int n=6;
    int arr[n]={900, 940,950,1100,1500,1800};
    int dep[n]={910, 1200, 1120,1130,1900,2000};

    cout<<findPlatform(arr,dep,n)<<'\n';
    
}