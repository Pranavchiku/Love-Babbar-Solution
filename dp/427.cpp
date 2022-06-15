#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int LCSof3 (string A, string B, string C, int n1, int n2, int n3)
{
   int dp[n1+1][n2+1][n3+1];

   for(int i=0;i<=n1;i++){
       for(int j=0;j<=n2;j++){
           for(int k=0;k<=n3;k++) dp[i][j][k]=0;
       }
   }

   int i=n1-1;int j=n2-1;int k=n3-1;

   for(int i=n1-1;i>=0;i--){
       for(int j=n2-1;j>=0;j--){
           for(int k=n3-1;k>=0;k--){
               if(A[i]==B[j] and B[j]==C[k]) dp[i][j][k]=1+dp[i+1][j+1][k+1];
               else{
                    dp[i][j][k]=max(dp[i][j][k+1],max(dp[i+1][j][k],dp[i][j+1][k]));
               }
           }
       }
   }

   return dp[0][0][0];
}
int main(){
    cout<<LCSof3("geeks","geeksfor","geeksforgeeks",5,8,13)<<'\n';
    return 0;
}