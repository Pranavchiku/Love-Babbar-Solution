#include <bits/stdc++.h>
using namespace std;
#define ll long long int


vector<vector<int>> merge(vector<vector<int>>& intervals) {
    sort(intervals.begin(),intervals.end());
    int p=0;
    int n=intervals.size();
    int l=intervals[p][0];
    int r=intervals[p++][1];
    vector<vector<int>> out = {};
    while(p<n){
        cout<<"here"<<'\n';
        cout<<intervals[p][0]<<intervals[p][1]<<'\n';
        if(intervals[p][0]>=l and intervals[p][0]<=r){
            if(intervals[p][1]>=r) {
                r=intervals[p][1];
                cout<<'l'<<' '<<l<<' '<<'r'<<' '<<r<<'\n';
            }
            p++;
        }
        else{
            cout<<'l'<<' '<<l<<' '<<'r'<<' '<<r<<'\n';
            out.push_back(vector<int>{l,r});
            l=intervals[p][0];
            r=intervals[p][1];
            p++;
            cout<<"here2"<<'\n';
            cout<<'l'<<' '<<l<<' '<<'r'<<' '<<r<<'\n';
        
        }
    }
    out.push_back(vector<int>{l,r});
    return out;
}


int main(){
    vector<vector<int>> intervals = {{1,4},{2,3}};
    vector<vector<int>> out = merge(intervals);
    for(auto& it: out){
        for(auto& it2: it){
            cout<<it2<<' ';
        }
        cout<<'\n';
    }
    return 0;
}