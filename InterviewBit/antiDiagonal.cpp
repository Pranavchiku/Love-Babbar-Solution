#include<bits/stdc++.h>
using namespace std;
#define ll long long int

bool isValid(int x, int y, int n){
    if(x<0 or x>=n or y<0 or y>=n) return false;
    return true;
}
vector<vector<int> > diagonal(vector<vector<int> > &A) {
    vector<vector<int>> ans;
    int i=0;
    int n=A.size();
    
    while(i<n){
        vector<int> temp;
        int x=0;
        int y=i;
        while(isValid(x,y,n)){
            temp.push_back(A[x][y]);
            x=x+1;
            y=y-1;
        }
        ans.push_back(temp);
        i++;
        
    }


    int j=1;
    while(j<n){
        vector<int> temp;
        int x=j;
        int y=n-1;
        while(isValid(x,y,n)){
            temp.push_back(A[x][y]);
            x=x+1;
            y=y-1;
        }
        ans.push_back(temp);
        j++;
    }
    return ans;

}

int main(){
    int n;cin>>n;
    vector<vector<int>> A(n,vector<int>(n,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>A[i][j];
        }
    }
    vector<vector<int>> ans=diagonal(A);
    for(auto it: ans){
        for(auto it2: it){
            cout<<it2<<" ";
        }
        cout<<'\n';
    }
    return 0;
}