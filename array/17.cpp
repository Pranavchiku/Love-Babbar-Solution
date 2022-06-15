#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void merge(int arr1[], int arr2[], int n, int m) {
    int i=n-1;
    int j=0;
    while(i>=0 and j<m){
        if(arr1[i]>arr2[j]){
            int temp=arr1[i];
            arr1[i]=arr2[j];
            arr2[j]=temp;
        }
        i--;
        j++;
    }
    sort(arr1,arr1+n);sort(arr2,arr2+m);
    for(int i=0;i<n;i++) cout<<arr1[i]<<' ';
    for(int i=0;i<m;i++) cout<<arr2[i]<<' ';
    cout<<'\n';
}
int main(){
    int n = 3;
    int arr1[n]={1, 3, 5, 7};
    int m = 5;
    int arr2[m]={0, 2, 6, 8, 9};
    merge(arr1,arr2,n,m);
    return 0;
}