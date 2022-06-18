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

int constructBST(int preorder[], int n, int pos, Node *curr, int left, int right){
    if(pos==n or preorder[pos]<left or preorder[pos]>right) return pos;

    if(preorder[pos]<curr->data){
        curr->left=createNode(preorder[pos]);
        pos+=1;
        pos=constructBST(preorder,n,pos,curr->left,left,curr->data-1);
    }

    if(pos==n or preorder[pos]<left or preorder[pos]>right) return pos;

    curr->right = createNode(preorder[pos]);
    pos+=1;
    pos=constructBST(preorder,n,pos,curr->right,curr->data+1,right);
    return pos;
}

Node* bstFromPreOrder(int preorder[], int n){
    if(n==0) return NULL;

    Node *root=createNode(preorder[0]);
    if(n==1) return root;

    constructBST(preorder,n,1,root,INT_MIN,INT_MAX);
    return root;
}

Node* post_order(int pre[], int size)
{
    Node *root=bstFromPreOrder(pre,size);
    return root;
}