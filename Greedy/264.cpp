#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    int t;cin>>t;
    while(t--){
        int w,h,n;cin>>w>>h>>n;
        vector<int> width;
        vector<int> height;

        for(int i=0;i<n;i++){
            int tempw,temph;cin>>tempw>>temph;
            width.push_back(tempw);
            height.push_back(temph);
        }

        sort(width.begin(),width.end());
        sort(height.begin(),height.end());

        vector<int> diffW;
        diffW.push_back(width[0]-1);
        vector<int> diffH;
        diffH.push_back(height[0]-1);
        for(int i=1;i<n;i++){
            diffW.push_back(width[i]-width[i-1]-1);
            diffH.push_back(height[i]-height[i-1]-1);
        }

        diffW.push_back(w+1-width[n-1]-1);
        diffH.push_back(h+1-height[n-1]-1);

        sort(diffW.begin(),diffW.end(),greater<int>());
        sort(diffH.begin(),diffH.end(),greater<int>());

        cout<<diffW[0]*diffH[0]<<'\n';

    }
    return 0;
}