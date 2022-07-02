#include<bits/stdc++.h>
using namespace std;
#define ll long long int

//amazing O(n) and O(1) solution 
//known as moore voting algorithm
int majorityElement(vector<int> A){
    int n=A.size();
    int count=0;
    int maj=A[0];
    for(int i=1;i<n;i++){
        if(A[i]==maj){
            count++;
        }
        else{
            count--;
        }
        if(count==0){
            maj=A[i];
            count=1;
        }
    }
    return maj;
}