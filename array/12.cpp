#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void rotate(int arr[], int n)
{
    int l =0;
    int r =n-1;
    while(l!=r){
        int temp =arr[l];
        arr[l]=arr[r];
        arr[r]=temp;
        l++;
    }
    // for(int i=0;i<n;i++) cout<<arr[i]<<' ';
    // cout<<'\n';
}

int main(){
    int n = 8;
    int arr[n]={9, 8, 7, 6, 4, 2, 1, 3};
    rotate(arr,n);
    return 0;
}