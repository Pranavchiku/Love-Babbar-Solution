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

void checkBST(Node *root, Node *prev, int &f){
    if(root==NULL) return;
    checkBST(root->left,prev,f);
    if(prev!=NULL and root->data<=prev->data){
        f=0;
        return;
    }
    prev=root;
    checkBST(root->right,prev,f);
}

bool isBST(Node *root){
    int f=1;
    Node *prev=NULL;
    checkBST(root,prev,f);
    return f;
}

class info{
    public:
    int maxi;
    int mini;
    bool isBST;
    int size;
};


info solve(Node *root, int &ans){
    if(root==NULL){
        return {INT_MIN, INT_MAX, true, 0};
    }
    info left=solve(root->left,ans);
    info right=solve(root->right,ans);

    info currNode;
    currNode.size=left.size+right.size+1;
    currNode.maxi=max(root->data,right.maxi);
    currNode.mini=min(root->data,left.mini);

    if(left.isBST and right.isBST and (root->data>left.maxi and root->data<right.mini)){
        currNode.isBST=true;
    }
    else currNode.isBST=false;

    if(currNode.isBST){
        ans=max(ans,currNode.size);
    }
    return currNode;
}

int largestBst(Node *root)
{
    int maxSize=0;
    info temp=solve(root,maxSize);
    return maxSize;
}

int main(){
    return 0;
}