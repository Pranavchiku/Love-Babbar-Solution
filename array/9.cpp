#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void sort012(int a[], int n)
{
    int l=0;
    int m=0;
    int h = n-1;
    while(m<=h){
        int i = m;
            if(a[i]==0){
                int temp = a[l];
                a[l]=0;
                a[i]=temp;
                l++;
                m++;
            }
            else if(a[i]==2){
                int temp = a[h];
                a[h]=2;
                a[i]=temp;
                h--;
            }
            else{
                m++;
            }
    }
    for (int i =0;i<n;i++) cout<<a[i]<<' ';
    cout<<'\n';
}

int main(){
    
    int n = 5;
    int a[n]={0,2,1,2,0};
    sort012(a,n);
    return 0;
}