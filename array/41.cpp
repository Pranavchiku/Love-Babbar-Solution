#include <bits/stdc++.h>
using namespace std;
#define ll long long int

double MedianOfArrays(vector<int>& array1, vector<int>& array2)
{
    vector<int> arr={};
    int p=0;
    int q=0;
    int n=array1.size();
    int m=array2.size();
    while(p<n and q<m){
        if(array1[p]<array2[q]){
            arr.push_back(array1[p++]);
        }
        else{
            arr.push_back(array2[q++]);
        }
    }
    for(;p<n;p++) arr.push_back(array1[p]);
    for(;q<m;q++) arr.push_back(array2[q]);

    if((m+n)%2==0){
        int temp=(m+n)/2;
        double a1=arr[temp];
        double a2=arr[temp-1];
        return (a1+a2)/2;
    }
    else{
        return (arr[((m+n)/2)]);
    }

}
int main(){
    vector<int> array1={4,6};
    vector<int> array2={1,2,3,5};
    cout<<MedianOfArrays(array1,array2)<<'\n';
    return 0;

}