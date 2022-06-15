#include <bits/stdc++.h>
using namespace std;
#define ll long long int


string chooseandswap(string a){
    int i=0;
    int j=1;
    int n=a.length();

    set<char> s;
    for(int i=0;i<n;i++) s.insert(a[i]);

    for(int i=0;i<n;i++){
        s.erase(a[i]);
        if(s.empty()) break;
        char ch=*s.begin();
        if(ch<a[i]){
            int ch2=a[i];
            for(int j=0;j<n;j++){
                if(a[j]==ch2) a[j]=ch;
                else if(a[j]==ch) a[j]=ch2;
            }
            break;
        }
    }
    return a;
}
int main(){
    cout<<chooseandswap("baab")<<'\n';
    return 0;
}