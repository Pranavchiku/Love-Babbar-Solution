#include<bits/stdc++.h>
using namespace std;
#define ll long long int


vector<int>visited;
vector<int>store;
int flag=0;
int dfs(vector<vector<int>>&v,int start,int index)
{
    int cnt=0;
    if(store[start]==store[index] && flag>1)
    {
        cnt++;
    }
    else
    {
        flag++;
    }
    visited[index]=1;
    for(auto &x:v[index])
    {
        if(visited[x]==0)
        {
            cnt+=dfs(v,start,x);
        }
    }
    visited[index]=0;
    return cnt;
}
void solve(int loop)
{
   int n;
   cin>>n;
   visited=vector<int>(n,0);
   store=vector<int>(n,0);
   vector<vector<int>>v(n);

   for(int i=0;i<n;i++)
   {
       int x;
       cin>>x;
       store[i]=x;
   }
   
   for(int i=0;i<(n-1);i++)
   {
        int x,y;
        cin>>x>>y;
        x--;y--;
        v[x].push_back(y);
        v[y].push_back(x);
   }
   
   int cnt=0;
   for(int i=0;i<n;i++)
   {
        if(visited[i]==0)
        {
            flag=1;
            cnt+=dfs(v,i,i);
            flag=0;
        }
   }
   cout<<cnt/2<<endl;
}

int main(){
    int loop;
    cin>>loop;
    while(loop--)
    {
        solve(loop);
    }
    return 0;
}