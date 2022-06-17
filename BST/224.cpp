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


void inOrderTraversal(Node *root, vector<int> &dfs){
    if(root!=NULL){
        inOrderTraversal(root->left,dfs);
        dfs.push_back(root->data);
        inOrderTraversal(root->right,dfs);
    }
}
//sorted array to balanced BST

Node *sortedBBST(vector<int> &arr, int start , int end){
    if(start>end) return NULL;

    int mid=(start+end)/2;
    Node*root=createNode(arr[mid]);

    root->left=sortedBBST(arr,start,mid-1);
    root->right=sortedBBST(arr,mid+1,end);

    return root;
}

Node *BSTToBalancedBST(Node *root){
    vector<int> dfs;
    inOrderTraversal(root,dfs);

    root=sortedBBST(dfs,0,dfs.size());
}