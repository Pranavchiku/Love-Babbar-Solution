#include <bits/stdc++.h>
using namespace std;
#define ll long long int

vector <int> commonElements (int a[], int b[], int c[], int n1, int n2, int n3)
{
    vector<int> out={};
   int i=0;
   int j=0;
   int k=0;
   while(i<n1 and j<n2 and k<n3){
       if(a[i]==b[j] and b[j]==c[k]){
           out.push_back(a[i]);
           int temp=a[i];
           while(i<n1 and a[i]==temp) i++;
            temp=b[j];
           while(j<n2 and b[j]==temp) j++;
           temp=c[k];
           while(k<n3 and c[k]==temp) k++;
       }
       else{
        int temp = min(c[k],min(a[i],b[j]));
        if(temp==a[i]){
            i++;
        }
        if(temp==b[j]){
            j++;
        }
        if(temp==c[k]){
            k++;
        }
       }
   }
   return out;
}
int main(){
    int n1=3;int n2=3;int n3=3;
    int a[n1]={3,3,3};
    int b[n2]={3,3,3};
    int c[n3]={3,3,3};
    vector<int> out = commonElements(a,b,c,n1,n2,n3);
    for(auto& it: out) cout<<it<<' ';
    cout<<'\n'; 
    return 0;
}