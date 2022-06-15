#include <bits/stdc++.h>
using namespace std;
#define ll long long int

vector<long long> nextSmallerElement(long long arr[], int n){
    stack<long long> st;

    vector<long long> v;

    for(int i=0;i<n;i++){
        v.push_back(-1);
    }
    st.push(0);
    for(int i=1;i<n;i++){
        if(arr[i]>=arr[st.top()]) st.push(i);
        else{
            v[st.top()]=i;
            st.pop();
            while(!st.empty() and arr[st.top()]>arr[i]){
                v[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }
    }

    return v;

}

long long getMaxArea(long long arr[], int n)
{
    vector<long long> nseR=nextSmallerElement(arr,n);

    reverse(arr,arr+n);

    vector<long long> nseL=nextSmallerElement(arr,n);

    reverse(nseL.begin(),nseL.end());
    for(int i=0;i<n;i++){
        if(nseL[i]!=-1){
            nseL[i]=n-1-nseL[i];
        }
    }

    long long out=-INT_MAX;

    reverse(arr,arr+n);
    for(int i=0;i<n;i++){
        long long width=0;
        if(nseL[i]!=-1 and nseR[i]!=-1){
            width=nseR[i]-nseL[i]-1;
            long long height=arr[i];
            out=max(out,(height*width));
        }
        else if(nseL[i]==-1 and nseR[i]!=-1){
            width=nseR[i];
            long long height=arr[i];
            out=max(out,height*width);
        }
        else if(nseL[i]!=-1 and nseR[i]==-1){
            width=n-1-i+1;
            out=max(out,arr[i]*width);
        }
        else out=max(out,arr[i]*(n));
    }

    return out;
}
int main(){

    int n=8;
    long long arr[n]={7,2,8,9,1,3,6,5};
    cout<<getMaxArea(arr,n)<<'\n';

}