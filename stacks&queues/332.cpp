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

vector <int> min_of_subarrays(int *arr, int n, int k)
{
    deque<int> q;
    vector<int> out;

    int i=0;
    while(i<k){
        while(!q.empty() and arr[i]<=arr[q.back()]){
            q.pop_back();
        }
        q.push_back(i);
        i++;
    }

    for(;i<n;++i){
        out.push_back(arr[q.front()]);
        while(!q.empty() and q.front()<=i-k) q.pop_front();

        while(!q.empty() and arr[i]<=arr[q.back()]) q.pop_back();

        q.push_back(i);
    }

    out.push_back(arr[q.front()]);
    // for(auto &it:out){
    //     cout<<it<<' ';
    // }
    // cout<<'\n';

    return out;
}

vector<int> sumMaxMin(int *arr, int n, int k){
    vector<int> maxE=max_of_subarrays(arr,n,k);
    vector<int> minE=min_of_subarrays(arr,n,k);
    vector<int> out;
    int a=maxE.size();
    for(int i=0;i<a;i++){
        out.push_back(maxE[i]+minE[i]);
    }
    return out;

}

int main(){
    int n=7;
    int k=4;
    int arr[n]={2,5,-1,7,-3,-1,-2};

    vector<int> out = sumMaxMin(arr,n,k);

    for(auto &it:out){
        cout<<it<<' ';
    }
    cout<<'\n';
}

