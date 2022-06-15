#include <bits/stdc++.h>
using namespace std;
#define ll long long int


vector<long long> nextLargerElement(vector<long long> arr, int n){
    stack<long long> st;

    vector<long long> v;

    for(int i=0;i<n;i++){
        v.push_back(-1);
    }
    st.push(0);
    for(int i=1;i<n;i++){
        if(arr[i]<=arr[st.top()]) st.push(i);
        else{
            v[st.top()]=arr[i];
            st.pop();
            while(!st.empty() and arr[st.top()]<arr[i]){
                v[st.top()]=arr[i];
                st.pop();
            }
            st.push(i);
        }
    }

    return v;

}
int main(){
    int n=5;
    vector<long long> arr={6,8,0,1,3};

    vector<long long> out=nextLargerElement(arr,n);

    for(auto &it: out) cout<<it<<' ';
    cout<<'\n';
    return 0;
}