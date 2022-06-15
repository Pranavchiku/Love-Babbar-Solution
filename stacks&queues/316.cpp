#include <bits/stdc++.h>
using namespace std;
#define ll long long int

bool checkRedunancy(string str){
    stack<char> st;

    int n=str.length();
    for(int i=0;i<n;i++){
        if(str[i]==')'){
            char top=st.top();
            st.pop();

            bool flag=true;
            while(!st.empty() and top!='('){
                if(top=='+' or top=='-' or top=='/' or top=='*') flag=false;

                top=st.top();
                st.pop();
            }

            if(flag==true) return false;
        }
        else st.push(str[i]);

    }
    return true;
}
int main(){
    return 0;
}