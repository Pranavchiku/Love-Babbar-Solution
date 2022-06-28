#include <bits/stdc++.h>
using namespace std;
#define ll long long int


void combinationSumUtil(vector<int> a, int b, int i, vector<int> temp, set<vector<int>> &res){
    if(b<0){
        return;
    }
    if(b==0){
        res.insert(temp);
        return;
    }
    if(i==a.size()){
        return;
    }
    //include that element
    temp.push_back(a[i]);
    combinationSumUtil(a, b-a[i], i, temp, res);
    //backtrack and exclude current element
    temp.pop_back();
    combinationSumUtil(a, b, i+1, temp, res);

}
vector<vector<int> > combinationSum(vector<int> &A, int B) {
    vector<vector<int>> result;
    set<vector<int>> res;
    vector<int> temp;
    unordered_set<int> s(A.begin(),A.end());
    vector<int> arr(s.begin(),s.end());
    sort(arr.begin(), arr.end());
    combinationSumUtil(arr, B, 0, temp, res);

    for(auto it:res){
        result.push_back(it);
    }
    return result;
}

int main(){
    int n;cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int b;cin>>b;
    vector<vector<int>> res=combinationSum(a,b);
    for(int i=0;i<res.size();i++){
        for(int j=0;j<res[i].size();j++){
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
}