#include<bits/stdc++.h>
using namespace std;
#define ll long long int


static bool comparator(int a, int b)
{
    string s1 = to_string(a) + to_string(b);
    string s2 = to_string(b) + to_string(a);
    return s1 > s2;
}

string largestNumber(const vector<int> &A){
    vector<int> B = A;
    sort(B.begin(), B.end(), comparator);
    string ans = "";
    for(int i = 0; i < B.size(); i++)
        ans += to_string(B[i]);
    return ans[0] == '0' ? "0" : ans;
}
string largestNumber2(const vector<int> &A) {
    map<int, priority_queue<string>, greater<int>> m;
    for(auto it: A){
        if(it==0){
            m[0].push(to_string(it));
        }
        else{
            if((it/10)==0){
                m[it].push(to_string(it));
            }
            else{
                m[(it/10)].push(to_string(it));
            }
        }
    }
    string ans="";
    if(!m[0].empty()){
        auto pq=m.begin()->second;
        ans+=pq.top();
        pq.pop();
        auto pq0=m[0];
        while(!pq0.empty()){
            ans+=pq0.top();
            pq0.pop();
        }
        
    }
    
    for(auto it: m){
        if(it.first!=0){
            auto pq=it.second;
            while(!pq.empty()){
                ans+=pq.top();
                pq.pop();
            }
        }
    }
    
    return ans;
}

int main(){
    int n;cin>>n;
    vector<int> A(n);
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
    cout<<largestNumber(A)<<endl;
}