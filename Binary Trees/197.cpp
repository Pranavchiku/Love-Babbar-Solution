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

void insert(Node *root, int key){

    Node* prev=NULL;
    Node *n=createNode(key);
    while(root!=NULL){
        prev=root;
        if(key==root->data) return;
        else if(key<root->data) root=root->left;
        else root=root->right;
    }
    if(key>prev->data) prev->right=n;
    else prev->left=n;
    
}
 
Node *solve(int pre[], int in[], int &idx, unordered_map<int,int> m, int lb, int ub){
    if(lb>ub) return NULL;
    Node *curr=createNode(pre[idx++]);
    if(lb==ub) return curr;
    int mid=m[curr->data];
    curr->left=solve(pre,in,idx,m,lb,mid-1);
    curr->right=solve(pre,in,idx,m,mid+1,ub);
    return curr;
}
Node* buildTree(int in[],int pre[], int n)
{
    int idx=0;
    unordered_map<int,int> m;
    m.clear();
    for(int i=0;i<n;i++) m[in[i]]=i;
    Node *root=solve(pre,in,idx,m,0,n-1);
    return root;
}