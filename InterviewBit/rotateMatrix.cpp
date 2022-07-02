#include<bits/stdc++.h>
using namespace std;
#define ll long long int

void rotate(vector<vector<int> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int n=A.size();
    //transpose of the matrix
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            swap(A[i][j],A[j][i]);
        }
    }

    //swap the ith and n-ith columns
    for(int i=0;i<(n/2);i++){
        for(int j=0;j<n;j++){
            swap(A[j][n-i-1],A[j][i]);
        }
    }
    
}

int main(){
    int n;
    cin>>n;
    vector<vector<int> > A(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>A[i][j];
        }
    }
    rotate(A);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<A[i][j]<<" ";
        }
        cout<<endl;
    }
}