#include <bits/stdc++.h>
using namespace std;
#define ll long long int

typedef struct Node{
    char ch;
    int count;
}Node;



string reorganizeString(string s) {
    map<char, int> m;
    priority_queue<pair<int,char>> q;
    for(int i=0;i<s.length();i++){
        m[s[i]]++;
    }

    for(auto x: m){
        int req=x.second-1;
        if(s.length()-x.second<req) return "-1";
    }


    // for(auto x: m){
    //     cout<<x.first<<' '<<x.second<<'\n';
    // }

    for(auto x:m){
        q.push({x.second,x.first});
    }

    string ans="";
    while(q.size()>1){
        pair<int, char> temp=q.top();
        q.pop();

        pair<int,char> temp2=q.top();
        q.pop();

        ans+=temp.second;
        ans+=temp2.second;

        temp.first--;
        temp2.first--;

        if(temp.first>0) q.push(temp);
        if(temp2.first>0) q.push(temp2);
    }

    if(!q.empty()){
        ans+=q.top().second;
    }

    return ans;
    
}

int main(){
    cout<<reorganizeString("aab")<<'\n';
    return 0;
}