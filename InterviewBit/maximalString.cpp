#include<bits/stdc++.h>
using namespace std;
void f(int i,int swp,string&ans,string A){
if(swp==0){
if(stoi(A)>stoi(ans)){
ans=A;
}
return;
}
if(i==A.length()){
if(stoi(A)>stoi(ans)){
ans=A;
}
return;
}
for(int j=i;j<A.length();j++){
if(j>i) swp--;
swap(A[i],A[j]);
f(i+1,swp,ans,A);
swap(A[i],A[j]);
if(j>i) swp++;
}
}

string solve(string A, int B) {
string ans="-1";
f(0,B,ans,A);
return ans;
}