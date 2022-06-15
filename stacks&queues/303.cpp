#include <bits/stdc++.h>
using namespace std;
#define ll long long int


bool ispar(string s)
{
    stack<char> st;

    int n=s.length();
    for(int i=0;i<n;i++){

        if(s[i]=='(' or s[i]=='{' or s[i]=='[') st.push(s[i]);
        else{
            if(st.empty()) return false;
            char temp=st.top();
            if(s[i]==')'){
                if(temp=='(') st.pop();
                else return false;
            }
            else if(s[i]==']'){
                if(temp=='[') {
                    st.pop();
                }
                else return false;
            }
            else if(s[i]=='}'){
                if(temp=='{') st.pop();
                else return false;
            }
        }
    }
    if(st.empty()) return true;
    else return false;
}
int main(){
    cout<<ispar("()]")<<'\n';
    return 0;
}