#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int getMinimumOfStickers(vector<string> stickers,string wording){
    map<char, set<string>> m;
    
}

int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<string> stickers(n);
        for(int i=0;i<n;i++){
            cin>>stickers[i];
        }
        string wording;
        cin>>wording;
        cout<<getMinimumOfStickers(stickers,wording)<<'\n';
    }
}