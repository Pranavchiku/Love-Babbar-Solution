#include <bits/stdc++.h>
using namespace std;
#define ll long long int

long int sortArray(long long arr[], long long n, long long l, long long mid, long long h){
    long long a[h-l+1]={0};
    long int p=l;
    long int q=mid+1;
    long int i=0;
    long long flag=0;
    long int count=0;
    // cout<<'l'<<' '<<l<<' '<<"h "<<h<<'\n';
    while(i<h-l+1 and p<=mid and q<=h){
        if(arr[p]<arr[q]){
            a[i++]=arr[p++];
            
        }
        else if(arr[p]==arr[q]) a[i++]=arr[q++];
        else{
            count+=mid-p+1;
            a[i++]=arr[q++];
        }
    }
    for(;p<=mid;p++) {
        a[i++]=arr[p];
    }
    for(;q<=h;q++) {
        a[i++]=arr[q];
    }
    // cout<<"count"<<count<<'\n';

    // for(ll i=0;i<h-l+1;i++) cout<<a[i]<<' ';
    // cout<<'\n';

    for(long long i=l;i<h-l+1;i++){
        // if(arr[i]!=a[i]) count++;
        arr[i]=a[i];
    }
    return count;
}

long int recSort(long long arr[], long long n, long long l, long long h){
    long int count=0;
    if(l<h){
        long long mid = (l+h)/2;
        // cout<<'l'<<' '<<l<<' '<<"h "<<h<<' '<<"mid "<<mid<<'\n';
        recSort(arr,n,l,mid);
        recSort(arr,n,mid+1,h);
        count+=sortArray(arr,n,l,mid,h);

        // cout<<"count"<<count<<'\n';
        // for(ll i=0;i<n;i++) cout<<arr[i]<<' ';
        // cout<<'\n';
    }
    return count;
    
}

long int inversionCount(long long arr[], long long n)
{   
    long long l=0;
    long long h=n-1;
    long int count=0;
    count+=recSort(arr,n,l,h);
    // for(ll i=0;i<n;i++) cout<<arr[i]<<' ';
    // cout<<'\n';
    return count;
}




int main(){
    long long n=5;
    long long arr[n]={2,3,4,1,5};
    cout<<inversionCount(arr,n)<<'\n';
    return 0;
}