#include<bits/stdc++.h>
using namespace std;
#define ll long long int

void selectionSort(vector<int> &arr, int n){
    int i,j,min_index;

    //iterate over all the places in an array
    for(i=0;i<n-1;i++){
        //find minimum element in the unsorted array
        min_index=i;
        for(j=i+1;j<n;j++){
            if(arr[j]<arr[min_index]){
                min_index=j;
            }
        }
        //swap the minimum element with the first element
        swap(arr[i],arr[min_index]);
    }
}


