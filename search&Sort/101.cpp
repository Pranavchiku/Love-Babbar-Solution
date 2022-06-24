#include <bits/stdc++.h>
using namespace std;
#define ll long long int

vector<int> find(int arr[], int n, int x){
    int l=0;
    int r=n-1;
    while(l<=r){
        int mid=(l+r)/2;
        if(arr[mid]==x){
            l=mid;
            break;
        }
        else if(arr[mid]<x){
            l=mid+1;
        }
        else{
            r=mid-1;
        }
    }
    if(l>r) return vector<int> {-1,-1};
    int ans1=l;
    int left=l;
    for(left;left>=0;left--){
        if(arr[left]!=x){
            break;
        }
    }
    left++;
    int right=l;
    for(right;right<n;right++){
        if(arr[right]!=x){
            break;
        }
    }
    right--;
    return vector<int> {left,right};
}