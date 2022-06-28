#include <bits/stdc++.h>
using namespace std;
#define ll long long int

bool isValid(string s){
    int counter=0;
    for(int i=0;i<s.length();i++){
        if(s[i]=='(')
            counter++;
        else if(s[i]==')')
            counter--;
        if(counter<0)
            return false;
    }
    return counter==0;
}
vector<string> removeInvalidParentheses(string s) {
    if(s.empty())
        return {""};
    unordered_set<string> visit;
    vector<string> result;

    queue<string> q;
    q.push(s);
    visit.insert(s);
    bool level;
    string temp;
    while(!q.empty()){
        s=q.front();
        q.pop();
        if(isValid(s)){
            result.push_back(s);
            level=true;
        }

        if(level) continue;
        for(int i=0;i<s.length();i++){
            if(s[i]=='(' or s[i]==')'){
                temp=s.substr(0,i)+ s.substr(i+1);
                if(visit.find(temp)==visit.end()){
                    q.push(temp);
                    visit.insert(temp);
                }
            }
        }
    }

    return result;
}