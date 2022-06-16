#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int pageFaults(int n, int c, int page[]){
    
    int count=0;
    vector<int> v;

    for(int i=0;i<n;i++){
        auto it=find(v.begin(),v.end(),page[i]);

        if(it==v.end()){
            if(v.size()==c){
                v.erase(v.begin());
            }
            v.push_back(page[i]);
            count++;
        }
        else{
            v.erase(it);
            v.push_back(page[i]);
        }
    }
    return count;
}