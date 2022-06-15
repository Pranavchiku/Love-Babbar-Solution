#include <bits/stdc++.h>
using namespace std;
#define ll long long int

stack<char> st;
string s;
void insert_at_bottom(char x){
    if(st.size()==0) st.push(x);
    else{
        char a=st.top();
        st.pop();
        insert_at_bottom(x);


        st.push(a);
    }
}

void reverse(){
    if(st.size()>0){
        char x=st.top();
        st.pop();
        reverse();

        insert_at_bottom(x);
    }
}

int main(){
    return 0;
}