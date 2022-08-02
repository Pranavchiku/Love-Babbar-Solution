#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const int N=1e5+5;
int par[N];

int find(int x){
    if(par[x]==x) return x;
    else return par[x]=find(par[x]);
}

void merge(int x,int y){
    par[x]=y;
}

long long solve(int n, vector<vector<int>> &locations){
    for(int i=0;i<n;i++){
        par[i]=i;
    }
    vector<pair<int,int>> x,y,z;
    for(int i=0;i<n;i++){
        x.push_back({locations[i][0],i});
        y.push_back({locations[i][1],i});
        z.push_back({locations[i][2],i});
    }
    sort(x.begin(),x.end());
    sort(y.begin(),y.end());
    sort(z.begin(),z.end());

    vector<vector<int>> edges;
    for(int i=1;i<n;i++){
        int w=abs(x[i].first-x[i-1].first);
        int a=x[i].second;
        int b=x[i-1].second;
        edges.push_back({w,a,b});
    }
    for(int i=1;i<n;i++){
        int w=abs(y[i].first-y[i-1].first);
        int a=y[i].second;
        int b=y[i-1].second;
        edges.push_back({w,a,b});
    }
    for(int i=1;i<n;i++){
        int w=abs(z[i].first-z[i-1].first);
        int a=z[i].second;
        int b=z[i-1].second;
        edges.push_back({w,a,b});
    }
    sort(edges.begin(),edges.end());

    long long ans=0;
    for(auto it: edges){
        int w=it[0];
        int a=it[1];
        int b=it[2];

        a=find(a);
        b=find(b);

        if(a!=b){
            ans+=w;
            merge(a,b);
        }
    }

    return ans;
}

int main(){
    int n;cin>>n;
    vector<vector<int>> locations(n,vector<int>(3));
    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++){
            cin>>locations[i][j];
        }
    }
    cout<<solve(n,locations)<<'\n';
}