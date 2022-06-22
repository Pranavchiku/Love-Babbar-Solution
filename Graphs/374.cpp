#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void topoSort(int s, vector<int> &visited, vector<vector<int>> adj, stack<int> &st){
    visited[s]=1;
    for(auto &it: adj[s]){
        if(!visited[it]){
            topoSort(it,visited,adj,st);
        }
    }
    st.push(s);
}
string findOrder(string dict[], int n, int k) {
    vector<vector<int>> adj(k);
    for(int i=0;i<n-1;i++){
        string w1=dict[i];
        string w2=dict[i+1];

        for(int j=0;j<min(w1.length(),w2.length());j++){
            if(w1[j]!=w2[j]){
                adj[w1[j]-'a'].push_back(w2[j]-'a');
                break;
            }
        }
    }

    vector<int> visited(k,0);
    stack<int> st;
    string ans="";
    for(int i=0;i<k;i++){
        if(!visited[i]){
            topoSort(i,visited,adj,st);
        }
    }
    while(!st.empty()){
        char ch = st.top()+'a';
        ans+=ch;
        st.pop();
    }
    return ans;

}