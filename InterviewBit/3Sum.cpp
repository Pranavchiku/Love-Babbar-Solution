#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int binarySearch(vector<int> arr, int l, int r, int x)
{
    
    while (l<arr.size() and r<arr.size() and l <= r) {
        int m = l + (r - l) / 2;
 
        // Check if x is present at mid
        if (arr[m] == x)
            return m;
 
        // If x greater, ignore left half
        if (arr[m] < x)
            l = m + 1;
 
        // If x is smaller, ignore right half
        else
            r = m - 1;
    }
 
    // if we reach here, then element was
    // not present
    return -1;
}
   

vector<vector<int>> threeSum(vector<int> &A) {
    set<vector<int>> ans;
    sort(A.begin(),A.end());
    int n=A.size();
    int l=0;
    int r=n-1;
    while(l<=r){
        int sum=A[l]+A[r];
        int se=binarySearch(A,l+1,r-1,(-1)*sum);
        if(se==-1){
            if(sum<=0) l++;
            else r--;
        }
        else{
            vector<int> v;
            v.push_back(A[l]);
            v.push_back(A[se]);
            v.push_back(A[r]);
            ans.insert(v);
            l++;
        }
    }
    vector<vector<int>> fAns;
    for(auto it: ans){
        fAns.push_back(it);
    }
    return fAns;
}

int main(){
    int n;
    cin>>n;
    vector<int> A(n);
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
    vector<vector<int>> fAns=threeSum(A);
    for(auto it: fAns){
        for(auto it2: it){
            cout<<it2<<" ";
        }
        cout<<endl;
    }
    return 0;
}