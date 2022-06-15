#include <bits/stdc++.h>
using namespace std;
#define ll long long int


int evaluatePostfix(string s)
{
    stack<int> st;
    int n=s.length();
    for(int i=0;i<n;i++){
        // cout<<s[i]<<'\n';
        if(s[i]=='/' or s[i]=='*' or s[i]=='+' or s[i]=='-'){
            int t1=st.top();
            st.pop();
            int t2=st.top();
            st.pop();

            if(s[i]=='/'){
                st.push(t2/t1);
            }
            else if(s[i]=='*') st.push(t2*t1);
            else if(s[i]=='+') st.push(t2+t1);
            else st.push(t2-t1);
        }
        else{
            st.push(s[i] - '0');
        }
    }

    return st.top();
}


//evaluate prefix same

int evalPrefix(string s){
    stack<int> st;
    int n=s.length();
    for(int i=n-1;i>=0;i--){
        if(s[i]=='/' or s[i]=='*' or s[i]=='+' or s[i]=='-'){
        int t1=st.top();
        st.pop();
        int t2=st.top();
        st.pop();

        if(s[i]=='/'){
            st.push(t1/t2);
        }
        else if(s[i]=='*') st.push(t1*t2);
        else if(s[i]=='+') st.push(t1+t2);
        else st.push(t1-t2);
        }
        else{
            st.push(s[i] - '0');
        }
    }
    return st.top();
}
int main(){
    string s= "-+8/632";
    cout<<evalPrefix(s)<<'\n';
    return 0;
}