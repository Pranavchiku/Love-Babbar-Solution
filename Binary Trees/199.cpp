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

int check(Node *root, bool &ans){
    if(root==NULL) return 0;
    if(root->left==NULL and root->right==NULL) return root->data;
    int left=check(root->left,ans);
    int right=check(root->right,ans);
    
    if(left+right!=root->data) ans=false;
    return root->data+left+right; //as leftsubtree's value and right subtree's value asked so needed to add root->Data;
}
bool isSumTree(Node* root)
{
    bool ans=true;
    check(root,ans);
    return ans;
}