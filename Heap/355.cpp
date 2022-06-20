#include <bits/stdc++.h>
using namespace std;
#define ll long long int

string solve(int arr[], int n) {
        sort(arr,arr+n);
       string s1="",s2="",ans="";
       int t,c=0,i;
       for(i=0;i<n;i++)
       {
           if(i%2==0)
           s1+=to_string(arr[i]);
           else
           s2+=to_string(arr[i]);
       }
       
       if(n%2!=0)
       s2="0"+s2;
       
       for(i=s1.size()-1;i>=0;i--)
       {
           t=(s1[i]-'0')+(s2[i]-'0')+c;
           
           c=t/10;
           ans=to_string(t%10)+ans;
       }
       if(c)
       ans=to_string(c)+ans;
       
       i=0;
       while(ans[i]=='0')
       i++;
       return ans.substr(i);
}