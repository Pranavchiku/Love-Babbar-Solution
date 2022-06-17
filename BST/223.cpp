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


void DFS(Node *root, vector<int> &dfs){
    if(root!=NULL){
        DFS(root->left,dfs);
        dfs.push_back(root->data);
        DFS(root->right,dfs);
    }
}

void btToBST(Node *root, vector<int> &dfs, int &i){
    if(root!=NULL){
        btToBST(root->left,dfs,i);
        root->data=dfs[i++];
        btToBST(root->right,dfs,i);
    }
}
Node *binaryTreeToBST (Node *root)
{
    vector<int> dfs;
    DFS(root,dfs);
    sort(dfs.begin(),dfs.end());
    int i=0;
    btToBST(root,dfs,i);
    return root;
}