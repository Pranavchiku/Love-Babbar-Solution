#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void sortPN(int a[], int n){
    int p=0;
    int i=p+1;
    while(i<n){
        if(a[i]<0){
            int temp = a[p];
            a[p]=a[i];
            a[i]=temp;
            p=p+1;
            i=p+1;
        }
        i++;
    }
    for(int i=0;i<n;i++) cout<<a[i]<<' ';
    cout<<'\n';
}
int main(){
    int n = 9;
    int a[n]={-12 ,-13 ,-5 ,-7 ,-3 ,-6, 11, 6, 5};
    sortPN(a,n);
    return 0;
}