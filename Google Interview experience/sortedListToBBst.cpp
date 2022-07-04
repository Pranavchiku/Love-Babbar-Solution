#include<bits/stdc++.h>
using namespace std;
#define ll long long int

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
TreeNode* solve(vector<int> nodes, int l, int r){
    if(l>r){
        return NULL;
    }
    int mid=(l+r)/2;
    TreeNode *root=new TreeNode(nodes[mid]);
    root->left=solve(nodes,l,mid-1);
    root->right=solve(nodes,mid+1,r);
    return root;
    
    
}
TreeNode* sortedListToBST(ListNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<int> nodes;
    ListNode *p=A;
    while(p!=NULL){
        nodes.push_back(p->val);
        p=p->next;
    }
    
    int l=0;
    int r=nodes.size()-1;
    
    TreeNode *root=solve(nodes,l,r);
    return root;
}

void inorder(TreeNode *root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}
int main(){
    ListNode *A=new ListNode(1);
    A->next=new ListNode(2);
    A->next->next=new ListNode(3);
    A->next->next->next=new ListNode(4);
    A->next->next->next->next=new ListNode(5);
    TreeNode *root=sortedListToBST(A);
    inorder(root);
    return 0;
}