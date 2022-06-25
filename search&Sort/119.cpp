#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int q;cin>>q;
    sort(arr,arr+n);
    while(q--){
        int power;cin>>power;
        int count=0;
        int sum=0;
        for(int i=0;i<n;i++){
            if(power>=arr[i]){
                count++;
                sum+=arr[i];
            }
        }
        cout<<count<<" "<<sum<<endl;
    }
    return 0;
}