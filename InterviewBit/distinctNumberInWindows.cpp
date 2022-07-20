#include<bits/stdc++.h>
using namespace std;
#define ll long long int

vector<int> dNums(vector<int> &A, int B) {
    int n=A.size();
    map<int,int> m;
    for(int i=0;i<B;i++) m[A[i]]++;
    int l=-1;
    vector<int> ans;
    ans.push_back(m.size());
    for(int r=B;r<n;r++){
        l++;
        if(m.find(A[l])!=m.end()){
            m[A[l]]--;
            
            if(m[A[l]]==0) {

                m.erase(A[l]);
            }
            m[A[r]]++;
            ans.push_back(m.size());
        }
        else{
            m[A[r]]++;
            ans.push_back(m.size());
        }
    }
    return ans;
}

int main(){
    int n; cin>>n;
    vector<int> A(n);
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
    int B; cin>>B;
    vector<int> ans=dNums(A,B);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<' ';
    }
    cout<<endl;
    return 0;
}