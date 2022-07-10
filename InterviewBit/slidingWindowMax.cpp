#include<bits/stdc++.h>
using namespace std;
#define ll long long int

vector<int> slidingMaximum(const vector<int> &A, int B) {
    map<int,int, greater<int>> m;
    queue<int> q;
    int i=0;
    for(int i=0;i<B;i++){
        q.push(A[i]);
        m[A[i]]++;
    }
    int n=A.size();
    i=B;

    for(auto it: m){
            cout<<it.first<<" "<<it.second<<endl;
        }
    cout<<"----------------------------------------"<<endl;

    vector<int> ans;
    while(i<n){
        // cout<<i<<'\n';
        auto it=m.begin();
        ans.push_back(it->first);
        m[q.front()]--;
        if(m[q.front()]==0) m.erase(q.front());

        for(auto it: m){
            cout<<it.first<<" "<<it.second<<endl;
        }
        cout<<"----------------------------------------"<<endl;
        q.pop();
        q.push(A[i]);
        m[A[i]]++;
        i++;
    }
    auto it=m.begin();
    ans.push_back(it->first);
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> A(n);
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
    int B;
    cin>>B;
    vector<int> ans=slidingMaximum(A,B);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
