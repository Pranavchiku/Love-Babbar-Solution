#include <bits/stdc++.h>
using namespace std;
#define ll long long int


typedef struct Node{
    int data;
    Node* left;
    Node* right;
}Node;

Node* createNode(int data){
    Node *n=new(Node);
    n->right=n->left=NULL;
    n->data=data;
    return n;
}



unordered_map <Node*,int> dp;
int func(Node *root) 
{
   if(root==NULL) return 0;

   if(dp[root]) return dp[root];

   int inc=root->data;
   if(root->left){
        inc+=func(root->left->left);
        inc+=func(root->left->right);
   }
   if(root->right){
        inc+=func(root->right->left);
        inc+=func(root->right->right);
   }
   int exc=func(root->left)+func(root->right);

   dp[root]=max(inc,exc);
   return dp[root];
}

int getMaxSum(Node *root){
    dp.clear();
    return func(root);
}