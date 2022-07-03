#include<bits/stdc++.h>
using namespace std;
#define ll long long int

vector<string> topKUsers(vector<string> statements, int k){
    vector<string> res;
    unordered_map<string,int> m;
    for(auto it: statements){
        int pos=it.find(':');
        string user=it.substr(0,pos);
        string msg=it.substr(pos+1);

        m[user]+=msg.size();
    }
    priority_queue<pair<int,string>> pq;
    for(auto it: m){
        pq.push({it.second,it.first});
    }

    while(k--){
        res.push_back(pq.top().second);
        pq.pop();
    }
    return res;
}

int main(){
    int n,k;
    cin>>n>>k;
    vector<string> statements(n);
    for(int i=0;i<n;i++){
        cin>>statements[i];
    }
    vector<string> res=topKUsers(statements,k);
    for(auto it: res){
        cout<<it<<endl;
    }

    return 0;

}