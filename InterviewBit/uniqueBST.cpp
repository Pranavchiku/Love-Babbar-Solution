#include<bits/stdc++.h>
using namespace std;

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
void helper(set<vector<int>> &res, vector<int> curr, int i, int A){
    //base condition
    if(i>=A){
        return;
    }
    res.insert(curr);
    for(int j=i;j<A;j++){
        swap(curr[i],curr[j]);
        helper(res,curr,i+1,A);
        //backtrack
        swap(curr[i],curr[j]);
    }
    return;
}
void generateTrees(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    //{1,2,3} - {1,2,3},{1,3,2},{2,3,1},{2,1,3},{3,2,1},{3,1,2}
    //1st task - to find all possible permutations of [1,n]
    set<vector<int>> res;
    vector<int> curr; //{1,2,3}
    for(int i=1;i<=A;i++) curr.push_back(i);
    helper(res,curr,0,A);
    
    for(auto it: res){
        for(auto it2: it){
            cout<<it2<<" ";
        }
        cout<<'\n';
    }
}


int main(){
    int A;cin>>A;
    generateTrees(A);
    return 0;
}

