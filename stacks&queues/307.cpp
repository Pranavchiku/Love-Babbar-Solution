#include <bits/stdc++.h>
using namespace std;
#define ll long long int


int celebrity(vector<vector<int> >& m, int n) 
{
    stack<int> st;

    for(int i=0;i<n;i++) st.push(i);

    while(st.size()>1){
        int j=st.top();
        st.pop();
        int k=st.top();
        st.pop();
        if(m[j][k]==1){
            st.push(k);
        }
        else{
            st.push(j);
        }
    }

    int temp=st.top();
    for(int i=0;i<n;i++){
        if(i!=temp){
            if(m[i][temp]!=1){
                return -1;
            }
        }
        
    }

    for(int i=0;i<n;i++){
        if(i!=temp){
            if(m[temp][i]!=0){
                return -1;
            }
        }
    }

    return temp;
}
int main(){
    int n=2;
    vector<vector<int>> m = {{0,1},{1,0}};

    cout<<celebrity(m,n)<<'\n';
    return 0;
}