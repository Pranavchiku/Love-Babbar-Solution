#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void heapifyIter(int arr[], int n){
    for(int i=(n/2)-1;i>=0;i--){
        int j=2*j+1;
        while(j<=n-1){
            if(n<=j+1){
                if(arr[i]<arr[j]){
                    int temp=arr[i];
                    arr[i]=arr[j];
                    arr[j]=temp;
                    i=j;
                    j=2*i+1;
                }
                else break;
            }
            else{
                if(arr[j]<arr[j+1]) j++;
                if(arr[i]<arr[j]){
                    int temp=arr[i];
                    arr[i]=arr[j];
                    arr[j]=temp;
                    i=j;
                    j=2*i+1;
                }
                else break;
            }
        }
    }
}

void heapifyRec(int arr[], int n, int i){
    int largest=i;
    int l=2*i+1;
    int r=2*i+2;

    if(l<n and arr[l]>arr[largest]) largest=l;
    if(r<n and arr[r]>arr[largest]) largest=r;

    if(largest!=i){
        swap(arr[i],arr[largest]);
        heapifyRec(arr,n,largest);
    }
}

void buildHeap(int arr[], int n){
    int start=(n/2)-1;

    for(int i=start;i>=0;i--){
        heapifyRec(arr,n,i);
    }
}