#include <bits/stdc++.h>
using namespace std;
#define ll long long int


char* reverse(char *s, int len)
{
    char *c= new char[len];
    stack<char> st;

    for(int i=0;i<len;i++){
        st.push(s[i]);
    }

    for(int i=0;i<len;i++){
        c[i]=st.top();
        st.pop();
    }
    return c;

}
int main(){
    char s[14]="GeeksforGeeks";
    reverse(s,14);
    return 0;
}