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

void mirrorify(Node *root, Node **mirror){
    if(root==NULL){
        mirror=NULL;
        return;
    }

    *mirror=createNode(root->data);
    mirrorify(root->left,&((*mirror)->right));
    mirrorify(root->right,&((*mirror)->left));
} 