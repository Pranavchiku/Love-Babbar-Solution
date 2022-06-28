#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int findFirstNumIndex(int &k, int n){
    if(n==1) return 0;
    n--;
    int firstNumIndex;
    int fact=n;
    while(k>=fact and n>1){
        fact=fact*(n-1);
        n--;
    }
    firstNumIndex=k/fact;
    k=k%fact;
    return firstNumIndex;
}

string findKthPermutation(int n, int k)
{   
    string ans="";

    set<int> s;
    for(int i=0;i<n;i++){
        s.insert(i+1);
    }
    set<int>::iterator itr;
    itr=s.begin();

    k=k-1;
    for(int i=0;i<n;i++){
        int index=findFirstNumIndex(k,n-i);
        advance(itr,index);

        ans+=to_string(*itr);
        s.erase(itr);
        itr=s.begin();
    }
    return ans;
}