#include <bits/stdc++.h>
using namespace std;
#define ll long long int
//this solution leads to tle as observes many cases
bool isValid(vector<int> sum, int n, int k){
    // for(auto it:sum){
    //     cout<<it<<" ";
    // }
    // cout<<'\n';
    for(int i=1;i<k;i++){
        if(sum[i]!=sum[i-1]){
            return false;
        }
    }
    return true;
}
bool solve(int a[], int n, int k, vector<int> &sum, int i){
    if(i==n){

        if(isValid(sum,n,k)){
            return true;
        }
        return false;
    }
    for(int j=0;j<k;j++){
        sum[j]+=a[i];
        if(solve(a,n,k,sum,i+1)){
            return true;
        }
        sum[j]-=a[i];
    }
    return false;

}
bool isKPartitionPossible(int a[], int n, int k)
{
    vector<int> sum(k,0);
    return solve(a, n, k, sum, 0);
}

//efficient solutino
void solve(vector<int>&a,int i,int n,int target,vector<int>&res,set<vector<int>>&ans
   ,vector<bool>&visited)
   {
       if(i==n)
       {
           if(target==0)
           {
               ans.insert(res);
           }
           return ;
       }
       if(a[i]<=target)
       {
           if(!visited[i]){
               visited[i]=true;
               res.push_back(a[i]);
               solve(a,i+1,n,target-a[i],res,ans,visited);
               res.pop_back();
               visited[i]=false;
           }
       }
       solve(a,i+1,n,target,res,ans,visited);
   }
   bool isKPartitionPossible(int a[], int n, int k)
   {
        //Your code here
        vector<int>res;
        set<vector<int>>ans;
        vector<bool>visited(n,false);
       if(k==1)
       {
           return true;
       }
       if(k>n)
       {
           return false;
       }
        int sum=0;
        vector<int>v;
        for(int i=0;i<n;i++)
        {
            sum+=a[i];
            v.push_back(a[i]);
        }
        sort(v.begin(),v.end());
        int targetSum=sum/k;
        if(sum%k==0)
        {
            solve(v,0,n,targetSum,res,ans,visited);
            if(ans.size()>=k)
            {
            return true;
            }
        }
        return false;
        
        
   }

int main(){
    int n;cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int k;cin>>k;
    if(isKPartitionPossible(a,n,k)){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
}
