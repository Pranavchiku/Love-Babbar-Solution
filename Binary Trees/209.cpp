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

Node *solve(Node *root, int n1, int n2){
    if(root==NULL or root->data==n1 or root->data==n2) return root;
    
    Node *left=solve(root->left,n1,n2);
    Node *right=solve(root->right,n1,n2);
    
    if(left!=NULL and right!=NULL){
        return root;
    }
    else if(left!=NULL and right==NULL){
        return solve(root->left,n1,n2);
    }
    else if(left==NULL and right!=NULL){
        return solve(root->right,n1,n2);
    }
}
Node* lca(Node* root ,int n1 ,int n2 )
{
    return solve(root,n1,n2);
}