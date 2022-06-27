#include <bits/stdc++.h>
using namespace std;
#define ll long long int

bool isValid(int a[], int n, int m, int mid){
    int numberOfStudents=1;
    int sum1=0;
    for(int i=0;i<n;i++){
        if(a[i]>mid) return false;
        if(sum1+a[i]>mid){
            numberOfStudents++;
            sum1=a[i];
            if(numberOfStudents>m) return false;
        }
        else{
            sum1+=a[i];
        }
    }
    return true;
}
int findPages(int a[], int n, int m) 
{
    int l=0;
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=a[i];
    }
    int ans=0;
    int h=sum;
    while(l<=h){
        int mid=(l+h)/2;
        if(isValid(a,n,m,mid)){
            ans=mid;
            h=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    return ans;
}