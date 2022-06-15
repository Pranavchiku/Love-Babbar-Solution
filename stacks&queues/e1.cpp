#include <bits/stdc++.h>
using namespace std;
#define ll long long int

vector <int> max_of_subarrays(int *arr, int n, int k)
{
    deque<int> q;
    vector<int> out;

    int i=0;
    while(i<k){
        while(!q.empty() and arr[i]>=arr[q.back()]){
            q.pop_back();
        }
        q.push_back(i);
        i++;
    }

    for(;i<n;++i){
        out.push_back(arr[q.front()]);
        while(!q.empty() and q.front()<=i-k) q.pop_front();

        while(!q.empty() and arr[i]>=arr[q.back()]) q.pop_back();

        q.push_back(i);
    }

    out.push_back(arr[q.front()]);
    // for(auto &it:out){
    //     cout<<it<<' ';
    // }
    // cout<<'\n';

    return out;
}

int main(){
    int n=5;
    int k=3;
    int arr[n]={4,1,3,2,6};

    vector<int> out = max_of_subarrays(arr,n,k);
    return 0;
}