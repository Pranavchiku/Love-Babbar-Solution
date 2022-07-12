#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int maximalRectangle(vector<vector<int>> &A) {
    int r=A.size();
    int c=A[0].size();
   
    if(r==0) return 0;
    vector<vector<int>> mat(r+1,vector<int>(c));
    for(int i=1;i<=r;++i){
        for(int j=0;j<c;++j){
            mat[i][j]=A[i-1][j];
        }
    }

    vector<vector<int>> dp(r+1,vector<int>(c));
    int max_area=0;
    for(int i=1;i<=r;++i){
        int leftBound=-1;
        stack<int> st;
        vector<int>left(c);
        for(int j=0;j<c;++j){
            if(mat[i][j]==1){
                mat[i][j]=mat[i-1][j]+1;
                while(!st.empty() and mat[i][st.top()]>=mat[i][j]){
                    st.pop();
                }
                int val=leftBound;
                if(!st.empty()){
                    val=max(val,st.top());
                }
                left[j]=val;
            }
            else{
                leftBound=j;
                left[j]=0;
            }
            st.push(j);
        }

        while(!st.empty()) st.pop();

        int rightBound=c;
        for(int j=c-1;j>=0;--j){
            if(mat[i][j]!=0){
                while(!st.empty() and mat[i][st.top()]>=mat[i][j]){
                    st.pop();
                }

                int val=rightBound;
                if(!st.empty()){
                    val=min(val,st.top());
                }
                dp[i][j]=mat[i][j]*((val-1)-(left[j]+1)+1);
                max_area=max(max_area,dp[i][j]);
                st.push(j);
            }
            else{
                rightBound=j;
                dp[i][j]=0;
            }
        }
    }
    return max_area;
}


int main(){
    int n,m;cin>>n>>m;
    vector<vector<int>> A(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>A[i][j];
        }
    }
    cout<<maximalRectangle(A);
    return 0;
}