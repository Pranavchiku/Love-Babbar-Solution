#include<bits/stdc++.h>
using namespace std;

/*
This method will work in O(n*m) time and O(n) space.
long long contest(string a, string b){
    int i=0;
    int j=0;

    map<char,int> m;
    for(int i=0;i<a.size();i++){
        m[a[i]]++;
    }

    for(auto it: b){
        if(m.find(it)==m.end()) return -1;
    }
    
    long long ans=0;
    while(j!=b.size()){
        if(a[i]==b[j]){
            j++;
        }
        i=(i+1)%a.size();
        ans++;
    }
    return ans;
}
*/


long long contest(string a, string b){
    unordered_map<char, queue<int>> m;
    unordered_map<char,queue<int>> mOriginal;

    for(int i=0;i<a.size();i++){
        m[a[i]].push(i+1);
        mOriginal[a[i]].push(i+1);
    }
    for(int i=0;i<a.size();i++){
        m[a[i]].push(-1);
        mOriginal[a[i]].push(-1);
    }
    for(auto it: b){
        if(m.find(it)==m.end()) return -1;
    }
    long long ans=0;
    long long last=0;
    for(auto it: b){
        int index=m[it].front();
        m[it].pop();

        if(index>last){
            ans+=index-last;
            last=index;
        }
        else{
            ans+=a.size()-last + index;
            last=index;
            m=mOriginal;
            int temp=m[it].front();
            m[it].pop();
            m[it].push(temp);
        }
    }
    return ans;
}

int main(){
    string a,b;
    cin >> a >> b;
    cout << contest(a,b)<<'\n';
    return 0;
}