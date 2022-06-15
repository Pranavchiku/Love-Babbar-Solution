#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int findLongestConseqSubseq(int arr[], int n)
{   
    int m=*max_element(arr,arr+n);
    int freq[m+1]={0};
    for(int i=0;i<n;i++) freq[arr[i]]++;

    int c=0;
    int output=-INT_MAX;
    for(int i=0;i<m+1;i++){
        if(freq[i]>=1){
            c++;
        }
        else{
            output=max(c,output);
            c=0;
        }
    }
    return max(c,output);
}
int main(){
    int n=7;
    int arr[n]={1,9,3,10,4,20,2};
    cout<<findLongestConseqSubseq(arr,n)<<'\n';
    return 0;
}